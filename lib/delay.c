#include "delay.h"

void delay_us(unsigned int usecond) {
  while (usecond-- > 0);
}

void delay_ms(unsigned int msecond) {
	unsigned int i=0, j=0;
	
	for (i=0; i<msecond; ++i)
		for (j=0; j<122; ++j);
}

//7us
void delay_min() {
	
}