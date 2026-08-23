/* sn-2.95.3-136 matched TU. */

extern int D_00747A84;

__attribute__((section(".text.cDvd_Check")))
int cDvd_Check(char *base, int h)
{
    char *e;
    char *p;
    char *q;
    char *end;

    if (h == 0) {
        return 0;
    }
    end = base + 0x1104;
    e = *(char **)base;
    if (e != 0) {
        if (*(int *)(e + 4) == h) {
            return 2;
        }
    }
    p = base + 4;
    q = base + 8;
    do {
        if (*(int *)p != 0) {
            if (*(int *)q == h) {
                return 1;
            }
        }
        p = p + 0x88;
        q = q + 0x88;
    } while ((int)p < (int)end);
    return 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_0037AD08")))
int func_0037AD08(char *a0) {
    int old;
    int t;
    t = *(unsigned char *)(a0 + 0x26);
    old = *(signed char *)(a0 + 0x26);
    if ((*(int *)(a0 + 0x2C) & 0x80) != 0) {
        return 0;
    }
    if ((*(int *)(a0 + 0x38) & 0x1000) != 0) {
        *(char *)(a0 + 0x26) = t - 1;
    }
    if ((*(int *)(a0 + 0x38) & 0x4000) != 0) {
        *(char *)(a0 + 0x26) = *(unsigned char *)(a0 + 0x26) + 1;
    }
    if (*(signed char *)(a0 + 0x26) < 0) {
        *(char *)(a0 + 0x26) = 6;
    }
    if (*(signed char *)(a0 + 0x26) >= 7) {
        *(char *)(a0 + 0x26) = 0;
    }
    return (*(signed char *)(a0 + 0x26) ^ old) != 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_002D8E18")))
void func_002D8E18(char *a0, int a1, short a2) {
    int n;
    if ((*(int *)(a0 + 0x16284) & 0x10) != 0) {
        return;
    }
    n = 0;
    if ((D_00747A84 & 0x20000000) == 0) {
        n = a2;
    }
    *(char *)(a0 + 0x16168) = a1;
    *(short *)(a0 + 0x16280) = 0;
    *(short *)(a0 + 0x16282) = n;
    if (n <= 0) {
        *(float *)(a0 + 0x1616C) = 1.0f;
    } else {
        *(int *)(a0 + 0x1616C) = 0;
    }
    *(unsigned int *)(a0 + 0x16284) = (*(unsigned int *)(a0 + 0x16284) | 0x10) & 0xFFFFFFDF;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002A9708")))
void func_002A9708(char *a0) {
    int align;
    int size;
    int pad;
    int blk;
    int n;
    int sz2;
    char *p;
    char *q;
    char *e;
    char *t;
    align = *(int *)(a0 + 0xC);
    size = *(int *)(a0 + 0x4);
    pad = align + 7;
    blk = (size + pad) & -align;
    n = *(int *)(a0 + 0x8);
    p = *(char **)(a0 + 0x0);
    if (n != 0) {
        do {
            q = p + *(int *)(a0 + 0x4);
            n--;
            *(char **)(q + 0x0) = q - blk;
            *(char **)(q + 0x4) = q + blk;
            p += blk;
        } while (n != 0);
    }
    sz2 = *(int *)(a0 + 0x4);
    e = *(char **)(a0 + 0x0) + sz2;
    *(int *)e = 0;
    t = *(char **)(a0 + 0x0) + blk * (*(int *)(a0 + 0x8) - 1) + *(int *)(a0 + 0x4);
    *(int *)(t + 0x4) = 0;
    *(char **)(a0 + 0x10) = e;
    *(int *)(a0 + 0x14) = 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002AABA0")))
void func_002AABA0(char *a0) {
    int i;
    char *p;
    if (*(unsigned char *)(a0 + 0x1C) == 0) return;
    for (i = 0; i < *(int *)(a0 + 0xC); i++) {
        p = *(char **)(a0 + 0x4) + i * 0xAC;
        if (p != 0) {
            *(unsigned short *)(p + 0xA0) = *(unsigned short *)(p + 0xA0) + 1;
            *(unsigned short *)(p + 0xA2) = *(unsigned short *)(p + 0xA2) + 1;
            *(unsigned short *)(p + 0xA6) = *(unsigned short *)(p + 0xA6) + 1;
            *(unsigned short *)(p + 0xA8) = *(unsigned short *)(p + 0xA8) + 1;
            *(unsigned short *)(p + 0xA4) = *(unsigned short *)(p + 0xA4) + 1;
        }
    }
}
