/* sn-2.95.3-136 */
#include "godhand/cEmWrap.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cEmSetParam.h"

extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);
extern cEmActor *cEmSetParam_setEm(cEmSetParam *self, unsigned char no);
extern void cEmWrap_StartAction(cEmWrap *self);
extern unsigned char D_00586AA5;

/* One wave arm: once the timer runs out, create enemy entry n and start its action. Each case
 * spells it out with its own entry number, as retail does; the arms share one call tail. */
#define START_WAVE(n) \
    if (self->phaseTimer == 0) { \
        D_00586AA5 = 0; \
        wrap.entryNo = (n); \
        cEmSetParam_setEm(&D_00586AB0, (n)); \
        cEmWrap_StartAction(&wrap); \
        self->phaseTimer = 0xF0; \
        self->enemyNum = self->enemyNum + 1; \
        self->phase = self->phase + 1; \
    } else { \
        self->phaseTimer = self->phaseTimer - 1; \
    }

/* Coliseum wave step: phase 0 defeats every enemy and starts a 240-frame wait; phases 1-7 each wait out the timer,
 * then start enemy entry N, count it and move on. */
__attribute__((section(".text.func_001F0A28")))
void func_001F0A28(ColiseumBattle *self)
{
    cEmWrap wrap;

    switch (self->phase) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phaseTimer = 0xF0;
        self->phase = self->phase + 1;
        break;
    case 1:
        START_WAVE(1);
        break;
    case 2:
        START_WAVE(2);
        break;
    case 3:
        START_WAVE(3);
        break;
    case 4:
        START_WAVE(4);
        break;
    case 5:
        START_WAVE(5);
        break;
    case 6:
        START_WAVE(6);
        break;
    case 7:
        START_WAVE(7);
        break;
    }
}
