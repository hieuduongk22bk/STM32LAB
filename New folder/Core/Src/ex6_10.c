/*
 * ex3.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ACER
 */

#include "ex6_10.h"

void init_ex6_10(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
			|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
			|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15);
}
uint16_t pins[12]={ GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7
		,GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12
		,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};

int counter6=4;

void ex6_run(){
	if(counter6>=15) counter6=4;
	GPIOA->ODR = 0x0001 << counter6;
	counter6++;
}
void clearAllClock(){
	GPIOA->ODR=0x00;
}
void setNumberOnClock(int num){
	HAL_GPIO_WritePin(GPIOA, pins[num], SET);
}

void clearNumberOnClock(int num){
	HAL_GPIO_WritePin(GPIOA, pins[num], RESET);
}

int second=55;
int minute=49;
int hour=0;

void init_ex10(){
	setNumberOnClock(second);
	setNumberOnClock(minute);
	setNumberOnClock(hour);
}
void ex10_run() {

	clearAllClock();
	setNumberOnClock(second / 5);
	setNumberOnClock(minute / 5);
	setNumberOnClock(hour % 12);

    second++;
    if (second >= 60) {
    	minute++;
    	second = 0;
    }
    if(minute >= 60) {
    	hour++;
    	minute = 0;

    }
    if (hour >= 24){
    	hour = 0;
    }

    // Set LEDs for seconds, minutes, and hours





}


