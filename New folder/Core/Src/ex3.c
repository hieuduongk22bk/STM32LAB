/*
 * ex3.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ACER
 */

#include "ex3.h"

int led_state3=state_green1;
int counter3=0;

void init_ex3(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_6);
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_7);
}
void ex3_run(){
	switch(led_state3){
		  case state_green1:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,SET);

			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);
			  counter3++;
			  if(counter3 >=3){
			  led_state3=state_yellow1;
			  counter3=0;
			  }
			  break;
		  case state_yellow1:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET);

			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);
			  counter3++;
			  if(counter3 >=2){
			  	led_state3=state_green2;
			    counter3=0;
			  		  }
			  break;
		  case state_green2:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET);

			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);
		  	  counter3++;
		  	  if(counter3 >=3){
		  		led_state3=state_yellow2;
		  		counter3=0;
		  			  }
		  	  break;
		  case state_yellow2:
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET);

			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
			  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);
		  	  counter3++;
		  	  if(counter3 >=2){
		  		led_state3=state_green1;
		  		counter3=0;
		  	           }
		  	break;
		  default:
			  break;
		  }
}
