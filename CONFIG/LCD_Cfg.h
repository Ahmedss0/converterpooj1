/*
 * LCD_Cfg.h
 *
 * Created: 1/18/2024 4:02:56 AM
 *  Author: cpu
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define RS         PIND5//PINA1
#define EN         PIND4//PINA2
#define LCD_PORT   PA

#define D7         PIND0//PINA6
#define D6         PIND1//PINA5
#define D5         PIND2//PINA4
#define D4         PIND3//PINA3

#define _4_Bit_      1
#define _8_Bit_      0



/* _4_Bit_ : _8_Bit_ */
#define LCD_Mode    _4_Bit_

#endif /* LCD_CFG_H_ */