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

void MTIMER0_voidInit (void)
{
	#if TIMER0_MODE == NORMAL_MODE
		// Set Wave Generation Mode to Normal Mode
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		// Turn on OVF Interrupt
		SET_BIT(TIMSK,0);
		CLR_BIT(TIMSK,1);

		// Start Timer by setting its Clock
		TCCR0 &= TIMER0_CLK_MASK;
		TCCR0 |= TIMER0_CLK_CFG;

	#elif TIMER0_MODE == PHASE_CORRECT_MODE

	#elif TIMER0_MODE == CTC_MODE
		// Set Wave Generation Mode to CTC Mode
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		// Turn on OVF Interrupt
		SET_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		OCR0 = OCR0_VALUE;

		// Start Timer by setting its Clock
		TCCR0 &= TIMER0_CLK_MASK;
		TCCR0 |= TIMER0_CLK_CFG;
	#elif TIMER0_MODE == FAST_PWM_MODE
		// Set Wave Generation to PWM Mode
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		// Turn of OVF and CTC Interrupts
		CLR_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		// set OCR0 Value
		OCR0 = FAST_PWM_MODE_VALUE;

		// set OC0 Pin Mode (Inverting or Non-Inverting)
		// Start Timer
		TCCR0 &= TIMER0_CLK_OC0_MASK;
		TCCR0 |= (TIMER0_CLK_CFG | (OC0_FAST_PWM_MODE	<<4));
	#endif
}

void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks)
{
	TCNT0 = A_u8NoOfTicks;
}

void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}

void MTIMER0_voidStopTimer()
{
	TCCR0 &= TIMER0_CLK_MASK;
}


void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}

void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}



void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CALLBACK != NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}


void MTIMER1_voidInit()
{
	// Select TIMER 1 MODE ==> 14
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

	// Non-Inverting Mode for OC1A
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);

	// ICR1 = 19999
	ICR1 = 19999;

	//OCR1A
	OCR1A = 1500;

	// Start Timer
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}

void MTIMER1_voidSetOCR1AValue (u16 A_u16Value)
{
	OCR1A = A_u16Value;
}

void MTIMER1_voidInitSWICU()
{
	// Start Timer by setting prescaler
	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);
}
void MTIMERS_voidSetTimer1Value(u16 A_u16Value)
{
	TCNT1 = A_u16Value;
}

u16 MTIMERS_u16ReadTimer1Value(void)
{
	return TCNT1;
}
