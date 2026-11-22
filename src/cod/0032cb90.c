/* cygnus-2.96: func_0032CB90, ADX stream server step: stop the input at the end offset, and once
 * the input has finished move to the flush state when every channel buffer has room. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
extern int Obj3270_GetField_30(void *sj);
extern void Obj3270_SetField_3C(void *sj, int v);
extern int Obj3260_GetByte_1_D778(void *sj);
extern int Obj3270_GetVia4_0033CE98_77A0(void *sj);

typedef struct AdxSvrHn {
    char unk0;
    char stat;                  /* 0x01 */
    char unk02[2];
    void *sji;                  /* 0x04 */
    char unk08[0x10];
    SjObj *sjo[4];           /* 0x18 */
    char unk28[0x44];
    signed char eos;            /* 0x6C */
    char unk6D[0x57];
    int endOfs;                 /* 0xC4 */
} AdxSvrHn;

__attribute__((section(".text.func_0032CB90")))
void func_0032CB90(AdxSvrHn *adx)
{
    int i;
    int nch;

    if (adx->eos == 0 && adx->endOfs != 0 && Obj3270_GetField_30(adx->sji) >= adx->endOfs)
        Obj3270_SetField_3C(adx->sji, -1);
    if (Obj3260_GetByte_1_D778(adx->sji) != 3)
        return;
    nch = Obj3270_GetVia4_0033CE98_77A0(adx->sji);
    D_003D1460 = nch;
    for (i = 0; i < nch; i++) {
        SjObj *o = adx->sjo[i];
        D_003D1464 = o->vt->getNumData(o, 1);
        if (D_003D1464 >= 0x40)
            break;
    }
    if (i == nch)
        adx->stat = 4;
}
