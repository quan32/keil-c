#inndef marco_h
#define marco_h

#define setBit(port,pin) (*port |= (1 << (pin)))
#define clearBit(port,pin) (*port &= ~(1 << (pin)))

#endif