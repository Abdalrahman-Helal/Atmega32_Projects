/*
 * Stepper_Program.c
 *
 *  Created on: Mar 16, 2025
 *      Author: Abdalrahman
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Stepper_Interface.h"
#include "Stepper_Private.h"
#include "Stepper_Cfg.h"

#include <util/delay.h>

#define F_CPU 12000000UL


void HSTEPPER_vInit(void)
{
//	u8 pinMask = (1 << STPR_PIN0) | (1 << STPR_PIN1) | (1 << STPR_PIN2) | (1 << STPR_PIN3);
//	MDIO_vSetPortDir(STPR_PORT , pinMask);

	MDIO_vSetPinDir(STPR_PORT , STPR_PIN0 , DIO_OUTPUT);
	MDIO_vSetPinDir(STPR_PORT , STPR_PIN1 , DIO_OUTPUT);
	MDIO_vSetPinDir(STPR_PORT , STPR_PIN2 , DIO_OUTPUT);
	MDIO_vSetPinDir(STPR_PORT , STPR_PIN3 , DIO_OUTPUT);
}

void HSTEPPER_vRotate(u16 A_u16Angle)
{

u16 Iteration = (512 * A_u16Angle) / 360;

    for(u16 i = 0; i < Iteration; i++)
    {
        // Step 1
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN0, DIO_LOW);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN1, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN2, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN3, DIO_HIGH);
        _delay_ms(10);

        // Step 2
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN0, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN1, DIO_LOW);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN2, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN3, DIO_HIGH);
        _delay_ms(10);

        // Step 3
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN0, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN1, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN2, DIO_LOW);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN3, DIO_HIGH);
        _delay_ms(10);

        // Step 4
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN0, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN1, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN2, DIO_HIGH);
        MDIO_vSetPinVal(STPR_PORT, STPR_PIN3, DIO_LOW);
        _delay_ms(10);
    }
}

