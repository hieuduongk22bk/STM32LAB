/*
 * global.c
 *
 *  Created on: Sep 29, 2024
 *      Author: ACER
 */

#include "global.h"

const int MAX_LED=4;
int index_led = 0;
int led_buffer[4]= {3,4,5,6};
int hour = 15, minute = 8, second = 50;

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {0xff,0x80,0x00,0x33,0x33,0x00,0x80,0xff};

void display7SEG(int num){
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,RESET);

		switch(num){
		case 0:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,SET);

			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,SET);
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,SET);
			break;
		case 8:
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,SET);
			break;
		}
	}
void update7SEG(int index){
	switch (index){
		case 0:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);

			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,SET);
		    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,SET);
		    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);

			display7SEG(led_buffer[1]);
			break;

		case 2:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,RESET);

			display7SEG(led_buffer[2]);
			break;

		case 3:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,RESET);

			display7SEG(led_buffer[3]);
			break;
		}
}

void updateClockBuffer(){
	if(minute < 10){
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
	if(minute >= 10){
		led_buffer[2] = minute/10;
		led_buffer[3] = minute%10;
	}
	if(hour < 10){
			led_buffer[0] = 0;
			led_buffer[1] = hour;
	}
	if(hour >= 10){
			led_buffer[0] = hour/10;
			led_buffer[1] = hour%10;
	}
	if(index_led == 4) index_led = 0;
		update7SEG(index_led++);

}
void updateLEDMatrix(int index){

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,RESET);

	uint8_t value = matrix_buffer[index];

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (value & 0x01) ? SET : RESET); // Bit 0 -> PB0
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (value & 0x02) ? SET : RESET); // Bit 1 -> PB1
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (value & 0x04) ? SET : RESET); // Bit 3 -> PB3
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (value & 0x08) ? SET : RESET); // Bit 4 -> PB4
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (value & 0x10) ? SET : RESET); // Bit 5 -> PB5
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (value & 0x20) ? SET : RESET); // Bit 6 -> PB6
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (value & 0x40) ? SET : RESET); // Bit 7 -> PB7
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (value & 0x80) ? SET : RESET); // Bit 8 -> PB8

		switch ( index ){
			case 0:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,RESET);
				break;

			case 1:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
				break;

			case 2:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,RESET);
				break;

			case 3:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,RESET);
				break;

			case 4:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,RESET);
				break;

			case 5:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_13,RESET);
				break;

			case 6:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_14,RESET);
				break;

			case 7:
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14,SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,RESET);
				break;

			default:
				break;
		}
}
