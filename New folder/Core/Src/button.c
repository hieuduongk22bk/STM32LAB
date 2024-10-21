#include "button.h"

int KeyReg0[NUM_BUT] = {NORMAL_STATE};
int KeyReg1[NUM_BUT] = {NORMAL_STATE};
int KeyReg2[NUM_BUT] = {NORMAL_STATE};
int KeyReg3[NUM_BUT] = {NORMAL_STATE};

int TimeOutForKeyPress =  500;
int button__pressed = 0;
int button_long_pressed = 0;
int button_flag[NUM_BUT] = {0};


void getKeyInput(){
	for(int i=0;i<NUM_BUT;i++){
  KeyReg2[i] = KeyReg1[i];
  KeyReg1[i] = KeyReg0[i];
  // Add your key
		if (i == 0) {
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
		} else if (i == 1) {
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);
		} else if (i == 2) {
			KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		}

  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
    if (KeyReg2[i] != KeyReg3[i]){
      KeyReg3[i] = KeyReg2[i];

      if (KeyReg3[i] == PRESSED_STATE){
        TimeOutForKeyPress = 500;
        //subKeyProcess();
        button_flag[i] = 1;
      }

    }else{
        TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	TimeOutForKeyPress = 500;
        	if (KeyReg3[i] == PRESSED_STATE){
        		//subKeyProcess();
        		button_flag[i] = 1;
        	}
        }
    }
  }
}
}

