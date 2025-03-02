/*
 * GIE_Prg.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Abdalrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include <avr/io.h>

#include "GIE_Int.h"

void MGIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, 7);
}
void MGIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG , 7);
}



