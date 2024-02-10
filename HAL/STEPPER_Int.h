/*
 * STEPPER_Init.h
 *
 * Created: 12/17/2023 1:57:48 AM
 *  Author: Ahmed Saad
 */ 


#ifndef STEPPER_INIT_H_
#define STEPPER_INIT_H_

#include "StdTybes.h"
#include "DIO_Int.h"


#define  F_CPU   8000000
#include  <util/delay.h>


#define   DELAY     2

/******************************* PIN STEPPER *******************************/

#define   COIL1A    PINC0         
#define   COIL1B    PINC1
#define   COIL2A    PINC2
#define   COIL2B    PINC3

/**************************************************************************/

void STEPPER_Bipoler_CW(void);
void STEPPER_Bipoler_CCW(void);
void STEPPER_Unipoler_CW(void);
void STEPPER_Unipoler_CCW(void);
void STEPPER_Unipoler_CW_HS(void);
void STEPPER_Unipoler_CCW_HS(void);
void STEPPER_ROTATE(void);
void STEPPER_STOP(void);

#endif /* STEPPER_INIT_H_ */