#include <reg51.h>
#include "switch.h"

struct SWITCH_CONTROL {
	unsigned char type;
};

/** 
 * 	init external interrupt
**/
void switch_init(const unsigned char type) {
	switch_ctrl->type = type;
	switch_init_exec();
}

static void switch_init_exec() {
	// use external interrupt 0
	if (switch_ctrl->type == 0) {
		IE   = 0x81;
		IT0  = 1;
	} else {
		IE   = 0x84;
		IT1  = 1;
	}
}

/**
 * 	external interrupt 0 irs
**/
static void keyboard_external_interrupt0_isr(void) interrupt 0 {

	switch_do_job();
}

/**
 * 	external interrupt 1 irs
**/
static void keyboard_external_interrupt1_isr(void) interrupt 3 {
	
	switch_do_job();
	
}