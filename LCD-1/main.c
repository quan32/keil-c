#include <reg51.h>
#include "../lib/lcd.h"

void main(void) {

	// Xoa man hinh
	lcd_cmd(0x01);
	
	// Bat man hinh, con tro
	lcd_cmd(0x0C);
	
	// Xuat 1 ky tu ra man hinh
	lcd_data('A');
	//delay_ms(1000);
	
	//Xoa man hinh
	//lcd_cmd(0x01);
	
	//Xuat 1 doan text ra man hinh
	
	//Xoa man hinh
	//lcd_cmd(0x01);
	//lcd_cmd(0x0E);
	
	//Chuyen con tro xuong dong 2
	//lcd_cmd(0x38);
	//lcd_cmd(0xC0);
	
	//Hien thi ky tu
	//lcd_data('B');
	
	while(1) {
		
	}
}