/*
 * UART_Interface.h
 *
 *  Created on: Aug 30, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

typedef enum {
	UART_RX_INTERRUPT=0,
	UART_UDRE_INTERRUPT,
	UART_TX_INTERRUPT
}UART_INTERRUPTS_e;

void MUART_voidInit(void);
void MUART_voidSendByteSyncBlocking(u16 A_u16DataByte);
void MUART_voidSendByteSyncnNonBlocking(u16 A_u16DataByte);
void MUART_voidSendStringSyncNonBlocking (u8 *A_pu8String);
void MUART_voidSendByteAsync(u8 A_pu8String);
u8 MUART_u8ReadByteSyncBlocking(void);
u8 MUART_u8ReadByteAsync(void);
u8 MUART_u8ReadByteSyncNonBlocking(void);
void MUART_voidSetCallBack (UART_INTERRUPTS_e A_InterruptSource , void(*A_PtoFunc)(void));
#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
