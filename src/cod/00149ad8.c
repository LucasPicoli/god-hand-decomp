/* sn-2.95.3-136 matched TU. */

extern int D_0041EA80;
extern void func_003A52F0(void *dst, int val, int n);

__attribute__((section(".text.cModel_setTextureExchange")))
int cModel_setTextureExchange(void *self, void *tex, void *tbl, int n) {
    char *base;
    char *dst;
    unsigned char *p;
    int cnt;
    int v;
    int r;
    int m1;

    if (tex == 0 || tbl == 0) {
        return 0;
    }
    if (*(int *)tbl != D_0041EA80) {
        return 0;
    }
    if (n >= *(unsigned short *)((char *)tbl + 4)) {
        return 0;
    }

    base = (char *)tbl + 8;
    dst = (char *)self + 0x2D4;
    p = (unsigned char *)(base + (*(unsigned short *)((char *)tbl + 6) << 3));

    if (n > 0) {
        do {
            p += p[0] * 2 + 1;
            n--;
        } while (n != 0);
    }

    func_003A52F0(dst, 0xFF, 0x10);

    v = p[0];
    p++;
    if (v == 0) {
        return 1;
    }
    cnt = v;
    m1 = -1;
    do {
        r = func_00152340(tex, ((long *)base)[p[1]]);
        if (r != m1) {
            dst[r] = p[0];
        }
        p += 2;
        cnt--;
    } while (cnt != 0);
    return 1;
}
