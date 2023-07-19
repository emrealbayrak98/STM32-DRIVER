/*
 * Led_blink.c
 *
 *  Created on: 4 Tem 2023
 *      Author: erdem
 */


#include "stm32f446xx.h"

void delay(){
	for(uint32_t i = 0; i < 50000 ; i++);
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


	    /* Loop forever */
		for(;;){
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
			delay();
		}
	return 0;
}
