/*
 * timer.h
 *
 *  Created on: Sep 21, 2024
 *      Author: ACER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];
void setTimer(int index,int counter);
void timerRun();
int isTimerExpired(int index);

#endif /* INC_TIMER_H_ */
