#include <reg51.h>
#include "lcd.h"
#include "delay.h"
#include "delay.c"

sbit LCD_RS = P1^0;
sbit LCD_EN = P1^1;

void lcd_cmd(unsigned char cmd) {
	LCD_RS 	 = 0;
	P2 			 = cmd;
	LCD_EN 	 = 0;
	LCD_EN 	 = 1;
	
	if (cmd == 0x01 || cmd == 0x02) {
		delay_ms(2);
	} else {
		delay_ms(1);
	}
}

void lcd_data(unsigned char c) {
	LCD_RS 	 = 1;
	P2 			 = c;
	LCD_EN 	 = 0;
	LCD_EN 	 = 1;
	
	if (c == 0x01 || c == 0x02) {
		delay_ms(2);
	} else {
		delay_ms(1);
	}
}

void display_string_on_lcd(unsigned char *str) {
	unsigned long i;
	
	while (str[i] != '\0') {
		lcd_data(str[i++]);
	}
}