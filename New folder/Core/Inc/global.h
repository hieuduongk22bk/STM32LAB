/*
 * global.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "main.h"
#include "button.h"
#include "led_traffic.h"
#include "7segment_bcd.h"

#define AUTO 20
#define MANUAL_RED 21
#define MANUAL_GREEN 22
#define MANUAL_AMBER 23

#define INIT 0
#define RED_GREEN 1
#define RED_AMBER 2
#define GREEN_RED 3
#define AMBER_RED 4

extern int status;
extern int mode;

extern int red_time, amber_time, green_time;
extern int temp_red,temp_amber,temp_green;
extern int auto_timer,man_timer,error_timer;
extern int first_time;
#endif /* INC_GLOBAL_H_ */
