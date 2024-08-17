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
#include "../Include/HAL/Stepper_Interface.h"

int main(void)
{
	MDIO_voidSetPortDirection(DIO_PORTA,0x0F);

	while(1)
	{
		HSTEPPER_voidRotate(20);
	}

}

