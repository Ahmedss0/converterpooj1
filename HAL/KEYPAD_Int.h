/*
 * KEYPAD_Int.h
 *
 * Created: 2/3/2024 9:04:33 PM
 *  Author: cpu
 */ 


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#define NO_KEY  'Q'

void KEYPAD_Init(void);

u8 KEYPAD_Getkey(void);
u16 KEYPAD_CALC(u16*arr);
void Convert_input(void);
void Convert_output(void);
void Store_Input(void);
void Get_Out(void);
void Runable(void);
void converter(void);

#endif /* KEYPAD_INT_H_ */