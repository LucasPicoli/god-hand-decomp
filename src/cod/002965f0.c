/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern unsigned int D_00747A80[];
extern char D_00747B20[];
extern char D_00747470[];
extern int D_003C2F84;
extern int D_003C2558;
extern void func_00296738(cEvent *);

extern void HideModelMgr_ResetHiddenModels(char *);
extern void HideModelMgr_ClearHiddenModelList(char *);
extern void cScenario_setOmSuspend(int, int);
extern void classFADE_start(char *, int, int, int, int, int, int);
extern void cNowLoading_executeTask(int);

/* START stage: wait until the screen is free, hide the models, fade out and
 * go to the CLEAR stage. The state value and the return value are one local
 * (ret = 1) so retail's single `li` serves both. */
__attribute__((section(".text.func_002965F0")))
int func_002965F0(cEvent *self) {
    int ret;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    switch ((signed char)self->phase) {
    case 0:
        func_00296738(self);
        self->phase++;
    case 1:
        break;
    default:
        return 0;
    }
    if (func_002967B0(self) == 0) return 0;
    D_00747A80[0] |= 0x2000000;
    HideModelMgr_ResetHiddenModels(D_00747B20);
    HideModelMgr_ClearHiddenModelList(D_00747B20);
    D_00747A80[-2] |= 0x200000;
    cScenario_setOmSuspend(D_003C2F84, 1);
    a = D_00747A80[-2] & 0xDFFFFFFF;
    c = D_00747A80[1] | 0x1000000;
    b = a & 0xEFFFFFFF;
    D_00747A80[1] = c;
    D_00747A80[-2] = b & 0xFBFFFFFF;
    classFADE_start(D_00747470, 0, 8, 0, 0xFF000000, 0xFF000000, 0);
    cNowLoading_executeTask(D_003C2558);
    ret = 1;                       /* CEVENT_STATE_CLEAR */
    self->state = ret;
    self->phase = 0;
    self->unk06 = 0;
    self->unk07 = 0;
    return ret;
}
