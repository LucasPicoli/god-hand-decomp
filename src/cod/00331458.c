#include "godhand/iopReq.h"
#include "godhand/globals.h"
typedef struct IopReqMgr {
    char unk0;
    signed char mode;
} IopReqMgr;

extern IopReqMgr D_003D8410;
extern int Forward33B568_33B658(void);
extern int Forward33B5C8_33B670(void);
extern void func_003312B8(void);
extern void srd_wait_dvd(IopReq *r);
extern void srd_wait_hst(IopReq *r);

__attribute__((section(".text.SRD_WaitComplete")))
void SRD_WaitComplete(IopReq *r)
{
    short i;
    signed char state;
    IopReqMgr *m;

    for (i = 0; i < 1000; i++) {
        Forward33B568_33B658();
        if (D_003D844C == 1) {
            Forward33B5C8_33B670();
            func_003312B8();
            continue;
        }
        D_003D844C = 1;
        Forward33B5C8_33B670();
        break;
    }
    state = r->state;
    if (state == 2) {
        m = &D_003D8410;
        if (m->mode == 1)
            srd_wait_dvd(r);
        if (m->mode == state)
            srd_wait_hst(r);
        if (r->state != 9) {
            r->state = 3;
            D_003D846C++;
        }
    }
    D_003D844C = 0;
}
