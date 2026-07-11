/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_00282578")))
void func_00282578(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)(s0 + 0x15B0)) t0 = two;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x138) + v0, *(int *)(v0 + 0x13C) + v0, 0.0f, 5, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x140) + v0, *(int *)(v0 + 0x144) + v0, 0.0f, 5, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
    case 3:
    L_mm:
        moveMotion(s0);
        break;
    case 4:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x148) + v0, *(int *)(v0 + 0x14C) + v0, 0.0f, 5, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 5:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    case 6:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x150) + v0, *(int *)(v0 + 0x154) + v0, 0.0f, 5, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 7:
        moveMotion(s0);
        break;
    }
}
