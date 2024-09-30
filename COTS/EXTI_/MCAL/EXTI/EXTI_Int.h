/*
 * EXTI_Int.h
 *
 *  Created on: Sep 30, 2024
 *      Author: Abdalrahman
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

void MEXTI_vInit();

void MEXTI_vEnableInterrupt(u8 A_u8ExtiLineNo);
void MEXTI_vDisableInterrupt(u8 A_u8ExtiLineNo);
void MEXTI_vSetSenseControl(u8 A_u8ExtiLineNo , u8 A_u8SenseCtrl);


#define DISABLE 0
#define ENABLE 1

#define  EXTI_RISING 		0
#define  EXTI_FALLING		1
#define  EXTI_ONCHANGE		2
#define  EXTI_LOWLEVEL		3

#endif /* MCAL_EXTI_EXTI_INT_H_ */
