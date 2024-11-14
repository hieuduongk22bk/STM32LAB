/*
 * led_traffic.c
 *
 *  Created on: Oct 8, 2024
 *      Author: ACER
 */
#include"led_traffic.h"

void led_green_red(){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0| GPIO_PIN_4,SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_3| GPIO_PIN_5,RESET);
}
void led_amber_red(){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2| GPIO_PIN_4,SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0| GPIO_PIN_1| GPIO_PIN_3| GPIO_PIN_5,RESET);
}
void led_red_green(){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1| GPIO_PIN_3,SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0| GPIO_PIN_2| GPIO_PIN_4| GPIO_PIN_5,RESET);

}
void led_red_amber(){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1| GPIO_PIN_5,SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0| GPIO_PIN_2| GPIO_PIN_4| GPIO_PIN_3,RESET);

}
void toggle_led_red(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_1|GPIO_PIN_4);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0|GPIO_PIN_2| GPIO_PIN_3|GPIO_PIN_5,RESET);
}
void toggle_led_amber(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_2|GPIO_PIN_5);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0| GPIO_PIN_1| GPIO_PIN_3|GPIO_PIN_4,RESET);
}
void toggle_led_green(){
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_0|GPIO_PIN_3);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_4| GPIO_PIN_5,RESET);
}

