/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00747A50[];

__attribute__((section(".text.func_001FB2D8")))
void func_001FB2D8(char *obj, unsigned short id)
{
    unsigned short *p;
    unsigned short *w;
    unsigned short val;
    unsigned int i;

    if (D_00747A50[1] == 0) return;
    obj = *(char **)obj;
    if (obj == 0) return;
    p = (unsigned short *)(obj + 0x28A);
    i = 0;
    val = 0xFFFF;
    w = p;
    for (; i < 0x80; i++) {
        if (p[3] == id) {
            *w = val;
            return;
        }
        w += 8;
        p += 8;
    }
}

__attribute__((section(".text.func_0027DBF8")))
void func_0027DBF8(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 7;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 7;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 7;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    }
}

__attribute__((section(".text.func_002832A0")))
void func_002832A0(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 6;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 6;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 6;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    }
}

extern struct D007474A0 {
    char pad[0x210];
    int f210;
} D_007474A0;

__attribute__((section(".text.func_002A4ED8")))
void func_002A4ED8(char *base)
{
    char *p;

    p = base + 0x28000;
    *(char **)(p + 0x2054) = base + ((D_007474A0.f210 & 1) * 0x15000 + 0x50);
    base = base + ((D_007474A0.f210 & 1) * 0x15000 + 0x50);
    base = base + 0x15000;
    *(char **)(p + 0x2058) = base;
}

__attribute__((section(".text.func_002B5EC0")))
void func_002B5EC0(char *n)
{
    char *q;

    if (*(char **)(n + 4) == 0) return;
    q = *(char **)(n + 0x10);
    if (q != 0) {
        *(char **)(q + 0xC) = *(char **)(n + 0xC);
    }
    q = *(char **)(n + 0xC);
    if (q != 0) {
        *(char **)(q + 0x10) = *(char **)(n + 0x10);
    } else {
        q = *(char **)(n + 4);
        *(char **)(q + 8) = *(char **)(n + 0x10);
    }
    *(char **)(n + 0x10) = 0;
    *(char **)(n + 0xC) = 0;
    *(char **)(n + 4) = 0;
}
