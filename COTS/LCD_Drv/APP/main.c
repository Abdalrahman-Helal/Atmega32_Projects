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
#include "../HAL/LCD/LCD_Int.h"



#define F_CPU 8000000UL

u8 C1 [] ={  // He
		  0B00000,
		  0B00000,
		  0B00110,
		  0B01001,
		  0B10101,
		  0B01011,
		  0B11111,
		  0B00000
};

u8 C2 [] ={  // La
		  0B00010,
		  0B01001,
		  0B00101,
		  0B00101,
		  0B00101,
		  0B00101,
		  0B11111,
		  0B00000
};

u8 C3 [] ={		 // L
		  0B00010,
		  0B00001,
		  0B00001,
		  0B00001,
		  0B00001,
		  0B01001,
		  0B00111,
		  0B00000
};


int main(void)
{
	HLCD_vInit();
//	HLCD_vSendChar('H');
//	HLCD_vSendChar('E');
//	HLCD_vSendChar('L');
//	HLCD_vSendChar('A');
//	HLCD_vSendChar('L');

//	HLCD_vPrintString("Name : HELAL");
//	_delay_ms(1000);
//	HLCD_vClearDisplay();
//
//	HLCD_vPrintString("Age : 20 ");
//	_delay_ms(1000);
//	HLCD_vClearDisplay();
//
//	HLCD_vPrintString("FCIS ");
//	_delay_ms(1000);
//	HLCD_vClearDisplay();
//	HLCD_vPrintNumber(123);


	HLCD_vSaveCustomChar(1,C1);
	HLCD_vSetCursorPosition(15,0);
	HLCD_vDisplayCustomChar(1);

	HLCD_vSaveCustomChar(2,C2);
	HLCD_vSetCursorPosition(14,0);
	HLCD_vDisplayCustomChar(2);

	HLCD_vSaveCustomChar(3,C3);
	HLCD_vSetCursorPosition(13,0);
	HLCD_vDisplayCustomChar(3);
	HLCD_vSetCursorPosition(12,0);


	while(1)
	{

	}







}
