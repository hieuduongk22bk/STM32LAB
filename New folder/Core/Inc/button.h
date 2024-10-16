/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define NUM_BUT 1
extern int button_flag[NUM_BUT];

void getKeyInput();

#endif /* INC_BUTTON_H_ */

