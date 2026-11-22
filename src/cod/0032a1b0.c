/* cygnus-2.96 matched TU. */
#include "godhand/adxPly.h"
#include "godhand/globals.h"

#define ADXT_SYNC_LIMIT_MS  60.0f

extern int D_003C7418;          /* vsync counter */
extern int D_003D142C;
extern float D_003D1458;        /* audio minus vsync time, ms */
extern char D_004520B0[];

/* The handle's time on the vsync clock: count from the vsync counter while
 * playing, and when that drifts more than 60 ms from the sample clock, move
 * the base to the sample clock. func_0032A160 is the locked wrapper. */
__attribute__((section(".text.adxt_GetTime")))
void adxt_GetTime(AdxPly *adxt, int *ncount, int *tscale)
{
    int nsmpl;
    int sfreq;

    if (adxt == 0 || ncount == 0 || tscale == 0) {
        func_0033F130(D_004520B0);
        return;
    }
    if (D_003D1408 == 0) {
        func_0032A018(adxt, ncount, tscale);
        return;
    }
    D_003D1458 = 0.0f;
    if (adxt->stat == ADXT_STAT_PLAYING || adxt->stat == ADXT_STAT_DECEND) {
        if (adxt->pause == 0) {
            *ncount = (D_003C7418 - adxt->baseVsync) * 100 + adxt->baseCount;
        } else {
            *ncount = adxt->baseCount;
        }
        func_0032A018(adxt, &nsmpl, &sfreq);
        D_003D1458 = ((float)nsmpl / sfreq - (float)*ncount / D_003D1454) * 1000.0f;
        if (D_003D1458 > ADXT_SYNC_LIMIT_MS || D_003D1458 < -ADXT_SYNC_LIMIT_MS) {
            if (D_003D142C == 1) {
                int use = D_003D1408;

                D_003D1408 = 0;
                adxt_GetTime(adxt, &nsmpl, &sfreq);
                D_003D1408 = use;
                Obj0000_PostInc_D_003D1428_32A148();
            }
            adxt->baseCount = (float)nsmpl / sfreq * D_003D1454;
            adxt->baseVsync = D_003C7418;
        }
    } else if (adxt->stat == ADXT_STAT_PLAYEND) {
        nsmpl = Obj3270_GetVia4_Obj33C8_18_77E8(adxt->sjd);
        sfreq = Obj3270_GetVia4_Obj33C8_14_7788(adxt->sjd);
        nsmpl = nsmpl * (16 / Obj3270_GetVia4_0033CEF0_77B8(adxt->sjd));
        *ncount = (float)nsmpl / sfreq * D_003D1454;
        *ncount += (int)(adxt->baseCount + 1);
    } else {
        *ncount = 0;
    }
    *ncount += adxt->ofs;
    *tscale = D_003D1454;
}
