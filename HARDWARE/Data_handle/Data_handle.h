#ifndef _Data_handle_H
#define _Data_handle_H

#include "main.h"
#include "delay.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "myusart1.h"
#include "dac8830.h"

void ADC_Start(void);
void ADC_Stop(void);
void Data_handle(void);
double lock(void) ;
void excel(void);
void Trisection(void);

#endif
