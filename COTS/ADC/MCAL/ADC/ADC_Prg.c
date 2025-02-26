/*
 * ADC_Prg.c
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_Int.h"
#include "ADC_Prv.h"
#include "ADC_Cfg.h"

// Pointer to Func
void (*ADC_Callback)(void);


void MADC_vInit(void)
{
	/* 1- Reference Voltage Selection */
#if ADC_REF_VOLT == AVCC
	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);


#elif ADC_REF_VOLT == INTERNAL_REF
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

#elif ADC_REF_VOLT == AREF
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);

#else
#error "Please select correct ref volatage "
#endif


	/* 2- Data Adjustment Direction */
	CLR_BIT(ADMUX,ADLAR);

	/* 3- Select Prescaler Bits */
	ADCSRA = (ADCSRA & 0xF8) | (ADC_PRESCALER);

	/* 4- Auto Trigger Enable*/
	/* 4a- Select Auto Trigger Source*/
	/* 5- Interrupt Enable/Disable*/
#if ADC_INTERRUPT_ENABLE == DISABLE
	CLR_BIT(ADCSRA, ADIE);

#elif ADC_INTERRUPT_ENABLE == ENABLE
	SET_BIT(ADCSRA, ADIE );
#endif

	/* 6- Enable ADC peripheral */
	SET_BIT(ADCSRA,ADEN);
}

u16 MADC_u16AnalogRead(u8 A_u8ChannelNo)
{
	/* 1- Select Channel */
	ADMUX= (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07);

	/* 2- Start Conversion */
	SET_BIT(ADCSRA , ADSC);

	/* 3- Poll on Flag */
	while(GET_BIT(ADCSRA , ADIF) != 1){}

	/* 4- Clear Flag */
	SET_BIT(ADCSRA, ADIF);

	/* 5- Return ADC Data */
	return ADC;
}

void MADC_vStartConversion(u8 A_u8ChannelNo)
{
	/* 1- Select Channel */
	ADMUX= (ADMUX & 0xE0) | (A_u8ChannelNo & 0x07);

	/* 2- Start Conversion */
	SET_BIT(ADCSRA , ADSC);
}

u16  MADC_u16GetADCData(void)
{
	return ADC;
}

void MADC_vSetCallback(void (*A_fptr)(void))
{
	ADC_Callback= A_fptr;
}

/* ADC ISR */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	ADC_Callback();
}
