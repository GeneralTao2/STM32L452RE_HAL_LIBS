/*
 * ir_obstacle_sensor.h
 *
 *  Created on: Jun 26, 2020
 *      Author: ar725
 */

#ifndef LIBS_IR_OBSTACLE_SENSOR_IR_OBSTACLE_SENSOR_H_
#define LIBS_IR_OBSTACLE_SENSOR_IR_OBSTACLE_SENSOR_H_

/*
 * To use IR Obstacle sensor need to some things
 * 1. Set Input DC GPIO pin for sensor OUT connecting in code-generator;
 * 2. Configure potentiometer of sensor for needed surroundings.
 */

/* Same microcontroller settings */
#include "../Src/tools.h"

typedef struct IR_ObstacleSN_HandleTypeDef {

	/* Pin configs for sensor OUT connection */
	GPIO_PinConfigs IN;

	/*
	 * Contains current sensor state 0/1
	 * 0: obstacle found;
	 * 1: obstacle not found.
	 */
	uint8_t state;
} IR_ObstacleSN_HandleTypeDef;

uint8_t IR_ObstacleSN_ReadState(IR_ObstacleSN_HandleTypeDef *irsn);

uint8_t IR_ObstacleSN_GetState(IR_ObstacleSN_HandleTypeDef *irsn);

#endif /* LIBS_IR_OBSTACLE_SENSOR_IR_OBSTACLE_SENSOR_H_ */
