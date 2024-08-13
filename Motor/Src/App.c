/*
 * App.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Abdalrahman
 */
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"

#define F_CPU 8000000UL

#define PRESSED 0
#define REALSEAD 1

int main()
{

	MDIO_voidSetPinDirection(DIO_PORTC , PIN1, DIO_SET); // PIN1 FOR MOTOR

	MDIO_voidSetPinValue(DIO_PORTC, PIN2, DIO_SET); // Active Pull-Up for the Switch
	MDIO_voidSetPinDirection(DIO_PORTC, PIN2, DIO_RESET);// PIN2 FOR SWITCH
	u8 SwitchState;

	while(1)
	{
		SwitchState = GET_BIT(PINC_REG,2);
		if(SwitchState == PRESSED)
		{
				// turn on the Motor
			MDIO_voidSetPinValue(DIO_PORTC,PIN1,DIO_SET);
		}
		else
		{
			MDIO_voidSetPinValue(DIO_PORTC,PIN1,DIO_RESET);
		}
	}
}

