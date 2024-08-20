/*
 * ADC_Program.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Private.h"
#include "../Include/MCAL/ADC/ADC_Cfg.h"

void MADC_voidInit(void)
{
	// 1- Select AVCC with external capacitor at AREF pin
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);

	// 2- Right Adjustment
	CLR_BIT(ADMUX, ADLAR);

	// 3- Disable Auto Trigger
	CLR_BIT(ADCSRA , ADATE);

	// 4- Select CLK/64
	CLR_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2 );

	// 5- Enable ADC
	SET_BIT(ADCSRA , ADEN);
}

u16 MADC_u16GetDigitalvalue(ADC_CHANNELS A_AdcChannel)
{
	u16 local_u16DigitalValue= 0;
	if(A_AdcChannel <= 32)
	{


	// Clear the channel 5-bits
		ADMUX &= ADC_CHANNEL_MASK;


	// Select channel
		ADMUX |= A_AdcChannel;


	// Start Conversion
		SET_BIT(ADCSRA , ADSC);


	// Polling on ADC Complete Flag
		while(GET_BIT(ADCSRA , ADIF ) == 0);


	// Clear , INT Flag
		SET_BIT(ADCSRA, ADIF);


	// Read Conversion Value
		local_u16DigitalValue = ADCLH;

	}
	return local_u16DigitalValue;
}

