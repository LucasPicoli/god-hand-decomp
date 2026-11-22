#include "godhand/criSj.h"
#include "godhand/globals.h"

typedef struct AdxLoopHn {
    char pad0[2];
    signed char stat;
    char pad3;
    void *stm;
    char pad8[0xC];
    SjObj *sj;
    char pad18[0x54];
    signed char lpflg;
    char pad6D[0x57];
    int lpPos;
} AdxLoopHn;

extern int Obj3270_GetField_30(void *);
extern int func_00327830(void *);
extern int GetVia4_Obj33C8_GetField_34_7878_327878(void *);

__attribute__((section(".text.func_0032B1C8")))
void func_0032B1C8(AdxLoopHn *adxt, int flg)
{
    SjObj *sj;
    int n, pos, len;

    if (adxt == 0) {
        func_0033F130(D_00452560);
        return;
    }
    sj = adxt->sj;
    if (sj != 0)
        n = sj->vt->getNumData(sj, 1);
    else
        n = 0;
    if (adxt->stat != 4 && adxt->lpflg == 1 && flg == 0) {
        pos = Obj3270_GetField_30(adxt->stm) + n;
        n = func_00327830(adxt->stm);
        n = (n + 0x7FF) / 0x800 * 0x800;
        len = (GetVia4_Obj33C8_GetField_34_7878_327878(adxt->stm) + 0x7FF) / 0x800 * 0x800 - n;
        if (len <= 0)
            adxt->lpPos = 0;
        else
            adxt->lpPos = (pos - n) / len * len + n;
    }
    adxt->lpflg = flg;
}
