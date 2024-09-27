/*
 * DCM_Int.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Abdalrahman
 */

#ifndef HAL_DCM_DCM_INT_H_
#define HAL_DCM_DCM_INT_H_

#define NOSTRUCT 	1
#define STRUCT 		2

#define METHOD 		STRUCT

typedef struct
{
	u8 PORT;
	u8 PIN1;
	u8 PIN2;

}DCM_t;


#if METHOD == NOSTRUCT
void HDCM_vInit(void);
void HDCM_vRotateCW(void);  		/* TODO : Implement Speed as input */
void HDCM_vRotateCWW(void);  	/* TODO : Implement Speed as input */
void HDCM_vStop(void);


#elif METHOD == STRUCT
DCM_t HDCM_xInit(u8 A_u8PORT, u8 A_u8PIN1, u8 A_u8PIN2);
void HDCM_vRotateCW(DCM_t * xMotor);  		/* TODO : Implement Speed as input */
void HDCM_vRotateCWW(DCM_t * xMotor);  	/* TODO : Implement Speed as input */
void HDCM_vStop(DCM_t * xMotor);

#endif

#endif /* HAL_DCM_DCM_INT_H_ */
