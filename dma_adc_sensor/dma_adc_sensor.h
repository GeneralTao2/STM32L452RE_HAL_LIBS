/*
 * temperature_sensor.h
 *
 *  Created on: Jun 23, 2020
 *      Author: ar725
 */

#ifndef LIBS_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_H_
#define LIBS_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_H_

/* 	For using this library need to do several things
 * in code-generator:
 * 1. Allow some ADC channels and configure them;
 * 2. Add ADC perephery to DMA Request with Circular Mode
 * Half World Data Width;
 * 3. In ADC Parameter Settings set:
 * 		a) Continuous Conversion Mode;
 * 		b) DMA Continuous Requests.
 */

/* Here is some microcontroller settings */
#include "../tools/tools.h"

/* Length of buffer with ADC values */
#define DMA_ADC_BUF_LEN 100

/* Buffer with ADC values */
static volatile uint16_t DMA_ADC_Buf[DMA_ADC_BUF_LEN];

/* Quantity of used ADC channels */
static uint32_t quantityOfChannels;

/* Structure with ADC channel settings */
typedef struct DMA_ADC_Sensor_HandleTypeDef {

	/* Serial number of using channel (in order of used channels) [0, MAX_CHANNEL] */
	uint16_t numberOfChannel;

	/* Contains average ADC value of current channel */
	uint32_t averageValue;

} DMA_ADC_Sensor_HandleTypeDef;

void DMA_ADC_Sensor_Init(ADC_HandleTypeDef *hadc);

uint16_t DMA_ADC_Sensor_CalcAverageValue(DMA_ADC_Sensor_HandleTypeDef *channel);

uint16_t DMA_ADC_Sensor_GetAverageValue(DMA_ADC_Sensor_HandleTypeDef *channel);

uint16_t DMA_ADC_Sensor_GetValue(DMA_ADC_Sensor_HandleTypeDef *channel);


#endif /* LIBS_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_H_ */
