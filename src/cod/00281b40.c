/* sn-2.95.3-136 matched TU. */

extern int D_005FEE00;
extern void cSnd_SeCall_2CBA48(int *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);

__attribute__((section(".text.func_00281B40")))
void func_00281B40(char *a0)
{
    long v;
    int obj;
    int b, lim;
    int spill[2];

    if (*(int *)(a0 + 0x564) == 0x26C)
        return;
    if (*(short *)(a0 + 0x54A) <= 0)
        return;
    if (*(int *)(a0 + 0x670) == 0)
        return;
    v = *(unsigned int *)(*(int *)(a0 + 0x670) + 0x60);
    if ((v & 1) == 0)
        return;
    if (0.0f < *(float *)(a0 + 0x54C))
        return;

    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xA, a0, 0, 0, 0, 0);

    b = *(unsigned char *)(a0 + 0x2B4);
    spill[0] = b;
    lim = 4;
    if (lim < b)
        obj = *(int *)(*(int *)(a0 + 0x278) + 0x10);
    else
        obj = 0;
    if (obj != 0)
        SetEffectPos(0x58, 0x10, 0, (void *)*(int *)(obj + 0xF0), -1, 1.0f);

    *(float *)(a0 + 0x54C) = 3.0f;
    if (*(short *)(a0 + 0x548) <= 0)
        *(short *)(a0 + 0x54A) = *(unsigned short *)(a0 + 0x548);
    else
        *(short *)(a0 + 0x54A) = 0;
    *(char *)(a0 + 0x2F4) = 2;
    *(char *)(a0 + 0x2F5) = 0;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F7) = 0;
}
