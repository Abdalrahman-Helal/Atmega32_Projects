/*
 * TIMERS_Prv.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Abdalrahman
 */

#ifndef MCAL_TIMERS_TIMERS_PRV_H_
#define MCAL_TIMERS_TIMERS_PRV_H_

#define TCNT0 		*((volatile u8*)(0x52))
#define TCCR0 		*((volatile u8*)(0x53))
#define TIFR		*((volatile u8*)(0x58))
#define TIMSK 		*((volatile u8*)(0x59))
#define OCR0		*((volatile u8*)(0x5C))



#endif /* MCAL_TIMERS_TIMERS_PRV_H_ */
