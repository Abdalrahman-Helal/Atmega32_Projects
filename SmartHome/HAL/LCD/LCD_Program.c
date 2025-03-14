/*
 * LCD_Program.c
 *
 *  Created on: Mar 3, 2025
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Cfg.h"

#include <util/delay.h>
#define F_CPU 12000000UL
void HLCD_vSendCommand(u8 A_u8Command)
{
	// To send Command RS -> 0 , RW -> 0
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_LOW);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);

	// Send Commnad
	MDIO_vSetPortVal(LCD_DATA_PORT , A_u8Command);

	// Set Pulse On Enable Pin
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_E_PIN , DIO_LOW);
}

void HLCD_vSendData(u8 A_u8Data)
{
	// To send Data RS -> 1 , RW -> 0
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_HIGH);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);

	// Send Commnad
	MDIO_vSetPortVal(LCD_DATA_PORT , A_u8Data);

	// Set Pulse On Enable Pin
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_E_PIN , DIO_LOW);
}

void HLCD_vInit(void)
{
	MDIO_vSetPortDir(LCD_DATA_PORT,0xFF);
	MDIO_vSetPortDir(LCD_CTRL_PORT,0x07);

	// wait for 30ms after VDD rises to 4.5V
	_delay_ms(30);

	// Function Set
	HLCD_vSendCommand(FUNCTION_SET);
	_delay_ms(1);

	// Display On/Off
	HLCD_vSendCommand(DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);

	// Display Clear
	HLCD_vSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);


	// Entry Mode Set
	HLCD_vSendCommand(ENTRY_MODE_SET);
	_delay_ms(1);
}

void HLCD_vClearDisplay(void)
{
	HLCD_vSendCommand(DISPLAY_CLEAR);
	_delay_ms(3);
}

void HLCD_vDisplayLongString(u8 *A_u8PtrToString)
{
	u8 ROW = LCD_ROW1 , COL =LCD_COL1;
	while(*A_u8PtrToString > 0)
	{
		if(COL > LCD_COL16 && ROW == LCD_ROW1)
		{
			ROW = LCD_ROW2;
			COL = LCD_COL1;
		}
		HLCD_vGoToPos(ROW , COL);
		HLCD_vSendData(*A_u8PtrToString);
		COL++;
		*A_u8PtrToString++;
	}
}

void HLCD_vDisplayString(u8 *A_u8PtrToString)
{
	while(*A_u8PtrToString > 0)
	{
		HLCD_vSendData(*A_u8PtrToString);
		*A_u8PtrToString++;

	}
}

void HLCD_vGoToPos(LCD_ROW_e A_LCDRow ,LCD_COL_e A_LCDCol)
{
	switch (A_LCDRow)
	{
		case LCD_ROW1:
			HLCD_vSendCommand(LCD_ROW1_BASE_ADD + A_LCDCol);
			break;
		case LCD_ROW2:
			HLCD_vSendCommand(LCD_ROW2_BASE_ADD + A_LCDCol);
			break;
	}
}

void HLCD_vDisplayNumber(u32 A_u32Number)
{
	u32 ReversedNum = 1;
	if(A_u32Number == 0)
	{
		HLCD_vSendData('0');
	}

	while(A_u32Number != 0)
	{
		ReversedNum = (ReversedNum*10) + (A_u32Number %10);
		A_u32Number = A_u32Number /10;
	}

	while(ReversedNum != 1)
	{
		HLCD_vSendData( (ReversedNum%10) + 48);
		ReversedNum= ReversedNum/10;
	}
}

void HLCD_vSendSpecialSymbol(u8 *A_ptru8SymbolArray, u8 A_u8PatternNum, LCD_ROW_e A_RowNo , LCD_COL_e A_COLNo)
{
	u8 CGRAMAddress;
	// Calculate CGRAM Address
	CGRAMAddress = A_u8PatternNum * 8;
	SET_BIT(CGRAMAddress ,6);

	// Set CGRAM
	HLCD_vSendCommand(CGRAMAddress);


	for(u8 counter = 0 ; counter < 8 ; counter++)
	{
		HLCD_vSendData(A_ptru8SymbolArray[counter]);
	}

	// send Command to set DDRAM Address
	HLCD_vGoToPos(A_RowNo , A_COLNo);

	// Display Pattern
	HLCD_vSendData(A_u8PatternNum);
}




