/*
 * ex2_10.c
 *
 *  Created on: Sep 29, 2024
 *      Author: ACER
 */
#include"ex2_10.h"
int temp;

void init_ex210(){}

void ex210_run(){
	if(boolflag(0)==1){
		temp=matrix_buffer[0];
		if(index_led_matrix >= 8) {
			index_led_matrix=0;
			matrix_buffer[7]=temp;
		}

		updateLEDMatrix( index_led_matrix++);
		if(index_led_matrix <= 7){
					matrix_buffer[index_led_matrix-1] = matrix_buffer[index_led_matrix];
				}
		setTimer(0,500);
}

}
