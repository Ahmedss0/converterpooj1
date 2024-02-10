#include "StdTybes.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
#include "MOTOR_Cfg.h"

void MOTOR_Init(void)
{
	//future use
}

void MOTOR_Stop(MOTOR_t motor)
{
	DIO_WritePin(MOTOR_PinsArray[motor][IN_1],LOW);
	DIO_WritePin(MOTOR_PinsArray[motor][IN_2],LOW);
	/*switch (motor)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,LOW);
		break;
	}*/
}

void MOTOR_CW(MOTOR_t motor)
{
	DIO_WritePin(MOTOR_PinsArray[motor][IN_1],HIGHT);
	DIO_WritePin(MOTOR_PinsArray[motor][IN_2],LOW);
	/*switch (motor)
	{
		case M1:
		DIO_WritePin(M1_IN1,HIGHT);
		DIO_WritePin(M1_IN2,LOW);
		break;
		case M2:
		DIO_WritePin(M2_IN1,HIGHT);
		DIO_WritePin(M2_IN2,LOW);
		break;
	}*/
}

void MOTOR_CCW(MOTOR_t motor)
{
	DIO_WritePin(MOTOR_PinsArray[motor][IN_1],LOW);
	DIO_WritePin(MOTOR_PinsArray[motor][IN_2],HIGHT);
	/*switch (motor)
	{
		case M1:
		DIO_WritePin(M1_IN1,LOW);
		DIO_WritePin(M1_IN2,HIGHT);
		break;
		case M2:
		DIO_WritePin(M2_IN1,LOW);
		DIO_WritePin(M2_IN2,HIGHT);
		break;
	}*/
}

void MOTOR_Speed(MOTOR_t motor,u8 speed);