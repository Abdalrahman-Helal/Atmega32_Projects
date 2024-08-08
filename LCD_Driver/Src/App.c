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
int main(void)
{

	MDIO_voidInit();
	HLCD_voidInit();

	u8 customChar[8] = {
	  0b10101,
	  0b10101,
	  0b10101,
	  0b10101,
	  0b11111,
	  0b10101,
	  0b01110,
	  0b10101
	};

	HLCD_voidDisplayString("3bdo");
	HLCD_voidSendSpecialSymbol(customChar,LCD_PATTERN0,LCD_ROW2,LCD_COL7);
	while(1)
	{

	}

}

