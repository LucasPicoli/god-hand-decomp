/* sn-2.95.3-136 matched TU. */

extern unsigned int D_00747A80;
extern char D_0076CF20[];

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0031EC48")))
void func_0031EC48(unsigned int *src, int *out) {
    unsigned int x;
    unsigned int m;
    unsigned int e;
    unsigned int sign;
    unsigned int es;

    x = *src;
    sign = x >> 31;
    es = x >> 23;
    es = es & 0xFF;
    m = x & 0x7FFFFF;
    e = es;
    out[1] = sign;
    if (e == 0) {
        out[0] = 2;
        return;
    }
    if (e == 0xFF) {
        if (m == 0) {
            out[0] = 4;
            return;
        }
        if ((m & 0x100000) != 0) {
            out[0] = 1;
        } else {
            out[0] = 0;
        }
        out[3] = m;
        return;
    }
    out[2] = e - 0x7F;
    out[0] = 3;
    out[3] = (m << 7) | 0x40000000;
}

__attribute__((section(".text.func_001F6B78")))
void func_001F6B78(int a0, int on) {
    if (on) {
        unsigned int v = D_00747A80;
        v |= 0x04000000;
        v |= 0x02000000;
        v |= 0x40000000;
        v |= 0x80000000;
        v |= 0x00200000;
        v |= 0x20000000;
        v |= 0x10000000;
        v |= 0x08000000;
        D_00747A80 = v;
    } else {
        unsigned int v = D_00747A80;
        v &= ~0x04000000;
        v &= ~0x02000000;
        v &= ~0x40000000;
        v &= ~0x80000000;
        v &= ~0x00200000;
        v &= ~0x20000000;
        v &= ~0x10000000;
        v &= ~0x08000000;
        D_00747A80 = v;
    }
}

__attribute__((section(".text.func_0037A8F8")))
short func_0037A8F8(char *a, char *b, short v) {
    short d;
    if (*(int *)(a + 0x2C) & 8) d = *(short *)(b + 0x10);
    else d = *(short *)(b + 0xE);
    if (*(int *)(a + 0x2C) & 0x80) {
        int m = *(int *)(a + 0x34);
        if (m & 0x8000) v = (short)*(unsigned short *)(b + 0xA);
        if (m & 0x2000) v = (short)*(unsigned short *)(b + 0xC);
        if (m & 0x1000) v = 0;
        if (m & 0x4000) v = 0;
    } else {
        int n = *(int *)(a + 0x38);
        if (n & 0x8000) v = v - d;
        if (n & 0x2000) v = v + d;
    }
    if (v < (short)*(unsigned short *)(b + 0xA)) v = (short)*(unsigned short *)(b + 0xC);
    if ((short)*(unsigned short *)(b + 0xC) < v) v = (short)*(unsigned short *)(b + 0xA);
    return v;
}

__attribute__((section(".text.func_00376D28")))
void func_00376D28(char *o, unsigned short mode) {
    int i;
    for (i = 0; i < 48; i++) {
        char *e = D_0076CF20 + i * 0x50;
        if (*(unsigned short *)e == 0) continue;
        if ((*(unsigned char *)(e + 5) & 4) == 0) continue;
        if (*(int *)(e + 0x14) != *(int *)(o + 4)) continue;
        switch (mode) {
        case 1:
            *(unsigned short *)(e + 0x26) = *(unsigned short *)(o + 0x24);
            *(unsigned short *)(e + 0x28) = *(unsigned short *)(o + 0x26);
            *(unsigned short *)(e + 6) |= 9;
            break;
        case 2:
            *(unsigned short *)(e + 0x2C) = *(unsigned short *)(o + 0x28);
            *(unsigned short *)(e + 6) |= 0xA;
            break;
        case 4:
            *(unsigned short *)(e + 0x2E) = *(unsigned short *)(o + 0x2A);
            *(unsigned short *)(e + 6) |= 4;
            break;
        }
    }
}

__attribute__((section(".text.func_0031BC98")))
void func_0031BC98(char *p, int idx) {
    int off = idx * 16 + 0x160;
    char *e = p + off;
    {
        int f1 = *(unsigned char *)e;
        if (f1 & 1) *(unsigned char *)(p + 0x360) = 1;
    }
    {
        int f = *(unsigned char *)e;
        if (f & 4) {
            *(unsigned char *)(e + 1) = *(unsigned char *)(e + 2);
            *(unsigned short *)(e + 0xA) =
                ((*(unsigned char *)(e + 2) - *(unsigned char *)(e + 3)) << 4) /
                *(unsigned short *)(e + 6);
            *(unsigned char *)e = f & 3;
            *(unsigned short *)(e + 0xC) = 0;
        }
    }
    {
        int f3 = *(unsigned char *)e;
        if (f3 & 2) {
            short d = *(short *)(e + 0xC);
            if (d != 0) {
                *(unsigned char *)(e + 1) = ((*(unsigned char *)(e + 2) << 4) - d) / 16;
            }
            if (*(unsigned char *)(p + 0x361) < *(unsigned char *)(e + 1))
                *(unsigned char *)(p + 0x361) = *(unsigned char *)(e + 1);
        }
    }
    if (*(short *)(e + 0xA) != 0) {
        *(unsigned short *)(e + 0xC) += *(unsigned short *)(e + 0xA);
    }
}
