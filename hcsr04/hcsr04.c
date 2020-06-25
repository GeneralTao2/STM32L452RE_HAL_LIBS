/*
 * hcsr04.c
 *
 *  Created on: Jun 20, 2020
 *      Author: ar725
 */
#include "hcsr04.h"

/* Calculates and returns wave reflection time us (micro second) */
uint32_t HCSR04_ReadEchoTime(HCSR04_HandleTypeDef *hcsr04) {
	uint32_t localTime = 0;

	/* Sending 10 us high pulse to start measurement */
	HAL_GPIO_WritePin(hcsr04->trig.GPIO, hcsr04->trig.PIN, GPIO_PIN_SET);
	DWT_Delay(10);
	HAL_GPIO_WritePin(hcsr04->trig.GPIO, hcsr04->trig.PIN, GPIO_PIN_RESET);

	/* When sensor detects Echo Back pulse beginning,
	 * starts to measure pulse width.
	 * Width corresponds distance.
	 */
	while(!(HAL_GPIO_ReadPin(hcsr04->echo.GPIO, hcsr04->echo.PIN)));
	while(HAL_GPIO_ReadPin(hcsr04->echo.GPIO, hcsr04->echo.PIN) &&
			localTime < HCSR04_US_TIMEOUT) {
		localTime++;
		DWT_Delay(1);
	}
	return localTime;
}

/* Calculates and returns distance in cm */
uint32_t HCSR04_ReadDistance(HCSR04_HandleTypeDef *hcsr04) {
	hcsr04->distance = HCSR04_ReadEchoTime(hcsr04) * 0.034;
	return hcsr04->distance;
}

/* Returns current saved distance */
uint32_t HCSR04_GetDistance(HCSR04_HandleTypeDef *hcsr04) {
	return hcsr04->distance;
}

