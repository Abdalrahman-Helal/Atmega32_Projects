/*
 * TIMERS_Int.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Abdalrahman
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_

void MTIMERS_vInit(void);
void MTIMERS_vSetPreLoadValue (/*Timer ID*/ u16 A_u16Preload);

void MTIMERS_vSetInterval_Asynch (u16 A_u16IntervalCounts , void(*A_fptr)(void));
void MTIMERS_vStartTimer(/*Timer ID*/);
void MTIMERS_vStopTimer(/*Timer ID*/);
#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
