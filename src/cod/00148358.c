/* sn-2.95.3-136 matched TU. */

extern char *D_00754C38;

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.displayScrollLayer")))
void displayScrollLayer(int id, int on) {
    char **a2;
    char *obj;
    unsigned int n;
    a2 = *(char ***)((char *)D_00754C38 + 4);
    if (a2 != *(char ***)((char *)D_00754C38 + 8)) {
        do {
            obj = *a2;
            n = *(unsigned char *)(obj + 0x2FD);
            if (id == n) {
                if (on) {
                    *(int *)(obj + 0x250) &= 0xFFFFFFFD;
                } else {
                    *(int *)(obj + 0x250) |= 2;
                }
            }
            a2++;
        } while (a2 != *(char ***)((char *)D_00754C38 + 8));
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0037C1B8")))
void func_0037C1B8(char *d, char *s) {
    *(unsigned short *)(d + 0x0) = *(unsigned short *)(s + 0x0);
    *(unsigned char *)(d + 0x4) = *(unsigned char *)(s + 0xC);
    *(unsigned char *)(d + 0x5) = *(unsigned char *)(s + 0xD);
    *(unsigned short *)(d + 0x6) = 0;
    *(int *)(d + 0xC) = 0;
    *(int *)(d + 0x10) = *(int *)(s + 0x4);
    *(int *)(d + 0x14) = *(int *)(s + 0x8);
    *(unsigned short *)(d + 0x18) = *(unsigned short *)(s + 0x12);
    *(unsigned short *)(d + 0x1A) = *(unsigned short *)(s + 0x14);
    *(unsigned short *)(d + 0x1C) = *(unsigned short *)(s + 0x20);
    *(unsigned short *)(d + 0x1E) = *(unsigned short *)(s + 0x22);
    *(unsigned short *)(d + 0x20) = *(unsigned short *)(s + 0x24);
    *(unsigned short *)(d + 0x22) = *(unsigned short *)(s + 0x2C);
    *(unsigned short *)(d + 0x24) = *(unsigned short *)(s + 0x16);
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00148358")))
void *func_00148358(char *p) {
    *(int *)(p + 0x38C) = 0;
    *(int *)(p + 0x390) = 0;
    *(float *)(p + 0x1B0) = 1.0f;
    *(float *)(p + 0x1B4) = 0.0f;
    *(float *)(p + 0x1B8) = 0.0f;
    *(float *)(p + 0x1C0) = 0.0f;
    *(float *)(p + 0x1C4) = 1.0f;
    *(float *)(p + 0x1C8) = 0.0f;
    *(float *)(p + 0x1D0) = 0.0f;
    *(float *)(p + 0x1D4) = 0.0f;
    *(float *)(p + 0x1D8) = 1.0f;
    *(float *)(p + 0x280) = 1.0f;
    *(float *)(p + 0x284) = 0.0f;
    *(float *)(p + 0x288) = 0.0f;
    *(float *)(p + 0x290) = 0.0f;
    *(float *)(p + 0x294) = 1.0f;
    *(float *)(p + 0x298) = 0.0f;
    *(float *)(p + 0x2A0) = 0.0f;
    *(float *)(p + 0x2A4) = 0.0f;
    *(float *)(p + 0x2A8) = 1.0f;
    *(int *)(p + 0x404) = 0;
    *(int *)(p + 0x408) = 0;
    *(int *)(p + 0x410) = 0;
    return p;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0037B798")))
int func_0037B798(char *p) {
    int old;
    old = *(char *)(p + 0x28);
    if (*(int *)(p + 0x38) & 0x1000) *(char *)(p + 0x28) = *(char *)(p + 0x28) - 1;
    if (*(int *)(p + 0x38) & 0x4000) *(char *)(p + 0x28) = *(char *)(p + 0x28) + 1;
    if (*(char *)(p + 0x28) < 0) *(char *)(p + 0x28) = 5;
    if (*(char *)(p + 0x28) >= 6) *(char *)(p + 0x28) = 0;
    return *(char *)(p + 0x28) != old;
}
