/*
 * LCD_Program.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/LCD/LCD_interface.h"
#include "../Include/HAL/LCD/LCD_Private.h"
#include "../Include/HAL/LCD/LCD_Cfg.h"
#define F_CPU 8000000UL

void HLCD_voidSendCommand(u8 A_u8Command)
{
	// To Send Command 	(RS-->0) (RW-->0)
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_RESET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_RESET);

	//Send Command
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Command);

	//Set Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_RESET);
}
void HLCD_voidSendData(u8 A_u8Data)
{
	// To Send Data 	(RS-->1) (RW-->0)
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_SET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_RESET);

	// Send Data
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_u8Data);

	//Set Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_RESET);
}

void HLCD_voidInit(void)
{
	// wait for more than 30ms after VDD rises to 4.5V
	_delay_ms(30);

	//Function Set Command then wait for 39us
	HLCD_voidSendCommand(FUCNTION_SET);
	_delay_ms(1);

	// Display On\Off Control then wait for 39us
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);

	// Display Clear then wait for 1.53ms
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);

	// Entry Mode then wait for 39us
	HLCD_voidSendCommand(ENTRY_MODE_SET);
	_delay_ms(1);
}

void HLCD_voidClearDisplay(void)
{
	// Display Clear then wait for 1.53ms
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
}

void HLCD_voidDisplayString(u8 *A_u8PtrToString)
{

	while(*A_u8PtrToString >0)
	{

		HLCD_voidSendData(*A_u8PtrToString++);
	}
}


void HLCD_voidGoToPos(LCD_ROW_e A_LCDRow, LCD_COL_e A_LCDCol)
{
	switch(A_LCDRow)
	{
	case LCD_ROW1:
		HLCD_voidSendCommand(ROW1_BASE_ADD + A_LCDCol);
		break;
	case LCD_ROW2:
		HLCD_voidSendCommand(ROW2_BASE_ADD + A_LCDCol);
		break;
	default:
		break;
	}

}

void HLCD_voidDisplayNumber(u32 A_u32Number)
{
//	u32 local_u32Number=1;
//	if(A_u32Number == 0 )
//	{
//		HLCD_voidSendData('0');
//	}
//
//	while(local_u32Number != 0)
//	{
//		local_u32Number = (local_u32Number *10) +(A_u32Number %10);
//		A_u32Number = A_u32Number/10;
//
//	}
//	while(local_u32Number != 1)
//	{
//		HLCD_voidSendData( (local_u32Number %10) + 48);
//		local_u32Number = local_u32Number/10;
//	}

	u32 reversedNumber = 0;
	u32 originalNumber = A_u32Number;

	// Edge case: if the number is 0, just print '0'
	if (A_u32Number == 0)
	{
		HLCD_voidSendData('0');
		return;
	}

	// Reverse the number
	while (A_u32Number != 0)
	{
		reversedNumber = (reversedNumber * 10) + (A_u32Number % 10);
		A_u32Number = A_u32Number / 10;
	}

	// Display the reversed number
	while (reversedNumber != 0)
	{
		HLCD_voidSendData((reversedNumber % 10) + '0');
		reversedNumber = reversedNumber / 10;
	}

	// Handle trailing zeros (if needed)
	if (originalNumber % 10 == 0)
	{
		HLCD_voidSendData('0');
	}
}





void HLCD_voidSendSpecialSymbol(u8 *A_pu8SymbolArray,LCD_PATTERNS_e A_patternNum, LCD_ROW_e A_RowNo, LCD_COL_e A_ColNo )
{
	u8 local_u8CGRAMAddress;

	//Calculate CGRAM Address
	local_u8CGRAMAddress = A_patternNum * 8;
	SET_BIT(local_u8CGRAMAddress,6);
	// send Set CGRAM Command
	HLCD_voidSendCommand(local_u8CGRAMAddress);

	for(u8 local_u8Counter=0; local_u8Counter<8; local_u8Counter++)
	{
		// send Byte by Byte from the Symbol Array
		HLCD_voidSendData(A_pu8SymbolArray[local_u8Counter]);
	}
		// Send Command to Set DDRAM Address
		HLCD_voidGoToPos(A_RowNo,A_ColNo);

		//Display Pattern
		HLCD_voidSendData(A_patternNum);

}








