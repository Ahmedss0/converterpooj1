/*
 * DIO_Priv.h
 *
 * Created: 12/8/2023 3:20:54 AM
 *  Author: cpu
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

static void DIO_InitPin(DIO_Pin_t pin,DIO_PinStatus_t status);
extern const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS];


#endif /* DIO_PRIV_H_ */