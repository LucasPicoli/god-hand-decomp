/* cygnus-2.96 matched TU. */

extern void func_0034D3E8(void *hn);
extern void func_00350040(void *hn);

__attribute__((section(".text.func_00350048")))
int func_00350048(void *hn, void **pp, void *ctx)
{
    int a;
    int b;
    void *st;
    char *sub;
    int r1;
    int r2;

    sub = (char *)ctx + 0x30;
    st = *pp;
    r1 = func_00366E18(st, sub, *(int *)(sub + 0x160), &a, &b);
    r2 = func_00366E18(st, (char *)ctx + 0xE0, *(int *)(sub + 0x164), &a, &b);
    if (r1 != 0 || r2 != 0) {
        return func_0034DD70(hn, 0xFF000D0DU);
    }
    return 0;
}

typedef struct Hd {
    int f0;
    int pad4[5];
    long long f18;
    long long f20;
    int f28;
    int f2C;
} Hd;

typedef struct Sub {
    int pad0[4];
    long long f10;
    int pad18[5];
    int f2C;
    int f30;
} Sub;






__attribute__((section(".text.func_0034FF98")))
int func_0034FF98(void *hn)
{
    Hd *hd;
    Sub *sub;
    char *tm;
    int err;

    hd = func_003500E8(hn);
    if (hd == 0) return 0;
    if (hd->f0 == 0) return 0;
    sub = *(Sub **)((char *)hn + 0x1F7C);
    func_0034D3E8(hn);
    func_00350040(hn);
    tm = (char *)hn + 0xD30;
    err = func_00350048(hn, sub, hd);
    if (err != 0) return err;
    sub->f2C = hd->f28;
    sub->f30 = hd->f2C;
    *(long long *)(tm + 0x150) = hd->f18;
    *(long long *)((char *)sub + 0x10) = hd->f20;
    return 0;
}
