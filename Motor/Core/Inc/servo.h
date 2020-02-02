#ifndef __SERVO_H__
#define __SERVO_H__
#include <stm32f1xx.h>

/* Setup
 * 		uing timer 2
 * 		Channel 1: PWM generation on channel 1
 * 		using internal clock at 8MHz
 * 		count set at 2019
 * 		prescaler set at 79
 * 		generating PWM on pin PA0
 *
 * Example code:
 * 		set_angle(&htim2, 90);
 */


void test_blink();
void set_angle(TIM_HandleTypeDef *htim, uint16_t angle);



#endif
