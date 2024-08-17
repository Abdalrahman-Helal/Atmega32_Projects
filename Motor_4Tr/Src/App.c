/*
 * App.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Abdalrahman
 */

#include <util/delay.h>
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
//#include "../Include/MCAL/DIO/DIO_Private.h"
int main(void)
{
	MDIO_voidSetPortDirection(DIO_PORTA,0b00000011);

	while(1)
	{
		MDIO_voidSetPinValue(DIO_PORTA, PIN1, DIO_INPUT);
		MDIO_voidSetPinValue(DIO_PORTA, PIN0, DIO_OUTPUT);
		_delay_ms(1500);
		// Change Direction of Motor
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_INPUT);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1, DIO_OUTPUT);
		_delay_ms(1500);

	}

}

