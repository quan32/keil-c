/**
 * hardware:
 * 		check keyboard port, control pin, external interrupt pin
 * software:
 * 		check STARTUP.A51 for address of vars
**/
#include <reg51.h>
#include "../lib/keyboard.h"
#include "../lib/lcd.h"

void main(void) {	
	keyboard_init(0);
	while(1) {
		
	}
}

void keyboard_do_job(const unsigned char pos) {
	lcd_display_number(pos);
}
