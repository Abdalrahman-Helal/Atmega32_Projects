/*
  * WDT_Program.c
 *
 *  Created on: Aug 29, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/WDT/WDT_Interface.h"
#include "../Include/MCAL/WDT/WDT_Private.h"
#include "../Include/MCAL/WDT/WDT_Cfg.h"

void MWDT_voidEnable(WDT_TIME_e A_TimeToReset)
{
	WDTCR =0x00;
	WDTCR |= (1<<WDE) | (A_TimeToReset);
}
void MWDT_voidDisable(void)
{
	WDTCR |= (1<<WDE) | (1<<WDTOE);
	WDTCR = 0x00;
}
