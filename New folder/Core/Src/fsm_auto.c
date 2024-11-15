/*
 * fsm_auto.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#include "fsm_auto.h"

void fsm_auto(){
	switch(status)
	case INIT:
		status = RED_GREEN;
		break;
	case RED_GREEN:
		status =
		break;
	case RED_AMBER:
		break;
	case GREEN_RED:
		break;
	case AMBER_RED:
		break;
}

