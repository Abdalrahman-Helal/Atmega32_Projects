/*
 * Timer_Cfg.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_

#define TIMER0_MODE CTC_MODE



/*
* 0 0 0 No clock source (Timer/Counter stopped).
* 0 0 1 clkI/O/(No prescaling)
* 0 1 0 clkI/O/8 (From prescaler)
* 0 1 1 clkI/O/64 (From prescaler)
* 1 0 0 clkI/O/256 (From prescaler)
* 1 0 1 clkI/O/1024 (From prescaler)
* 1 1 0 External clock source on T0 pin. Clock on falling edge.
* 1 1 1 External clock source on T0 pin. Clock on rising edge
*/




#define OCR0_VALUE 199



#define TIMER0_MODE CTC_MODE

#define FAST_PWM_MODE_VALUE 99

#define OC0_FAST_PWM_MODE OC0_NONINVERTING_MODE

/*
 * 0b000 No clock source (Timer/Counter stopped).
 * 0b001 clkI/O/(No prescaling)
 * 0b010 clkI/O/8 (From prescaler)
 * 0b011 clkI/O/64 (From prescaler)
 * 0b100 clkI/O/256 (From prescaler)
 * 0b101 clkI/O/1024 (From prescaler)
 * 0b110 External clock source on T0 pin. Clock on falling edge.
 * 0b111 External clock source on T0 pin. Clock on rising edge.
 */
#define TIMER0_CLK_CFG 0b010

#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
