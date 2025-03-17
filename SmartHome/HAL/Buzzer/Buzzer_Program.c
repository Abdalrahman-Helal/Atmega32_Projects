/*
 * Buzzer_Program.c
 *
 *  Created on: Mar 16, 2025
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Buzzer_Interface.h"
#include "Buzzeer_Private.h"
#include "Buzzer_Cfg.h"



void HBUZZER_vInit(void)
{
	MDIO_vSetPinDir(BUZZER_PORT ,BUZZER_PIN ,DIO_OUTPUT);
}

void HBUZZER_vTurnOn(void)
{
	MDIO_vSetPinVal(BUZZER_PORT , BUZZER_PIN , DIO_HIGH);
}

void HBUZZER_vTurnOff(void)
{
	MDIO_vSetPinVal(BUZZER_PORT , BUZZER_PIN , DIO_LOW);
}
