#include <reg51.h>
#include "../lib/delay.h"

//declare variables
sbit COL1 = P1^0;
sbit COL2 = P1^1;
sbit COL3 = P1^2;
sbit COL4 = P1^3;
sbit ROW1 = P1^4;
sbit ROW2 = P1^5;
sbit ROW3 = P1^6;
sbit ROW4 = P1^7;

sbit ctr1 = P3^0;
sbit ctr2 = P3^1;
bit  flag = 0;
unsigned char SEGMENTS[] 	= {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

//functions
void seven_segment_display(unsigned char number);
unsigned char scan(unsigned char row);

void main(void) {
	unsigned char i 	= 0;
	unsigned char pos = 0, tmp=0;
	
	while(1) {
		for (i=1; i<=4; ++i) {
			tmp = scan(i);
			if (tmp != 0) {
				break;
			}
		}
		if (tmp != 0) {
			pos = tmp;
		}
		
		seven_segment_display(pos);
	}
}

void seven_segment_display(unsigned char number) {
	if (flag == 0) {
		ctr1 = 0;
		P2 	 = SEGMENTS[number%10];
		delay_ms(1);
		
		flag = 1;
		ctr1 = 1;
	} else {
		ctr2 = 0;
		P2 	 = SEGMENTS[number/10];
		delay_ms(1);
		
		flag = 0;
		ctr2 = 1;
	}
}

unsigned char scan(unsigned char row) {
	unsigned char col = 0;
	
	switch(row) {
		case 1:
			ROW1 = 0;
			break;
		
		case 2:
			ROW2 = 0;
			break;
		
		case 3:
			ROW3 = 0;
			break;
		
		case 4:
			ROW4 = 0;
			break;
		
		default:
			break;
	}
	
	if (COL1 == 0) {
		col  = 1;
		COL1 = 1;
	} else if (COL2 == 0) {
		col  = 2;
		COL2 = 1;
	} else if (COL3 == 0) {
		col  = 3;
		COL3 = 1;
	} else if (COL4 == 0) {
		col  = 4;
		COL4 = 1;
	}
	
	(ROW1 == 0) ? (ROW1 = 1) : 1;
	(ROW2 == 0) ? (ROW2 = 1) : 1;
	(ROW3 == 0) ? (ROW3 = 1) : 1;
	(ROW4 == 0) ? (ROW4 = 1) : 1;
	
	if (col != 0) {
		return ((row-1)*4 + col);
	}
	
	return 0;
}