/*
 * Stepper_Program.c

 *
 *  Created on: Aug 17, 2024
 *      Author: Abdalrahman
 */
#include "util/delay.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/Stepper_Interface.h"

void HSTEPPER_voidRotate(A_u16Angle)
{
	u16 Iteration = (512*A_u16Angle)/360;

	for(u16 i =0; i< Iteration ; i++)
	{
		// Step 1
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_RESET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_SET);
		_delay_ms(10);

		// Step 2
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_RESET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_SET);
		_delay_ms(10);

		// Step 3
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_RESET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_SET);
		_delay_ms(10);

		// Step 4
		MDIO_voidSetPinValue(DIO_PORTA,PIN0,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN1,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN2,DIO_SET);
		MDIO_voidSetPinValue(DIO_PORTA,PIN3,DIO_RESET);
		_delay_ms(10);
	}
}

