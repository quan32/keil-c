#include <reg51.h>
#include "lcd.h"
#include "delay.h"
#include "delay.c"

extern bit  LCD_RS;
extern bit  LCD_EN;
extern data unsigned char LCD_DATA;

void lcd_cmd(const unsigned char cmd) {
	LCD_RS 	 = 0;
	LCD_DATA = cmd;
	LCD_EN 	 = 0;
	LCD_EN 	 = 1;
	
	if (cmd == 0x01 || cmd == 0x02) {
		delay_ms(2);
	} else {
		delay_ms(1);
	}
}

void lcd_data(const unsigned char c) {
	LCD_RS 	 = 1;
	LCD_DATA = c;
	LCD_EN 	 = 0;
	LCD_EN 	 = 1;
	
	if (c == 0x01 || c == 0x02) {
		delay_ms(2);
	} else {
		delay_ms(1);
	}
}

void display_string_on_lcd(const unsigned char *str) {
	unsigned int i=0;
	
	while (str[i] != '\0') {
		lcd_data(str[i++]);
	}
}