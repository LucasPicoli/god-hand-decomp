/* sn-2.95.3-136 matched TU. */

struct S_338F30 {
    char pad0[0xC];
    int fC;
    char pad1[0x1C - 0x10];
    int (*f1C)();
    int f20;
};

__attribute__((section(".text.SJMEM_GetNumData")))
int SJMEM_GetNumData(struct S_338F30 *a0, int a1) {
    int (*fp)();
    if (a1 == 1)
        return a0->fC;
    if (a1 == 0)
        return 0;
    fp = a0->f1C;
    if (fp == 0)
        return 0;
    fp(a0->f20, -3);
    return 0;
}

struct S_339848 {
    char pad0[0xC];
    int fC;
    int f10;
    char pad1[0x38 - 0x14];
    int (*f38)();
    int f3C;
};

__attribute__((section(".text.SJRBF_GetNumData")))
int SJRBF_GetNumData(struct S_339848 *a0, int a1) {
    int (*fp)();
    if (a1 == 1)
        return a0->fC;
    if (a1 == 0)
        return a0->f10;
    fp = a0->f38;
    if (fp == 0)
        return 0;
    fp(a0->f3C, -3);
    return 0;
}

__attribute__((section(".text.decode_sleb128")))
char *decode_sleb128(unsigned char *a0, int *a1) {
    unsigned int shift = 0;
    int result = 0;
    unsigned char byte;
    do {
        byte = *a0;
        a0++;
        result |= (byte & 0x7F) << shift;
        shift += 7;
    } while (byte & 0x80);
    if (shift < 0x20 && (byte & 0x40))
        result |= -1 << shift;
    *a1 = result;
    return (char *)a0;
}

typedef struct { int *base; int count; } Desc;

__attribute__((section(".text.add_fdes")))
void add_fdes(int *n, Desc *d, unsigned int *pmin, unsigned int *pmax) {
    unsigned int curmin;
    unsigned int curmax;
    unsigned int v;
    unsigned int sum;
    int off;
    int *p;

    curmin = *pmin;
    curmax = *pmax;
    if (n[0] != 0) {
        do {
            if (n[1] != 0 && n[2] != 0) {
                d->base[d->count++] = (int)n;
                v = n[2];
                sum = v + n[3];
                curmin = (v < curmin) ? v : curmin;
                curmax = (curmax < sum) ? sum : curmax;
            }
            off = n[0];
            p = (int *)((char *)n + off);
            n = p + 1;
        } while (p[1] != 0);
    }
    *pmin = curmin;
    *pmax = curmax;
}
