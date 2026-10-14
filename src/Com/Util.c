#include "Util.h"


void delay_ms(u32 ms){
    u8 i, j;
    while (ms > 0)
    {
        ms--;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}