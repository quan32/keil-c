#ifndef lcd_h
#define lcd_h

void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char c);
void display_string_on_lcd(unsigned char *str);

#endif