/*
 * ex1.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ACER
 */

#include "ex1.h"

int led_state1=state_0;
int counter1=0;
void init_ex1(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_6);
}
void ex1_run(){
	switch(led_state1){
		  case state_0:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
			  counter1++;
			  if(counter1 >=2){
			  led_state1=state_1;
			  counter1=0;
			  }
			  break;
		  case state_1:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			  counter1++;
			  if(counter1 >=2){
			  	led_state1=state_0;
			    counter1=0;
			  		  }
			  break;
		  default:
			  break;
		  }
}
