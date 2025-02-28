/*
 * main.c
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Int.h"
#include "../MCAL/ADC/ADC_Int.h"
#include "../HAL/LCD/LCD_Int.h"
#include "../MCAL/GIE/GIE_Int.h"

#include "util/delay.h"

#define F_CPU 8000000UL

volatile u16 ADC_Value =0;

void ADC_ISR(void)
{
	u16 ADC_Value = MADC_u16GetADCData();
	MADC_vStartConversion(0);
}

int main(void)
{
	MADC_vSetCallback(ADC_ISR);
	MADC_vInit();
	HLCD_vInit();
	// u16 ADC_Value=0;

	MADC_vStartConversion(0);
	MGIE_vEnableGlobalInterrupt();
	while(1)
	{
		// ADC_Value = MADC_u16AnalogRead(0);
		HLCD_vClearDisplay();
		HLCD_vPrintNumber(ADC_Value);
		_delay_ms(250);
	}
}
