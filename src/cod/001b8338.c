/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern float SetField444SignedByFlag434_158288(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int D_005864F0;

/* SN ProDG ee-gcc 2.95.3 matched TU. */






__attribute__((section(".text.func_001B8338")))
void func_001B8338(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    float r = cEmManage_GetSpeedRate(&D_005864F0);
    float f2 = *(float *)(s0 + 0x604);
    if (0.0f < f2) {
        *(float *)(s0 + 0x604) = f2 - r;
    }
    *(float *)(s0 + 0x5A8) = r;
    SetField444SignedByFlag434_158288(s0, r);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC) + v0, 0, 0.0f, 0, 0, 0);
        moveMotion(s0);
        *(unsigned short *)(s0 + 0x434) |= 8;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        break;
    case 1:
        break;
    case 2:
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 3:
        *(unsigned short *)(s0 + 0x434) |= 8;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x601) = 1;
        }
        break;
    case 4:
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        break;
    case 5:
        break;
    }
}
