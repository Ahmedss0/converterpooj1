/*
 * STEPPER_Prg.c
 *
 * Created: 12/17/2023 1:56:58 AM
 *  Author: Ahmed Saad
 */ 
#include "STEPPER_Int.h"

void STEPPER_Bipoler_CW(void)
{           
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);           /*TIME FOR EACH STEP*/
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}
void STEPPER_Bipoler_CCW(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);              /**/
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}
void STEPPER_Unipoler_CW(void)
{
	         
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);          /*TIME FOR EACH STEP*/
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
}
void STEPPER_Unipoler_CCW(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
}
void STEPPER_Unipoler_CW_HS(void)
{
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);          /*TIME FOR EACH STEP*/
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
}
void STEPPER_Unipoler_CCW_HS(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGHT);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,HIGHT);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGHT);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGHT);
	_delay_ms(DELAY);
}

void STEPPER_STOP(void)
{
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
}

void STEPPER_ROTATE(void)
{
	while(!DIO_ReadPin(PIND2))
	{
		STEPPER_Unipoler_CW();
	}
	while(!DIO_ReadPin(PIND3))
	{
		STEPPER_Unipoler_CCW();
	}
	STEPPER_STOP();
}