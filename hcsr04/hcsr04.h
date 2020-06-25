/*
 * hcsr04.h
 *
 *  Created on: Jun 20, 2020
 *      Author: ar725
 */

#ifndef LIBS_HCSR04_HCSR04_H_
#define LIBS_HCSR04_HCSR04_H_

/*
 * To use HC-SR04 need to do some things in code-generator:
 * 1. Set Output and Inpit GPIO pin to Trigg and Echo respectively;
 * 2. Use high frequency (> 70 MHz) in corresponding periphery.
 */

/* Same microcontroller settings */
#include "../Src/tools.h"

/* Allows to use 1 us ((micro second) delays
 * https://github.com/keatis/dwt_delay
 */
#include "../dwt_delay/dwt_delay.h"

/* Measurement timeout in us (micro seconds) */
#define HCSR04_US_TIMEOUT 3000000

/* HCSR04 pin settings */
typedef struct HCSR04_HandleTypeDef {
	/* Trigger pin configs */
	GPIO_PinConfigs trig;

	/* Echo pin configs */
	GPIO_PinConfigs echo;

	/* Contains distance in cm (to an obstacle) */
	uint32_t distance;
} HCSR04_HandleTypeDef;

uint32_t HCSR04_ReadEchoTime(HCSR04_HandleTypeDef *hcsr04);

uint32_t HCSR04_ReadDistance(HCSR04_HandleTypeDef *hcsr04);

uint32_t HCSR04_GetDistance(HCSR04_HandleTypeDef *hcsr04);

#endif /* LIBS_HCSR04_HCSR04_H_ */
