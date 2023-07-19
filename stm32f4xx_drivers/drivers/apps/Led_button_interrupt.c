/*
 * Led_button_interrupt.c
 *
 *  Created on: 4 Tem 2023
 *      Author: erdem
 */

#include <string.h>
#include "stm32f446xx.h"


void delay(void)
{
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}

int main(void)
{

	GPIO_Handle_t GPIO_LED, GPIO_BUTTON;

	memset(&GPIO_LED,0,sizeof(GPIO_LED));
	memset(&GPIO_BUTTON,0,sizeof(GPIO_BUTTON));

	//this is led gpio configuration
	GPIO_LED.pGPIOx = GPIOA;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_LED);


	//this is btn gpio configuration
	GPIO_BUTTON.pGPIOx = GPIOC;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_BUTTON);

	GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,GPIO_PIN_RESET);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);

    while(1);

}


void EXTI15_10_IRQHandler(void)
{
	delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_13); //clear the pending event from exti line
	GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
}
