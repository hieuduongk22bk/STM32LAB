/*
 * ex3.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ACER
 */

#include "ex4.h"
int counter4 =0;
void init_ex4(){
	    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_6);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2);
}
void ex4_run(){
	if(counter4 > 9) counter4=0;
	display7SEG(counter4);
	counter4++;
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
