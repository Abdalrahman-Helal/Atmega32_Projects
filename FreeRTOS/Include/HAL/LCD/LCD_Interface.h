/*
 * LCD_Interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_


void HLCD_voidSendCommand (u8 A_u8Command);
void HLCD_voidSendData (u8 A_u8Data);
void HLCD_voidInit (void);
void HLCD_voidDisplayString (u8 * A_ptrToString);

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
