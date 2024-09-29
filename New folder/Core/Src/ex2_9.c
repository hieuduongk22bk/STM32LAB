/*
 * ex2_9.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ACER
 */

#include <ex2_9.h>

void init_ex29(){}

void ex29_run(){
	if(boolflag(0)==1){
		  updateClockBuffer();
		  setTimer(0,100);
	}
	if(boolflag(1)==1){
			  second++;
			  if(second >= 60){
				  second = 0;
				  minute++;
			  }
			  if(minute >= 60){
				  minute=0;
				  hour++;
			  }
			  if(hour >= 24){
				  hour =0;
			  }
			  setTimer(1,1000);
	}
	if(boolflag(2) == 1){
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
		setTimer(2,1000);
	}
	if(boolflag(3) == 1){
		if(index_led_matrix == 8) index_led_matrix=0;
		updateLEDMatrix( index_led_matrix++);
		setTimer(3,100);
	}
}
