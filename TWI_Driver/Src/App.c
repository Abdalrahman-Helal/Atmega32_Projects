/*
 * App.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */
#include <util/delay.h>

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/TWI/TWI_Interface.h"

#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/EEPROM/EEPROM_Interface.h"
#define F_CPU 8000000UL



void main(void)
{
	// local variable to return data in
	u8 local_u8Data=0;

	// Initialize DIO --> PORTD LCD Data, PORTB LCD Control, PORTC TWI
	MDIO_voidInit();

	// Initialize TWI in Master Mode
	TWI_voidInitMaster(0);

	// Send byte to EEPROM
	EEPROM_voidSendDataByte(5, 7);

	// Read Byte from EEPROM
	local_u8Data= EEPROM_u8ReadDataByte(5);

	if (local_u8Data == 7)
	{
		MDIO_voidSetPinValue(0,0,1);
	}
	// Super Loop
	while (1);

}
