/* sn-2.95.3-136 matched TU. */
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/cGameObj.h"


__attribute__((section(".text.func_00281B40")))
void func_00281B40(cGameObj *a0)
{
    long v;
    int obj;
    int b, lim;
    int spill[2];

    if (a0->emNo == 0x26C)
        return;
    if (a0->hp <= 0)
        return;
    if (*(int *)((char *)a0 + 0x670) == 0)
        return;
    v = *(unsigned int *)(*(int *)((char *)a0 + 0x670) + 0x60);
    if ((v & 1) == 0)
        return;
    if (0.0f < a0->hitFlash)
        return;

    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, (cObj *)a0, 0, 0, 0, 0);

    b = a0->partNum;
    spill[0] = b;
    lim = 4;
    if (lim < b)
        obj = *(int *)(*(int *)((char *)a0 + 0x278) + 0x10);
    else
        obj = 0;
    if (obj != 0)
        SetEffectPos(0x58, 0x10, 0, (void *)*(int *)(obj + 0xF0), 1.0f, -1);

    a0->hitFlash = 3.0f;
    if (a0->hpMax <= 0)
        a0->hp = *(unsigned short *)((char *)a0 + 0x548);
    else
        a0->hp = 0;
    *(char *)((char *)a0 + 0x2F4) = 2;
    *(char *)((char *)a0 + 0x2F5) = 0;
    *(char *)((char *)a0 + 0x2F6) = 0;
    *(char *)((char *)a0 + 0x2F7) = 0;
}
