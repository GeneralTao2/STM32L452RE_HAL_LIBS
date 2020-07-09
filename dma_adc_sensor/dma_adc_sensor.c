/*
 * temperature_sensor.c
 *
 *  Created on: Jun 23, 2020
 *      Author: ar725
 */
#include "dma_adc_sensor.h"

/* Initialization of ADC periphery using DMA */
void DMA_ADC_Sensor_Init(ADC_HandleTypeDef *hadc) { /* ??? */
	quantityOfChannels = hadc->Init.NbrOfConversion;
	HAL_ADC_Start_DMA(hadc, (uint32_t*)DMA_ADC_Buf, DMA_ADC_BUF_LEN);
}

/* Returns current value of ADC channel */
uint16_t DMA_ADC_Sensor_GetValue(DMA_ADC_Sensor_HandleTypeDef *channel) {
	return DMA_ADC_Buf[channel->numberOfChannel];
}

/* Calculates and returns average value of ADC channel */
uint16_t DMA_ADC_Sensor_CalcAverageValue(DMA_ADC_Sensor_HandleTypeDef *channel) {
	uint32_t summ = 0;
	uint16_t i;
	for(i=channel->numberOfChannel; i<DMA_ADC_BUF_LEN; i+=quantityOfChannels) {
		summ += DMA_ADC_Buf[i];
	}
	channel->averageValue = summ / i;
	return channel->averageValue;
}

/* Returns average value value of ADC channel */
uint16_t DMA_ADC_Sensor_GetAverageValue(DMA_ADC_Sensor_HandleTypeDef *channel) {
	return channel->averageValue;
}
