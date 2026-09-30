/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern float D_00567FC0[];
extern unsigned char D_005FEE00[];
extern int cOmSub_move(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern float D_00568020[];
extern void func_001B6FB8(void *a0);
extern void *AllocActiveSlot_1FE218(void *a0, void *a1, int a2);
extern void func_001FD9D8(void *a0, void *a1, float *a2, float *a3, float *t0);
extern int cModel_getMeshPtr(void *a0, int a1);
extern int D_00574380;

/* sn-2.95.3-136 matched TU. */
/* sn-2.95.3-136, -f=-fno-gcse */
__attribute__((section(".text.func_0019F190")))
int func_0019F190(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    char *mp;
    char *mq;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.05680001f;
    cb = 2.11739993f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[6] = ca;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    slot = AllocActiveSlot_1FE218(&D_00574380, p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    mp = (char *)cModel_getMeshPtr(p, 0);
    *(int *)(mp + 0x380) |= 1;
    mq = (char *)cModel_getMeshPtr(p, 1);
    *(int *)(mq + 0x380) &= 0xFFFFFFFE;
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= 8;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= 0x10;
        i++;
        n++;
        if (!(i < 13 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}
