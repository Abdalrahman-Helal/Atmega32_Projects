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

	HLCD_voidDisplayString("7pepy bo7meed");
	while(1)
	{

	}

}

