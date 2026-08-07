/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_0027C888")))
void func_0027C888(void *a0) {
    char *s0 = (char *)a0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0xC, s0, 0, 0, 0, 0);
        if (*(unsigned char *)(s0 + 0x2F7)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x60) + v, *(int *)(v + 0x64) + v, 0.0f, 0, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x48) + v, *(int *)(v + 0x4C) + v, 0.0f, 0, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        if (*(unsigned char *)(s0 + 0x2F7)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x68) + v, *(int *)(v + 0x6C) + v, 0.0f, 3, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x50) + v, *(int *)(v + 0x54) + v, 0.0f, 3, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    case 3:
    L_mm:
        moveMotion(s0);
        break;
    case 4:
        if (*(unsigned char *)(s0 + 0x2F7)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x70) + v, *(int *)(v + 0x74) + v, 0.0f, 3, 0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x58) + v, *(int *)(v + 0x5C) + v, 0.0f, 3, 0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 5:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    }
}
