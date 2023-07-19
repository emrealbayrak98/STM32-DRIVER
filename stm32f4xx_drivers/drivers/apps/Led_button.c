/*
 * Led_button.c
 *
 *  Created on: 4 Tem 2023
 *      Author: erdem
 */


#include "stm32f446xx.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW

void delay(){
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}
int main(void)
{
	GPIO_Handle_t GPIO_LED;
	GPIO_LED.pGPIOx = GPIOA;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_LED);

	GPIO_Handle_t GPIO_BUTTON;
	GPIO_BUTTON.pGPIOx = GPIOC;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_BUTTON);


	/* Loop forever */
	for(;;){
		if(!(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13))){
			delay();
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		}


	}
	return 0;
}
