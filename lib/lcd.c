#include "lcd.h"

extern bit  LCD_RS;
extern bit  LCD_EN;
extern data unsigned char LCD_DATA;

void lcd_cmd(const unsigned char cmd) {
	LCD_RS 	 = 0;
	LCD_DATA = cmd;
	LCD_EN 	 = 0;
	LCD_EN 	 = 1;
	
	if (cmd == 0x01 || cmd == 0x02) {
		lcd_delay(2);
	} else {
		lcd_delay(1);
	}
}

void lcd_data(const unsigned char c) {
	LCD_RS 	 = 1;
	LCD_DATA = c;
	LCD_EN 	 = 0;
	LCD_EN 	 = 1;
	
	lcd_delay(1);
}

void lcd_init(unsigned char input_type, unsigned char cursor_type) {
	//clear screen
	lcd_cmd(0x01);
	
	switch(input_type) {
		case 1:
			lcd_cmd(0x38);		// 2lines - 8bit mode
			break;
		
		case 2:
			lcd_cmd(0x28);		// 2lines - 4bit mode
			break;
		
		default:
			lcd_cmd(0x38);
			break;
	}
	
	switch(cursor_type) {
		case 1:
			lcd_cmd(0x0E); 		//display cursor
			break;
		
		case 2:
			lcd_cmd(0x0C); 		//do not display cursor
			break;
		
		default:
			lcd_cmd(0x0E);
			break;
	}
}

void lcd_display_number(unsigned int number) {
	unsigned char data_arr[5];
	unsigned char i=0;
	
	if (number == 0) {
		lcd_data(number+0x30);
		return;
	}
	
	while (number != 0) {
		data_arr[i] = number%10;
		++i;
		number /= 10;
	}
	--i;
	
	while (1) {
		lcd_data(data_arr[i]+0x30);
		if (i==0) {
			break;
		}
		--i;
	}
}

void lcd_display_string(const unsigned char *str) {
	unsigned int i=0;
	
	while (str[i] != '\0') {
		lcd_data(str[i++]);
	}
}



void lcd_cursor_move(const unsigned char row, const unsigned char col) {
	unsigned char offset = 0;
	unsigned char cmd 	 = 0x01;

	switch(row) {
		case 1:
			offset = 0x80;
			break;
		
		case 2:
			offset = 0xC0;
			break;
		
		default:
			break;
	}
	cmd = offset + col-1;
	lcd_cmd(cmd);
}

void lcd_move_to_line_beginer(const unsigned char type) {
	switch(type) {
		case 1:
			lcd_cmd(0x80);
			break;
		
		case 2:
			lcd_cmd(0xC0);
			break;
		
		default:
			break;
	}
}

void lcd_data_at(const unsigned char c, const unsigned char row, const unsigned char col) {
	lcd_cursor_move(row, col);
	lcd_cmd(c);
}

void lcd_display_number_at(const unsigned int number, const unsigned char row, const unsigned char col) {
	lcd_cursor_move(row, col);
	lcd_display_number(number);
}

void lcd_display_string_at(const unsigned char *str, const unsigned char row, const unsigned char col) {
	lcd_cursor_move(row, col);
	lcd_display_string(str);
}