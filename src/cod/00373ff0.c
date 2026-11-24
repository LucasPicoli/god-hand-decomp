/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"

extern short D_003F2060[];
extern int SdeSystemOutModeGet(void);

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.func_00373FF0")))
void func_00373FF0(char *p, int idx, float x)
{
    float t;

    if (*(int *)p == 0) {
        return;
    }
    t = x * D_005FEE00.unk00[idx] / 127.0f;
    t = t * D_005FEE00.unk0C[idx] / 127.0f;
    if (SdeSystemOutModeGet() == 2) {
        t = t * *(float *)(p + 0x34);
    }
    t = t * *(float *)(p + 0x2C);
    if (t >= 127.0f) {
        t = 127.0f;
    }
    ADXT_SetOutVol(*(int *)p, D_003F2060[(int)t]);
    *(float *)(p + 0x14) = x;
}
