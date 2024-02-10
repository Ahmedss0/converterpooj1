/*
 * LCD_Int.h
 *
 * Created: 1/18/2024 3:23:16 AM
 *  Author: Ahmed Saad
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "StdTybes.h"
#include "DIO_Int.h"

#define  F_CPU   8000000
#include  <util/delay.h>

#define BB         PIND2

void LCD_Init(void);
void LCD_WritrChar(u8 ch);
void LCD_WriteStr(c8*str);
void LCD_WriteNum(s32 num);
void LCD_WriteBinary(u8 ch);
void LCD_WriteHex(u8 num);
void LCD_Clear(void);
void LCD_Cursor(u8 line,u8 cell);
void LCD_Display(c8*str);
void LCD_CGRAM(void);
void LCD_MAND1(void);
void LCD_MAND2(void);
void LCD_DINASOUR_Clear_Down(void);
void LCD_DINASOUR_Clear_up(void);
void LCD_DINASOUR_Down(void);
void LCD_DINASOUR_up(void);
void LCD_1Tree(u8 i);
void LCD_2Tree(u8 i);
void LCD_KEY(void);

#endif /* LCD_INT_H_ */