/*
 * Timer_Private.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_
// Timer 0
#define WGM01 3
#define WGM00 6

// Timer 1
#define WGM10 0
#define WGM11 1
#define WGM12 3
#define WGM13 4

#define COM1B0 4
#define COM1B1 5

#define COM1A0 6
#define COM1A1 7

#define TOIE0 0
#define OCIE0 1

#define TCCR0  (*((volatile u8 * )0x53))
#define TCNT0  (*((volatile u8 * )0x52))
#define OCR0   (*((volatile u8 * )0x5C))
#define TIMSK  (*((volatile u8 * )0x59))
#define TIFR   (*((volatile u8 * )0x58))

#define TCCR1A (*((volatile u8 * )0x4F))
#define TCCR1B (*((volatile u8 * )0x4E))
#define	TCNT1H (*((volatile u8 * )0x4D))
#define	TCNT1L (*((volatile u8 * )0x4C))
#define TCNT1  (*((volatile u16 * )0x4C))
#define	OCR1AH (*((volatile u8 * )0x4B))
#define OCR1AL (*((volatile u8 * )0x4A))
#define OCR1A   (*((volatile u16 * )0x4B))
#define OCR1BH (*((volatile u8 * )0x49))
#define OCR1BL (*((volatile u8 * )0x48))
#define OCR1B  (*((volatile u16 * )0x48))
#define ICR1H  (*((volatile u8 * )0x47))
#define ICR1L  (*((volatile u8 * )0x46))
#define ICR1   (*((volatile u16 * )0x46))

#define TIMER0_CLRMASK 		0b11111000
#define TIMER0_CLK_OCR_MASK  0b11001000
#endif /* INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_ */
