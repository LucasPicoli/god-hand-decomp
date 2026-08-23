/* sn-2.95.3-136 matched TU. */

extern unsigned int D_00747A34;
extern char *D_003F50F8;

__attribute__((section(".text.func_002A9800")))
void func_002A9800(char *o, int idx) {
    char *n, *p, *q, *r;
    if (idx == 0) return;
    n = (char *)(idx + *(int *)(o + 4));
    p = *(char **)n;
    if (p != 0) *(int *)(p + 4) = *(int *)(n + 4);
    else *(int *)(o + 0x14) = *(int *)(n + 4);
    q = *(char **)(n + 4);
    if (q != 0) *(int *)q = *(int *)n;
    *(int *)n = 0;
    r = *(char **)(o + 0x10);
    *(char **)(n + 4) = r;
    if (r != 0) *(char **)r = n;
    *(char **)(o + 0x10) = n;
}

__attribute__((section(".text.func_002B2D28")))
int func_002B2D28(char *o) {
    unsigned short t;
    if ((*(int *)(o + 0x14) & 0x8000) == 0) {
        unsigned short h = *(unsigned short *)(*(int *)(o + 0x8C) + 2);
        *(int *)(o + 0x14) |= 0x8000;
        *(unsigned short *)(o + 0x3A) = h;
    }
    t = *(unsigned short *)(o + 0x3A);
    if (t != 0) {
        *(unsigned short *)(o + 0x3A) = t - 1;
        return 1;
    }
    *(unsigned int *)(o + 0x14) &= 0xFFFF7FFFU;
    return 0;
}

__attribute__((section(".text.func_002A97A0")))
int func_002A97A0(char *o) {
    char *n, *t;
    if ((D_00747A34 & 0x80000) != 0) return 0;
    n = *(char **)(o + 0x10);
    if (n == 0) return 0;
    *(int *)(o + 0x10) = *(int *)(n + 4);
    t = *(char **)(n + 4);
    if (t != 0) *(int *)t = 0;
    *(int *)n = 0;
    t = *(char **)(o + 0x14);
    *(char **)(n + 4) = t;
    if (t != 0) *(char **)t = n;
    *(char **)(o + 0x14) = n;
    return (int)n - *(int *)(o + 4);
}

__attribute__((section(".text._IO_un_link")))
void _IO_un_link(char *fp) {
    char **f;
    int flags = *(int *)fp;
    if (flags & 0x80) {
        for (f = &D_003F50F8; *f != 0; f = (char **)(*f + 0x34)) {
            if (*f == fp) { *f = *(char **)(fp + 0x34); break; }
        }
        *(int *)fp = flags & ~0x80;
    }
}
