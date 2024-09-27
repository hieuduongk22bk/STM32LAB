/*
 * timer.h
 *
 *  Created on: Sep 27, 2024
 *      Author: ACER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer_flag[10];

void timerSet(int index, int dur);
void timerRun();
int boolflag(int index);


#endif /* INC_TIMER_H_ */
