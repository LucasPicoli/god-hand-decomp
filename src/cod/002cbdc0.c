/* sn-2.95.3-136 matched TU. */

extern char D_0076A7D4[];
extern char D_0076A790[];
extern char D_0076E590[];

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002CBDC0")))
void func_002CBDC0(char *a0, int b, int c, int d) {
    int i;
    int sc;
    i = *(int *)(a0 + 0x1E0) + 1;
    i %= 16;
    *(int *)(a0 + 0x1E0) = i;
    sc = i * 8;
    *(short *)(a0 + sc + 0x160) = b;
    sc = *(int *)(a0 + 0x1E0) * 8;
    *(short *)(a0 + sc + 0x162) = c;
    sc = *(int *)(a0 + 0x1E0) * 8;
    *(int *)(a0 + sc + 0x164) = d;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
typedef struct { char b[0x20]; } T32;


__attribute__((section(".text.func_00374980")))
void func_00374980(short i, void *dst) {
    *(T32 *)dst = *(T32 *)(D_0076A7D4 + i * 0x20);
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_00375748")))
void func_00375748(unsigned char f) {
    char *p;
    p = D_0076A790;
    if (f & 1)
        *(unsigned short *)(p + 0x22) |= 1;
    if (f & 2)
        *(unsigned short *)(p + 0x22) |= 4;
    if (f & 4)
        *(unsigned short *)(p + 0x22) |= 0x10;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_003779D0")))
void *func_003779D0(short key) {
    char *p;
    char *end;
    p = D_0076E590;
    end = D_0076E590 + 0x380;
    do {
        if (*(unsigned short *)p != 0 && (*(unsigned char *)(p + 8) & 0x10) == 0 &&
            *(short *)(p + 0xC) == key)
            return p;
        p += 0x70;
    } while ((int)p < (int)end);
    return 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0037C160")))
void func_0037C160(char *d, char *s) {
    *(unsigned short *)(d + 0x00) = *(unsigned short *)(s + 0x00);
    *(unsigned char *)(d + 0x04) = *(unsigned char *)(s + 0x0C);
    *(unsigned char *)(d + 0x05) = *(unsigned char *)(s + 0x0D);
    *(int *)(d + 0x0C) = 0;
    *(int *)(d + 0x10) = *(int *)(s + 0x04);
    *(int *)(d + 0x14) = *(int *)(s + 0x08);
    *(unsigned short *)(d + 0x18) = *(unsigned short *)(s + 0x12);
    *(unsigned short *)(d + 0x1A) = *(unsigned short *)(s + 0x20);
    *(unsigned short *)(d + 0x1C) = *(unsigned short *)(s + 0x22);
    *(unsigned char *)(d + 0x1E) = *(unsigned char *)(s + 0x28);
    *(unsigned short *)(d + 0x06) = *(unsigned short *)(s + 0x48);
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_003810F8")))
void func_003810F8(char *a0, char *a1) {
    int v;
    unsigned int w;
    if (*(int *)(a1 + 0x38) & 0x8000) {
        v = *(unsigned char *)(a0 + 5);
        *(unsigned char *)(a0 + 5) = (v == 0) ? 9 : v - 1;
    }
    if (*(int *)(a1 + 0x38) & 0x2000) {
        w = *(unsigned char *)(a0 + 5);
        if (w < 9) *(unsigned char *)(a0 + 5) = w + 1;
        else *(unsigned char *)(a0 + 5) = 0;
    }
}
