/*
 * ADC_Prg.c
 *
 * Created: 2/9/2024 1:17:36 AM
 *  Author: Ahmed Saad
 */ 
#include "StdTybes.h"
#include "MemMap.h"
#include "ADC_Int.h"

void ADC_Init(ADC_VolRef_t vref)
{
	//moods
	//vref
	switch(vref)
	{
		case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS1);
		CLEAR_BIT(ADMUX,REFS0);
		break;
		case VREF_AVCC:
		CLEAR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
	}
	
	
	//ADC ENABLE
	SET_BIT(ADCSRA,ADEN);
}