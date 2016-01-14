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

void do_job(const unsigned char pos) {
	
	lcd_cmd(0x01);
	lcd_cmd(0x0C);

	lcd_data(pos/10+0x30);
	lcd_data(pos%10+0x30);
}
