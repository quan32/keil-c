#include <reg51.h>
#include "../lib/base.h"
#include "../lib/lcd.h"

sbit SW = P1^0;

void main(void) {
	unsigned char count = 0;
	boolean checked = false;
	
	while (1) {
		if (SW == 1) {
			if (checked == false) {
				checked = true;
				++count;
				lcd_display_number(count);
			}
		} else {
			checked = false;
		}
	}
}