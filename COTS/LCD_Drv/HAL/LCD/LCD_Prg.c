/*
 * LCD_Prg.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Int.h"
#include "../../HAL/LCD/LCD_Int.h"

#include <util/delay.h>

void HLCD_vInit(void)
{
	// Set Pin Directions
	MDIO_vSetPortDir(LCD_DATA_PORT , 0xFF);
	MDIO_vSetPinDir(LCD_CTRL_PORT , LCD_RS_PIN , DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT , LCD_RW_PIN , DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT , LCD_EN_PIN , DIO_OUTPUT);

	// Start Init Sequence

	//wait delay until to Rises 4.5V
	_delay_ms(50);

	// Send Function Set
	HLCD_vSendCommand(0b00111000);

	// wait 39us
	_delay_ms(1);

	// Display ON/OFF Control
	HLCD_vSendCommand(0b00001111);
	// wait 39us
	_delay_ms(1);

	// Display Clear
	HLCD_vSendCommand(0b00000001);
	// wait 1.53ms
	_delay_ms(2);

	// Entry Mode Set
	HLCD_vSendCommand(0b00000110);  // *************************** SET LAST BIT TO 0
	_delay_ms(1);

}

void HLCD_vSendCommand(u8 A_u8Command)
{

	// Set RS , RW --> Low
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_LOW );
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW );

	// Put Command in Data Port
	MDIO_vSetPortVal(LCD_DATA_PORT , A_u8Command);

	// Make Pulse for Enable Pin
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN, DIO_LOW);
	_delay_ms(1);

}

void HLCD_vSendChar(u8 A_u8Char)
{
	// Set RS -> Low , RW -> High
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RS_PIN , DIO_HIGH);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_RW_PIN , DIO_LOW);

	// Put Data In Data Port
	MDIO_vSetPortVal(LCD_DATA_PORT , A_u8Char);

	// Make Pulse for Enable Pin
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN , DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT , LCD_EN_PIN , DIO_LOW);
	_delay_ms(1);


}
//void HLCD_vSendData(u8 A_u8Data);


//void HLCD_vPrintString(u8 A_s8String[])
//{
//	for(u8 i=0; A_s8String[i] != '\0'; i++)
//	{
//		HLCD_vSendChar(A_s8String[i]);
//	}
//}


void HLCD_vPrintString(u8 *pString)
{
	while(*pString)
	{
		HLCD_vSendChar(*pString++);
	}
}


void HLCD_vClearDisplay(void)
{
	HLCD_vSendCommand(HLCD_CLR);
}
void HLCD_vPrintNumber(s32 A_s32Number)
{
//	u8 i=0;
//	u8 Buffer[12];
//	while(A_s32Number != 1)
//	{
//		Buffer[i++] = (A_s32Number % 10) + '0' ; // Get Last Digit then convert it to ASCII
//		A_s32Number /= 10; // Delete The last Digit
//	}
//	HLCD_vSendChar(Buffer[--i]);


	/**********************/

	u8 L_u8digits[10]={0};
	u8 L_u8counter =0;
	/* TODO : Implement Negative Number Handling
	 * TODO : Implement Zero in units Corner
	 */

	while(A_s32Number >0)
	{
		// Save Reversed in Array
		L_u8digits[L_u8counter++] = A_s32Number %10 + '0'; // get the last digit and convert it to ASCII
		A_s32Number /=10;
	}

	for(s8 j=L_u8counter; j>=0; --j)
	{
		// Print Array in Reverse
		HLCD_vSendChar(L_u8digits[j]);
	}


	/*********************/







}
//void HLCD_vSetCursorPosition( u8 A_u8LinePos, u8 A_u8LineNo );
void HLCD_vSaveCustomChar( u8 L_CGRAM_Index, u8 A_CustomCharData[])
{
	// Set CGRAM Address
	HLCD_vSendCommand(0b01000000 +(L_CGRAM_Index*8));

	// Send Custom Char data
	for(u8 i =0; i <= 8 ; i++ )
	{
		HLCD_vSendChar(A_CustomCharData[i]);
	}

	// Set DDRAM Address Command
	HLCD_vSendCommand(0x80);
}
void HLCD_vDisplayCustomChar(u8 A_u8CGRAM_IDX)
{
	// Input Validation
	if(A_u8CGRAM_IDX < 8 )
	{
		HLCD_vSendChar(A_u8CGRAM_IDX);
	}
}

void HLCD_vSetCursorPosition( u8 A_u8LinePos, u8 A_u8LineNo )
{
	switch(A_u8LineNo)
	{
	case LCD_LINE0:
		HLCD_vSendCommand(0x80 + A_u8LinePos + 0);
		break;

	case LCD_LINE1:
		HLCD_vSendCommand(0x80 + A_u8LinePos + 64);
		break;

	}
}

void HLCD_vDisplayShift(void)
{
//	HLCD_vSendCommand(0b00000111);
	HLCD_vSendCommand(0b00011100);
}
