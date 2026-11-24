#include "godhand/adxPly.h"
extern int Obj3270_GetField_2C(void *);
extern int Obj3260_Tramp_003383B0_D358(int);

__attribute__((section(".text.func_0032A018")))
void func_0032A018(AdxPly *adxt, int *pos, int *rate)
{
    unsigned char stat = adxt->stat;
    int t, n, v;

    if ((unsigned int)(stat - ADXT_STAT_PLAYING) < 2) {
        *rate = Obj3270_GetVia4_Obj33C8_14_7788(adxt->sjd);
        t = Obj3270_GetField_2C(adxt->sjd);
        n = Obj3260_Tramp_003383B0_D358((int)adxt->rna);
        *pos = t - (n - adxt->sub + ADXT_GetNumSmplObuf(adxt, 0)) + adxt->base;
    } else if ((signed char)stat == ADXT_STAT_PLAYEND) {
        *pos = Obj3270_GetVia4_Obj33C8_18_77E8(adxt->sjd);
        *rate = Obj3270_GetVia4_Obj33C8_14_7788(adxt->sjd);
        *pos = *pos * (16 / Obj3270_GetVia4_0033CEF0_77B8(adxt->sjd));
        *pos = *pos + adxt->base;
    } else {
        *pos = 0;
        *rate = 1;
    }
    v = *pos + adxt->ofs;
    if (v < 0)
        v = 0;
    *pos = v;
}
