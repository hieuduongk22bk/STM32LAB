/*
 * ex2_9.h
 *
 *  Created on: Sep 28, 2024
 *      Author: ACER
 */

#ifndef INC_EX2_9_H_
#define INC_EX2_9_H_

#include "main.h"
#include "timer.h"

void init_ex29();
void ex29_run();
void display7SEG1(int num);
void update7SEG1(int index);
void updateClockBuffer1();
void updateLEDMatrix(int index);
#endif /* INC_EX2_9_H_ */
