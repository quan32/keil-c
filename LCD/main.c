#include <reg51.h>
#include "../lib/delay.h"

sbit LED = P1^1;

void main(void) {
    LED  = 1;
    while(1) {
        delay_ms(500);
        LED = ~LED;
    }           
}