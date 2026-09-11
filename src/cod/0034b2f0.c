/* cygnus-2.96 matched TU. */

typedef struct Obj {
    void *f0;
    char pad4[0x2C];
    int f30;
} Obj;

typedef struct Tm2 {
    long long t;
    long long f;
} Tm2;

extern void func_0034B430(void *hn, int sw);
extern int sfadxt_IsEndDecinfo(void *ax);

extern void func_0034B4B8(void *hn, int *tm, int sfreq);

extern void func_0035C548(void *p, Tm2 *t2);

__attribute__((section(".text.func_0034B2F0")))
int func_0034B2F0(void *hn, unsigned int sw)
{
    Tm2 t2;
    int tm;
    Obj *p;
    void *ax;
    int n;
    int sfreq;
    int r;

    p = *(Obj **)((char *)hn + 0x2004);
    ax = p->f0;
    switch (sw) {
    case 0:
        p->f30 = 0;
        func_0034B430(hn, 0);
        break;
    case 1:
        func_0034B430(hn, sw);
        break;
    case 2:
        if (sfadxt_IsEndDecinfo(ax) != 0) {
            sfreq = func_0032A530(ax);
            func_0034B4B8(hn, &tm, sfreq);
            n = tm + p->f30;
            r = func_0032B4E8(ax, n);
            t2.t = tm;
            t2.f = sfreq;
            p->f30 = n - r;
            func_0035C548((char *)hn + 0x1020, &t2);
        }
        break;
    }
    return 0;
}
