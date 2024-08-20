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
#include "../Include/MCAL/ADC/ADC_Interface.h"

#define F_CPU 8000000UL


int main(void)
{
	// PA0 --> I/P Floating , PC0 , PC1 , PC2 O/P --> low
	MDIO_voidInit();
	MADC_voidInit();
	u16 local_u16DigitalValue , local_u16AnalogValue;

	while(1)
	{
		local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC0);

		// Analog = Digital * Step , Step = Max Voltage / 2^10(No. Bits)
		local_u16AnalogValue = local_u16DigitalValue * 5000UL / 1024; // in mV (milliVolt)

		if(local_u16AnalogValue < 1500)
		{
			HLED_voidTurnLEDOn(DIO_PORTC, PIN0);
			HLED_voidTurnLEDOff(DIO_PORTC , PIN1);
			HLED_voidTurnLEDOff(DIO_PORTC , PIN2);
		}

		else if(local_u16AnalogValue < 3000)
		{
			HLED_voidTurnLEDOn(DIO_PORTC, PIN0);
			HLED_voidTurnLEDOn(DIO_PORTC , PIN1);
			HLED_voidTurnLEDOff(DIO_PORTC , PIN2);
		}

		else if(local_u16AnalogValue < 5000)
		{
			HLED_voidTurnLEDOn(DIO_PORTC, PIN0);
			HLED_voidTurnLEDOn(DIO_PORTC , PIN1);
			HLED_voidTurnLEDOn(DIO_PORTC , PIN2);
		}
	}

}

