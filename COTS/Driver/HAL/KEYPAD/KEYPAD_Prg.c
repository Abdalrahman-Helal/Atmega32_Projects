/*
 * KEYPAD_Prg.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "util/delay.h"

#include "../../MCAL/DIO/DIO_Int.h"
#include "../../HAL/KEYPAD/KEYPAD_Int.h"

#include "KEYPAD_Int.h"

void KPD_Init(void)
{
	// Set PORTB --> Input / Output
	MDIO_vSetPortDir(KPD_PORT , 0x0F);

	// Active Pull-up
	MDIO_vSetPortVal(KPD_PORT, 0xFF);
}


u8 KPD_u8GetPressedkey(void)
{
	u8 pressed_key;

	for (u8 row=0; row<4; row++)
	{
		// Activate Current Row
		MDIO_vSetPinVal(KPD_PORT , row , DIO_LOW);

		for (u8 col=0; col<4; col++)
		{
			if(MDIO_u8GetPinVal(KPD_PORT , col+4) == 0) // a button get pressed
			{
				pressed_key =(row * 4 )+ col + 1; //key_number
			}
			while(MDIO_u8GetPinVal(KPD_PORT , col+4) == 0)
			{

			}
			_delay_ms(10);
		}
		// De-Activate Current Row
		MDIO_vSetPinVal(KPD_PORT , row , DIO_HIGH);
	}
	return pressed_key;
}



