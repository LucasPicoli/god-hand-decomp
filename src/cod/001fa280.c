/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern cCoreSave D_00569B70;        /* the game's cCoreSave */
extern unsigned int D_00568240;
extern unsigned int D_00747A84;
extern unsigned short D_00747A50;   /* current stage id */
extern unsigned short D_005CAC94;
extern int D_003BF160[];            /* levelPoint thresholds, one per game level */
extern int cCoreSave_getGameDifficulty(cCoreSave *self); /* difficulty */
extern int cCoreSave_getGameLevel(cCoreSave *self);

/* Add (or with a negative value, remove) level points, scaled by the current
 * game level. A level drop is absorbed while levelDownGrace lasts: the grace
 * is spent and the points reset to the bottom of the level. */
__attribute__((section(".text.cCoreSave_addGameLevelPoint")))
void cCoreSave_addGameLevelPoint(cCoreSave *self, int point)
{
    long v;
    int lv;
    int nl;
    cCoreSaveData *q;
    float f;

    if (self->data == 0) {
        return;
    }
    if ((D_00747A84 & 0x400000) != 0) {
        return;
    }
    if (cCoreSave_getGameDifficulty(self) == 2) {
        return;
    }
    if ((D_00569B70.data->flags & 0x4000000) != 0) {
        v = D_00568240;
        if (((v >> 1) & 1) == 0) {
            return;
        }
    }
    lv = cCoreSave_getGameLevel(self);
    if (point > 0) {
        switch (cCoreSave_getGameLevel(self) - 1) {
        default:
        case 0: f = 1.5f; break;
        case 1: f = 1.2f; break;
        case 2: f = 1.0f; break;
        case 3: f = 0.7f; break;
        case 4: f = 0.5f; break;
        }
        if (D_005CAC94 >= 2) {
            f = f * 0.8f;
        }
    } else {
        switch (cCoreSave_getGameLevel(self) - 1) {
        default:
        case 0: f = 1.0f; break;
        case 1: f = 1.0f; break;
        case 2: f = 1.0f; break;
        case 3: f = 1.0f; break;
        case 4: f = 1.0f; break;
        }
        if (D_00747A50 == 0x801) {
            f = f * 0.8f;
        }
    }
    point = (int)((float)point * f);
    if (point < -1000) {
        point = -1000;
    }
    self->data->levelPoint += point;
    if (self->data->levelPoint < 0) {
        self->data->levelPoint = 0;
    }
    if (cCoreSave_getGameDifficulty(self) == 0) {
        q = self->data;
        if (q->levelPoint > D_003BF160[1] - 1) {
            q->levelPoint = D_003BF160[1] - 1;
        }
    } else {
        q = self->data;
        if (q->levelPoint > D_003BF160[4] - 1) {
            q->levelPoint = D_003BF160[4] - 1;
        }
    }
    nl = cCoreSave_getGameLevel(self);
    if (nl < lv - 1) {
        nl = lv - 1;
    }
    if (nl == 4) {
        nl = 3;
    }
    if (lv < nl) {
        self->data->levelDownGrace = 1;
    }
    if (nl < lv) {
        q = self->data;
        nl = nl - 1;
        if (nl < 0) {
            nl = 0;
        }
        if (q->levelDownGrace != 0) {
            q->levelDownGrace -= 1;
            self->data->levelPoint = D_003BF160[nl];
        }
    }
}
