#include "uart_communication_fsm.h"

UART_HandleTypeDef huart2;
ADC_HandleTypeDef hadc1;
uint32_t val=0;
char str[50]="";
int first_send = 0;
void read_adc(){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	val = HAL_ADC_GetValue(&hadc1);

}
void uart_communication_fsm(){
	switch(state_com){
	case CMD_CHECK:
		if(cmd_flag == 1) {
	        if(strcmp(cmd,"RST")==0) {
	        	state_com = CMD_SEND;
	        	first_send = 0;
	        }
	        cmd_flag = 0;
		}
		break;

	case CMD_SEND:
		if(first_send == 0) {
			read_adc();
			first_send = 1;
		}
		HAL_UART_Transmit (& huart2 , (void *)str , sprintf(str, "!ADC=%ld#\r\n", val ),1000) ;
		state_com = CMD_ACK;
		setTimer(0, 3000);
		break;
	case CMD_ACK:
		if(cmd_flag == 1){
			if(strcmp(cmd,"OK")==0) state_com = CMD_CHECK;
			HAL_UART_Transmit (& huart2 , (uint8_t*)"!END#" ,5,100) ;
			cmd_flag = 0;
		}
		if(timer_flag[0] == 1) state_com = CMD_SEND;
		break;
	}

}
