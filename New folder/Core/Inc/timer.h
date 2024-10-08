/*
 * timer.h
 *
 *  Created on: Oct 8, 2024
 *      Author: ACER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"

extern int timerFlag[10];


void setTimer(int num, int dur);
void timerRun();
int checkTimer(int num);

#endif /* INC_TIMER_H_ */
