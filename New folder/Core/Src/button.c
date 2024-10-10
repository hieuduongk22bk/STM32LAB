/*
 * button.c
 *
 *  Created on: Oct 5, 2024
 *      Author: ACER
 */

#include "button.h"

int keyReg0[NO_BUTTON];
int keyReg1[NO_BUTTON];
int keyReg2[NO_BUTTON];
int keyReg3[NO_BUTTON];

int button_flag[NO_BUTTON];
int TimeOut = 500;

void getButton() {
	for (int i = 0; i < NO_BUTTON; i++) {
		keyReg2[i] = keyReg1[i];
		keyReg1[0] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
		keyReg1[1] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		keyReg1[2] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);

		if (keyReg1[i] == keyReg2[i] && keyReg1[i] == keyReg0[i]) {
			if (keyReg2[i] != keyReg3[i]) {
				keyReg3[i] = keyReg2[i];

				if (keyReg3[i] == BUTTON_PRESSED) {
					TimeOut = 500;
					button_flag[i] = 1;
				}
			} else {
				TimeOut--;
				if (TimeOut == 0) {
					TimeOut = 500;
					if (keyReg3[i] == BUTTON_PRESSED) {
						button_flag[i] = 1;
					}
				}
			}
		}
	}
}

int isButtonPress(int num){
	if(button_flag[num] == 1) {
		button_flag[num] = 0;
		return 1;
	}
	return 0;
}
