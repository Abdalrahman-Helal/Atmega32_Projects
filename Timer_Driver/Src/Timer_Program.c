/*
 * Timer_Program.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/Timer/Timer_Interface.h"
#include "../Include/MCAL/Timer/Timer_Private.h"
#include "../Include/MCAL/Timer/Timer_Cfg.h"

#define NULL 0
void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void MTIMER0_voidInit(void)
{
	#if TIMER0_MODE == NORMAL_MODE

	// Set Waveform in Normal Mode
	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);

	// Enable OVF Interrupt and Disable CTC Interrupt
	SET_BIT(TIMSK , TOIE0);
	CLR_BIT(TIMSK , OCIE0);

	// Start Timer by setting its Clock
	TCCR0 &= TIMER0_CLRMASK;
	TCCR0 |= TIMER0_CLK;

#elif TIMER0_MODE == CTC_MODE
	// Set Waveform in Normal Mode
	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);

	// Disable OVF Interrupt and Enable CTC	Interrupt
	SET_BIT(TIMSK , TOIE0);
	CLR_BIT(TIMSK , OCIE0);

	// Set Compare match value
	OCR0 = OCR0_VALUE;

	// Start Timer by setting its Clock and also set OC0 pin mode
	TCCR0 &= TIMER0_CLK_OCR_MASK;
	TCCR0 |= TIMER0_CLK  | (OC0_MODE << 4);

#elif TIMER0_MODE == PHASE_CORRECT_MODE

	// Set Waveform in Phase Correct Mode

#endif

}

void MTIMER0_voidSetPreloadValue(u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}
void MTIMER0_voidStopTimer (void)
{
	TCCR0 |= TIMER0_CLRMASK;
}
void MTIMER0_voidSetOCR0Value(u8 A_u8OCR0Value)
{
	OCR0=A_u8OCR0Value;
}

void MTIMER0_voidSetOVFCallback (void (*A_ptrToFunc)(void))
{
	if( A_ptrToFunc != NULL)
	{
		TIMER0_OVF_CALLBACK=A_ptrToFunc;
	}
}

void MTIMER0_voidSetCTCCallback (void (*A_ptrToFunc)(void))
{
	if( A_ptrToFunc != NULL)
	{
		TIMER0_CTC_CALLBACK=A_ptrToFunc;
	}
}

void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	if( TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}

void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	if( TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}


