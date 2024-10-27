/*
 * ADC_Prg.c
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_Int.h"
#include "ADC_Cfg.h"
#include "ADC_Prv.h"

#include <avr/io.h>

void MADC_vInit(void)
{
	/*1- Reference Voltage Selection*/
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);

	/*2- Data Adjustment Direction */
	CLR_BIT(ADMUX,ADLAR);

	/*3- Select Prescaler Bits */
	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER);

	/*4- Auto Trigger Enable */
	/*4A- Select Auto Trigger Source */
	CLR_BIT(ADCSRA , ADATE);

	/* Interrupt Enable/Disable */
	CLR_BIT(ADCSRA , ADIE);

	/*Enable ADC Peripheral */
	SET_BIT(ADCSRA,ADEN);
}

u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	/*1- Select Channel */
	ADMUX = (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07);

	/*2- Start Conversion */
	SET_BIT(ADCSRA , ADSC);

	/*3- Poll on Flag */
	while( GET_BIT(ADCSRA,ADIF) != 1 ){}


	/*4- Clear Flag */
	SET_BIT(ADCSRA , ADIF);

	/*5- Return ADC Data */
	return ADC;


}



