/*
 * KEYPAD_Cfg.h
 *
 * Created: 2/3/2024 9:05:26 PM
 *  Author: cpu
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define  Row  4
#define  Col  4

#define KFIRST_OUTPUT  PINA0//PINB4
#define KFIRST_INPUT   PINB4//PIND2

#ifdef KEYPAD_PROG
u8 KeysArray[Row][Col]={{'7','8','9','A'},
{'4','5','6','B'},
{'1','2','3','C'},
{'c','0','=','D'}};

#endif


#endif /* KEYPAD_CFG_H_ */