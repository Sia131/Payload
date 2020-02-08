#include <stm32f1xx.h>
#include "encoder.h"
#include "stdint.h"


volatile int32_t count;
volatile float angle;


void encoder_update_count(){
	count = TIM4->CNT;
}

void encoder_init(){
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; //AFIO might not even be needed?

	TIM4->ARR = 0xFFFF;

	//per datasheet instructions
	TIM4->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  //step 1 and 2
	TIM4->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);  // step 3 and 4
	TIM4->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;   //step 5
	TIM4->CR1 |= TIM_CR1_CEN ;     //step 6
}

int32_t enocder_get_count(){
	return count;
}

float encoder_get_angle(){
	angle = count/(2*3.14);
	return angle;
}



