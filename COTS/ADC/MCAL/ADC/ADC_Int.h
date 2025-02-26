/*
 * ADC_Int.h
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

void MADC_vInit(void);
u16 MADC_u16AnalogRead(u8 A_u8ChannelNo);

// Interrupt Based APIs
void MADC_vStartConversion(u8 A_u8ChannleNo);
u16  MADC_u16GetADCData(void);
void MADC_vSetCallback(void (*A_fptr)(void));


#endif /* MCAL_ADC_ADC_INT_H_ */
