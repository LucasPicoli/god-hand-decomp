/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
#include "godhand/adxPly.h"

extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void Obj3260_Tramp_00338338_D338(int a0, int a1);
extern int D_003C7418;

/* cygnus-2.96 candidate. */











__attribute__((section(".text.func_0032B340")))
void func_0032B340(AdxPly *adxt, int mode)
{
    int x;
    int y;
    int saved;
    int kind;

    if (adxt == 0) {
        func_0033F130(D_00452630);
        return;
    }
    kind = adxt->stat;
    if (mode == adxt->pause) {
        return;
    }
    Forward33B658_33E678();
    adxt->pause = mode;
    if (kind == ADXT_STAT_PLAYING || kind == ADXT_STAT_DECEND) {
        if (mode == 1) {
            Obj3260_Tramp_00338338_D338((int)adxt->rna, 0);
        } else {
            Obj3260_Tramp_00338338_D338((int)adxt->rna, 1);
            adxt->baseVsync = D_003C7418;
        }
        saved = D_003D1408;
        D_003D1408 = 0;
        adxt_GetTime(adxt, &x, &y);
        D_003D1408 = saved;
        adxt->baseCount = (float)x / y * D_003D1454;
    }
    Forward33B670_33E690();
}
