/*
 * data_receiver.c
 *
 *  Created on: Dec 9, 2024
 *      Author: ACER
 */
#include "command_parser_fsm.h"
#include "string.h"
#include "stdio.h"

int start = -1;
int end = -1;

void command_parser_fsm(){
	switch(state){
	case FIND_START:
		if(temp == (uint8_t)'!'){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
			start = index_buffer;
			state = FIND_END;
		}
		break;
	case FIND_END:
		if(temp == (uint8_t)'#'){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
			end = index_buffer;
			}

		if (start != -1 && end != -1 && end > start) {
				int cmd_length = end - start -1;
				if (cmd_length > 0 && cmd_length < sizeof(cmd)) {
				   strncpy(cmd, (char *)&buffer[start], cmd_length);
				   cmd[cmd_length] = '\0';

				   }
				cmd_flag = 1;
				start = -1;
				end = -1;
				state = FIND_START;
		}
		break;

	}


}


