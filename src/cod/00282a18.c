/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_00282A18")))
void func_00282A18(void *a0) {
    char *s0 = (char *)a0;
    unsigned long t0 = 0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x120) + v, *(int *)(v + 0x124) + v, 0.0f, 2, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x108) + v, *(int *)(v + 0x10C) + v, 0.0f, 2, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x128) + v, *(int *)(v + 0x12C) + v, 0.0f, 2, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x110) + v, *(int *)(v + 0x114) + v, 0.0f, 2, t0, 0);
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
            func_002A8578(s0, *(int *)(v + 0x130) + v, *(int *)(v + 0x134) + v, 0.0f, 2, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x118) + v, *(int *)(v + 0x11C) + v, 0.0f, 2, t0, 0);
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
