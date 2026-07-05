/* sn-2.95.3-136 matched TU. */

extern void func_001E4520(char *a0, int a1);
extern void func_001E4200(char *a0, int a1, int a2, int a3);
extern void func_001E4438(char *a0, int a1, int a2);
extern void displayScrollLayer(int a0, int a1);
extern int D_005FEE00;
extern void cSnd_SeCall_2CBA48(int *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);

__attribute__((section(".text.func_001E2EB8")))
void func_001E2EB8(char *a0)
{
    long v;
    int done;

    switch (*(int *)(a0 + 0xC)) {
    case 0:
        v = *(unsigned int *)(a0 + 0x54);
        *(short *)(a0 + 0x4C2) = 0xA;
        if (((v >> 8) & 1) == 0) {
            func_001E4520(a0, 1);
            *(int *)(a0 + 0x54) |= 0x100;
        }
        *(int *)(a0 + 0xC) += 1;
        break;
    case 1:
        func_001E4200(a0, *(unsigned short *)(a0 + 0x494), 1, 1);
        func_001E4438(a0, 0, 1);
        *(int *)(a0 + 0x10) = 0x78;
        *(int *)(a0 + 0xC) += 1;
        break;
    case 2:
        if (*(int *)(a0 + 0x10) != 0) {
            *(int *)(a0 + 0x10) -= 1;
            done = 0;
        } else {
            done = 1;
        }
        if ((done & 0xFF) != 0) {
            func_001E4200(a0, *(unsigned short *)(a0 + 0x494), 0, 0);
            *(int *)(a0 + 0xC) += 1;
        }
        break;
    case 3:
        *(int *)(a0 + 0x4) = 0;
        *(int *)(a0 + 0x8) = 0;
        *(int *)(a0 + 0xC) = 0;
        break;
    }
}

__attribute__((section(".text.func_001E4610")))
void func_001E4610(char *a0)
{
    long v;

    if (*(int *)(a0 + 0x4B0) == 0)
        return;
    if (*(int *)(a0 + 0x4B4) == 0)
        return;
    v = *(unsigned int *)(a0 + 0x54);
    if (((v >> 9) & 1) == 0)
        return;

    *(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) -= 1.0f;
    *(float *)(*(int *)(*(int *)(a0 + 0x4B4) + 0xF0)) -= 1.0f;

    if (*(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) < -130.0f) {
        *(int *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) = 0;
        *(int *)(*(int *)(*(int *)(a0 + 0x4B4) + 0xF0)) = 0;
    }

    if (*(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) < -50.0f &&
        *(float *)(*(int *)(*(int *)(a0 + 0x4B0) + 0xF0)) > -60.0f) {
        displayScrollLayer(*(int *)(a0 + 0x458), 1);
        displayScrollLayer(*(int *)(a0 + 0x488), 1);
    } else {
        displayScrollLayer(*(int *)(a0 + 0x458), 0);
        displayScrollLayer(*(int *)(a0 + 0x488), 0);
    }
}

__attribute__((section(".text.func_0027BDD8")))
void func_0027BDD8(char *a0)
{
    long v;
    int obj;
    int b, lim;
    int spill[2];

    if (*(int *)(a0 + 0x564) == 0x263)
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
