/*
 * TIMERS_Prg.c
 *
 *  Created on: Feb 26, 2025
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_Int.h"
#include "TIMERS_Prv.h"
#include "TIMERS_Cfg.h"

#define NULL 0

void (*G_TIM0_OVF_Callback)(void);

u32 G_u32IntervalCount;

void MTIMERS_vInit(void)
{
	/*
	 * MODE : Normal Overflow
	 * Interrupt : Enable Overflow Interrupt
	 * Prescaler : No Clock
	 */

	TCCR0 = 0b00000000;
	SET_BIT(TIMSK, 0); 	//TOIE0


}
void MTIMERS_vSetPreLoadValue (/*Timer ID*/ u16 A_u16Preload)
{
	TCNT0 = A_u16Preload;
}

void MTIMERS_vSetInterval_Asynch (u16 A_u16IntervalCounts , void(*A_fptr)(void))
{
	G_u32IntervalCount= A_u16IntervalCounts;
	G_TIM0_OVF_Callback = A_fptr;

	/*Start Timer*/
	MTIMERS_vInit();
}
void MTIMERS_vStartTimer(/*Timer ID*/)
{
	TCCR0 =(TCCR0 & 0xF8) | (0b010);
}
void MTIMERS_vStopTimer(/*Timer ID*/)
{
	TCCR0 =(TCCR0 & 0xF8) | (0b000);
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u32 LS_u32Counter= 0;
	LS_u32Counter++;

	if(G_TIM0_OVF_Callback != NULL)
	{
		G_TIM0_OVF_Callback();
		LS_u32Counter= 0;
	}
}
