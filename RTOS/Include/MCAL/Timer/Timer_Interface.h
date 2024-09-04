/*
 * Timer_Interface.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_

#define NORMAL_MODE    		0
#define PHASE_CORRECT_MODE  1
#define CTC_MODE       		2
#define FAST_PWM_MODE  		3


//0 0 Normal port operation, OC0 disconnected.
//0 1 Reserved
//1 0 Clear OC0 on compare match, set OC0 at BOTTOM,
//(nin-inverting mode)
//1 1 Set OC0 on compare match, clear OC0 at BOTTOM,
//(inverting mode)

#define OC0_NORMAL_DIO_PIN 		0
#define OC0_NONINVERTING_MODE 	2
#define OC0_INVERTING_MODE 		3



void MTIMER0_voidInit (void);
void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks);
void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void));
void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void));
void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value);
void MTIMER0_voidStopTimer (void);
void MTIMER1_voidInit();
void MTIMER1_voidSetOCR1AValue(u16 A_u16Value);

void MTIMER1_voidInitSWICU();
void MTIMERS_voidSetTimer1Value(u16 A_u16Value);
u16 MTIMERS_u16ReadTimer1Value(void);





#endif /* INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_ */
