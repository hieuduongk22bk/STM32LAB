/*
 * ex2.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ACER
 */

#include "ex2.h"
int led_state2=state_0;
int counter2=0;

void init_ex2(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_6);
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_7);
}
void ex2_run(){
	switch(led_state2){
		  case state_0:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
			  counter2++;
			  if(counter2 >=5){
			  led_state2=state_1;
			  counter2=0;
			  }
			  break;
		  case state_1:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);
			  counter2++;
			  if(counter2 >=3){
			  	led_state2=state_2;
			    counter2=0;
			  		  }
			  break;
		  case state_2:
		  			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
		  			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
		  			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
		  			  counter2++;
		  			  if(counter2 >=2){
		  			  	led_state2=state_0;
		  			    counter2=0;
		  			  		  }
		  			  break;
		  default:
			  break;
		  }
}
