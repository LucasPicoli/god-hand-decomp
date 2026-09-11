/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpc.o :: _decMB0 */

#define IPU_CTRL (*(volatile unsigned int *)0x10002010)

extern char D_0045E750[];
extern void _waitIpuIdle(void *s);
extern long long _sceMpegWaitIpuIdle64(void *s);

extern void func_0039C390(void *s, char *msg);
extern void func_0039ECF0(void *s, int n);
extern void func_0039FDD8(int a, int b);
extern void func_0039DF50(void *s, int *PMV, int *dmv, int *mvfs, int idx,
                          int mvcount, int mvformat, int hr, int vr,
                          int dmvf, int mvscale);
extern void func_0039DB28(void *s, int *PMV, int *dmv, int hr, int vr,
                          int dmvf, int mvscale, int fullpel);

__attribute__((section(".text.func_0039E0F0")))
int func_0039E0F0(char *s, int *mbtypep, int *motion_typep, int *dct_typep,
                  int *PMV, int *mvfs, int *dmvector)
{
    long long v;
    long long top;
    unsigned int bp;
    unsigned int cmd;
    unsigned int q;
    int mbtype;
    int mt;
    int ps;
    int mvcount;
    int two;
    int mvformat;
    int dmv;
    int mvscale;
    int dct_type;

    IPU_CTRL = (IPU_CTRL & 0xF8FFFFFF) | (*(int *)(s + 0x160) << 24);
    _waitIpuIdle(s);
    *(volatile unsigned int *)0x10002000 = 0x34000000;
    *(int *)(s + 0x828) = 0;
    *(int *)(s + 0x82C) = 0x30000000;
    v = _sceMpegWaitIpuIdle64(s);
    bp = *(volatile unsigned int *)0x10002020;
    top = *(volatile long long *)0x10002030;
    *(int *)(s + 0x848) = (int)top;
    if (top < 0)
        *(int *)(s + 0x84C) = (0 - (bp & 0x1F)) & 0x1F;
    else
        *(int *)(s + 0x84C) = 0x20;
    *(int *)(s + 0x12C) = ((int)v == 0);
    mbtype = (short)v;
    *mbtypep = mbtype;
    if (mbtype == 0) {
        func_0039C390(s, D_0045E750);
        *(int *)(s + 0x12C) = 1;
        return 0;
    }
    if ((mbtype & 0xC) != 0) {
        if (*(int *)(s + 0x184) == 3 && *(int *)(s + 0x18C) != 0)
            *motion_typep = 2;
        else
            *motion_typep = func_0039EAA8(s, 2);
    } else if ((mbtype & 1) != 0) {
        if (*(int *)(s + 0x190) != 0)
            do { *motion_typep = (*(int *)(s + 0x184) == 3) ? 2 : 1; } while (0);
    }
    ps = *(int *)(s + 0x184);
    mt = *motion_typep;
    if (ps == 3) {
        mvcount = (mt == 1) ? 2 : 1;
        mvformat = (mt == 2);
    } else {
        two = 2;
        do { } while (0);
        mvcount = 1;
        do { } while (0);
        mvformat = 0;
        do { } while (0);
        if (mt == 2)
            mvcount = two;
    }
    dmv = (mt == 3);
    mvscale = (mvformat == 0 && ps == 3);
    if (ps == 3 && *(int *)(s + 0x18C) == 0 && (*mbtypep & 3) != 0)
        dct_type = func_0039EAA8(s, 1);
    else
        dct_type = 0;
    *dct_typep = dct_type;
    if ((*mbtypep & 0x10) != 0)
        *(int *)(s + 0x1C4) = func_0039EAA8(s, 5);
    if ((*mbtypep & 8) != 0
        || ((*mbtypep & 1) != 0 && *(int *)(s + 0x190) != 0)) {
        if (*(int *)(s + 0x858) != 0)
            func_0039DF50(s, PMV, dmvector, mvfs, 0, mvcount, mvformat,
                          *(int *)(s + 0x174) - 1, *(int *)(s + 0x178) - 1,
                          dmv, mvscale);
        else
            func_0039DB28(s, PMV, dmvector, *(int *)(s + 0x168) - 1,
                          *(int *)(s + 0x168) - 1, 0, 0, *(int *)(s + 0x164));
    }
    if (*(int *)(s + 0x12C) != 0)
        return 0;
    if ((*mbtypep & 4) != 0) {
        if (*(int *)(s + 0x858) != 0)
            func_0039DF50(s, PMV, dmvector, mvfs, 1, mvcount, mvformat,
                          *(int *)(s + 0x17C) - 1, *(int *)(s + 0x180) - 1,
                          0, mvscale);
        else
            func_0039DB28(s, PMV + 2, dmvector, *(int *)(s + 0x170) - 1,
                          *(int *)(s + 0x170) - 1, 0, 0, *(int *)(s + 0x16C));
    }
    if (*(int *)(s + 0x12C) != 0)
        return 0;
    if ((*mbtypep & 1) != 0 && *(int *)(s + 0x190) != 0)
        func_0039ECF0(s, 1);
    if ((*mbtypep & 3) != 0) {
        func_0039FDD8(*(int *)(s + *(int *)(s + 0x820) * 0x140 + 0x5A4), 0x300);
        _waitIpuIdle(s);
        q = (*(int *)(s + 0x1C4) << 16) | 0x20000000;
        cmd = (((*mbtypep & 1) << 27)
               | ((*dct_typep << 25) | (*(int *)(s + 0x1C0) << 26))) | q;
        *(volatile unsigned int *)0x10002000 = cmd;
        *(int *)(s + 0x82C) = cmd & 0xF0000000;
        if (*(int *)(s + 0x82C) == 0x20000000
            || *(int *)(s + 0x82C) == 0x30000000
            || *(int *)(s + 0x82C) == 0x40000000)
            *(int *)(s + 0x828) = 0;
        else
            *(int *)(s + 0x828) = 1;
    } else {
        *(int *)(s + *(int *)(s + 0x820) * 0x140 + 0x6DC) = 1;
    }
    *(int *)(s + 0x1C0) = 0;
    if (*(int *)(s + 0x12C) != 0)
        return 0;
    if ((*mbtypep & 1) == 0)
        *(int *)(s + 0x1C0) = 1;
    if ((*mbtypep & 1) != 0 && *(int *)(s + 0x190) == 0) {
        PMV[5] = 0;
        PMV[4] = 0;
        PMV[1] = 0;
        PMV[0] = 0;
        PMV[7] = 0;
        PMV[6] = 0;
        PMV[3] = 0;
        PMV[2] = 0;
    }
    if (*(int *)(s + 0x160) != 2)
        return 1;
    if ((*mbtypep & 9) != 0)
        return 1;
    PMV[5] = 0;
    PMV[4] = 0;
    PMV[1] = 0;
    PMV[0] = 0;
    if (*(int *)(s + 0x184) == 3) {
        *motion_typep = 2;
    } else {
        *motion_typep = 1;
        *mvfs = (*(int *)(s + 0x184) == 2);
    }
    return 1;
}
