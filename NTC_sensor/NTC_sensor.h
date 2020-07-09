/*
 * NTC_sensor.h
 *
 *  Created on: Jul 9, 2020
 *      Author: ar725
 */

#ifndef LIBS_NTC_SENSOR_NTC_SENSOR_H_
#define LIBS_NTC_SENSOR_NTC_SENSOR_H_

#include "../Libs/dma_adc_sensor/dma_adc_sensor.h"
#include <math.h>

/*
 * For using this sensor need to do some things:
 * 1. Configure DMA ADC perephery;
 * 2. Call DMA ADC initialization function before main loop;
 * 3. Create NTC_Sensor_HnadleTypeDef structure and fill needed fields (!);
 * Sensor should be connected in a bridge circuit. So, need to use difference of
 * voltage in bridge trough differential ADC channel.
 */

/* Formula for differential ADC signal to temperature in Celsius conversion */
#define NTC_ADC_TO_C(x) (0.000000004*pow((x),3)-0.00001113*pow((x),2)+0.0290342*x+0.73380614)

typedef struct NTC_Sensor_HnadleTypeDef {

	/*! DMA ADC structure */
	DMA_ADC_Sensor_HandleTypeDef adc;

	/* Contains current temperature in Celsius */
	float temeperature;

} NTC_Sensor_HnadleTypeDef;

float NTC_ReadTemperatureInC(NTC_Sensor_HnadleTypeDef *ntc);

float NTC_GetTemperatureInC(NTC_Sensor_HnadleTypeDef *ntc);

#endif /* LIBS_NTC_SENSOR_NTC_SENSOR_H_ */
