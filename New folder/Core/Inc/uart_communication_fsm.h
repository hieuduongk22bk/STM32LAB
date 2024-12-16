/*
 * error_handling.h
 *
 *  Created on: Dec 9, 2024
 *      Author: ACER
 */

#ifndef INC_UART_COMMUNICATION_FSM_H_
#define INC_UART_COMMUNICATION_FSM_H_

#include "global.h"
#include "string.h"
#include "timer.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
extern uint32_t val;
extern char str[50];
extern int first_send;
void uart_communication_fsm();
void read_adc();
#endif /* INC_UART_COMMUNICATION_FSM_H_ */
