#include <reg51.h>
#include "keyboard.h"

struct KEYBOARD_CONTROL {
	unsigned char type;
};

/** 
 * 	init external interrupt, keyboard row
**/
void keyboard_init(const unsigned char type) {
	keyboard_ctrl->type = type;
	keyboard_init_exec();
}

static void keyboard_init_exec() {
	// use external interrupt 0
	if (keyboard_ctrl->type == 0) {
		IE   = 0x81;
		IT0  = 1;
	} else {
		IE   = 0x84;
		IT1  = 1;
	}
	
	KEYBOARD_ROW1 = 0;
	KEYBOARD_ROW2 = 0;
	KEYBOARD_ROW3 = 0;
	KEYBOARD_ROW4 = 0;
}

/**
 *	keyboard scan init
 * 		stop external interrupts to keyboard scan
 * 		set KEYBOARD
**/
static void keyboard_scan_init() {
	IE  			= 0x00;
	KEYBOARD  = 0xFF;
}

/**
 * 	scan
**/
static unsigned char scan(const unsigned char row) {
	unsigned char col = 0;
	
	switch(row) {
		case 1:
			KEYBOARD_ROW1 = 0;
			break;
		
		case 2:
			KEYBOARD_ROW2 = 0;
			break;
		
		case 3:
			KEYBOARD_ROW3 = 0;
			break;
		
		case 4:
			KEYBOARD_ROW4 = 0;
			break;
		
		default:
			break;
	}
	
	if (KEYBOARD_COL1 == 0) {
		col  = 1;
	} else if (KEYBOARD_COL2 == 0) {
		col  = 2;
	} else if (KEYBOARD_COL3 == 0) {
		col  = 3;
	} else if (KEYBOARD_COL4 == 0) {
		col  = 4;
	}
	
	if (col != 0) {
		return ((row-1)*4 + col);
	}
	
	return 0;
}

/**
 * 	external interrupt 0 irs
**/
static void keyboard_external_interrupt0_isr(void) interrupt 0 {
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
		keyboard_do_job(pos);
	}
	
	keyboard_init_exec();
}

/**
 * 	external interrupt 1 irs
**/
static void keyboard_external_interrupt1_isr(void) interrupt 3 {
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
		keyboard_do_job(pos);
	}
	
	keyboard_init_exec();
}