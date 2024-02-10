#include "MemMap.h"
#include "StdTybes.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
#include "STEPPER_Int.h"
#include "MOVE_Init.h"
#include "LCD_Int.h"
#include "KEYPAD_Cfg.h"
#include "KEYPAD_Int.h"
#define  F_CPU   8000000
#include  <util/delay.h>
#define delay1  300



int main(void)
{
	DIO_Init();
	MOVE_init();
	LCD_Init();
	KEYPAD_Init();
	converter();
	while(1)
	{
		Runable();
	}
}

