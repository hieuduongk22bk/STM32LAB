/*
 * 7segment.c
 *
 *  Created on: Oct 9, 2024
 *      Author: ACER
 */


#include "7segment.c"

int led_buffer[4]={0};

void display7seg_1(int num){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13
					| GPIO_PIN_14 | GPIO_PIN_15, RESET);
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);

		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);
		break;
	case 8:
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);
		break;
	}
}

void display7seg_2(int num){
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13
					| GPIO_PIN_14 | GPIO_PIN_15, RESET);
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);

		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);
		break;
	case 8:
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
		break;
	}
}
void update7seg(int index){
	switch (index) {
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
		display7seg_1(led_buffer[0]);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
		display7seg_1(led_buffer[1]);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
		display7seg_2(led_buffer[2]);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
		display7seg_2(led_buffer[3]);
		break;
	}
}

