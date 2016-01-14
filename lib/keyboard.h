#ifndef keyboard_h
#define keyboard_h

static struct KEYBOARD_CONTROL *keyboard_ctrl;

extern data unsigned char KEYBOARD;
extern bit KEYBOARD_COL1;
extern bit KEYBOARD_COL2;
extern bit KEYBOARD_COL3;
extern bit KEYBOARD_COL4;
extern bit KEYBOARD_ROW1;
extern bit KEYBOARD_ROW2;
extern bit KEYBOARD_ROW3;
extern bit KEYBOARD_ROW4;

extern void keyboard_init(const unsigned char type);
extern void keyboard_init_exec();
extern void keyboard_scan_init();
extern unsigned char keyboard_scan(const unsigned char row);
extern void do_job(const unsigned char pos);

#endif