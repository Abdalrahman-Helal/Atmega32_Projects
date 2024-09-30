/*
 * EXTI_Prg.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "avr/io.h"

#include "EXTI_Int.h"
#include "EXTI_Cfg.h"


void MEXTI_vInit()
{

#if EXTI_LINE1 == ENABLE
	// Sense Control Falling Edge for INT1
#if EXTT_LIN1_SENSE_CTRL == EXTI_FALLING
	SET_BIT(MCUCR , 3);
	CLR_BIT(MCUCR , 2);

#elif EXTT_LIN1_SENSE_CTRL == EXTI_RISING
	SET_BIT(MCUCR , 3);
	SET_BIT(MCUCR , 2);

#elif EXTT_LIN1_SENSE_CTRL == EXTI_ONCHANGE
	CLR_BIT(MCUCR , 3);
	SET_BIT(MCUCR , 2);

#elif EXTT_LIN1_SENSE_CTRL == EXTI_LOWLEVEL
	CLR_BIT(MCUCR , 3);
	CLR_BIT(MCUCR , 2);
#else
#error "Sense Control Must be falling , Rising , ..."

#endif
	// Enable INT0
	SET_BIT(GICR , 6);
#endif


/**********************/

#if EXTI_LINE0 == ENABLE
	// Sense Control Falling Edge for INT0
#if EXTT_LIN0_SENSE_CTRL == EXTI_FALLING
	SET_BIT(MCUCR , 1);
	CLR_BIT(MCUCR , 0);

#elif EXTT_LIN0_SENSE_CTRL == EXTI_RISING
	SET_BIT(MCUCR , 1);
	SET_BIT(MCUCR , 0);

#elif EXTT_LIN0_SENSE_CTRL == EXTI_ONCHANGE
	CLR_BIT(MCUCR , 1);
	SET_BIT(MCUCR , 0);

#elif EXTT_LIN0_SENSE_CTRL == EXTI_LOWLEVEL
	CLR_BIT(MCUCR , 1);
	CLR_BIT(MCUCR , 0);
#else
#error "Sense Control Must be falling , Rising , ..."

#endif
	// Enable INT0
	SET_BIT(GICR , 6);
#endif

	/*****************************/


#if EXTI_LINE2 == ENABLE
	// Sense Control Falling Edge for INT0

#if EXTI_LINE2 == EXTI_FALLING
	CLR_BIT(MCUCSR , 6);
#elif EXTI_LINE2 == EXTI_RISING
	SET_BIT(MCUCSR , 6);
#endif


	// Enable INT0
	SET_BIT(GICR , 6);
#endif

}
