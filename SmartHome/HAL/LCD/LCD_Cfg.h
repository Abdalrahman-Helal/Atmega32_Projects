/*
 * LCD_Cfg.h
 *
 *  Created on: Mar 3, 2025
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT 	DIO_PORTD
#define LCD_CTRL_PORT 	DIO_PORTC

#define LCD_RS_PIN 		PIN0
#define LCD_RW_PIN 		PIN1
#define LCD_E_PIN 		PIN2


/*
 * 	0 -> 1 Line
 * 	1 -> 2 Lines
 */
#define LCD_NO_OF_LINES  1

/*
 * 	0 -> 5x7 	Dots
 * 	1 -> 5x10 	Dots
 */
#define LCD_CHAR_SIZE	0

/*
 * 0 -> OFF
 * 1 -> ON
 */
#define LCD_DISPLAY_STATUS 1

/*
* 0 -> OFF
* 1 -> ON
 */
#define LCD_CURSOR_DISPLAY 1


/*
* 0 -> OFF
* 1 -> ON
 */
#define LCD_CURSOR_BLINK 1


/*
 * 0 -> Right to Left
 * 1 -> Left to Right
 */
#define LCD_DISPLAY_DIRECTION	1


/*
 * 	0 -> OFF
 * 	1 -> ON
 */
#define LCD_SHIFT_ENABLE 0


#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
