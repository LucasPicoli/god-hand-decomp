/* sn-2.95.3-136 matched TU. */

extern char *D_00754C38;
extern char *D_00754C30;
extern char D_0061B644;
extern unsigned int D_00747A78;
extern unsigned short D_00747A50;

__attribute__((section(".text.setColorScrollLayer")))
void setColorScrollLayer(int id, float r, float g, float b) {
    char **a2;
    unsigned int n;
    a2 = *(char ***)((char *)D_00754C38 + 4);
    if (a2 != *(char ***)((char *)D_00754C38 + 8)) {
        do {
            n = *(unsigned char *)(*a2 + 0x2FD);
            if (id == n) {
                *(float *)(*a2 + 0x240) = r;
                *(float *)(*a2 + 0x244) = g;
                *(float *)(*a2 + 0x248) = b;
                *(float *)(*a2 + 0x310) = r;
                *(float *)(*a2 + 0x314) = g;
                *(float *)(*a2 + 0x318) = b;
            }
            a2++;
        } while (a2 != *(char ***)((char *)D_00754C38 + 8));
    }
}

__attribute__((section(".text.classPAD_WORK_Pad_act_set")))
void classPAD_WORK_Pad_act_set(char *o, unsigned int v, unsigned int w) {
    unsigned char *p = (unsigned char *)(o + 0x160);
    unsigned int i = 0;
    while (*p != 0) {
        i++;
        if (i >= 0x20) return;
        p += 0x10;
    }
    p[0] = v >> 24;
    p[1] = v >> 16;
    p[2] = v >> 8;
    p[3] = v;
    *(short *)(p + 6) = w >> 16;
    *(short *)(p + 4) = w + 1;
    *(short *)(p + 0xA) = 0;
    *(short *)(p + 0xC) = 0;
}

__attribute__((section(".text.func_001D0090")))
void func_001D0090(char *o, int v) {
    float *d = (float *)(o + 0x490);
    char *n = *(char **)(o + 0x600);
    unsigned int f;
    if (n != 0) {
        float *s = *(float **)(n + 0xF0);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
    }
    *(float *)(o + 0x24C) = 1.0f;
    f = *(unsigned int *)(o + 0x250) & 0xFFFFFFEFU;
    *(unsigned int *)(o + 0x250) = f;
    *(int *)(o + 0x670) = v;
    *(unsigned char *)(o + 0x2F5) = 0xF;
    *(int *)(o + 0x600) = 0;
    *(int *)(o + 0x630) = 0;
    *(unsigned char *)(o + 0x2F4) = 0;
    *(unsigned char *)(o + 0x2F6) = 0;
    *(unsigned char *)(o + 0x2F7) = 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_002FA470")))
void func_002FA470(int susp) {
    char **cur;
    char *o;
    long ok;
    int tmp;
    int st1;
    int st2;

    cur = *(char ***)(D_00754C30 + 4);
    while (cur != *(char ***)(D_00754C30 + 8)) {
        o = *cur;
        st1 = *(unsigned short *)(o + 0x2FE);
        st2 = *(unsigned short *)(o + 0x2FE);
        ok = 0;
        if (st1 >= 0x500) {
            tmp = st2 < 0x600;
            ok = tmp;
        }
        if (ok & 0xFF) {
            if (susp) {
                *(int *)(o + 0x250) = *(int *)(o + 0x250) | 0x8000;
            } else {
                *(int *)(o + 0x250) = *(int *)(o + 0x250) & ~0x8000;
            }
        }
        cur++;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.setScrollFlagScrollLayer")))
void setScrollFlagScrollLayer(int layer, unsigned int id, int on) {
    char **a2;
    char *obj;
    unsigned int w;
    unsigned int bit;

    a2 = *(char ***)((char *)D_00754C38 + 4);
    if (a2 != *(char ***)((char *)D_00754C38 + 8)) {
        bit = 0x80000000 >> (id & 0x1F);
        w = (id >> 5) * 4;
        do {
            obj = *a2;
            if (layer == *(unsigned char *)(obj + 0x2FD)) {
                obj = obj + 0x350;
                if (on == 1) {
                    *(unsigned int *)(w + (int)obj) |= bit;
                } else {
                    *(unsigned int *)(w + (int)obj) &= ~bit;
                }
            }
            a2++;
        } while (a2 != *(char ***)((char *)D_00754C38 + 8));
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_002E9BA0")))
int func_002E9BA0(char *a0) {
    char *s;
    float v;

    *(int *)(a0 + 0x11C) = *(int *)(a0 + 0x11C) & 0xFEFFFFFF;
    s = *(char **)(a0 + 0x110);
    v = *(float *)(s + 0x144) * 0.01f;
    *(float *)(a0 + 0x2B0) = v;
    *(float *)(a0 + 0x2BC) = *(float *)(s + 0x150) * 0.1f;
    *(float *)(a0 + 0x2B4) = v;
    *(float *)(a0 + 0x2C8) = *(float *)(s + 0x13C) * 1000.0f;
    *(float *)(a0 + 0x2D0) = *(float *)(s + 0x140);
    *(char *)(a0 + 0x2CC) = *(unsigned char *)(s + 0x16C);
    *(char *)(a0 + 0x2CE) = *(unsigned char *)(s + 0x170) + 1;
    D_0061B644 = 0;
    return 1;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_001F6C40")))
void func_001F6C40(int unused, int on) {
    if (on != 0) {
        unsigned int v = D_00747A78;
        v = v | 0x80000000;
        v = v | 0x40000000;
        v = v | 0x20000000;
        v = v | 0x10000000;
        v = v | 0x00080000;
        v = v | 0x00040000;
        D_00747A78 = v;
    } else {
        unsigned int w = D_00747A78;
        w = w & 0x7FFFFFFF;
        w = w & 0xBFFFFFFF;
        w = w & 0xDFFFFFFF;
        w = w & 0xEFFFFFFF;
        w = w & 0xFFF7FFFF;
        w = w & 0xFFFBFFFF;
        D_00747A78 = w;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_00268408")))
int func_00268408(char *o) {
    int st;
    int a;

    st = *(int *)(o + 0x564);
    if (st < 0x20F) {
        return 0;
    }
    if (!(st < 0x211)) {
        if (st != 0x226) {
            return 0;
        }
    }
    a = *(int *)(o + 0x474);
    if (a != 1 && a != 9) {
        return 0;
    }
    if (D_00747A50 != 0x700) {
        return 0;
    }
    if (0.0f < *(float *)(o + 0x1744)) {
        return 0;
    }
    *(unsigned char *)(o + 0x2F7) = 0;
    *(unsigned char *)(o + 0x2F4) = 0;
    *(unsigned char *)(o + 0x2F6) = 0;
    *(unsigned char *)(o + 0x2F5) = 0x86;
    return 1;
}
