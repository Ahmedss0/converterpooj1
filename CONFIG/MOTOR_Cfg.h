/*
* MOTOR_Cfg.h
*
* Created: 12/12/2023 5:55:09 PM
*  Author: Ahmed Saad
*/


#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_

#define M1_IN1  PINC1
#define M1_IN2  PINC2

#define M2_IN1  PINC3
#define M2_IN2  PINC4

#define M3_IN1  PIND1
#define M3_IN2  PIND2

#define M4_IN1  PIND3
#define M4_IN2  PIND4 

#define MOTOR_NUM     4 
#define MOTOR_IN_NUM  2 

DIO_Pin_t MOTOR_PinsArray[MOTOR_NUM][MOTOR_IN_NUM]={{M1_IN1,M1_IN2},/* M1*/
{M2_IN1,M2_IN2},/* M2*/
{M3_IN1,M3_IN2},/* M3*/
{M4_IN1,M4_IN2} /* M4*/
};


#endif /* MOTOR_CFG_H_ */