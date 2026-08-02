/* sn-2.95.3-136 matched TU. */

extern int ForwardFieldNeg20_002A9680_30F5A0();
extern char D_00463050[];
extern int cCamManager_setSubScrCamera();

/* clone */

__attribute__((section(".text.CustomIDWork")))
int CustomIDWork(int a0) {
    *(int*)((char*)a0 + 0x0) = 0;
    *(int*)((char*)a0 + 0x8) = 0;
    *(int*)((char*)a0 + 0x28) = 0;
    *(int*)((char*)a0 + 0x48) = 0;
    *(int*)((char*)a0 + 0x5C) = 0;
    *(int*)((char*)a0 + 0x4) = 0;
    return a0;
}

/* clone */

__attribute__((section(".text.CustomIDWork_SetColorAnimNormal_2D68D8")))
void CustomIDWork_SetColorAnimNormal_2D68D8(int a0, int a1, int a2, int a3) {
    if (*(int*)((char*)a0 + 0x4) != 0) {
        a3 = a3 & 0xFFFF;
        *(int*)((char*)a0 + 0x50) = a1;
        *(int*)((char*)a0 + 0x48) = 3;
        *(int*)((char*)a0 + 0x54) = a2;
        *(short*)((char*)a0 + 0x58) = a3;
        if (a3 == 0) {
            *(short*)((char*)a0 + 0x58) = 1;
        }
        *(short*)((char*)a0 + 0x5A) = 0;
    }
}

/* clone */


__attribute__((section(".text.CustomIDWork__dtor")))
void CustomIDWork__dtor(int a0, int a1) {
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0();
    }
}

/* clone */



__attribute__((section(".text.Poker_SetPokerCamera")))
void Poker_SetPokerCamera(int a0, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(D_00463050, 0);
    *(int *)(a0 + 0x304C) = (int)(D_00463050 + 0xC90);
    dst1 = (float *)(D_00463050 + 0xEA0);
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(*(int *)(a0 + 0x304C) + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}

/* clone */



__attribute__((section(".text.cArea_HitCheck")))
int cArea_HitCheck(unsigned char *a0) {
    switch (a0[1]) {
    case 1:
        return func_001F85D0();
    case 2:
        return func_001F8810();
    }
    return 0;
}

/* clone */

__attribute__((section(".text.cCoreSave_setCasinoTicketNum")))
void cCoreSave_setCasinoTicketNum(void *a0, int a1) {
    if (!*(void **)a0)
        return;
    *(int *)((char *)*(void **)a0 + 0xB94) = a1;
    if (*(int *)((char *)*(void **)a0 + 0xB94) >= 0xA)
        *(int *)((char *)*(void **)a0 + 0xB94) = 9;
    if (*(int *)((char *)*(void **)a0 + 0xB94) < 0)
        *(int *)((char *)*(void **)a0 + 0xB94) = 0;
}
