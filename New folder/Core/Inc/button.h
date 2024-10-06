/*
 * button.h
 *
 *  Created on: Oct 5, 2024
 *      Author: ACER
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NO_BUTTON 1
#define INCREASING_DUR 100
#define BUTTON_PRESSED GPIO_PIN_RESET
#define BUTTON_RELEASED GPIO_PIN_SET


void getButton();


#endif /* INC_BUTTON_H_ */
