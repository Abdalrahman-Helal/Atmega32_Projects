/*
 * GI_Program.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Abdalrahman
 */


#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"


#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/GI/GI_Private.h"
#include "../Include/MCAL/GI/GI_Cfg.h"

void MGI_voidEnable(void)
{
	SET_BIT(SREG , GLOBAL_INTERUPPT_ENABLE_BIT);
}

void MGI_voidDisable(void)
{
	CLR_BIT(SREG , GLOBAL_INTERUPPT_ENABLE_BIT);
}

