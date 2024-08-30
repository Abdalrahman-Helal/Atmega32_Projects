/*
 * App.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */
#include <util/delay.h>

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"


#define F_CPU 8000000UL

int main(void)
{
//	MDIO_voidInit();
	MDIO_voidSetPinDirection(DIO_PORTA,PIN0,DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTD,PIN1,DIO_OUTPUT);
	MUART_voidInit();

	u8 local_u8ReceivedData=255;
	MUART_voidSendStringSyncNonBlocking("To Turn LED On Enter 'O' or 'o '\r\nTo Turn LED Off Enter 'F' or 'f' \r\n");
	_delay_ms(100);
	while(1)
	{
		local_u8ReceivedData= MUART_u8ReadByteSyncBlocking();
		_delay_ms(100);
		if((local_u8ReceivedData == 'O') || (local_u8ReceivedData == 'o') )
		{
			HLED_voidTurnLEDOn(DIO_PORTA, PIN0);
			MUART_voidSendStringSyncNonBlocking("\r\nLED On	\r\n");
		}
		else if ((local_u8ReceivedData == 'F') || (local_u8ReceivedData == 'f'))
		{
			HLED_voidTurnLEDOff(DIO_PORTA, PIN0);
			MUART_voidSendStringSyncNonBlocking("\r\nLED Off\r\n");
		}
	}
}











