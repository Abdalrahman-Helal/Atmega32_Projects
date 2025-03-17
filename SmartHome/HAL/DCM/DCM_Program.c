/*
 * DCM_Program.c
 *
 *  Created on: Mar 17, 2025
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "DCM_Interface.h"
#include "DCM_Private.h"
#include "DCM_Cfg.h"

#include <util/delay.h>

#define F_CPU 12000000UL

#if METHOD==NOSTRUCT

void HDCM_vInit(void)
{
	MDIO_vSetPinDir(DCM_PORT , DCM_PIN1 , DIO_OUTPUT);
	MDIO_vSetPinDir(DCM_PORT , DCM_PIN2 , DIO_OUTPUT);
	/* TODO : Setup Control Pin */
}

void HDCM_vRotateCW(void)
{
	/* TODO : Implement Speed as input */

	MDIO_vSetPinVal(DCM_PORT , DCM_PIN1 , DIO_LOW);
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN2 , DIO_HIGH);

}

void HDCM_vRotateCCW(void)
{
	/* TODO : Implement Speed as input */

	MDIO_vSetPinVal(DCM_PORT , DCM_PIN1 , DIO_HIGH);
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN2 , DIO_LOW);
}

void HDCM_vStop(void)
{
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN1 , DIO_LOW);
	MDIO_vSetPinVal(DCM_PORT , DCM_PIN2 , DIO_LOW);
}
#endif


//#if METHOD == STRUCT
//DCM_t HDCM_xInit(u8 A_u8Port , u8 A_u8Pin1 , u8 A_u8Pin2)
//{
//	DCM_t xNewMotor;
//
//	xNewMotor.Port = A_u8Port;
//	xNewMotor.Pin1 = A_u8Pin1;
//	xNewMotor.Pin2 = A_u8Pin2;
//
//	return xNewMotor;
//}
//
//void HDCM_vRotateCW(DCM_t* A_xMotor)
//{
//	/* TODO : implement speed as input */
//	MDIO_vSetPinVal(A_xMotor->Port , A_xMotor->Pin1 , DIO_HIGH);
//	MDIO_vSetPinVal(A_xMotor->Port , A_xMotor->Pin2 , DIO_LOW);
//}
//
//void HDCM_vRotateCCW(DCM_t* A_xMotor)
//{
//	/* TODO : implement speed as input */
//	MDIO_vSetPinVal(A_xMotor->Port , A_xMotor->Pin1 , DIO_LOW);
//	MDIO_vSetPinVal(A_xMotor->Port , A_xMotor->Pin2 , DIO_HIGH);
//}
//
//void HDCM_vStop(DCM_t* A_xMotor)
//{
//	MDIO_vSetPinVal(A_xMotor->Port , A_xMotor->Pin1 , DIO_LOW);
//	MDIO_vSetPinVal(A_xMotor->Port , A_xMotor->Pin2 , DIO_LOW);
//}
//
//#endif


