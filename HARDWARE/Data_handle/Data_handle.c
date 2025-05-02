#include "Data_handle.h"

#define sample 	200

extern uint16_t num 						;

double 			data[200] = {0}				;
uint16_t 		ADC_GetValue[sample] = {0}	;

void ADC_Start(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)ADC_GetValue, sample);
}

void ADC_Stop(void)
{
	HAL_ADC_Stop_DMA(&hadc1);
}

void Data_handle(void)
{
	uint8_t i;
	uint32_t data_max = 0;
	for(i = 0;i<sample;i++)
	{
		if(data_max < ADC_GetValue[i])
			data_max = ADC_GetValue[i];
	}
	data[num] = 3.3f*(double)data_max/4095;
}

double lock(void)
{
	double data_min = 3.3;
	double data_lock = 0;
	uint16_t i =0;
	for(i=0;i<num;i++)
	{
		if(data_min > data[i])
		{
			data_min = data[i];
			data_lock = i;
		}
	}
	return data_lock;
}

void excel(void)
{
	uint16_t i =0;
	for(i=0;i<num;i++)
	{
		printf("%.2f \r\n",data[i]);		
	}	
	printf("打表结束\r\n");
}

//三分查找
void Trisection(void)
{
	uint16_t l = 0   ,ll;	
	uint16_t mid = 0;
	uint16_t r = num ,rr;	
	
	while(r-l>1)
	{
		mid=(l+r)/2;
		ll=(l+mid)/2;
		rr=(mid+r)/2;
		if(data[ll]>data[rr]) l=ll;
		else r=rr;
	}
	
	printf("稳定位置 = %.d\r\n",l);
	printf("稳定位置电压 = %.f\r\n",(float)l/50);

}
