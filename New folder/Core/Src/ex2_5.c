/*
 * ex2_5.c
 *
 *  Created on: Sep 28, 2024
 *      Author: ACER
 */

/*
 * ex22.c
 *
 *  Created on: Sep 16, 2024
 *      Author: ACER
 */



#include <ex2_5.h>

const int MAX_LED=4;
int index_led=0;
int led_buffer[4]= {3,4,5,6};
int hour = 15, minute = 8, second = 50;

void init_ex25(){}
void ex25_run(){
		  second++;
		  if(second >= 60){
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60){
			  minute=0;
			  hour++;
		  }
		  if(hour >= 24){
			  hour =0;
		  }
		  updateClockBuffer();

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
	if(index_led == 4) index_led=0;
		update7SEG(index_led++);

}

