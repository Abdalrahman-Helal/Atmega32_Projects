/*
 * ADC_Cfg.h
 *
 *  Created on: Oct 24, 2024
 *      Author: Abdalrahman
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_


#define ADC_PRESCALER 	0b010
#define ADC_CHANNEL 	0b00001

/*
 *		Options
 			 ADC_PS_2
			 ADC_PS_4
			 ADC_PS_8
			 ADC_PS_16
			 ADC_PS_32
		 	 ADC_PS_64
		     ADC_PS_128
 */
#define ADC_PRESCALER 	ADC_PS_4

/*
 * Options :
			AREF
			AVCC
			INTERNAL_REF
*/

#define ADC_REF_VOLT 	AVCC
/*
 * Options :
 	 	  ENABLE
	   	  DISBALE
 */

#define ADC_INTERRUPT_ENABLE 	ENABLE

#endif /* MCAL_ADC_ADC_CFG_H_ */
