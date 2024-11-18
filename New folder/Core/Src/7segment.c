/*
 * 7segment.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */


#include "7segment.h"

int buffer[4]={10};
int enb=0;

void seg_num(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
			break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
			break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
			break;


	}
}
void update_buffer(int num1, int num2) {
	 num1=num1/10;
	 num2=num2/10;
	 buffer[0] = num1 / 10;
	 buffer[1] = num1 % 10;
	 buffer[2] = num2 / 10;
	 buffer[3] = num2 % 10;

}

void display(){
	switch(enb){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, SET);
		seg_num(buffer[0]);
		enb=1;
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15, SET);
		seg_num(buffer[1]);
		enb=2;

		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, SET);
		seg_num(buffer[2]);
		enb=3;
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_12, SET);
		seg_num(buffer[3]);
		enb=0;
		break;
	}
}
