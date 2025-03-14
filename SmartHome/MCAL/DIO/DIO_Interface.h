/*
 * DIO_Interface.h
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdalrahman
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
	DIO_LOW=0,
	DIO_HIGH
}DIO_VALUE_e;

// Port - PinNo - (I/P or O/P)
void MDIO_vSetPinDir(DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_DIRECTION_e A_pinDirection);
void MDIO_vSetPinVal(DIO_PORT_e A_portID, DIO_PIN_e A_pinID, DIO_VALUE_e A_pinValue);
DIO_VALUE_e MDIO_GetPinVal(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void MDIO_vTogglePinVal (DIO_PORT_e A_portID, DIO_PIN_e A_pinID);
void MDIO_vSetPortDir (DIO_PORT_e A_portID, u8 A_u8PortDirection);
void MDIO_vSetPortVal (DIO_PORT_e A_portID, u8 A_u8PortValue);
void MDIO_vInit();


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
