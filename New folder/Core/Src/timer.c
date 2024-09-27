/*
 * timer.c
 *
 *  Created on: Sep 27, 2024
 *      Author: ACER
 */


#include "timer.h"

int timer_flag[10];
int counter[10];

void timerSet(int index, int dur){
	timer_flag[index]= 0;
	counter[index] = dur/10;
}

void timerRun(){
	for(int i=0;i<5;i++){
		if(counter[i] > 0) counter[i]--;
		if(counter[i] <= 0) timer_flag[i] = 1;
	}
}
int boolflag(int index){
	return timer_flag[i];
}
