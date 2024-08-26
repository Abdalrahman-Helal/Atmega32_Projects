/*
 * Timer_Interface.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_

#define NORMAL_MODE 0
#define PHASE_CORRECT_MODE 1
#define CTC_MODE 2
#define FAST_PWM_MODE 3



void MTIMER0_voidInit (void);
void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks);
void MTIMER0_voidSetOVFCallback (void (*A_ptrToFunc)(void));
void MTIMER0_voidSetCTCCallback (void (*A_ptrToFunc)(void));
void MTIMER0_voidSetOCR0Value(u8 A_u8OCR0Value);
void MTIMER0_voidStopTimer (void);




#endif /* INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_ */
