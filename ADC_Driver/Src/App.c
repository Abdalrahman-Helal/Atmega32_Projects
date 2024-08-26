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
#include "../Include/HAL/LCD/LCD_Interface.h"

#define F_CPU 8000000UL


//int main(void)
//{
	// PA0 --> I/P Floating , PC0 , PC1 , PC2 O/P --> low
//	MDIO_voidInit();
//	MADC_voidInit();
//	HLCD_voidInit();
//	u16 local_u16DigitalValue , local_u16AnalogValue;
//
//	while(1)
//	{
//		local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC0);

		// Analog = Digital * Step , Step = Max Voltage / 2^10(No. Bits)
//		local_u16AnalogValue = local_u16DigitalValue * 5000UL / 1024; // in mV (milliVolt)
//
//		if(local_u16AnalogValue < 1500)
//		{
//			HLED_voidTurnLEDOn(DIO_PORTC, PIN0);
//			HLED_voidTurnLEDOff(DIO_PORTC , PIN1);
//			HLED_voidTurnLEDOff(DIO_PORTC , PIN2);
//		}
//
//		else if(local_u16AnalogValue < 3000)
//		{
//			HLED_voidTurnLEDOn(DIO_PORTC, PIN0);
//			HLED_voidTurnLEDOn(DIO_PORTC , PIN1);
//			HLED_voidTurnLEDOff(DIO_PORTC , PIN2);
//		}
//
//		else if(local_u16AnalogValue < 5000)
//		{
//			HLED_voidTurnLEDOn(DIO_PORTC, PIN0);
//			HLED_voidTurnLEDOn(DIO_PORTC , PIN1);
//			HLED_voidTurnLEDOn(DIO_PORTC , PIN2);
//		}
//}

	/********************************/

int main(void)
{



	// PA0 --> I/P Floating , PC3 , PC4 , PC5 O/P --> low ,	PORT D O/P Low
//	MDIO_voidInit();
	MDIO_voidSetPinDirection(DIO_PORTA, PIN0 , DIO_INPUT);
	MDIO_voidSetPinValue(DIO_PORTA, PIN0 , DIO_RESET);

	MDIO_voidSetPortDirection(DIO_PORTC, 0xFF);
	MDIO_voidSetPortValue(DIO_PORTC , 0x00);

	MDIO_voidSetPortDirection(DIO_PORTD , 0xFF);
	MDIO_voidSetPortValue(DIO_PORTD , 0x00);
	MADC_voidInit();
	HLCD_voidInit();
	u16 local_u16DigitalValue , local_u16AnalogValue;
	while(1)
	{
		_delay_ms(500);
		local_u16DigitalValue = MADC_u16GetDigitalvalue(ADC0);
		// Analog = Digital * Step , Step = Max Voltage / 2^10(No. Bits)
		local_u16AnalogValue = (local_u16DigitalValue * 500UL) / 1024; // in mV (milliVolt)
//		local_u16AnalogValue /= 10;  // then divide by 10 to get temperature (10mV --> 1 C)
		HLCD_voidClearDisplay();
		HLCD_voidDisplayString("Temperature : ");
		HLCD_voidDisplayNumber(local_u16AnalogValue);
		_delay_ms(2000);

	}
}




