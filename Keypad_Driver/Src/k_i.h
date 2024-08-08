/*
 * k_i.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_KEYPAD_K_I_H_
#define INCLUDE_HAL_KEYPAD_K_I_H_

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/Keypad/Keypad_Interface.h"
#include "../Include/HAL/Keypad/Keypad_Private.h"
#include "../Include/HAL/Keypad/Keypad_Cfg.h"

#include <util/delay.h>
#define F_CPU 8000000UL


	u8 static const global_u8ArrOfRows [KEYPAD_ROW_NO]=KEYPAD_ROWS;
	u8 static const global_u8ArrOfCols [KEYPAD_COL_NO] = KEYPAD_COLS;

	u8 HKEYPAD_u8GetPressedKey(void)
	{


	u8 local_u8KeyValue = NO_KEY_PRESSED;

	u8 local_u8RowCounter=0, local_u8ColCounter=0, local_u8PinValue, local_flag=FLAG_DOWN;

	for(local_u8RowCounter=0; local_u8RowCounter<KEYPAD_ROW_NO;local_u8RowCounter++)
	{
		//Active one Row
		MDIO_voidSetPinValue(KEYPAD_PORT, global_u8ArrOfRows[local_u8RowCounter],KEYPAD_ROW_ACTIVATE);

		for(local_u8ColCounter=0; local_u8RowCounter<KEYPAD_COL_NO;local_u8RowCounter)
		{
			local_u8PinValue=MDIO_getPinValue(KEYPAD_PORT,global_u8ArrOfCols[local_u8ColCounter]);
			if(local_u8PinValue == 0)
			{
				// delay
				_delay_ms(30);
				local_u8PinValue=MDIO_getPinValue(KEYPAD_PORT,global_u8ArrOfCols[local_u8ColCounter]);

				if(local_u8PinValue == 0)
				{
					while(local_u8PinValue == 0)
					{
					local_u8PinValue=MDIO_getPinValue(KEYPAD_PORT,global_u8ArrOfCols[local_u8ColCounter]);
					}
				}
				local_u8KeyValue= global_u8ArrofKeypadValues[local_u8RowCounter][local_u8ColCounter];
				local_flag=FLAG_UP;
				break;
			}
		} // End of Col loop

		// De-Activate One Row
		MDIO_voidSetPinValue(KEYPAD_PORT,global_u8ArrOfRows[local_u8RowCounter],KEYPAD_ROW_DAECTIVATE);
		if(local_flag	== FLAG_UP)
		{
			local_flag= FLAG_DOWN;
			break;
		}
	} // End of Row loop

	return local_u8KeyValue;
	}


#endif /* INCLUDE_HAL_KEYPAD_K_I_H_ */
