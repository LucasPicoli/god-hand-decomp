/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_0027F780")))
void func_0027F780(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    unsigned long t0 = 0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x2F7)) {
            int v1 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v1 + 0x48) + v1, *(int *)(v1 + 0x50) + v1, 0.0f, 5, t0, 0);
        } else {
            int v2 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v2 + 0x48) + v2, *(int *)(v2 + 0x4C) + v2, 0.0f, 5, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        goto L_mm;
    case 2:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x48) + v0, *(int *)(v0 + 0x58) + v0, 0.0f, 5, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    case 3:
    L_mm:
        moveMotion(s0);
        break;
    case 4:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x48) + v0, *(int *)(v0 + 0x60) + v0, 0.0f, 5, t0, 0);
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
