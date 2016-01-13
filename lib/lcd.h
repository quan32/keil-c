#ifndef lcd_h
#define lcd_h

void lcd_cmd(const unsigned char cmd);
void lcd_data(const unsigned char c);
void display_string_on_lcd(const unsigned char *str);

#endif