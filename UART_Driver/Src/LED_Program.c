/*
 * LED_Program.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LED/LED_Private.h"
#include "../Include/HAL/LED/LED_cfg.h"


void HLED_voidTurnLEDOn(DIO_PORT_e A_portID, DIO_PIN_e A_pinID)
{
	MDIO_voidSetPinValue(A_portID ,A_pinID , DIO_SET);
}
void HLED_voidTurnLEDOff(DIO_PORT_e A_portID, DIO_PIN_e A_pinID)
{
	MDIO_voidSetPinValue(A_portID ,A_pinID , DIO_RESET);
}
void HLED_voidToggleLED(DIO_PORT_e A_portID, DIO_PIN_e A_pinID)
{
	MDIO_voidTogglePinValue(A_portID,A_pinID);
}
