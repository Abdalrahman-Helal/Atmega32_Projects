/*
 * DCM_Prg.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_Int.h"

#include "DCM_Int.h"
#include "DCM_Cgf.h"


void HDCM_vInit(void)
{
	MDIO_vSetPinDir(DCM_PORT , DCM_PIN1 , DIO_OUTPUT);
	MDIO_vSetPinDir(DCM_PORT , DCM_PIN2 , DIO_OUTPUT);
	/* TODO : Setup Control Pin */
}

void HDCM_vRotateCW(void)
{
	/* TODO : Implement Speed as input */

	MDIO_vSetPinVal(DCM_PORT , DCM_PIN1 , DIO_HIGH);
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN2 , DIO_LOW);

}

void HDCM_vRotateCWW(void)
{
	/* TODO : Implement Speed as input */

	MDIO_vSetPinVal(DCM_PORT , DCM_PIN1 , DIO_LOW);
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN2 , DIO_HIGH);
}

void HDCM_vStop(void)
{
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN1 , DIO_LOW);
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN2 , DIO_LOW);
}




/*********************/


DCM_t HDCM_xInit(u8 A_u8PORT, u8 A_u8PIN1, u8 A_u8PIN2)
{
	DCM_t L_xNewMotor;
	L_xNewMotor.PORT = A_u8PORT;
	L_xNewMotor.PIN1 = A_u8PIN1;
	L_xNewMotor.PIN2 = A_u8PIN2;
}

void HDCM_vRotateCW(DCM_t * xMotor)
{
	/* TODO : Implement Speed as input */
	MDIO_vSetPortVal(xMotor->PORT, xMotor -> PIN1 , DIO_HIGH);
	MDIO_vSetPortVal(xMotor->PORT, xMotor -> PIN2 , DIO_LOW);

}

void HDCM_vRotateCWW(DCM_t * xMotor)
{
	/* TODO : Implement Speed as input */
	MDIO_vSetPortVal(xMotor->PORT, xMotor -> PIN1 , DIO_LOW);
	MDIO_vSetPortVal(xMotor->PORT, xMotor -> PIN2 , DIO_HIGH);

}

void HDCM_vStop(DCM_t * xMotor)
{
	MDIO_vSetPortVal(xMotor->PORT, xMotor -> PIN1 , DIO_LOW);
	MDIO_vSetPortVal(xMotor->PORT, xMotor -> PIN2 , DIO_LOW);
}



