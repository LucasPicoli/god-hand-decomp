/* cygnus-2.96 matched TU. */

extern int func_0035DE38();
extern int func_0035DE88();
extern int func_0035DED8();
extern int func_0035DF28();
extern int func_0035DFE0();
extern int func_0035E030();
extern int func_0035E080();
extern int sfhds_CallN(void *h, int (*f)());
extern void func_0035C2D0(void *h, int a, int b, int c, int d);
extern void *Obj35C0_IsIndexedSet_1F3C_C380(void *h, int n);

typedef struct R { int f0; int f4; int f8; int fC; int f10; int f14; int f18; } R;










__attribute__((section(".text.sfhds_AnlySys")))
void sfhds_AnlySys(void *h, R *r)
{
    r->f0 = sfhds_CallN(h, func_0035DE38);
    r->f4 = sfhds_CallN(h, func_0035DE88);
    r->f8 = sfhds_CallN(h, func_0035DED8);
    r->fC = sfhds_CallN(h, func_0035DF28);
    r->f10 = sfhds_CallN(h, func_0035DFE0);
    r->f14 = sfhds_CallN(h, func_0035E030);
    r->f18 = sfhds_CallN(h, func_0035E080);
}

__attribute__((section(".text.sfpl2_TrPause")))
void sfpl2_TrPause(void *h, int n)
{
    func_0035C2D0(h, 7, 8, n, 0);
    do { } while (0);
}

__attribute__((section(".text.sfply_TrStart")))
void sfply_TrStart(void *h)
{
    func_0035C2D0(h, 7, 6, 0, 0);
    do { } while (0);
}

__attribute__((section(".text.sfsee_IsMpsStream")))
int sfsee_IsMpsStream(void *h)
{
    return Obj35C0_IsIndexedSet_1F3C_C380(h, 1) != 0;
}
