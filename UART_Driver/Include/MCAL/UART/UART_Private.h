/*
 * UART_Private.h
 *
 *  Created on: Aug 30, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

#define UDR   (*(volatile u8 *)0x2C)
#define UCSRA (*(volatile u8 *)0x2B)
#define UCSRB (*(volatile u8 *)0x2A)
#define UBRRL (*(volatile u8 *)0x29)
#define UBRRH (*(volatile u8 *)0x40)
#define UCSRC (*(volatile u8 *)0x40)

#define BAUD_RATE_EQUATION (F_CPU /16/BAUDRATE_VALUE-1)


#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
