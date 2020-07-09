/*
 * NTC_sensor.c
 *
 *  Created on: Jul 9, 2020
 *      Author: ar725
 */

#include "../NTC_sensor/NTC_sensor.h"

/* Calculates and returns temperature in Celsius */
float NTC_ReadTemperatureInC(NTC_Sensor_HnadleTypeDef *ntc) {
	ntc->temeperature = NTC_ADC_TO_C( DMA_ADC_Sensor_CalcAverageValue(&ntc->adc) );
	return ntc->temeperature;
}

/* Returns temperature in Celsius */
float NTC_GetTemperatureInC(NTC_Sensor_HnadleTypeDef *ntc) {
	return ntc->temeperature;
}
