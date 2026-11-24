/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
#include "godhand/adxPly.h"

extern int Obj3260_Tramp_003388B0_D468(int a0);
extern void func_0032AF88(void);
extern int D_003C7418;

/* cygnus-2.96 matched TU. */








__attribute__((section(".text.func_0032B530")))
int func_0032B530(AdxPly *adxt)
{
    int x;
    int y;
    int saved;
    int r;

    if (adxt->pause == 0) {
        return 0;
    }
    r = Obj3260_Tramp_003388B0_D468((int)adxt->rna);
    func_0032AF88();
    saved = D_003D1408;
    D_003D1408 = 0;
    adxt_GetTime(adxt, &x, &y);
    D_003D1408 = saved;
    adxt->baseCount = (float)x / y * D_003D1454;
    adxt->baseVsync = D_003C7418;
    return r;
}
