/*
* LCD_Prg.c
*
* Created: 1/18/2024 3:23:42 AM
*  Author: Ahmed Saad
*/

#include "LCD_Int.h"
#include "LCD_Cfg.h"

#if LCD_Mode==_8_Bit_

static void Write_Instruction(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGHT);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void Write_Data(u8 data)
{
	DIO_WritePin(RS,HIGHT);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGHT);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	Write_Instruction(0x38);    // 8 Bit VS 2 Line VS 5*7 Font
	Write_Instruction(0x0c);    // On Display Vs Off Cursor Off Vs off Blinks Off
	Write_Instruction(0x01);    // Clear
	_delay_ms(1);               // 1.59 ms
	Write_Instruction(0x06);    // I/D : 1 Vs Sh : 0
}

#elif LCD_Mode==_4_Bit_

static void Write_Instruction(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGHT);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGHT);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void Write_Data(u8 data)
{
	DIO_WritePin(RS,HIGHT);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGHT);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGHT);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	Write_Instruction(0x02); 
	Write_Instruction(0x28);    // 4 Bit VS 2 Line VS 5*7 Font
	Write_Instruction(0x0c);    // On Display Vs Off Cursor Off Vs off Blinks Off
	Write_Instruction(0x01);    // Clear
	_delay_ms(1);               // 1.59 ms
	Write_Instruction(0x06);    // I/D : 1 Vs Sh : 0
}
#endif

void LCD_WritrChar(u8 ch)
{
	Write_Data(ch);
}

void LCD_WriteNum(s32 num)
{
	u8 i,str[16];
	s8 j;
	if(num>0)
	{
		for(i=0;num>0;i++)
		{
			str[i]=num%10+'0';
			num=num/10;
		}
		for(j=i-1;j>=0;j--)
		{
			Write_Data(str[j]);
		}
	}
	else if(num<0)
	{
		num=num*-1;
		for(i=0;num>0;i++)
		{
			str[i]=num%10+'0';
			num=num/10;
		}
		str[i]='-';
		for(j=i;j>=0;j--)
		{
			Write_Data(str[j]);
		}
	}
	else
	{
		Write_Data('0');
	}
	
}
void LCD_WriteBinary(u8 num)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		LCD_WriteNum(READ_BIT(num,(7-i)));
	}
}
void LCD_WriteHex(u8 num)
{
	u8 str[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	//first=;
	//second=(num>>4)&0xf;
	Write_Data(str[(num>>4)&0xf]);
	Write_Data(str[(num&0xf)]);
}

void LCD_WriteStr(c8*str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WritrChar(str[i]);
	}
}

void LCD_Clear(void)
{
	Write_Instruction(0x01);    // Clear
	_delay_ms(1);
}

void LCD_Cursor(u8 line,u8 cell)
{
	switch(line)
	{
		case 1:
		Write_Instruction(0x80|cell);
		break;
		case 2:
		Write_Instruction(0x80|cell|0x40);
		break;
	}
}

/*void LCD_Display(c8*str)
{
	s8 i,j,s,n;
	s=0;
	for(j=0;str[j];j++);
	for(i=1;i<32+j;i++)
	{
		LCD_Clear();
		if(i<=16+j)
		{
			LCD_Cursor(1,i-j);
			LCD_WriteStr(str);
		}
		if(i>=16)
		{
			LCD_Cursor(2,0);
			for(n=0;n<=s;n++)
			{
				LCD_WritrChar(str[j-1+n-s]);
			}
			s++;
		}
		_delay_ms(50);
	}
}
*/
void LCD_Display(c8*str)
{
	s8 i,j,n,c;
	c=0;
	for(j=0;str[j];j++);
	for(i=1;i<32+j;i++)
	{
		if(i<=16+j||c>=5)
		{
			LCD_Cursor(1,i-j-1);
			LCD_WritrChar(' ');
			LCD_Cursor(1,i-j);
			LCD_WriteStr(str);
		}
		if(i>=16)
		{
				LCD_Cursor(2,0);
				for(n=0;n<=c;n++)
				{
					LCD_WritrChar(str[j-1+n-c]);
				}
				c++;
		}
	}
}
void LCD_CGRAM(void)
{
	Write_Instruction(0x40);
	//Meshmesh 0
	Write_Data(0x07);
	Write_Data(0x07);
	Write_Data(0x07);
	Write_Data(0x04);
	Write_Data(0x1C);
	Write_Data(0x1C);
	Write_Data(0x18);
	Write_Data(0x08);
	//curve    1
	Write_Data(0x00);
	Write_Data(0x00);
	Write_Data(0x00);
	Write_Data(0x02);
	Write_Data(0x03);
	Write_Data(0x03);
	Write_Data(0x03);
	Write_Data(0x01);
	//arrow    2 
	Write_Data(0x04);
	Write_Data(0x05);
	Write_Data(0x05);
	Write_Data(0x15);
	Write_Data(0x1F);
	Write_Data(0x04);
	Write_Data(0x04);
	Write_Data(0x04);
	//Meshmesh2 3 
	Write_Data(0x01);
	Write_Data(0x03);
	Write_Data(0x05);
	Write_Data(0x0B);
	Write_Data(0x15);
	Write_Data(0x1B);
	Write_Data(0x1F);
	Write_Data(0x00);
	//curve2 4
	Write_Data(0xFF);
	Write_Data(0xFF);
	Write_Data(0xFF);
	Write_Data(0xFF);
	Write_Data(0xFF);
	Write_Data(0xFF);
	Write_Data(0xFF);
	Write_Data(0xFF);
	//arrow2 5
	Write_Data(0x00);
	Write_Data(0x00);
	Write_Data(0x08);
	Write_Data(0x1E);
	Write_Data(0x08);
	Write_Data(0x00);
	Write_Data(0x00);
	Write_Data(0x00);
	//dead 6
	Write_Data(0x00);
	Write_Data(0x04);
	Write_Data(0x08);
	Write_Data(0x07);
	Write_Data(0x0B);
	Write_Data(0x07);
	Write_Data(0x08);
	Write_Data(0x04);
}

