/*
 * KEYPAD_Prg.c
 *
 * Created: 2/3/2024 9:04:04 PM
 *  Author: cpu
 */ 
#define KEYPAD_PROG 0
#include "StdTybes.h"
#include "DIO_Int.h"
#include "KEYPAD_Int.h"
#include "KEYPAD_Cfg.h"
#include "LCD_Int.h"
#define  F_CPU   8000000
#include  <util/delay.h>


void KEYPAD_Init(void)
{
	u8 i;
	for (i=0;i<Row;i++)
	{
		DIO_WritePin(KFIRST_OUTPUT+i,HIGHT);
	}
}

u8 KEYPAD_Getkey(void)
{
	u8 r,c,key=NO_KEY;
	for(r=0;r<Row;r++)
	{
		DIO_WritePin(KFIRST_OUTPUT+r,LOW);
		for(c=0;c<Col;c++)
		{
			if(DIO_ReadPin(KFIRST_INPUT+c)==0)
			{
				key=KeysArray[r][c];
				_delay_ms(10);
				while(DIO_ReadPin(KFIRST_INPUT+c)==0);
				_delay_ms(10);
			}
		}
		DIO_WritePin(KFIRST_OUTPUT+r,HIGHT);
	}
	return key;
}

u16 KEYPAD_CALC(u16*arr)
{
	LCD_Cursor(2,0);
	u8 s=0,n=0;
	u16 Result;
	u8 Arr_S[7];
	u16 Arr_N[7];
	for (u8 i=0;arr[i];i++)
	{
		if ((i%2)==1)
		{
			Arr_S[s]=arr[i];
			//LCD_WritrChar(Arr_S[s]);
			s++;
			//LCD_WriteNum(s);
		}
		if ((i%2)==0)
		{
			Arr_N[n]=arr[i];
			//LCD_WriteNum(Arr_N[n]);
			n++;
		}
	}
	for (u8 i=0;i<=s;i++)
	{
		if(Arr_S[i]=='*')
		{
			Arr_N[i]=Arr_N[i]*Arr_N[i+1];
			u8 j;
			for (j=i+1;j<s;j++)
			{
				Arr_N[j]=Arr_N[j+1];
				Arr_S[j-1]=Arr_S[j];
			}
			Arr_S[j-1]=Arr_S[j];
			s--;
			n--;
			i--;
		}
		else if(Arr_S[i]=='/')
		{
			Arr_N[i]=Arr_N[i]/Arr_N[i+1];
			u8 j;
			for (j=i+1;j<s;j++)
			{
				Arr_N[j]=Arr_N[j+1];
				Arr_S[j-1]=Arr_S[j];
			}
			Arr_S[j-1]=Arr_S[j];
			s--;
			n--;
			i--;
		}
	}
	Result=Arr_N[0];
	for (u8 i=0;i<=s;i++)
	{
		if(Arr_S[i]=='+')
		{
			Result+=Arr_N[i+1];
		}
		else if (Arr_S[i]=='-')
		{
			Result-=Arr_N[i+1];
		}
	}
	return Result;	
}
u8 f1=0,f2=0,f3=0,f=0,Result_f=0;
u8 g1=0,g2=0,g3=0,g=0;
u8 num=0;
u8 Hex[2],Bin[8];
void Convert_input(void)
{
	if (!f)
	{
		LCD_Cursor(1,1);
		LCD_WriteStr("Select Input:");
		LCD_Cursor(2,0);
		LCD_WriteStr("1)H");
		LCD_Cursor(2,6);
		LCD_WriteStr("2)D");
		LCD_Cursor(2,13);
		LCD_WriteStr("3)B");
		u8 k;
		k=KEYPAD_Getkey();
		if(k!=NO_KEY)
		{
			if (k=='1')
			{
				f1=1;
				f=1;
				LCD_Clear();
			}
			else if (k=='2')
			{
				f2=1;
				f=1;
				LCD_Clear();
			}
			else if (k=='3')
			{
				f3=1;
				f=1;
				LCD_Clear();
			}
		}
	}
}
void Convert_output(void)
{
	if (f&&!g)
	{
		LCD_Cursor(1,1);
		LCD_WriteStr("Select Output:");
		LCD_Cursor(2,0);
		LCD_WriteStr("1)H");
		LCD_Cursor(2,6);
		LCD_WriteStr("2)D");
		LCD_Cursor(2,13);
		LCD_WriteStr("3)B");
		u8 k;
		k=KEYPAD_Getkey();
		if(k!=NO_KEY)
		{
			if (k=='1')
			{
				g1=1;
				g=1;
			}
			else if (k=='2')
			{
				g2=1;
				g=1;
			}
			else if (k=='3')
			{
				g3=1;
				g=1;
			}
		}
	}
}
void Store_Input(void)
{
	if (f==1&&g==1&&Result_f==0)
	{
		LCD_Clear();
		u8 i=0;
		LCD_Cursor(1,0);
		if (f1==1)
		{
			LCD_WriteStr("H:");
		}
		else if (f2==1)
		{
			LCD_WriteStr("D:");
		}
		else if (f3==1)
		{
			LCD_WriteStr("B:");
		}
		u8 k;
		while(Result_f==0)
		{
			k=KEYPAD_Getkey();
			if(k!=NO_KEY)
			{
				if (f1==1&&k!='=')
				{
					LCD_WritrChar(k);
					Hex[i]=k;
					i++;
				}
				else if (f2==1&&k!='=')
				{
					LCD_WritrChar(k);
					num=num*10+k-'0';
				}
				else if (f3==1&&k!='=')
				{
					LCD_WritrChar(k);
					if (k=='1')
					{
						Bin[i]=1;
					}
					else if(k=='0')
					{
						Bin[i]=0;
					}
					i++;
				}
				if (k=='=')
				{
					Result_f=1;
					break;
				}
				if (k=='c')
				{
					f=0;
					g=0;
					f1=0;
					f2=0;
					f3=0;
					g1=0;
					g2=0;
					g3=0;
				    LCD_Clear();
					break;
				}
			}
		}
	}
}
u8 final_result=0,p_Result=0;
void Get_Out(void)
{
	if (Result_f==1)
	{
		u8 i=0;
		LCD_Cursor(2,0);
		if (g1==1)
		{
			LCD_WriteStr("H:");
		}
		else if (g2==1)
		{
			LCD_WriteStr("D:");
		}
		else if (g3==1)
		{
			LCD_WriteStr("B:");
		}
		u8 k;
		while(Result_f==1)
		{
			if (f1==1)
			{
				if (g2==1||g3==1)
				{
					if (Hex[0]=='A')
					{
						final_result=0XA0;
					}
					else if (Hex[0]=='B')
					{
						final_result=0XB0;
					}
					else if (Hex[0]=='C')
					{
						final_result=0XC0;
					}
					else if (Hex[0]=='D')
					{
						final_result=0XD0;
					}
					else if (Hex[0]<='9'&&Hex[0]>='0')
					{
						final_result=(Hex[0]-'0')<<4;
					}
					if (Hex[1]=='A')
					{
						final_result=final_result+0X0A;
					}
					else if (Hex[1]=='B')
					{
						final_result=final_result+0X0B;
					}
					else if (Hex[1]=='C')
					{
						final_result=final_result+0X0C;
					}
					else if (Hex[1]=='D')
					{
						final_result=final_result+0X0D;
					}
					else if (Hex[1]<='9'&&Hex[0]>='0')
					{
						final_result=final_result+(Hex[1]-'0');
					}
					if(p_Result==0&&g2==1)
					{
						LCD_WriteNum(final_result);
						p_Result=1;
					}
					if(p_Result==0&&g3==1)
					{
						LCD_WriteBinary(final_result);
						p_Result=1;
					}
				}
			}
			if (f2==1)
			{
				if (g1==1||g3==1)
				{
					if(p_Result==0&&g1==1)
					{
						LCD_WriteHex(num);
						p_Result=1;
					}
					if(p_Result==0&&g3==1)
					{
						LCD_WriteBinary(num);
						p_Result=1;
					}
				}
			}
			if (f3==1)
			{
				if (g1==1||g2==1)
				{
					for (i=0;i<=7;i++)
					{
						final_result=final_result|(Bin[i]<<(7-i));
					}
					if(p_Result==0&&g1==1)
					{
						LCD_WriteHex(final_result);
						p_Result=1;
					}
					if(p_Result==0&&g2==1)
					{
						LCD_WriteNum(final_result);
						p_Result=1;
					}
				}
			}
			k=KEYPAD_Getkey();
			if(k=='c')
			{
				p_Result=0;
				Result_f=0;
				Hex[0]=0;
				Hex[1]=0;
				for (i=0;i<=7;i++)
				{
					Bin[i]=0;
				}
				num=0;
				i=0;
				final_result=0;
			}
		}
	}
}

void Runable(void)
{
	Convert_input();
	Convert_output();
	Store_Input();
	Get_Out();
}

void converter(void)
{
	LCD_Cursor(1,1);
	LCD_WriteStr("CONV Project");
	LCD_Cursor(2,1);
	LCD_WriteStr("ENG.Ahmed Saad");
	_delay_ms(2000);
	LCD_Clear();
}