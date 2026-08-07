/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_002821F0")))
void func_002821F0(void *a0) {
    char *s0 = (char *)a0;
    unsigned long t0 = 0;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x3C) + v, *(int *)(v + 0x40) + v, 0.0f, 5, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x14) + v, *(int *)(v + 0x18) + v, 0.0f, 5, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        break;
    case 2:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x44) + v, *(int *)(v + 0x48) + v, 0.0f, 5, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x1C) + v, *(int *)(v + 0x20) + v, 0.0f, 5, t0, 0);
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    case 4:
        if (*(unsigned char *)(s0 + 0x15B0)) {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x4C) + v, *(int *)(v + 0x50) + v, 0.0f, 5, t0, 0);
        } else {
            int v = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v + 0x24) + v, *(int *)(v + 0x28) + v, 0.0f, 5, t0, 0);
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
