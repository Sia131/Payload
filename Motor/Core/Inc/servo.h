#ifndef __SERVO_H__
#define __SERVO_H__
#include <stm32f1xx.h>
#include "stm32f1xx_hal.h"
#include <stdint.h>

/* Example code:
 * set_angle(&htim2, 90);
 */

void test_blink();
void set_angle(TIM_HandleTypeDef *htim, uint16_t angle);



#endif
