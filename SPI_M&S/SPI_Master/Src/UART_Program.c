/*
 * UART_Program.c
 *
 *  Created on: Aug 30, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/MCAL/UART/UART_Private.h"
#include "../Include/MCAL/UART/UART_Cfg.h"

#define F_CPU 8000000UL
#define NULL 0

static void (*FuncPtr[3]) (void)={NULL , NULL , NULL};

void MUART_voidInit(void)
{
	u16 local_u16BaudRate = BAUD_RATE_EQUATION;
	// Set BaudRate
	UBRRL= (u8) local_u16BaudRate;
	UBRRH = (u8) (local_u16BaudRate >> 8);

	//Character Size 8-Bit
	CLR_BIT(UCSRB,2);

	//Character Size 8-Bit
	//Mode Asynchronous operation
	// Parity Disbaled
	// 1 Stop Bit
	UCSRC = CONC_BIT(1,0,0,0,0,1,1,0);

	//Enable Receiver
	//Enable Transmitter
	SET_BIT(UCSRB ,3);
	SET_BIT(UCSRB ,4);

}

void MUART_voidSendByteSyncBlocking(u16 A_u16DataByte)
{
	// Wait until UDR is Empty
	while(GET_BIT(UCSRA,5) == 0);

	// Set Data into Tx Register and Start Transmission
	UDR=A_u16DataByte;

	// Wait Until UDR is Empty
	while(GET_BIT(UCSRA,5) == 0);

	// Clear transmit Interrupt Flag
	SET_BIT(UCSRA ,6);
}

void MUART_voidSendByteSyncnNonBlocking(u16 A_u16DataByte)
{
	u32 local_u32Timeout=0;

	// Wait until UDR is Empty
	while(GET_BIT(UCSRA,5) == 0)
	{
		local_u32Timeout++;
		if(local_u32Timeout == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}
	if(local_u32Timeout != NON_BLOCKING_TIME_OUT)
	{
		// Set Data into Tx Register and Start Transmission
		UDR=A_u16DataByte;

		// Wait until UDR is Empty
		while(GET_BIT(UCSRA,5) == 0)
		{
			local_u32Timeout++;
			if(local_u32Timeout == NON_BLOCKING_TIME_OUT)
			{
				break;
			}
		}
		// Clear transmit Interrupt Flag
		SET_BIT(UCSRA ,6);
	}
}

void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String)
{
	while(*A_pu8String > 0)
	{
		MUART_voidSendByteSyncnNonBlocking(*A_pu8String++);
	}
}

void MUART_voidSendByteAsync(u8 A_pu8String)
{
	// Check if Data Register is empty
	if(GET_BIT(UCSRA , 5) == 1)
	{
		UDR=A_pu8String;
	}
}

u8 MUART_u8ReadByteSyncBlocking(void)
{
	// wait for Rx Flag
	while(GET_BIT(UCSRA , 7)==0);
	return UDR;
}

u8 MUART_u8ReadByteAsync(void)
{
	return UDR;
}

u8 MUART_u8ReadByteSyncNonBlocking(void)
{
	u8 local_u8ReceivedData= NO_VALUE_RETURNED;
	u32 local_u32Timeout=0;

	// wait until Rx is Ready
	while(GET_BIT(UCSRA , 7)==0)
	{
		local_u32Timeout++;
		if(local_u32Timeout == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}

	if(local_u32Timeout !=NON_BLOCKING_TIME_OUT )
	{
		// Read Received Data from UDR
		local_u8ReceivedData = UDR;
	}
	return local_u8ReceivedData;

}

void MUART_voidSetCallBack (UART_INTERRUPTS_e A_InterruptSource , void(*A_PtoFunc)(void))
{
	if( (A_InterruptSource <=UART_TX_INTERRUPT) && (A_PtoFunc != NULL))
	{
		FuncPtr [A_InterruptSource] = A_PtoFunc;
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(FuncPtr[UART_RX_INTERRUPT] != NULL)
	{
		FuncPtr[UART_RX_INTERRUPT]();
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if(FuncPtr[UART_UDRE_INTERRUPT] != NULL)
	{
		FuncPtr[UART_UDRE_INTERRUPT]();
	}
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(FuncPtr[UART_TX_INTERRUPT] != NULL)
	{
		FuncPtr[UART_TX_INTERRUPT]();
	}
}



