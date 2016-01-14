#include <reg51.h>
#include "../lib/delay.h"
#include "../lib/IC74595.h"

void main() {
	unsigned char i=0;
	unsigned char data_arr[2] = {0x80, 0x55}; 
	
	while (1) {
		for (i=0; i<2; ++i) {
			IC74595_data_transfer(data_arr[i]);
			delay_ms(1000);
		}
	}
	
}


