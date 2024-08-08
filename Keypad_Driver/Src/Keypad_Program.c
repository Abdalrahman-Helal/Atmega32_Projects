/*
 * Keypad_Program.c
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/Keypad/Keypad_Interface.h"
#include "../Include/HAL/Keypad/Keypad_Private.h"
#include "../Include/HAL/Keypad/Keypad_Cfg.h"

#include <util/delay.h>
#define F_CPU 8000000UL

u8 static const global_u8ArrofRows[KEYPAD_ROW_NO]=KEYPAD_ROWS;
u8 static const global_u8ArrofCols[KEYPAD_COL_NO]= KEYPAD_COLS;



u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8KeyValue = NO_KEY_PRESSED;

	u8 local_u8RowCounter=0 , local_u8ColCounter=0 ,local_u8PinValue, local_u8Flag=FLAG_DOWN;

	// Loop on Rows
	for(local_u8RowCounter=0; local_u8RowCounter < KEYPAD_ROW_NO ; local_u8RowCounter++ )
	{
		//Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT,global_u8ArrofRows[local_u8RowCounter],KEYPAD_ROW_ACTIVATE);

		// Check Cols
		for(local_u8ColCounter=0; local_u8ColCounter < KEYPAD_ROW_NO ; local_u8ColCounter++ )
		{
			local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT,global_u8ArrofCols[local_u8ColCounter]);

			if(local_u8PinValue == KEY_PRESSED)
			{
				//Debouncing Delay
				_delay_ms(KEYPAD_DEBOUNCING_DELAY_ms);
				local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT,global_u8ArrofCols[local_u8ColCounter]);

				if(local_u8PinValue == KEY_PRESSED)
				{
					while (local_u8PinValue == KEY_PRESSED) // Polling On Flag
					{
						local_u8PinValue = MDIO_getPinValue(KEYPAD_PORT,global_u8ArrofCols[local_u8ColCounter]);
					} // End Of While Loop
				}
				local_u8KeyValue=global_u8ArrofKeyValues[local_u8RowCounter][local_u8ColCounter];
				local_u8Flag=FLAG_UP; // Notification for Rows loop to break and return
				break;
			}

		}// End of COLs Loop

		// De-Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT, global_u8ArrofRows[local_u8RowCounter] , KEYPAD_ROW_DEACTIVATE);
		if(local_u8Flag == FLAG_UP)
		{
			break; //break ROWs Loop
		}
	}// End of ROWs Loop

	return local_u8KeyValue; //return pressed key value

}




