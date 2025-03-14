/*
 * Keypad_Interface.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_

#define NO_KEY_PRESSED 255

void HKEYPAD_vInit(void);
u8 HKEYPAD_u8GetPressedKey(void);
u16 HKEYPAD_u16MultiDigitInput(void);


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
