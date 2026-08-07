/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float SetField444SignedByFlag434_158288(void *a0, float f);

/* sn-2.95.3-136 matched TU. */







__attribute__((section(".text.func_00282BB0")))
void func_00282BB0(void *a0) {
    char *s0 = (char *)a0;
    unsigned long t0 = 0;
    float r = *(float *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0x5A8);
    *(float *)(s0 + 0x5A8) = r;
    SetField444SignedByFlag434_158288(s0, r);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x180) + v, *(int *)(v + 0x184) + v, 0.0f, 2, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x168) + v, *(int *)(v + 0x16C) + v, 0.0f, 2, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x188) + v, *(int *)(v + 0x18C) + v, 0.0f, 2, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x170) + v, *(int *)(v + 0x174) + v, 0.0f, 2, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    case 3:
    L_mm:
        moveMotion(s0);
        break;
    case 4:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x190) + v, *(int *)(v + 0x194) + v, 0.0f, 2, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x178) + v, *(int *)(v + 0x17C) + v, 0.0f, 2, t0, 0);
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
