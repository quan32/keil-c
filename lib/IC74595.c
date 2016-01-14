#include "IC74595.h"

void IC74595_data_transfer(const unsigned char x) {
	unsigned char i=0;
	
	for (i=0; i<8; ++i) {
		IC74595_DS = x & (0x80 >> i);
		
		IC74595_SHCP = 0;
		IC74595_SHCP = 1;
	}
	
	IC74595_STCP = 0;
	IC74595_STCP = 1;
}