#ifndef _DAC8830_H
#define _DAC8830_H

#include "main.h"




#define SPI_CLK_1 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET)
#define SPI_CLK_0 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET)

#define SPI_SDI_1 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET)
#define SPI_SDI_0 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET)

#define SPI_LE_1 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET)
#define SPI_LE_0 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET)

void DAC8830_Init(void);
void DAC8830_Write16Byte(uint16_t byte);
void delay_s_us(void);
void DAC8830_WriteDate(double date);

void DAC8830_WriteAll(void);


#endif

