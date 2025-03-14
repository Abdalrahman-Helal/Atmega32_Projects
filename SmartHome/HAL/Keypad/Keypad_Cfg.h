/*
 * Keypad_Cfg.h
 *
 *  Created on: Aug 7, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_

#define KEYPAD_ROW_NO 4
#define KEYPAD_COL_NO 4

//u8 global_u8ArrofKeyValues[KEYPAD_ROW_NO][KEYPAD_COL_NO]={
//															{'1','2','3','+'},
//															{'4','5','6','-'},
//															{'7','8','9','*'},
//															{'C','0','=','/'}
//														  };

u8 ArrofKeyValues[KEYPAD_ROW_NO][KEYPAD_COL_NO]={
															{'7','8','9','/'},
															{'4','5','6','*'},
															{'1','2','3','-'},
															{'C','0','=','#'}
														  };





#define KEYPAD_PORT DIO_PORTA

#define KEPAD_ROW0 PIN0
#define KEPAD_ROW1 PIN1
#define KEPAD_ROW2 PIN2
#define KEPAD_ROW3 PIN3

#define KEYPAD_COL0 PIN4
#define KEYPAD_COL1 PIN5
#define KEYPAD_COL2 PIN6
#define KEYPAD_COL3 PIN7

#define KEYPAD_ROWS {KEPAD_ROW0,KEPAD_ROW1,KEPAD_ROW2,KEPAD_ROW3};
#define KEYPAD_COLS {KEYPAD_COL0,KEYPAD_COL1,KEYPAD_COL2,KEYPAD_COL3};



#define DEBOUNCING_DELAY_ms 30










#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CFG_H_ */
