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
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../HAL/LCD/LCD_Int.h"



#define F_CPU 8000000UL

int main(void)
{


	HKEYPAD_vInit();
	HLCD_vInit();

	u8 L_pressedKey;
	u8 L_CharCounter=0;
	u8 L_CalcCounter=0;
	u8 operand1, operand2  , operation , result;



	while(1)
	{
		L_pressedKey= HKEYPAD_u8GetPressedKey();

		if(L_pressedKey != 255)
		{
			switch (L_CalcCounter)
			{
				case 0:
					operand1 = L_pressedKey - '0';
					break;
				case 1:
					operation = L_pressedKey;
					break;
				case 2:
					operand2 = L_pressedKey- '0';
					break;
				case 3:
					if(L_pressedKey == '=')
					{
						HLCD_vSendChar('=');
						switch(operation)
						{
						case '+':
							result = operand1 + operand2;
							HLCD_vPrintNumber(result);
							break;

						case '-':
							result = operand1 - operand2;
							HLCD_vPrintNumber(result);
							break;

						case '*':
							result = operand1 * operand2;
							HLCD_vPrintNumber(result);
							break;

						case '/':
							result = operand1 / operand2;
							HLCD_vPrintNumber(result);
							break;
						}
					}
				case 4:
					if(L_pressedKey == 'C')
					{
						HLCD_vClearDisplay();
						L_CharCounter=0;
					}
			}


			switch(L_pressedKey)
			{
			case 0 ... 9:
				L_pressedKey += '0';
				break;
			default :
				break;
			}
			if(L_CalcCounter != 3 && L_CalcCounter !=4)
			{
				HLCD_vSendChar(L_pressedKey);
			}
			L_CharCounter++;
			L_CalcCounter++;
			if(L_CalcCounter == 5)
			{
				L_CalcCounter =0;
			}

			if(L_CharCounter == 16)
			{
				HLCD_vSetCursorPosition(0,1);
			}

			else if(L_CharCounter == 32)
			{
				HLCD_vClearDisplay();
				HLCD_vSetCursorPosition(0,0);
				L_CharCounter=0;
			}
		}
	}
}

