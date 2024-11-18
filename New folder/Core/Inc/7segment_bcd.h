/*
 * 7segment_bcd.h
 *
 *  Created on: Nov 17, 2024
 *      Author: ACER
 */

#ifndef INC_7SEGMENT_BCD_H_
#define INC_7SEGMENT_BCD_H_

#include"global.h"
#include"main.h"

extern int buffer_led[4];
void seg0(int num);
void seg1(int num);
void seg2(int num);
void seg3(int num);
void display_seg(int num1,int num2);
#endif /* INC_7SEGMENT_BCD_H_ */
