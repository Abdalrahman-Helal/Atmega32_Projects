/*
 * Timer_Cfg.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_

#define TIMER0_MODE FAST_PWM_MODE



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


#define TIMER0_CLK 0b010

#define OCR0_VALUE 199


/* Normal Mode
 * 0 0 Normal port operation, OC0 disconnected.
 0 1 Toggle OC0 on compare match
 1 0 Clear OC0 on compare match
 1 1 Set OC0 on compare match
 */

/* Fast-PWM Mode
 *  0 0 Normal port operation, OC0 disconnected.
 *	0 1 Reserved
 *	1 0 Clear OC0 on compare match, set OC0 at BOTTOM,
 *	(nin-inverting mode)
 *	1 1 Set OC0 on compare match, clear OC0 at BOTTOM,
	(inverting mode)
 */
#define OC0_MODE 2

#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
