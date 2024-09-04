/*
 * LCD_Cfg.h
 *
 *  Created on: Sep 15, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT  DIO_PORTD
#define LCD_CTRL_PORT  DIO_PORTC

#define LCD_RS_PIN  PIN0
#define LCD_RW_PIN  PIN1
#define LCD_E_PIN   PIN2

/*
 *  0 --> 1 Line
 *  1 --> 2 Lines
 */
#define LCD_NO_LINES 1

/*
 *  0 --> 5 * 7
 *  1 --> 5 * 10
 */
#define LCD_CHAR_FONT 0

/*
 *  0 --> OFF
 *  1 --> ON
 */
#define LCD_DISPLAY_ON_OFF 1

/*
 *  0 --> OFF
 *  1 --> ON
 */
#define LCD_CURSOR_DISPLAY 1

/*
 *  0 --> OFF
 *  1 --> ON
 */
#define LCD_CURSOR_BLINK 1


/*
 *  0 --> Right to Left
 *  1 --> Left to Right
 */
#define LCD_MOVE_DIRECTION 1


/*
 *  0 --> OFF
 *  1 --> ON
 */
#define LCD_SHIFT 0
#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
