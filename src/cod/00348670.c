/* cygnus-2.96: open slot id and fill its 0x20-byte record, or report one of three errors and return 0. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int func_00348938(int id);
extern void MWSST_Init(int id);
extern int MWSST_CalcWorkSize(int id, int *p0, int *p1, int *p2);
extern int func_003395A0(int a, int b, int c);
extern int MWSST_CreateCoreHn(int id, int a2, int p0);
extern void SFD_SetElementOutSj(int ctx, int a, int span, int z0, int z1);

__attribute__((section(".text.MWSST_Create")))
int MWSST_Create(MwsfdHn *o, int id, int a2, int a3, int a4)
{
    int p0;
    int p1;
    int p2;
    MwsfdSlot *s;
    int opened;
    int span;
    int made;
    int ctx;

    opened = func_00348938(id);
    if (opened == 0)
        return 0;
    MWSST_Init(id);
    ctx = (int)o->sfd;
    s = &o->slot[id];
    s->opened = opened;
    s->id = id;
    s->base = a2;
    s->limit = a3;
    s->buf = (char *)a4;
    if (a3 < MWSST_CalcWorkSize(id, &p0, &p1, &p2)) {
        MWSFSVM_Error(D_00459240);
        return 0;
    }
    span = func_003395A0(a2 + p0, p1, p2);
    if (span == 0) {
        MWSFSVM_Error(D_00459270);
        return 0;
    }
    s->sj = (SjObj *)span;
    made = MWSST_CreateCoreHn(id, a2, p0);
    if (made == 0) {
        MWSFSVM_Error(D_00459298);
        return 0;
    }
    s->made = made;
    s->flag = 1;
    SFD_SetElementOutSj(ctx, a4 + 0xC0, span, 0, 0);
    return made;
}
