/*
 * LED_Interface.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Abdalrahman
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define GREEN    	PIN0
#define YELLOW 		PIN1
#define RED			PIN2



void HLED_voidTurnLEDOn(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);

void HLED_voidTurnLEDOff(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);

void HLED_voidToggleLED(DIO_PORT_e A_portID, DIO_PIN_e A_pinID);


#endif /* HAL_LED_LED_INTERFACE_H_ */
