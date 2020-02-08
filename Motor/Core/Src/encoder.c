#include <stm32f1xx.h>
#include "encoder.h"
#include "stdint.h"

#define MAX_COUNT_ENCODER_HEX 0x60
volatile float angle;



void encoder_init(){
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; //AFIO might not even be needed?

	// value to count up to : 16 bit so max is 0xFFFF = 65535
	TIM4->ARR = MAX_COUNT_ENCODER_HEX;

	//per datasheet instructions
	TIM4->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  //step 1 and 2
	TIM4->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);  // step 3 and 4
	TIM4->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;   //step 5
	TIM4->CR1 |= TIM_CR1_CEN ;     //step 6
}

uint16_t encoder_get_count(){
	return TIM4->CNT;
}


//fikk ikke implementert den riktig
float encoder_get_angle(){
	//trasnfer function
	return angle;

}
void encoder_reset(){
	TIM4->CNT = 0;
}