/*void LCD_CGRAMPatern(u8*arr)
{
	Write_Instruction(0x40);
	for(u8 i=0;i<8;i++)
	{
		Write_Data(arr[i]);
	}
}*/

void LCD_MAND1(void)
{
	LCD_Cursor(1,0);
	LCD_WritrChar(0);
	LCD_Cursor(1,1);
	LCD_WritrChar(1);//const man1 position
	LCD_Cursor(1,15);
	LCD_WritrChar(3);
	LCD_Cursor(1,14);
	LCD_WritrChar(4);//const man2 position
	for(u8 i=2;i<15;i++)
	{
		LCD_Cursor(1,i);
		Write_Data(2);
		_delay_ms(25);
		LCD_Cursor(1,i);
		Write_Data(' ');
	}
	LCD_Cursor(1,15);
	Write_Data(6);
}

void LCD_MAND2(void)
{
	LCD_Cursor(1,0);
	LCD_WritrChar(0);
	LCD_Cursor(1,1);
	LCD_WritrChar(1);//const man1 position
	LCD_Cursor(1,15);
	LCD_WritrChar(3);
	LCD_Cursor(1,14);
	LCD_WritrChar(4);//const man2 position
	for(u8 i=13;i>0;i--)
	{
		LCD_Cursor(1,i);
		Write_Data(5);
		_delay_ms(25);
		LCD_Cursor(1,i);
		Write_Data(' ');
	}
	LCD_Cursor(1,0);
	Write_Data(6);
}

void LCD_DINASOUR_Down(void)
{
	LCD_Cursor(2,2);
	LCD_WritrChar(0);
	LCD_Cursor(2,1);
	LCD_WritrChar(1);
}

void LCD_DINASOUR_up(void)
{
	LCD_Cursor(1,2);
	LCD_WritrChar(0);
	LCD_Cursor(1,1);
	LCD_WritrChar(1);
}

void LCD_DINASOUR_Clear_up(void)
{
	LCD_Cursor(1,2);
	LCD_WritrChar(' ');
	LCD_Cursor(1,1);
	LCD_WritrChar(' ');
}
void LCD_DINASOUR_Clear_Down(void)
{
	LCD_Cursor(2,2);
	LCD_WritrChar(' ');
	LCD_Cursor(2,1);
	LCD_WritrChar(' ');
}

void LCD_1Tree(u8 i)
{
	LCD_Cursor(2,i);
	LCD_WritrChar(2);
	LCD_WritrChar(' ');
	_delay_ms(50);
	if(i==0)
	{
		_delay_ms(100);
		LCD_Cursor(2,0);
		LCD_WritrChar(2);
		_delay_ms(300);
		LCD_Cursor(2,0);
		LCD_WritrChar(' ');
	}
}

void LCD_2Tree(u8 i)
{
	LCD_Cursor(2,i);
	LCD_WritrChar(2);
	LCD_WritrChar(2);
	LCD_WritrChar(' ');
	if(i==0)
	{
		LCD_Cursor(2,0);
		LCD_WritrChar(2);
		LCD_WritrChar(' ');
		_delay_ms(300);
		LCD_Cursor(2,0);
		LCD_WritrChar(' ');
	}
}

void LCD_3Tree(u8 i)
{
	LCD_Cursor(2,i);
	LCD_WritrChar(2);
	LCD_WritrChar(2);
	LCD_WritrChar(2);
	LCD_WritrChar(' ');
	if(i==0)
	{
		LCD_Cursor(2,0);
		LCD_WritrChar(2);
		LCD_WritrChar(2);
		LCD_WritrChar(' ');
		_delay_ms(300);
		LCD_Cursor(2,0);
		LCD_WritrChar(' ');
		_delay_ms(300);
		LCD_WritrChar(' ');
	}
}

void LCD_KEY(void)
{
	LCD_Cursor(1,1);
	LCD_WriteStr("Calc Project");
	LCD_Cursor(2,1);
	LCD_WriteStr("Eng. Ahmed Saad");
	_delay_ms(2000);
	LCD_Cursor(1,1);
	LCD_WriteStr("               ");
	LCD_Cursor(2,1);
	LCD_WriteStr("               ");
}