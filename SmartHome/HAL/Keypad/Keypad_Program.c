/*
 * Keypad_Program.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdalrahman
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Keypad_Interface.h"
#include "Keypad_Private.h"
#include "Keypad_Cfg.h"

#include "../LCD/LCD_Interface.h"

#include <util/delay.h>

#define F_CPU 12000000UL

u8 static const ArrOfRows[KEYPAD_ROW_NO]=KEYPAD_ROWS;
u8 static const ArrOfCols[KEYPAD_COL_NO]= KEYPAD_COLS;



void HKEYPAD_vInit(void)
{
	// Set PORT INPUT / OUTPUT
	MDIO_vSetPortDir(KEYPAD_PORT , 0x0F);

	// Set all Port to high
	MDIO_vSetPortVal(KEYPAD_PORT , 0xFF);

}

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 KeyMap = NO_KEY_PRESSED ;
	u8 PinValue ,RowNo=0 , ColNo=0  , Flag=FLAG_DOWN;

	for (RowNo=0; RowNo < KEYPAD_ROW_NO; RowNo++ )
	{
		// Activate One Row
		MDIO_vSetPinVal(KEYPAD_PORT , ArrOfRows[RowNo], DIO_LOW);

		// Check on COls
		for(ColNo=0; ColNo < KEYPAD_COL_NO; ColNo++)
		{
			// Read COLs
			PinValue= MDIO_GetPinVal(KEYPAD_PORT, ArrOfCols[ColNo]);

			// Check if KeyPressed
			if(PinValue == KEY_PRESSED)
			{
				// Debouncing Delay
				_delay_ms(DEBOUNCING_DELAY_ms);
				PinValue= MDIO_GetPinVal(KEYPAD_PORT, ArrOfCols[ColNo]);
				if(PinValue == KEY_PRESSED)
				{
					while(PinValue == KEY_PRESSED) // Polling of Flag
					{
						_delay_ms(DEBOUNCING_DELAY_ms);
						PinValue= MDIO_GetPinVal(KEYPAD_PORT, ArrOfCols[ColNo]);
					} // End of While Loop

					KeyMap = ArrofKeyValues[RowNo][ColNo]; // Get Pressed Key Value
					Flag = FLAG_UP; // Notification for ROWs Loop to break and Return
					break;
				}
			}
		} // End of COLs Loop

		// De-Activate One Row
		MDIO_vSetPinVal(KEYPAD_PORT , ArrOfRows[RowNo], DIO_HIGH);

		if(Flag == FLAG_UP) // Check if Key was Pressed
		{
			break; // break ROWs Loop
		}

	}// End of ROWs Loop

	return KeyMap;
}

u16 HKEYPAD_u16MultiDigitInput(void)
{
	u16 Number =0;
	u8 key;

	while(1)
	{
		key = HKEYPAD_u8GetPressedKey();

		if(key != NO_KEY_PRESSED)
		{
			if (key == '#')
			{
				break;
			}
			else
			{
				key -= '0';
				if(key >= 0 && key <= 9)
				{
					Number = Number * 10 + key;
				}
			}
		}
	}
		return Number;
}






