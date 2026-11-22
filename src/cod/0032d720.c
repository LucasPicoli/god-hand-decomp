#include "godhand/criSj.h"
#include "godhand/mwPly.h"
#include "godhand/globals.h"
typedef struct AdxtHn {
    char used;
    char pad1[2];
    signed char maxnch;
    void *sjf;
    int stm;
    int rna;
    char pad10[0x7C];
    SjObj *sjo;
    char pad90[4];
    SjObj *sji[1];
} AdxtHn;

extern void Obj33F8_Tramp_0033F130_FCB0(char *msg);
extern void func_0032DBA0(MwPly *ply);
extern int func_003283E8(int stm, int a, int b);
extern void func_00327D90(int stm);
extern void func_0032EE88(AdxtHn *adxt);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void Obj33F8_Tramp_0033B670_FC88(void);
extern void func_0032F428(void *sjf);
extern void *func_003A52F0(void *p, int c, int n);

__attribute__((section(".text.func_0032D720")))
void func_0032D720(AdxtHn *adxt)
{
    int stm;
    int i;
    SjObj *sj;
    void *sjf;

    if (adxt == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_004529F8);
        return;
    }
    func_0032DBA0((MwPly *)adxt);
    stm = adxt->stm;
    if (stm != 0) {
        adxt->stm = 0;
        func_003283E8(stm, 0, 0);
        func_00327D90(stm);
    }
    if (adxt->rna != 0)
        func_0032EE88(adxt);
    Obj33F8_Tramp_0033B658_FC70();
    for (i = 0; i < adxt->maxnch; i++) {
        if (adxt->sji[i] != 0) {
            SjObj *t = adxt->sji[i];
            adxt->sji[i] = 0;
            t->vt->destroy(t);
        }
    }
    sj = adxt->sjo;
    if (sj != 0) {
        adxt->sjo = 0;
        sj->vt->destroy(sj);
    }
    sjf = adxt->sjf;
    if (sjf != 0) {
        adxt->sjf = 0;
        func_0032F428(sjf);
    }
    func_003A52F0(adxt, 0, 0x278);
    adxt->used = 0;
    Obj33F8_Tramp_0033B670_FC88();
}
