/*
 * KEYPAD_Int.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Abdalrahman
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

#define KPD_PORT DIO_PORTB



void KPD_Init(void);

u8 KPD_u8GetPressedkey(void);






#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
