#ifndef _ENCODER_H_
#define _ENCODER_H_


void encoder_init();
void encoder_update_count();
int32_t enocder_get_count();
float encoder_get_angle();


void encoder_reset();
uint8_t encoder_get_dir();





#endif
