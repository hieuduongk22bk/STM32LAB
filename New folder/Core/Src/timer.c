/*
 * timer.c
 *
 *  Created on: Oct 8, 2024
 *      Author: ACER
 */

#include "timer.h"

int timerFlag[10] = {0};
int counter[10] = {0};
int TIMER_CYCLE = 10;

void setTimer(int num,int dur){
	counter[num] = dur/TIMER_CYCLE;
	timerFlag[num] = 0;
}
void timerRun(){
	for(int i=0; i < 10; i++){
		if(counter[i] > 0) counter[i]--;
		if(counter[i] <= 0) {
			timerFlag[i] = 1;
		}
	}

}
int checkTimer(int num){
	return timerFlag[num];
}
