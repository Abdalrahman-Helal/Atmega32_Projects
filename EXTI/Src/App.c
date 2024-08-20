/*
 * App.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include <util/delay.h>



#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"

#define F_CPU 12000000UL

void FUNC(void)
{
	HLED_voidToggleLED(DIO_PORTA,PIN0);
}
int main(void)
{
	MDIO_voidInit();
	MEXTI_voidConfig(EXTI0,FALLING_EDGE);
//		MEXTI_voidConfig(EXTI0,ON_CHANGE);
	MEXTI_voidSetCallBack(EXTI0,FUNC);
	MEXTI_voidEnable(EXTI0);
	MGI_voidEnable();

	while(1)
	{

	}

}

