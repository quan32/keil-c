#include "IC74573.h"

void IC74573_transfer_data(const unsigned char c, const unsigned char i) {
	IC74573_DATA = c;
	
	switch (i) {
		case 1:
			IC74573_LE1 = 0;
			break;
		
		case 2:
			IC74573_LE2 = 0;
			break;
		
		default:
			break;
	}
}