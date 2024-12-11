/*
 * global.h
 *
 *  Created on: Dec 9, 2024
 *      Author: ACER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include"main.h"

extern char cmd[10];

#define FIND_START 1
#define FIND_END 2

#define CMD_CHECK 5
#define CMD_SEND 6
#define CMD_ACK 7

#define MAX_BUFFER_SIZE 30

extern int state;
extern int state_com;
extern int cmd_flag;

extern uint8_t temp;
extern uint8_t buffer [ MAX_BUFFER_SIZE ];
extern uint8_t index_buffer ;
extern uint8_t buffer_flag ;
#endif /* INC_GLOBAL_H_ */
