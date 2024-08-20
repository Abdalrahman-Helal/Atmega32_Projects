/*
 * ADC_Private.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_PRIVATE_H_

#define ADMUX  (*((volatile u8 *)0x27))
#define ADCSRA (*((volatile u8 *)0x26))
#define ADCL   (*((volatile u8 *)0x25))
#define ADCH   (*((volatile u8 *)0x24))

#define ADCLH (*((volatile u16 *)0x24))

#define ADC_CHANNEL_MASK 0b1110000

#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADATE 5
#define ADIF  4
#define ADSC  6
#define ADEN  7

#endif /* INCLUDE_MCAL_ADC_PRIVATE_H_ */
