/*
 * ex2_1.c
 *
 *  Created on: Sep 27, 2024
 *      Author: ACER
 */
#include "ex2_1.h"

int enable = en0;
void ex21_run(){
	//if(boolflag(0)==1){
	switch (enable){
	case en0:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
		display7SEG(1);
		enable = en1;
		break;
	case en1:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);

		display7SEG(2);
		enable = en0;
		break;
	}
	//}
	//setTimer(0,1000);
}

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
