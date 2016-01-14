#include <reg51.h>
#include "../lib/delay.h"
#include "../lib/lcd.h"

void main(void) {
	lcd_init(1, 2);
	lcd_display_string_at("Viet Nam", 2, 16);
	
	while(1) {
		delay_ms(500);
		lcd_cmd(0x18);
	}
}

void lcd_delay(const unsigned char type) {
	switch(type) {
		case 1:
			delay_ms(1);
			break;
		
		case 2:
			delay_ms(2);
			break;
		
		default:
			break;
	}
}
