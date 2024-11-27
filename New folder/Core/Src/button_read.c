/*
 * button_read.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */
#include"button_read.h"

void button_mode(){
	getKeyInput();
	if(button_flag[0]==1){
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		//init
		reset_led();
		//fsm
		switch(mode){
		case AUTO:
			mode = MANUAL_RED;
			mode_light(1);
			break;
		case MANUAL_RED:

			mode = MANUAL_GREEN;
			mode_light(2);
			break;
		case MANUAL_GREEN:

			mode = MANUAL_AMBER;
			mode_light(3);
			break;
		case MANUAL_AMBER:
			mode = MANUAL_RED;
			mode_light(1);
			break;

		}

	}

}
