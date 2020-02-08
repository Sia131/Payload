#ifndef _ENCODER_H_
#define _ENCODER_H_

/*The driverr uses timer 4.
 * No implementation of timer 4 is needed, everything is initialized within the encoder_init()
 * the input pins are B6 and B7
 * For the setup of the encoder follow link:http://www.candrian.gr/index.php/3-pin-rotary-encoder-how-to/
 * Vcc to encoder: 3.3V
 * Resistor value: 10K
 * Capasitor value: Unknown
 */


void encoder_init();
uint16_t encoder_get_count();
float encoder_get_angle();
void encoder_reset();




#endif
