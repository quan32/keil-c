#include <reg51.h>

#define BASE 		0xFC18
#define BASE_HIGHT  0XFC
#define BASE_LOW 	0x18
#define SECOND 	    0


//variables
unsigned char SEGMENTS[] 	= {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char date_time[]	= {0};
unsigned int  count;
bit flag_0;
bit flag_1;

void init();
void setTimer();
void update_led();

void timer0(void) interrupt 2 {

    setTimer();
        
    ++count;
    if (count == 1000) {
        ++date_time[SECOND];
        count = 0;
    }
    
    update_led();    
}

void main(void) {

    IE   = 0x82;
    TMOD = 0x01;
    setTimer();
    init();
    TR0  = 1;
    
    while(1);
}

void init() {
    P2     = 0x02;
    P0     = SEGMENTS[0];
    P2     = 0x01;
    P0     = SEGMENTS[0];
    
    flag_0 = 1;
    flag_1 = 0;
}

void setTimer() {
    TH0  = 0xFC;
    TL0  = 0x18;
}

void update_led() {
    if (flag_0 == 1) {
        P2 = 0x02;
        flag_0 =0;
        flag_1 = 1;
        
        P0 = SEGMENTS[date_time[SECOND]%10];
    } else if (flag_1 == 1) {
        P2 = 0x01;
        flag_1 = 0;
        flag_0 = 1;
        
        P0 = SEGMENTS[date_time[SECOND]/10];
    }
}

