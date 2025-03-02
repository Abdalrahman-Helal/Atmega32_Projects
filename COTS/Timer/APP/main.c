/*
 * main.c
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */
// Proteus not tested  yet
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Int.h"
#include "../HAL/LCD/LCD_Int.h"
#include "../MCAL/TIMERS/TIMERS_Int.h"
#include "../MCAL/GIE/GIE_Int.h"

void ToggleLED(void)
{
	MDIO_vTogPinVal(DIO_PORTA , DIO_PIN0 );
}

#define F_CPU 8000000UL

int main(void)
{
	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	MTIMERS_vInit();
	MTIMERS_vSetInterval_Asynch(2000,ToggleLED);
	MGIE_vEnableGlobalInterrupt();

}
