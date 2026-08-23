/* sn-2.95.3-136 matched TU. */

extern signed char D_003F2620[];

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0026A338")))
void func_0026A338(char *o) {
    int st;

    st = *(int *)(o + 0x564);
    if (st == 0x223) {
        goto B;
    }
    if (st < 0x223) {
        goto A;
    }
    if (!(st < 0x277)) {
        goto A;
    }
    if (!(st < 0x275)) {
        goto B;
    }
A:
    if ((*(unsigned char *)(o + 0x1700) & 1) != 0) {
        *(float *)(o + 0x16FC) = 0.261799395f;
    } else {
        *(float *)(o + 0x16FC) = -0.261799395f;
    }
    goto done;
B:
    if ((*(unsigned char *)(o + 0x1700) & 1) != 0) {
        *(float *)(o + 0x16FC) = 0.122173049f;
    } else {
        *(float *)(o + 0x16FC) = -0.122173049f;
    }
done:
    *(char *)(o + 0x1700) = *(unsigned char *)(o + 0x1700) + 1;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.cCockScroll_OnScroll")))
void cCockScroll_OnScroll(char *o, unsigned short a, unsigned short kind) {
    int n;
    int v;
    int off;
    char *p;

    n = *(short *)(o + 0x100);
    if (n < 4) {
        if (kind == 0) {
            goto k0;
        }
        if (kind == 1) {
            goto k1;
        }
        goto skip;
k0:
        off = n * 2;
        v = a + 0x30D1;
        goto st;
k1:
        off = n * 2;
        v = a + 0x304E;
st:
        *(short *)(o + off + 0xF0) = v;
skip:
        if ((*(unsigned char *)(o + 0x104) & 2) != 0) {
            p = *(char **)(o + 0x90);
            *(float *)(p + 0x38) = *(float *)(p + 0x38) + 50.0f;
        }
        *(char *)(o + 0x104) = *(unsigned char *)(o + 0x104) & 0xFD;
        v = *(short *)(o + 0x100) * 2;
        *(short *)(o + v + 0xF8) = kind;
        *(short *)(o + 0x100) = *(unsigned short *)(o + 0x100) + 1;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_0037A6A8")))
int func_0037A6A8(char *a0) {
    int old;
    int t;
    int lim;

    lim = D_003F2620[*(signed char *)(a0 + 0x7)];
    t = *(unsigned char *)(a0 + 0x25);
    old = *(signed char *)(a0 + 0x25);
    if ((*(int *)(a0 + 0x2C) & 0x80) != 0) {
        return 0;
    }
    if ((*(int *)(a0 + 0x38) & 0x1000) != 0) {
        *(char *)(a0 + 0x25) = t - 1;
    }
    if ((*(int *)(a0 + 0x38) & 0x4000) != 0) {
        *(char *)(a0 + 0x25) = *(unsigned char *)(a0 + 0x25) + 1;
    }
    if (*(signed char *)(a0 + 0x25) < 0) {
        *(char *)(a0 + 0x25) = lim - 1;
    }
    if (*(signed char *)(a0 + 0x25) >= lim) {
        *(char *)(a0 + 0x25) = 0;
    }
    return (*(signed char *)(a0 + 0x25) ^ old) != 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_003762D8")))
void func_003762D8(char *d, char *s) {
    if ((*(unsigned short *)(s + 0x1A) & 1) != 0) {
        *(short *)(d + 0x20) = *(unsigned short *)(s + 0x28);
        *(short *)(d + 0x12) = *(unsigned short *)(d + 0x12) | 1;
    }
    if ((*(unsigned short *)(s + 0x1A) & 2) != 0) {
        *(short *)(d + 0x22) = *(unsigned short *)(s + 0x2A);
        *(short *)(d + 0x12) = *(unsigned short *)(d + 0x12) | 1;
    }
    if ((*(unsigned short *)(s + 0x1A) & 4) != 0) {
        *(short *)(d + 0x28) = *(unsigned short *)(s + 0x2C);
        *(short *)(d + 0x12) = *(unsigned short *)(d + 0x12) | 2;
    }
    if ((*(unsigned short *)(s + 0x1A) & 8) != 0) {
        *(short *)(d + 0x2A) = *(unsigned short *)(s + 0x34);
        *(short *)(d + 0x12) = *(unsigned short *)(d + 0x12) | 4;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0031DFA8")))
void func_0031DFA8(unsigned long *src, int *out) {
    unsigned long x;
    unsigned long m;
    unsigned int e;
    unsigned long sign;

    x = *src;
    sign = x >> 63;
    m = x & 0xFFFFFFFFFFFFFUL;
    e = (unsigned int)(x >> 52) & 0x7FF;
    out[1] = sign;
    if (e == 0) {
        out[0] = 2;
        do { } while (0);
        return;
    }
    if (e == 0x7FF) {
        if (m == 0) {
            out[0] = 4;
            return;
        }
        if ((m & 0x8000000000000UL) != 0) {
            out[0] = 1;
        } else {
            out[0] = 0;
        }
        *(unsigned long *)(out + 4) = m;
        return;
    }
    out[2] = e - 0x3FF;
    out[0] = 3;
    *(unsigned long *)(out + 4) = (m << 8) | 0x1000000000000000UL;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00383478")))
void func_00383478(char *o, char *s) {
    unsigned char b;
    char *p;
    int lim;
    int f;
    int cur;

    p = o + 0x370;
    if ((*(unsigned char *)(p + 3) & 1) != 0) {
        char *q = o + 0x414;
        if (*(int *)(q + 0x20) != 0) {
            lim = *(int *)(q + 0x8);
            goto have;
        }
    } else if (*(int *)(p + 0x64) != 0) {
        lim = 0;
        goto have;
    }
    lim = 0;
    if ((*(unsigned char *)(p + 3) & 2) != 0) {
        lim = *(int *)(p + 0xD4);
    }
have:
    f = *(int *)(s + 0x38);
    if ((f & 4) != 0) {
        cur = *(unsigned char *)(p + 4);
        if (cur != 0) {
            *(char *)(p + 4) = cur - 1;
        } else {
            *(char *)(p + 4) = lim;
        }
        return;
    }
    if ((f & 8) != 0) {
        b = *(unsigned char *)(p + 4);
        cur = b;
        if (cur < lim) {
            *(char *)(p + 4) = cur + 1;
        } else {
            *(char *)(p + 4) = 0;
        }
    }
}
