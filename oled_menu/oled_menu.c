/*
 * oled_menu.c
 *
 *  Created on: Jul 9, 2020
 *      Author: ar725
 */

#include "oled_menu.h"

void OLED_PrintMenu(void) {
	if(HAL_GetTick() - LCD_progTime > LCD_PROGTIME_DELAY) {
		ssd1306_Fill(Black);
		switch(encoder.tumblerState % 3) {
		case 0:
			OLED_Print_irsn();
			break;
		case 1:
			OLED_Print_ntc();
			break;
		case 2:
			OLED_Print_hcsr();
			break;
		}
		ssd1306_UpdateScreen();
		LCD_progTime = HAL_GetTick();
	}
}

void OLED_Print_hcsr(void) {
	ssd1306_SetCursor(0, 5);
	ssd1306_WriteString("HC-SR04", Font_16x26, White);

	ssd1306_SetCursor(0, 30);
	sprintf(LCD_Buffer, "Dist: %dcm", HCSR04_GetDistance(&hcsr));
	ssd1306_WriteString(LCD_Buffer, Font_11x18, White);
}

void OLED_Print_ntc(void) {
	ssd1306_SetCursor(0, 5);
	ssd1306_WriteString("NTC", Font_16x26, White);

	ssd1306_SetCursor(0, 30);
	sprintf(LCD_Buffer, "Temp: %.1f", NTC_ReadTemperatureInC(&ntc));
	ssd1306_WriteString(LCD_Buffer, Font_11x18, White);
}

void OLED_Print_irsn(void) {
	ssd1306_SetCursor(0, 5);
	ssd1306_WriteString("IR", Font_16x26, White);

	ssd1306_SetCursor(0, 30);
	sprintf(LCD_Buffer, "State: %s", IR_ObstacleSN_ReadState(&irsn) ? "No" : "Yes");
	ssd1306_WriteString(LCD_Buffer, Font_11x18, White);
}
