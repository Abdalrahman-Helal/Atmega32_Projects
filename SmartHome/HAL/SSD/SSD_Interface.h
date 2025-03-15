/*
 * SSD_Interface.h
 *
 *  Created on: Mar 2, 2025
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_

#define ZERO 	0b01000000
#define ONE 	0b01111001
#define TWO 	0b00100100
#define THREE 	0b00110000
#define FOUR 	0b00011001
#define FIVE 	0b00010010
#define SIX 	0b00000010
#define SEVEN 	0b01111000
#define EIGHT 	0b00000000
#define NINE 	0b00010000



void HSSD_vInit(DIO_PORT_e A_PortID);
void HSSD_vDisplayNumber(DIO_PORT_e A_PortID, u8 A_u8NumberValue);
void HSSD_vDisplayNumberAscending(DIO_PORT_e A_PortID , u16 A_u16TimetoWait);
void HSSD_vCountDown(DIO_PORT_e A_PortID , s8 A_s8Time, u16 A_u16TimetoWait);

#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
