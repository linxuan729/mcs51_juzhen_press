#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"


void main(void)
{
    Int_DigitalTube_Init();
    while(1)
    {
        u8 key = Int_MatrixKey_CheckKey();
        if (key != 0)
        {
            Int_DigitalTube_DisplayNum(key);
            Int_DigitalTube_Refresh();
        }
    }
}
