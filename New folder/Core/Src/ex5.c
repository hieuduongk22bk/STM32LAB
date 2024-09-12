/*
 * ex3.c
 *
 *  Created on: Sep 12, 2024
 *      Author: ACER
 */

#include "ex5.h"
int led_state5=state_green1;
int counter_r=5;
int counter_g=3;
int counter_y=2;
int counter5=0;
void init_ex5(){
	    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_1);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_5);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_6);

		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_7);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_8);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_10);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_11);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_12);
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_13);
}
void test_count(){
	if(counter5>=10) counter5=0;
		display7SEG2(counter5);
		counter5++;

}
void ex5_run(){
	switch(led_state5){
			  case state_green1:
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,SET);

				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);

				  display7SEG1(counter_g);
				  display7SEG2(counter_r);
				  counter_g--;
				  counter_r--;


				  if(counter_g <=0){
				  led_state5=state_yellow1;
				  counter_g=3;
				  }
				  break;
			  case state_yellow1:
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,SET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET);

				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);

				  display7SEG1(counter_y);
				  display7SEG2(counter_r);
				  counter_y--;
				  counter_r--;


				  if(counter_y <= 0){
				  	led_state5=state_green2;
				    counter_y=2;
				    counter_r=5;
				  		  }
				  break;
			  case state_green2:
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,SET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET);

				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,SET);

				  display7SEG1(counter_r);
				  display7SEG2(counter_g);
			  	  counter_r--;
			  	  counter_g--;


			  	  if(counter_g <= 0){
			  		led_state5=state_yellow2;
			  		counter_g=3;
			  			  }
			  	  break;
			  case state_yellow2:
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,SET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET);

				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,SET);
				  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,RESET);

				  display7SEG1(counter_r);
				  display7SEG2(counter_y);
			  	  counter_r--;
			  	  counter_y--;

			  	  if(counter_y <= 0){
			  		led_state5=state_green1;
			  		counter_y = 2 ;
			  		counter_r = 5 ;
			  	           }
			  	break;
			  default:
				  break;
			  }
}
void display7SEG1(int num){
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
void display7SEG2(int num){
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,RESET);
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,SET);

		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,SET);
		break;
	case 8:
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,SET);
		break;
	}
}

