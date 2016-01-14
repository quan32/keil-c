#include <reg51.h>
#include "../lib/delay.h"
#include "../lib/IC74573.h"

void main() {
	unsigned char data_arr[2] = {0x80, 0x55};
	unsigned char i=0;
	
	for (i=0; i<2; ++i) {
		IC74573_transfer_data(data_arr[i], i+1);
		//delay_ms(1000);
	}
	
	while (1) {
		
	}
}