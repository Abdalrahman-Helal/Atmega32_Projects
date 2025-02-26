/*
 * ADC_Prv.h
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_


#define AREF  			0
#define AVCC  			1
#define INTERNAL_REF 	2

#define ENABLE 		0
#define DISABLE 	1

// Prescaler
#define ADC_PS_2 		0b001
#define ADC_PS_4 		0b010
#define ADC_PS_8 		0b011
#define ADC_PS_16 		0b100
#define ADC_PS_32		0b101
#define ADC_PS_64 		0b110
#define ADC_PS_128 		0b111

//  ADMUX
#define REFS1 	7
#define REFS0 	6
#define ADLAR 	5
#define MUX4 	4
#define MUX3 	3
#define MUX2 	2
#define MUX1 	1
#define MUX0 	0

// ADCSRA
#define ADEN 	7
#define ADSC 	6
#define ADATE 	5
#define ADIF 	4
#define ADIE 	3
#define ADPS2 	2
#define	ADPS1 	1
#define APDS0 	0


#define ADMUX   	*((volatile u8 *)(0x27))
#define ADCSRA  	*((volatile u8 *)(0x26))
#define ADCH		*((volatile u8 *)(0x25))
#define ADCL		*((volatile u8 *)(0x24))
#define SFIOR 		*((volatile u8 *)(0x50))
#define ADC   		*((volatile u16 *)(0x24))






#endif /* MCAL_ADC_ADC_PRV_H_ */
