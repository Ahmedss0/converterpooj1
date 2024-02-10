#include "DIO_Int.h"

#define M1_IN1  PINC1
#define M1_IN2  PINC2

#define M2_IN1  PIND1
#define M2_IN2  PIND2

#define M3_IN1  PINA1
#define M3_IN2  PINA2

#define M4_IN1  PINB1
#define M4_IN2  PINB2



DIO_Pin_t MOTOR_PinsArray[4][2]={{M1_IN1,M1_IN2},/* M1*/
{M2_IN1,M2_IN2},/* M2*/
{M3_IN1,M3_IN2},/* M3*/
{M4_IN1,M4_IN2} /* M4*/
};
