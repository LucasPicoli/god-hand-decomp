/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"
#include "godhand/cOmbb.h"

extern void KillEffect(void *a0, int a1, int a2);
extern void cSnd_SeStop(void *a0, int a1);

/* SN ProDG ee-gcc 2.95.3 matched TU. */








__attribute__((section(".text.cOmbb__clearFire")))
void cOmbb__clearFire(void *arg) {
    cOmbb *s0 = arg;
    int se;
    float f;
    KillEffect(s0, 0, 2);
    SetEffect(1, 2, arg, 0, 0, EFFECT_FOLLOW_OWNER);
    se = s0->hissSe;
    if (se != 0) {
        cSnd_SeStop(&D_005FEE00, se);
    }
    s0->hissSe = 0;
    cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x16, arg, 0, 0, 0, 0);
    switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
    case 0:
    default: s0->countdown = 450.0f; break;
    case 1: s0->countdown = 350.0f; break;
    case 2: s0->countdown = 250.0f; break;
    case 3: s0->countdown = 250.0f; break;
    case 4: s0->countdown = 150.0f; break;
    }
    (void)f;
    s0->base.mode = 0;
    s0->base.step = 4;
    s0->fireLit = 0;
}
