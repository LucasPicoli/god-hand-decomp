/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002827C8")))
void func_002827C8(void *a0) {
    char *s0 = (char *)a0;
    int v0;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)(s0 + 0x15B0)) t0 = two;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        default:
        case 0:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0xC0) + v0, *(int *)(v0 + 0xC4) + v0, 0.0f, 2, t0, 0);
            break;
        case 1:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0xB8) + v0, *(int *)(v0 + 0xBC) + v0, 0.0f, 2, t0, 0);
            break;
        case 2:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0xC8) + v0, *(int *)(v0 + 0xCC) + v0, 0.0f, 2, t0, 0);
            break;
        case 3:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0xD0) + v0, *(int *)(v0 + 0xD4) + v0, 0.0f, 2, t0, 0);
            break;
        case 4:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0xD8) + v0, *(int *)(v0 + 0xDC) + v0, 0.0f, 2, t0, 0);
            break;
        case 5:
            v0 = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(v0 + 0xD0) + v0, *(int *)(v0 + 0xD4) + v0, 0.0f, 2, t0, 0);
            break;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        moveMotion(s0);
        break;
    }
}
