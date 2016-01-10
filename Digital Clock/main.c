#include <reg52.h>

#define BASE 		0xFC18
#define BASE_HIGHT  0XFC
#define BASE_LOW 	0x18
#define SECOND 	    0
#define MINUTE 	    1
#define HOUR 		2
#define DAY 		3
#define MONTH 	    4
#define YEAR1 	    5
#define YEAR2 	    6

//variables
unsigned char SEGMENTS[] 	= {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char date_time[]	= {0, 0, 0, 0, 0, 0, 0};
bit flag_0;
bit flag_1;
bit flag_2;
bit flag_3;
bit flag_4;
bit flag_5;
bit flag_6;
bit flag_7;
bit flag_8;
bit flag_9;
bit flag_10;
bit flag_11;
bit flag_12;
bit flag_13;
unsigned int count=0;

//functions
void init();
void setTimer();
void update_led();

void main(void) {
	
	IE 		= 0x82;
    TMOD 	= 0x01;
    
	init();
    
	setTimer();
	TR0 = 1;
	while (1);
}

void init() {
	flag_0 = 1;
	flag_1 = 0;
	flag_2 = 0;
	flag_3 = 0;
	flag_4 = 0;
	flag_5 = 0;
	flag_6 = 0;
	flag_7 = 0;
	flag_8 = 0;
	flag_9 = 0;
	flag_10 = 0;
	flag_11 = 0;
	flag_12 = 0;
	flag_13 = 0;
}

void setTimer() {
	TH0 = BASE_HIGHT;
	TL0 = BASE_LOW;
}

void timer0(void) interrupt 1 {
	setTimer();
	++count;
	
	//second
	if (count == 1000) {
		date_time[SECOND]++;
		count = 0;
	}
	
	//minute
	if (date_time[SECOND]	== 60) {
		++date_time[MINUTE];
		date_time[SECOND] = 0;
	}
	
	//hour
	if (date_time[MINUTE] == 60) {
		++date_time[HOUR];
		date_time[MINUTE] = 0;
	}
	
	//day
	if (date_time[HOUR] == 24) {
		++date_time[DAY];
		date_time[HOUR] 	= 0;
	}
	
	//month
	if (date_time[DAY] == 30) {
		++date_time[MONTH];
		date_time[DAY] 		= 0;
	}
	
	//year
	if (date_time[MONTH] == 12) {
		++date_time[YEAR1];
		date_time[MONTH] 	= 0;
		
		if (date_time[YEAR1] == 100) {
			date_time[YEAR1] = 0;
			++date_time[YEAR2];
		}
	}
	
	update_led();
}
		
void update_led() {
	unsigned char i=0, tmp=0;
	
	//second
	if (flag_0 == 1) {
				P2 = 0x01;
				P1 = 0x00;
				flag_0 = 0;
				flag_1 = 1;
				
				tmp = date_time[0];
				P0  = SEGMENTS[tmp%10];
		
		return;
	}
	
	if (flag_1 == 1) {
				P2 = 0x02;
				P1 = 0x00;
				flag_1 = 0;
				flag_2 = 1;
				
				tmp = date_time[0];
				P0  = SEGMENTS[tmp/10];
		
		return;
	}
	
	//minute
	if (flag_2 == 1) {
				P2 = 0x04;
				P1 = 0x00;
				flag_2 = 0;
				flag_3 = 1;
				
				tmp = date_time[1];
				P0  = SEGMENTS[tmp%10];
		
		return;
	}
	
	if (flag_3 == 1) {
				P2 = 0x08;
				P1 = 0x00;
				flag_3 = 0;
				flag_4 = 1;
				
				tmp = date_time[1];
				P0  = SEGMENTS[tmp/10];
		
		return;
	}
	
	//hour
	if (flag_4 == 1) {
				P2 = 0x10;
				P1 = 0x00;
				flag_4 = 0;
				flag_5 = 1;
				
				tmp = date_time[2];
				P0  = SEGMENTS[tmp%10];
		
		return;
	}
	
	if (flag_5 == 1) {
				P2 = 0x20;
				P1 = 0x00;
				flag_5 = 0;
				flag_6 = 1;
				
				tmp = date_time[2];
				P0  = SEGMENTS[tmp/10];
		
		return;
	}
	
	//day
	if (flag_6 == 1) {
				P2 = 0x40;
				P1 = 0x00;
				flag_6 = 0;
				flag_7 = 1;
				
				tmp = date_time[3];
				P0  = SEGMENTS[tmp%10];
		
		return;
	}
	
	if (flag_7 == 1) {
				P2 = 0x80;
				P1 = 0x00;
				flag_7 = 0;
				flag_8 = 1;
				
				tmp = date_time[3];
				P0  = SEGMENTS[tmp/10];
		
		return;
	}
	
	//month
	if (flag_8 == 1) {
				P2 = 0x00;
				P1 = 0x01;
				flag_8 = 0;
				flag_9 = 1;
				
				tmp = date_time[4];
				P0  = SEGMENTS[tmp%10];

			return;
	}
	
	if (flag_9 == 1) {
				P2 = 0x00;
				P1 = 0x02;
				flag_9 	= 0;
				flag_10 = 1;
				
				tmp = date_time[4];
				P0  = SEGMENTS[tmp/10];

			return;
	}
	
	//year	
	if (flag_10 == 1) {
				P2 = 0x00;
				P1 = 0x04;
				flag_10 = 0;
				flag_11 = 1;
				
				tmp = date_time[5];
				P0  = SEGMENTS[tmp%10];
		
		return;
	}
	
	if (flag_11 == 1) {
				P2 = 0x00;
				P1 = 0x08;
				flag_11 = 0;
				flag_12 = 1;
				
				tmp = date_time[5];
				P0  = SEGMENTS[tmp/10];
		
		return;
	}
	
	if (flag_12 == 1) {
				P2 = 0x00;
				P1 = 0x10;
				flag_12 = 0;
				flag_13 = 1;
				
				tmp = date_time[6];
				P0  = SEGMENTS[tmp%10];
		
		return;
	}
	
	if (flag_13 == 1) {
				P2 = 0x00;
				P1 = 0x20;
				flag_13 = 0;
				flag_0 = 1;
				
				tmp = date_time[6];
				P0  = SEGMENTS[tmp/10];
		
		return;
	}
}