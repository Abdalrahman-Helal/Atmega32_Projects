/*
 * App.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */
#include <util/delay.h>

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/Timer/Timer_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/Services/RTOS/RTOS_Interface.h"


#define F_CPU 8000000UL

void TogLed1()
{
	HLED_voidToggleLED(DIO_PORTA , PIN0);
}

void TogLed2()
{
	HLED_voidToggleLED(DIO_PORTA , PIN1);
}

void TogLed3()
{
	HLED_voidToggleLED(DIO_PORTA , PIN2);
}


int main()
{
//	MDIO_voidInit();

	MDIO_voidSetPinDirection(DIO_PORTA,PIN0 , DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTA,PIN1 , DIO_OUTPUT);
	MDIO_voidSetPinDirection(DIO_PORTA,PIN2 , DIO_OUTPUT);
	SRTOS_voidInitArrayFunctions();

	SRTOS_voidCreateTask(0, 1000, 0 , TogLed1);
	SRTOS_voidCreateTask(1, 2000, 0 , TogLed1);
	SRTOS_voidCreateTask(2, 5000, 0 , TogLed1);

	SRTOS_voidInit();
	MGI_voidEnable();

	while(1)
	{

	}

}











