/*
 * LCD_Interface.h
 *
 *  Created on: Mar 3, 2025
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_


typedef enum
{
	LCD_ROW1=1,
	LCD_ROW2
}LCD_ROW_e;

typedef enum
{
	LCD_COL1=1,
	LCD_COL2,
	LCD_COL3,
	LCD_COL4,
	LCD_COL5,
	LCD_COL6,
	LCD_COL7,
	LCD_COL8,
	LCD_COL9,
	LCD_COL10,
	LCD_COL11,
	LCD_COL12,
	LCD_COL13,
	LCD_COL14,
	LCD_COL15,
	LCD_COL16
}LCD_COL_e;

typedef enum{
	LCD_PATTERN0=0,
	LCD_PATTERN1,
	LCD_PATTERN2,
	LCD_PATTERN3,
	LCD_PATTERN4,
	LCD_PATTERN5,
	LCD_PATTERN6,
	LCD_PATTERN7,
};

void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendData(u8 A_u8Command);
void HLCD_vInit(void);
void HLCD_vClearDisplay(void);
void HLCD_vDisplayLongString(u8 *A_u8PtrToString);
void HLCD_vDisplayString(u8 *A_u8PtrToString);
void HLCD_vGoToPos(LCD_ROW_e A_LCDRow ,LCD_COL_e A_LCDCol);
void HLCD_vDisplayNumber(u32 A_u32Number);
void HLCD_vSendSpecialSymbol(u8 *A_ptru8SymbolArray, u8 A_u8PatternNum, LCD_ROW_e A_RowNo , LCD_COL_e A_COLNo);


#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
