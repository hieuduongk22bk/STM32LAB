/*
 * fsm_auto.c
 *
 *  Created on: Oct 8, 2024
 *      Author: ACER
 */

#include"fsm_auto.h"

int local_red_time,local_green_time,local_amber_time;

void fsm_auto_run(){

	local_red_time = red_time;
	local_green_time = green_time;
	local_amber_time = amber_time;

switch(status){
	case INIT:
		//TODO INIT
		if(1){
			status = GREEN_RED;
			setTimer(0,red_time*1000);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai GREEN_RED button=0 (vi GREEN_RED co doi nut nhan)
			setTimer(2,10);
		}
		break;
	case GREEN_RED:
		led_green_red();
		update7segBuffer(local_green_time,local_red_time);

		if(checkTimer(2)==1){
			//Update Display;
			local_green_time--;
			local_red_time--;
			setTimer(2,1000);
		}
		if(checkTimer(0)==1){
			status = AMBER_RED;
			setTimer(0,2000);
		}
		if(button_flag[0]==1){
			status = MAN_GREEN_RED;
			setTimer(1,10000);
			button_flag[0] = 0; // chuan bi cho trang thai nut nhan, dam bao truoc trang thai tiep theo button=0
		}
		break;
	case AMBER_RED:
		break;
	case RED_GREEN:
		break;
	case RED_AMBER:
		break;
	default:
		break;
	}
}
