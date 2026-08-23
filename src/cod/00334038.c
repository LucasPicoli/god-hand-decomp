/* cygnus-2.96 matched TU. */

extern signed char D_003D9FE0[];

__attribute__((section(".text.func_00334038")))
int func_00334038(void) {
    signed char *p = D_003D9FE0;
    int i;
    for (i = 0; i < 13; i++) {
        if (p[0] == 1 && p[2] == 2) return 1;
        p += 0x30;
    }
    return 0;
}
