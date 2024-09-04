/*
 * RTOS_Program.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/Timer/Timer_Interface.h"

#include "../Include/Services/RTOS/RTOS_Interface.h"
#include "../Include/Services/RTOS/RTOS_Private.h"
#include "../Include/Services/RTOS/RTOS_Cfg.h"

#define NULL ((void *)0)

RTOS_TCB Global_RTOSArrOfTasks[RTO_u8_MAX_NUMBER_TASKS];


void SRTOS_voidInit(void)
{
	MTIMER0_voidSetCTCCallback(SRTOS_voidScheduler);
	MTIMER0_voidInit();
}

void SRTOS_voidInitArrayFunctions(void)
{
	u8 local_u8Counter=0;
	for ( ; local_u8Counter < RTO_u8_MAX_NUMBER_TASKS ; local_u8Counter++)
	{
		Global_RTOSArrOfTasks[local_u8Counter].pf = NULL;
	}
}

void SRTOS_voidCreateTask (u8 A_u8priority, u16 A_u16Periodicity, u16 A_u16FirstDelay, void (*pf)(void))
{
	if ((A_u8priority < RTO_u8_MAX_NUMBER_TASKS) && (pf != NULL))
	{
		Global_RTOSArrOfTasks[A_u8priority].FirstDelay  = A_u16FirstDelay;
		Global_RTOSArrOfTasks[A_u8priority].Periodicity = A_u16Periodicity;
		Global_RTOSArrOfTasks[A_u8priority].pf          = pf;
	}
}

void SRTOS_voidScheduler (void)
{
	u8 static counter=0;
	counter++;

	if (counter == 5)
	{
		counter = 0;
		u8 local_u8Counter=0;
		for ( ; local_u8Counter < RTO_u8_MAX_NUMBER_TASKS ; local_u8Counter++)
		{
			if (Global_RTOSArrOfTasks[local_u8Counter].FirstDelay == 0)
			{
				if (Global_RTOSArrOfTasks[local_u8Counter].pf != NULL)
				{
					Global_RTOSArrOfTasks[local_u8Counter].pf();
				}
				Global_RTOSArrOfTasks[local_u8Counter].FirstDelay = Global_RTOSArrOfTasks[local_u8Counter].Periodicity - 1;
			}
			else
			{
				Global_RTOSArrOfTasks[local_u8Counter].FirstDelay--;
			}
		}
	}
}
