/*
 * global.c
 *
 *  Created on: Dec 9, 2024
 *      Author: ACER
 */

#include "global.h"

char cmd[10]="";
int state=FIND_START;
int state_com=CMD_CHECK;
int cmd_flag=0;
uint8_t temp;
uint8_t buffer [ MAX_BUFFER_SIZE ];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
