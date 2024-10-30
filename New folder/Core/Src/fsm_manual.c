#include "fsm_manual.h"

void init_fsm_man() {
}
void fsm_man_run() {
	switch (status) {
	case MAN_GREEN_RED:
		if (button_flag[0] == 1) {
			status = MAN_AMBER_RED;
			setTimer(1, 10000);
			setTimer(4, 250);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[1] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			green_time1 += 1000;
			red_time1 += 1000;
			if (red_time1 >= 100000) {
				green_time1 = 1000;
				red_time1 = green_time1 + amber_time1;
			}
			setTimer(1, 10000);
			button_flag[1] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[2] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			button_flag[2] = 0;
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(1) == 1) {
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(green_time1 / 1000, red_time1 / 1000);
			setTimer(2, 250);
		}
		if (checkTimer(4) == 1){
			toggle_led_green_red();
			setTimer(4,250);
		}
		break;
	case MAN_AMBER_RED:
		if (button_flag[0] == 1) {
			status = MAN_RED_GREEN;
			setTimer(1, 10000);
			setTimer(4, 250);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[1] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			amber_time1 += 1000;
			red_time1 += 1000;
			if (red_time1 >= 100000) {
				amber_time1 = 1000;
				red_time1 = green_time1 + amber_time1;
			}
			setTimer(1, 10000);
			button_flag[1] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[2] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			button_flag[2] = 0;
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(1) == 1) {
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(amber_time1 / 1000, red_time1 / 1000);
			setTimer(2, 250);
		}
		if (checkTimer(4) == 1){
			toggle_led_amber_red();
			setTimer(4,250);
				}
		break;
	case MAN_RED_GREEN:
		if (button_flag[0] == 1) {
			status = MAN_RED_AMBER;
			setTimer(1, 10000);
			setTimer(4, 250);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[1] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			green_time2 += 1000;
			red_time2 += 1000;
			if (red_time2 >= 100000) {
				green_time2 = 1000;
				red_time2 = green_time2 + amber_time2;
			}
			setTimer(1, 10000);
			button_flag[1] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[2] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			button_flag[2] = 0;
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(1) == 1) {
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(red_time2 / 1000, green_time2 / 1000);
			setTimer(2, 250);
		}
		if (checkTimer(4) == 1){
			toggle_led_red_green();
			setTimer(4,250);
				}
		break;
	case MAN_RED_AMBER:
		if (button_flag[0] == 1) {
			status = MAN_GREEN_RED;
			setTimer(1, 10000);
			setTimer(4, 250);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[1] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			amber_time2 += 1000;
			red_time2 += 1000;
			if (red_time2 >= 100000) {
				amber_time2 = 1000;
				red_time2 = green_time2 + amber_time2;
			}
			setTimer(1, 10000);
			button_flag[1] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		if (button_flag[2] == 1) {
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			button_flag[2] = 0;
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(1) == 1) {
			status = GREEN_RED;
			local_green_time1 = green_time1 / 1000;
			local_red_time1 = red_time1 / 1000;
			local_amber_time1 = amber_time1 / 1000;
			setTimer(0, green_time1);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			setTimer(2, 10);
			setTimer(3, 1000);
		}
		if (checkTimer(2) == 1) {
			//Update Display;
			update7segBuffer(red_time2 / 1000, amber_time2 / 1000);
			setTimer(2, 250);
		}
		if (checkTimer(4) == 1){
			toggle_led_red_amber();
			setTimer(4,250);
				}
		break;
	default:
		break;

	}
}
