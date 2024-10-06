/*
 * button.c
 *
 *  Created on: Oct 5, 2024
 *      Author: ACER
 */

#include "button.h"

static GPIO_PinState buttonBuffer[NO_BUTTON];
static GPIO_PinState keyReg1[NO_BUTTON];
static GPIO_PinState keyReg2[NO_BUTTON];
static GPIO_PinState keyReg3[NO_BUTTON];

static int button_flag[NO_BUTTON];
static int TimeOut = 500;

void getButton() {
	for (int i = 0; i < NO_BUTTON; i++) {
		keyReg2[i] = keyReg1[i];
		keyReg1[i] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);

		if (keyReg1[i] == keyReg2[i] && keyReg1[i] == keyReg0[i]) {
			if (keyReg2[i] != keyReg3[i]) {
				keyReg3 = keyReg2;

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
