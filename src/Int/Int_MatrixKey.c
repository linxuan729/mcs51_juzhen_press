#include "Int_MatrixKey.h"

static u8 s_candidate_key = 0;
static u8 s_candidate_count = 0;
static u8 s_stable_key = 0;

u8 Int_MatrixKey_CheckKey(void)
{
    u8 i;
    u8 j;
    u8 key;

    key = 0;
    for (i = 0; i < 4; i++)
    {
        P2 = 0xFF;
        P2 &= ~(1 << i);
        for (j = 4; j < 8; j++)
        {
            if ((P2 & (1 << j)) == 0)
            {
                key = i * 4 + j - 3;
                break;
            }
        }
        if (key != 0)
        {
            break;
        }
    }

    P2 = 0xFF;

    if (key == s_candidate_key)
    {
        if (s_candidate_count < 3)
        {
            s_candidate_count++;
        }
    }
    else
    {
        s_candidate_key = key;
        s_candidate_count = 1;
    }

    if (s_candidate_count >= 3 && s_stable_key != s_candidate_key)
    {
        s_stable_key = s_candidate_key;
        if (s_stable_key != 0)
        {
            return s_stable_key;
        }
    }

    return 0;
}