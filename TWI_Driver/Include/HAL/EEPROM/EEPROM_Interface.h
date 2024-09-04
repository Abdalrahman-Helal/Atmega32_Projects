/*
 * EEPROM_Interface.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_
#define INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);

#endif /* INCLUDE_HAL_EEPROM_EEPROM_INTERFACE_H_ */
