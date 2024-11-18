/*
 * global.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */


#include "global.h"

int status = INIT;
int mode = AUTO;
int auto_timer = 0,man_timer=0,error_timer=0;
int red_time=120, amber_time = 40, green_time = 80;
int temp_red,temp_amber,temp_green;
int first_time=1;
