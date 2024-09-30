/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Int.h"
#include "../MCAL/EXTI/EXTI_Int.h"
#include "../MCAL/EXTI/EXTI_Cfg.h"

#include "../MCAL/GIE/GIE_Int.h"

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	MDIO_vTogPinVal(DIO_PORTA , DIO_PIN0);

}


#define F_CPU 8000000UL

int main(void)
{
	MDIO_vSetPinDir(DIO_PORTD , DIO_PIN2 , DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTD , DIO_PIN2 , DIO_HIGH); // Active Pull-up
	MDIO_vSetPinDir(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	MEXTI_vInit();
	MGIE_vEnableGlobalInterrupt();

	while(1)
	{

	}
}
