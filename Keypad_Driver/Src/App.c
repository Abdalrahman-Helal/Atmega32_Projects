/*
 * App.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include <util/delay.h>



#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/LCD/LCD_interface.h"
#include "../Include/HAL/Keypad/Keypad_Interface.h"
#define F_CPU 8000000UL

int main(void)
{

	MDIO_voidInit();
	HLCD_voidInit();

	u8 local_u8KeyPadValue;
	u8 local_u8CharCounter=0;
	while(1)
	{
		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
		if(local_u8KeyPadValue != 255)
		{
			HLCD_voidSendData(local_u8KeyPadValue);
			local_u8CharCounter++;
			if(local_u8CharCounter == 16)
			{
				HLCD_voidGoToPos(LCD_ROW2,LCD_COL1);
			}
			else if(local_u8CharCounter == 32)
			{
				HLCD_voidClearDisplay();
				HLCD_voidGoToPos(LCD_ROW1,LCD_COL1);
				local_u8CharCounter=0;

			}
		}
	}


}

