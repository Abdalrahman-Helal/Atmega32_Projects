/*
 * LCD_Int.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Abdalrahman
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_CTRL_PORT 	DIO_PORTC
#define LCD_DATA_PORT 	DIO_PORTD

#define LCD_RS_PIN   DIO_PIN0
#define LCD_RW_PIN	 DIO_PIN1
#define LCD_EN_PIN	 DIO_PIN2

#define HLCD_CLR 0b00000001

#define LCD_LINE0 0
#define LCD_LINE1 1

void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vClearDisplay(void);
//void HLCD_vSendData(u8 A_u8Data);
//void HLCD_vPrintString(u8 A_s8Strinf[]);
void HLCD_vPrintString(u8 *pString);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition( u8 A_u8LinePos, u8 A_u8LineNo );
void HLCD_vSaveCustomChar( u8 L_CGRAM_Index, u8 A_CustomCharData[]);
void HLCD_vDisplayCustomChar(u8 A_u8CGRAM_IDX);

void HLCD_vDisplayShift(void);


#endif /* HAL_LCD_LCD_INT_H_ */
