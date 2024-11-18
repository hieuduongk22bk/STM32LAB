/*
 * 7segment.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#ifndef INC_7SEGMENT_H_
#define INC_7SEGMENT_H_
#include "global.h"
extern int buffer[4];
extern int enb;
void seg_num(int num);
void update_buffer(int num1,int num2);
void display();

#endif /* INC_7SEGMENT_H_ */
