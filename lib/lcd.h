#ifndef lcd_h
#define lcd_h

void lcd_cmd(const unsigned char cmd);
void lcd_data(const unsigned char c);

void lcd_init(unsigned char input_type, unsigned char cursor_type);
void lcd_display_number(unsigned int number);
void lcd_display_string(const unsigned char *str);

void lcd_cursor_move(const unsigned char row, const unsigned char col);
void lcd_move_to_line_beginer(const unsigned char type);
void lcd_data_at(const unsigned char c, const unsigned char row, const unsigned char col);
void lcd_display_number_at(const unsigned int number, const unsigned char row, const unsigned char col);
void lcd_display_string_at(const unsigned char *str, const unsigned char row, const unsigned char col);
void lcd_delay(const unsigned char type);

#endif