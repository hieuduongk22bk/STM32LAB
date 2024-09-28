/*
 * ex22.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ACER
 */



#include "ex2_2.h"
#include "timer.h"

int enable = en0;
void init_ex22(){}
void ex22_run(){
	switch (enable){
	case en0:

		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);

		display7SEG(1);
		enable = en1;
		break;
	case en1:

		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,SET);
	    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,SET);
	    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);

		display7SEG(2);
		enable = en2;
		break;

	case en2:

			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,RESET);

			display7SEG(3);
			enable = en3;
			break;

	case en3:

			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,SET);
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,RESET);

		display7SEG(0);
		enable = en0;
		break;
	}

}

void display7SEG(int num){
		GPIOB->ODR=0x00;
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
