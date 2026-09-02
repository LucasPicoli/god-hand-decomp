/* ee-2.9-991111 matched TU. */

extern void func_003BACA0(int, int);
extern unsigned char D_0045E400[];
extern void func_0039C390(void *, void *);
extern void func_003B63F0(void);

__attribute__((section(".text._clearEach")))
void _clearEach(void *m) {
    int oldstat;
    *(int *)((char *)m + 0x828) = 1;
    *(int *)((char *)m + 0x1C0) = 0;
    oldstat = func_003B63A0();
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 | 0x10000;
    *(volatile unsigned int *)0x1000B000 = 0;
    *(volatile unsigned int *)0x1000B400 = 0;
    *(volatile unsigned int *)0x1000D400 = 0;
    *(volatile unsigned int *)0x1000F590 = *(volatile unsigned int *)0x1000F520 & 0xFFFEFFFFU;
    if (oldstat != 0) func_003B63F0();
    *(volatile unsigned int *)0x1000B020 = 0;
    *(volatile unsigned int *)0x1000B420 = 0;
    *(volatile unsigned int *)0x1000D420 = 0;
    *(volatile unsigned int *)0x10002010 = 0x40000000;
    func_003BACA0(0, 0);
}

__attribute__((section(".text._clearOnce")))
void _clearOnce(void *m) {
    int mode;
    *(volatile unsigned int *)0x10002010 =
        (*(volatile unsigned int *)0x10002010 & 0xFF7FFFFFU) | 0x800000;
    mode = *(int *)((char *)m + 0x87C);
    if (mode == 0) {
        int spr = 0x70000000;
        *(int *)((char *)m + 0x830) = 0x70003600;
        *(int *)((char *)m + 0x5A0) = spr;
        *(int *)((char *)m + 0x5A4) = 0x70001800;
        *(int *)((char *)m + 0x6E0) = 0x70001B00;
        *(int *)((char *)m + 0x6E4) = 0x70003300;
        *(int *)((char *)m + 0x820) = 0;
        return;
    }
    if (mode == 1) {
        *(int *)((char *)m + 0x830) = (int)((char *)m + 0xE80);
        *(int *)((char *)m + 0x5A4) =
            (int)((((unsigned int)((char *)m + 0x880)) & 0x0FFFFFFFU) | 0x30000000U);
        *(int *)((char *)m + 0x6E4) =
            (int)((((unsigned int)((char *)m + 0xB80)) & 0x0FFFFFFFU) | 0x30000000U);
        *(int *)((char *)m + 0x5A0) = 0;
        *(int *)((char *)m + 0x6E0) = 0;
        *(int *)((char *)m + 0x820) = 0;
        return;
    }
    func_0039C390(m, D_0045E400);
}

__attribute__((section(".text._dualPrimeVector")))
void _dualPrimeVector(void *pic, int DMV[][2], int *dmvector, int mvx, int mvy) {
    if (*(int *)((char *)pic + 0x184) == 3) {
        if (*(int *)((char *)pic + 0x188)) {
            DMV[0][0] = ((mvx   + (mvx > 0)) >> 1) + dmvector[0];
            DMV[0][1] = ((mvy   + (mvy > 0)) >> 1) + dmvector[1] - 1;
            DMV[1][0] = ((3*mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[1][1] = ((3*mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        } else {
            DMV[0][0] = ((3*mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[0][1] = ((3*mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            DMV[1][0] = ((mvx   + (mvx > 0)) >> 1) + dmvector[0];
            DMV[1][1] = ((mvy   + (mvy > 0)) >> 1) + dmvector[1] + 1;
        }
    } else {
        DMV[0][0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
        DMV[0][1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1];
        if (*(int *)((char *)pic + 0x184) == 1)
            DMV[0][1]--;
        else
            DMV[0][1]++;
    }
}

__attribute__((section(".text.func_0039FDD8")))
void func_0039FDD8(unsigned int addr, int size) {
    int oldstat;
    oldstat = func_003B63A0();
    if ((addr >> 28) == 7) {
        addr &= 0x0FFFFFFFU;
        addr |= 0x80000000U;
    } else {
        addr &= 0x0FFFFFFFU;
    }
    *(volatile unsigned int *)0x1000B010 = addr;
    *(volatile unsigned int *)0x1000B020 = size >> 4;
    *(volatile unsigned int *)0x1000B000 = 0x100;
    if (oldstat != 0) func_003B63F0();
}
