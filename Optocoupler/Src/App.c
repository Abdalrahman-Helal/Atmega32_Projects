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
	MDIO_voidSetPortDirection(DIO_PORTA,0x01);

	while(1)
	{
//
//		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_OUTPUT);
//		_delay_ms(1000);
//		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_INPUT);
//		_delay_ms(1000);

		//H Bridge Relay
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_OUTPUT);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_INPUT);
	}

}

