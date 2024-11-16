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
#include "7segment.h"

#define INIT 0
#define RED_GREEN 1
#define RED_AMBER 2
#define GREEN_RED 3
#define AMBER_RED 4

#define MAN_RED_GREEN 11
#define MAN_RED_AMBER 12
#define MAN_GREEN_RED 13
#define MAN_AMBER_RED 14

extern int status;
extern int red_time1, amber_time1, green_time1;
extern int local_red_time1,local_green_time1,local_amber_time1;

#endif /* INC_GLOBAL_H_ */
