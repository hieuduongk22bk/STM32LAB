/*
 * fsm_man.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#include "fsm_man.h"

int _first(int *first_time) {
	if (*first_time) {
		*first_time = 0;
		return 1;
	}
	return 0;
}
void fsm_man() {
	if (_first(&first_time)) {
		temp_red = red_time;
		temp_green = green_time;
		temp_amber = amber_time;
	}
	switch (mode) {
	case MANUAL_RED:
		if (man_timer >= 50) {
			toggle_led_red();
			display_seg(temp_red, temp_red);
			man_timer = 0;
		}

		if (button_flag[1] == 1) {
			button_flag[1] = 0;
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
			temp_red += 10;
		}

		break;
	case MANUAL_GREEN:
		if (man_timer >= 50) {
			toggle_led_green();
			display_seg(temp_green, temp_green);
			man_timer = 0;
		}

		if (button_flag[1] == 1) {
			button_flag[1] = 0;
			temp_green += 10;
		}

		break;
	case MANUAL_AMBER:
		if (man_timer >= 50) {
			toggle_led_amber();
			display_seg(temp_amber, temp_amber);
			man_timer = 0;
		}
		if (button_flag[1] == 1) {
			button_flag[1] = 0;
			temp_amber += 10;
		}

		break;
	}

	if (temp_red == (temp_green + temp_amber)) {
		no_toggle_error();
		if (button_flag[2] == 1) {
			button_flag[2] = 0;
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
			//init

			red_time = temp_red;
			green_time = temp_green;
			amber_time = temp_amber;
			mode = AUTO;
			auto_timer = 0;
			status = INIT;
			mode_light(0);
		}
	} else if (temp_red != (temp_green + temp_amber) && error_timer >= 50) {
		toggle_error();
		error_timer = 0;
	}
	man_timer += 1;
	error_timer += 1;
}
