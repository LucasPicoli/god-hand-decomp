/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float SetField444SignedByFlag434_158288(void *a0, float f);

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_002808D8")))
void func_002808D8(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    unsigned long t0 = 0;
    float r = *(float *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0x5A8);
    *(float *)(s0 + 0x5A8) = r;
    SetField444SignedByFlag434_158288(s0, r);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x168) + v0, *(int *)(v0 + 0x16C) + v0, 0.0f, 2, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x170) + v0, *(int *)(v0 + 0x174) + v0, 0.0f, 2, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    case 3:
    L_mm:
        moveMotion(s0);
        break;
    case 4:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x178) + v0, *(int *)(v0 + 0x17C) + v0, 0.0f, 2, t0, 0);
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
