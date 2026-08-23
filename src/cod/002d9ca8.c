/* sn-2.95.3-136 matched TU. */

extern char D_00747A78[];

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_002D9CA8")))
void func_002D9CA8(int *a0) {
    char *p;
    int f;
    long t;
    p = D_00747A78;
    if ((*(int *)D_00747A78 & 0x2000) != 0) {
        return;
    }
    t = *(int *)(p - 0x54);
    if ((((unsigned long)t >> 3) & 1UL) == 1UL) {
        return;
    }
    f = *(int *)(p + 0xC);
    if ((f & 0x2000000) != 0) {
        return;
    }
    p = p - 0x5D8;
    if (*(unsigned short *)(p + 0x5B0) == 0x21) {
        return;
    }
    if ((*(int *)(p + 0x594) & 0x800) != 0) {
        if ((f & 0x8000000) != 0) {
            return;
        }
    }
    if (*(unsigned char *)(p + 0x569) == 1) {
        if ((*(int *)(p + 0x210) & 1) == 0) {
            return;
        }
    }
    a0[1] = a0[1] + 1;
}
