/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GuardedCall_00329FD0_329F98(void *hn);
extern void func_0032A160(void *hn, int *ntime, int *tunit);
extern int Obj0000_Get_D_003EEA70_360C58(void);
extern void SFTST_Calc(void *tst, long long *a, long long *b, long long *c);
extern void func_0034BD98(void *sj, int kind);
extern void sfply_ChkCondDfl(void);
extern void sfply_FixAvPlay(void *p);
extern void sfply_AdjustSyncMode(void *p);
extern void sfply_AdjustEtrg(void *p);

__attribute__((section(".text.sfadxt_GetTimeTst")))
void sfadxt_GetTimeTst(void *tst, void *hn, int *ptmr, int *ptunit)
{
    long long a[2];
    long long b[2];
    long long c[2];
    int ntime;
    int tunit;

    D_003EE0A4 = GuardedCall_00329FD0_329F98(hn);
    func_0032A160(hn, &ntime, &tunit);
    a[0] = ntime;
    a[1] = tunit;
    b[0] = func_00360B18();
    b[1] = Obj0000_Get_D_003EEA70_360C58();
    SFTST_Calc(tst, a, b, c);
    *ptmr = (int)c[0];
    *ptunit = (int)c[1];
}

__attribute__((section(".text.SFBUF_DestroySj")))
void SFBUF_DestroySj(void *sj)
{
    func_0034BD98(sj, 0);
    func_0034BD98(sj, 1);
    func_0034BD98(sj, 2);
}

__attribute__((section(".text.func_00201A50")))
int func_00201A50(void)
{
    return sceCdDiskReady(1) == 2;
}

__attribute__((section(".text.func_003571D0")))
void func_003571D0(void)
{
    sfply_ChkCondDfl();
    D_003EE304 = 0;
}

__attribute__((section(".text.sfply_AdjustPrepEnd")))
void sfply_AdjustPrepEnd(void *p)
{
    sfply_FixAvPlay(p);
    sfply_AdjustSyncMode(p);
    sfply_AdjustEtrg(p);
}
