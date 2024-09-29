/*
 * global.h
 *
 *  Created on: Sep 29, 2024
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

extern int minute,second,hour;
extern int index_led,index_led_matrix;
extern uint8_t matrix_buffer [8];
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();
void updateLEDMatrix(int index);
#endif /* INC_GLOBAL_H_ */
