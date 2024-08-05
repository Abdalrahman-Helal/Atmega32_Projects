/*
 * LCD_interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

typedef enum{
	ROW1=1,
	ROW2
}LCD_ROW_e;

typedef enum{
	COL1=1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14,
	COL15
}LCD_COL_e;
void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);

void HLCD_voidInit(void);
void HLCD_voidClearDisplay(void);
void HLCD_voidDisplayString(u8 *A_u8PtrToString);
void HLCD_voidGoToPos(LCD_ROW_e A_LCDRow, LCD_COL_e A_LCDCol);


#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
