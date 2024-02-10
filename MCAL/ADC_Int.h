/*
 * ADC_Int.h
 *
 * Created: 2/9/2024 1:18:07 AM
 *  Author: cpu
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
	}ADC_VolRef_t;

void ADC_Init(ADC_VolRef_t vref);
u16 ADC_Read(void);



#endif /* ADC_INT_H_ */