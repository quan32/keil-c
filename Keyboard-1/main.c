#include <reg51.h>
#include "../lib/lcd.h"

//declare variables
sbit COL1 = P1^0;
sbit COL2 = P1^1;
sbit COL3 = P1^2;
sbit COL4 = P1^3;
sbit ROW1 = P1^4;
sbit ROW2 = P1^5;
sbit ROW3 = P1^6;
sbit ROW4 = P1^7;

//functions
void init();
void keyboard_scan_init();
unsigned char scan(unsigned char row);
void lcd_display(unsigned char pos);

void main(void) {	
	init();
	while(1) {
		
	}
}

void init() {
	IE   = 0x81;
	IT0  = 1;
	
	ROW1 = 0;
	ROW2 = 0;
	ROW3 = 0;
	ROW4 = 0;
}

void external_interrupt_isr(void) interrupt 0 {
	unsigned char i 	= 0;
	unsigned char pos = 0, tmp=0;
	
	keyboard_scan_init();
	
	for (i=1; i<=4; ++i) {
		tmp = scan(i);
		if (tmp != 0) {
			break;
		}
	}
	if (tmp != 0) {
		pos = tmp;
		lcd_display(pos);
	}
	
	init();
}

void lcd_display(unsigned char pos) {
	
	lcd_cmd(0x01);
	lcd_cmd(0x0C);

	lcd_data(pos/10+0x30);
	lcd_data(pos%10+0x30);
}

void keyboard_scan_init() {
	IE  = 0x00;
	P1  = 0xFF;
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