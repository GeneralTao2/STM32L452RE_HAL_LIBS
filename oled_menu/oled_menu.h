/*
 * oled_menu.h
 *
 *  Created on: Jul 9, 2020
 *      Author: ar725
 */

#ifndef LIBS_OLED_MENU_OLED_MENU_H_
#define LIBS_OLED_MENU_OLED_MENU_H_

#include "../Libs/NTC_sensor/NTC_sensor.h"
#include "../Libs/ir_obstacle_sensor/ir_obstacle_sensor.h"
#include "../Libs/hcsr04/hcsr04.h"
#include "../Libs/encoder/encoder.h"
#include "../Libs/ssd1306/ssd1306.h"
#include <stdio.h>

extern Encoder_HandleTypeDef encoder;
extern IR_ObstacleSN_HandleTypeDef irsn;
extern HCSR04_HandleTypeDef hcsr;
extern NTC_Sensor_HnadleTypeDef ntc;

void OLED_PrintMenu(void);

void OLED_Print_irsn(void);

void OLED_Print_hcsr(void);

void OLED_Print_ntc(void);

/*void LCD_PrintEncoderState() {
	if(HAL_GetTick() - LCD_progTime > LCD_PROGTIME_DELAY) {
		ssd1306_Fill(Black);

		ssd1306_SetCursor(0, 5);
		sprintf(LCD_Buffer, "Echo: %d", 2);
		ssd1306_WriteString(LCD_Buffer, Font_11x18, White);

		ssd1306_SetCursor(0, 23);
		sprintf(LCD_Buffer, "Value: %d", val);
		ssd1306_WriteString(LCD_Buffer, Font_11x18, White);

		ssd1306_SetCursor(0, 40);
		sprintf(LCD_Buffer, "Tumbler: %d", encoder.tumblerState);
		ssd1306_WriteString(LCD_Buffer, Font_11x18, White);

		ssd1306_SetCursor(0, 40);
		sprintf(LCD_Buffer, "State: ");
		strcat(LCD_Buffer, encoder.buttonState ? "ON" : "OFF");
		ssd1306_WriteString(LCD_Buffer, Font_11x18, White);

		ssd1306_UpdateScreen();

		LCD_progTime = HAL_GetTick();
	}
}*/

#endif /* LIBS_OLED_MENU_OLED_MENU_H_ */
