


#ifndef MOTOR_INT_H_
#define MOTOR_INT_H_

#define IN_1   0
#define IN_2   1


typedef enum{
	M1,
	M2,
	M3,
	M4,
	total_motor
}MOTOR_t;

void MOTOR_Init(void);

void MOTOR_Stop(MOTOR_t motor);

void MOTOR_CW(MOTOR_t motor);

void MOTOR_CCW(MOTOR_t motor);
/*  speed  0:100  */
void MOTOR_Speed(MOTOR_t motor,u8 speed);

#endif /* MOTOR_INT_H_ */