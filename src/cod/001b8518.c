/* sn-2.95.3-136 matched TU. */

extern void KillEffect(void *a0, int a1, int a2);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void cSnd_SeStop(void *a0, int a1);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int cCoreSave_getGameLevel(void *a0);
extern int D_005FEE00[];
extern int D_00569B70;

/* SN ProDG ee-gcc 2.95.3 matched TU. */








__attribute__((section(".text.cOmbb__clearFire")))
void cOmbb__clearFire(void *arg) {
    char *s0 = (char *)arg;
    int se;
    float f;
    KillEffect(s0, 0, 2);
    SetEffect(1, 2, s0, 0, 0, 0xFFFFFFFFU);
    se = *(int *)(s0 + 0x608);
    if (se != 0) {
        cSnd_SeStop(D_005FEE00, se);
    }
    *(int *)(s0 + 0x608) = 0;
    cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x16, s0, 0, 0, 0, 0);
    switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
    case 0:
    default: *(float *)(s0 + 0x604) = 450.0f; break;
    case 1: *(float *)(s0 + 0x604) = 350.0f; break;
    case 2: *(float *)(s0 + 0x604) = 250.0f; break;
    case 3: *(float *)(s0 + 0x604) = 250.0f; break;
    case 4: *(float *)(s0 + 0x604) = 150.0f; break;
    }
    (void)f;
    *(unsigned char *)(s0 + 0x2F4) = 0;
    *(unsigned char *)(s0 + 0x2F6) = 4;
    *(unsigned char *)(s0 + 0x600) = 0;
}
