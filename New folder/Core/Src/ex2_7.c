/*
 * ex2_6.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ACER
 */


#include <ex2_7.h>


void init_ex27(){}
void ex27_run(){
	if(boolflag(0)==1){
		  updateClockBuffer();
		  setTimer(0,250);
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
}
