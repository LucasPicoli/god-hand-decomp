/* cygnus-2.96: func_00329E08, stops a stream player: halts the SJ, releases the reader and clears the state. */
#include "godhand/criStm.h"

extern void Forward33B658_33E678(void);
extern void Forward33B670_33E690(void);
extern void Obj3260_Tramp_003382A0_D320(void *sj, int id);
extern void Obj3260_Tramp_00338338_D338(void *sj, int id);
extern void PS2RNA_SetDiscardSw(void *sj, int id);
extern void ADXSJD_Stop(void *dec);
extern void func_0033C228(void *buf);

__attribute__((section(".text.func_00329E08")))
void func_00329E08(StmPly *p)
{
    StmRd *rd;

    Forward33B658_33E678();
    Obj3260_Tramp_003382A0_D320(p->sj, 0);
    Obj3260_Tramp_00338338_D338(p->sj, 0);
    PS2RNA_SetDiscardSw(p->sj, 1);
    ADXSJD_Stop(p->dec);
    if (p->kind == 2) {
        rd = p->rd;
        if (rd != 0) {
            p->rd = 0;
            rd->vt->destroy(rd);
        }
    }
    if (p->buf != 0)
        func_0033C228(p->buf);
    p->rd = 0;
    p->stat = 0;
    p->eos = 0;
    Forward33B670_33E690();
}
