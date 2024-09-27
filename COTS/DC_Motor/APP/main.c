/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>
//#include <avr/io.h>

#include "../MCAL/DIO/DIO_Int.h"
#include "../HAL/DCM/DCM_Int.h"


#define F_CPU 8000000UL

int main(void)
{
	DCM_t Motor1 = {DIO_PORTA ,DIO_PIN0 , DIO_PIN1 };
	DCM_t Motor2 = HDCM_xInit(DIO_PORTA ,DIO_PIN0 ,DIO_PIN1);
	DCM_t Motor2 = HDCM_xInit(DIO_PORTB ,DIO_PIN2 ,DIO_PIN7);

	HDCM_vRotateCW(*Motor1);
	HDCM_vRotateCCW(*Motor2);



	HDCM_vInit();
	while(1)
	{

	}

}
