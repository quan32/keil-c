#include "delay.h"

void delay_us(unsigned int usecond) {
    while (usecond-- > 0);
}

void delay_ms(unsigned int msecond) {
    while(msecond-- > 0) {
        delay_us(MS_US);
    }
}