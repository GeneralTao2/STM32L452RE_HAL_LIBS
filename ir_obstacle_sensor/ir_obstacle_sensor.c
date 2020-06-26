/*
 * ir_obstacle_sensor.c
 *
 *  Created on: Jun 26, 2020
 *      Author: ar725
 */
#include "ir_obstacle_sensor.h"

/*
* Reads and returns current sensor state 0/1
* 0: obstacle found;
* 1: obstacle not found.
*/
uint8_t IR_ObstacleSN_ReadState(IR_ObstacleSN_HandleTypeDef *irsn) {
	irsn->state = HAL_GPIO_ReadPin(irsn->IN.GPIO, irsn->IN.PIN);
	return irsn->state;
}

/*
* Returns current sensor state 0/1
* 0: obstacle found;
* 1: obstacle not found.
*/
uint8_t IR_ObstacleSN_GetState(IR_ObstacleSN_HandleTypeDef *irsn) {
	return irsn->state;
}

