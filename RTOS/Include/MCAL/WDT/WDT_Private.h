/*
 * WDT_Private.h
 *
 *  Created on: Aug 29, 2024
 *      Author: Abdalrahman
 */

#ifndef INCLUDE_MCAL_WDT_WDT_PRIVATE_H_
#define INCLUDE_MCAL_WDT_WDT_PRIVATE_H_

#define WDP0  0
#define WDP1  1
#define WDP2  2
#define WDE   3
#define WDTOE 4

#define WDTCR (*(volatile u8 * )0x41)

#endif /* INCLUDE_MCAL_WDT_WDT_PRIVATE_H_ */
