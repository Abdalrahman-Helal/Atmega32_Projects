/*
 * DIO_Interface.h
 *
 *  Created on: Sep 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_



typedef enum{
	DIO_PORTA=0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
}DIO_PORT_e;


typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}DIO_PIN_e;

typedef enum{
	DIO_INPUT=0,
	DIO_OUTPUT
}DIO_DIRECTION_e;


typedef enum{
	DIO_RESET=0, // LOW
	DIO_SET // HIGH
}DIO_VALUE_e;

// Port - PinNo - (I/P or O/P)
void MDIO_voidSetPinDirection(DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_DIRECTION_e A_pinDirection);
void MDIO_voidSetPinValue(DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_VALUE_e A_pinValue);
DIO_VALUE_e MDIO_getPinValue(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void MDIO_voidTogglePinValue (DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void MDIO_voidSetPortDirection (DIO_PORT_e A_portID, u8 A_u8PortDirection);
void MDIO_voidSetPortValue (DIO_PORT_e A_portID, u8 A_u8PortValue);
void MDIO_voidInit (void);
#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
