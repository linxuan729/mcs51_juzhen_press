#include "Int_DigitalTube.h"
#define SMG_EN P36
#define LED_EN P34

static u8 s_digital_codes[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
static u8 s_digital_buffer[8] = {0};


void Int_DigitalTube_DisplayNum(u32 num)
{

    u16 i,j;
    if (num == 0)
    {
        s_digital_buffer[7] = s_digital_codes[0];
        return;
    }

    j = 0;
    while(j < 8)
    {
        s_digital_buffer[j] = 0;
        j++;
    }

    i = 7;
    while(num > 0 && i >= 0)
    {
        s_digital_buffer[i] = s_digital_codes[num % 10];
        num /= 10;
        i--;
    }
}


void Int_DigitalTube_Init(void)
{
    SMG_EN = 0;
    LED_EN = 0;
}


void Int_DigitalTube_DisplaySingle(u8 dig, u8 dat){
    P0 = 0;
    P0 = dat;

    P1 &= ~0x38;
    P1 |= (dig << 3);
    
}

void Int_DigitalTube_Refresh(void)
{
    u8 i = 0;
    for(i = 0; i < 8; i++)
    {
        Int_DigitalTube_DisplaySingle(i, s_digital_buffer[i]);
        delay_ms(1);
    }
}