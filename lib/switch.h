#ifndef switch_h
#define swtich_h

static struct SWITCH_CONTROL *switch_ctrl;

extern void switch_init(const unsigned char type);
extern void switch_init_exec();
extern void switch_do_job();

#endif