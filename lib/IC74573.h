#ifndef IC74573_h
#define IC74573_h

extern bit IC74573_LE1;
extern bit IC74573_LE2;
extern data unsigned char IC74573_DATA;

void IC74573_transfer_data(const unsigned char c, const unsigned char i);

#endif