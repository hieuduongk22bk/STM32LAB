/*
 * fsm_auto.c
 *
 *  Created on: Oct 8, 2024
 *      Author: ACER
 */

#include"fsm_auto.h"


void fsm_auto_run() {
	switch (status) {
	case INIT:
		//TODO INIT
		if (1) {
			status = GREEN_RED;

			local_green_time = green_time/1000;
			local_red_time = red_time/1000;
			local_amber_time = amber_time/1000;

			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)

			setTimer(0, green_time);
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		break;
	case GREEN_RED:
		led_green_red();
		if (checkTimer(3) == 1) {
			local_green_time--;
			local_red_time--;
			if(local_green_time <= 0) local_green_time = green_time/1000;
			if(local_red_time <= 0) local_red_time = red_time/1000;
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(local_green_time, local_red_time);
			setTimer(2, 250);
		}
		if (checkTimer(0) == 1) {
			status = AMBER_RED;
			setTimer(0, amber_time);
		}

		if(button_flag[0]==1){
		status = MAN_GREEN_RED;
		setTimer(1,10000);
		setTimer(2,10);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		break;
	case AMBER_RED:
		led_amber_red();
		if (checkTimer(0) == 1) {
			status = RED_GREEN;
			setTimer(0, green_time);
		}
		if (checkTimer(3) == 1) {
			local_amber_time--;
			local_red_time--;
			if(local_amber_time <= 0) local_amber_time = amber_time/1000;
			if(local_red_time <= 0) local_red_time = red_time/1000;
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(local_amber_time , local_red_time);
			setTimer(2, 250);
		}

		if(button_flag[0]==1){
				status = MAN_GREEN_RED;
				setTimer(1,10000);
				setTimer(2,10);
				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
				button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
				}

		break;
	case RED_GREEN:
		led_red_green();
		if (checkTimer(0) == 1) {
			status = RED_AMBER;
			setTimer(0, amber_time);
		}
		if (checkTimer(3) == 1) {
			local_green_time--;
			local_red_time--;
			if(local_green_time <= 0) local_green_time = green_time/1000;
			if(local_red_time <= 0) local_red_time = red_time/1000;
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(local_red_time, local_green_time);
			setTimer(2, 250);
		}

		if(button_flag[0]==1){
				status = MAN_GREEN_RED;
				setTimer(1,10000);
				setTimer(2,10);
				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
				button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
				}
		break;
	case RED_AMBER:
		led_red_amber();
		if (checkTimer(0) == 1) {
			status = GREEN_RED;
			setTimer(0, green_time);
		}
		if (checkTimer(3) == 1) {
			local_amber_time--;
			local_red_time--;
			if(local_amber_time <= 0) local_amber_time = amber_time/1000;
			if(local_red_time <= 0) local_red_time = red_time/1000;
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(local_red_time, local_amber_time);
			setTimer(2, 250);
		}

		if(button_flag[0]==1){
				status = MAN_GREEN_RED;
				setTimer(1,10000);
				setTimer(2,10);
				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
				button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
				}
		break;
	default:
		break;
	}
}
