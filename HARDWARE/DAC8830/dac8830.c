#include "dac8830.h"


void delay_s_us(void)
{
	uint8_t i=48;
	while(i--);
}


void DAC8830_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct = {0};
	 
	 __HAL_RCC_GPIOB_CLK_ENABLE();
	 GPIO_InitStruct.Pin=GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
	 GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
	 GPIO_InitStruct.Pull=GPIO_NOPULL;
	 GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_MEDIUM;
	 
	 HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	 SPI_LE_1;
	 SPI_CLK_0;
	 SPI_SDI_0;
	
}
void DAC8830_Write16Byte(uint16_t byte)
{
	uint8_t i=0;
	SPI_LE_0;
	delay_s_us();
	for(i=0;i<16;i++){
		if(byte&0x8000){
			SPI_SDI_1;
		}
		else{
			SPI_SDI_0;
		}
		byte<<=1;
		delay_s_us();
		SPI_CLK_1;
		delay_s_us();
		SPI_CLK_0;
	}
	SPI_LE_1;
}
void DAC8830_WriteDate(double date)
{
	uint16_t a=0;
	a=(uint16_t)(65535.0*(date/2.5));
	DAC8830_Write16Byte(a);
}
void DAC8830_WriteAll(void)
{
	
	DAC8830_Write16Byte(30000);
	
}

