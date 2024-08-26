/*
 * App.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */
#include <util/delay.h>

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"


#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/Timer/Timer_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL

void Timer0_OVF()
{
	static u16 Counter =0;
	Counter++;
	if(Counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		Counter =0;
		HLED_voidToggleLED(DIO_PORTC , PIN0);
		HLED_voidToggleLED(DIO_PORTC , PIN1);
		HLED_voidToggleLED(DIO_PORTC , PIN2);
	}
}

void Timer0_CTC()
{
	static u16 Counter =0;
	Counter++;
	if(Counter == 5000)
	{
		Counter =0;
		HLED_voidToggleLED(DIO_PORTC , PIN0);
		HLED_voidToggleLED(DIO_PORTC , PIN1);
		HLED_voidToggleLED(DIO_PORTC , PIN2);
	}
}
/* Normal Mode */
//int main(void)
//{


	// Timer 0 - > 8 	BIT , Prescaler -- > 8 , F_CPU --> 8 Mhz , 1 Sec
//	MDIO_voidInit();
//	MTIMER0_voidSetOVFCallback(Timer0_OVF);
//	MTIMER0_voidInit();
//	MTIMER0_voidSetPreloadValue(192);
//	MGI_voidEnable();
//	while(1)
//	{
//
//	}
//}

	/* CTC Mode */
int main(void)
{
//	 Timer 0 - > 8 	BIT , Prescaler -- > 8 , F_CPU --> 8 Mhz , 1 Sec
		MDIO_voidInit();
		MTIMER0_voidSetCTCCallback(Timer0_CTC);
		MTIMER0_voidInit();
		MGI_voidEnable();
		while(1)
		{

		}
}












