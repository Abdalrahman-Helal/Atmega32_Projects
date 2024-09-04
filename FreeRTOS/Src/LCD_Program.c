/*
 * LCD_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: abdelrahmanhossam
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_Private.h"
#include "../Include/HAL/LCD/LCD_Cfg.h"

#define F_CPU 8000000UL


void HLCD_voidSendCommand (u8 A_u8Command)
{
	// Send Command --> (RS --> LOW) - (RW --> LOW)
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_RESET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_RESET);

	// Sending the command
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

	// Apply Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidSendData (u8 A_u8Data)
{
	// Send Data --> (RS --> HIGH) - (RW --> LOW)
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_SET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, DIO_RESET);

	// Sending the command
	MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

	// Apply Pulse on E Pin
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT, LCD_E_PIN, DIO_RESET);
}

void HLCD_voidInit (void)
{
	// Wait for more than 30ms after V DD rises to 4.5V
	_delay_ms(30);

	// Function Set Command
	HLCD_voidSendCommand(FUNCTION_SET);
	//Wait for more than 39 us
	_delay_ms(1);

	// Display ON/OFF Control Command
	HLCD_voidSendCommand(DISPLAY_ON_OFF);
	//Wait for more than 39 us
	_delay_ms(1);

	// Display Clear Command
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//Wait for more than 1.53ms
	_delay_ms(2);

	// Entry Mode Set Command
	HLCD_voidSendCommand(ENTRY_MODE_SET);
	//Wait for more than 39 us
	_delay_ms(1);
}

void HLCD_voidDisplayString (u8 * A_ptrToString)
{
	while (*A_ptrToString > 0)
	{
		HLCD_voidSendData(*A_ptrToString++);
	}
}

void HLCD_voidDisplayNumber (u32 A_u32Number)
{
  u32 local_u32Number = 1;
  if (A_u32Number == 0)
  {
	  HLCD_voidSendData('0');
  }
  else
  {
	  while (A_u32Number != 0)
	  {
		  local_u32Number = ((local_u32Number*10)+(A_u32Number%10));
		  A_u32Number = A_u32Number / 10;
	  }
	  while (local_u32Number !=1)
	  {
		  HLCD_voidSendData((local_u32Number%10)+48);
		  local_u32Number = local_u32Number /10;
	  }
  }
}


