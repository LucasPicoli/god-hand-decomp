/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int D_003BF160[];
extern int cCoreSave_getGameLevel(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.cCoreSave_getLevelProgress")))
/* Progress through the current game level, 0.0 to 1.0. */
float cCoreSave_getLevelProgress(cCoreSave *self)
{
    int level;
    int hi;
    int lo;
    int num;
    float den;

    if (self->data == 0) {
        return 0.0f;
    }
    level = cCoreSave_getGameLevel(self);
    hi = D_003BF160[level - 1];
    if (level - 1 <= 0) {
        lo = 0;
    } else {
        lo = D_003BF160[level - 2];
    }
    den = (float)(hi - lo);
    num = self->data->levelPoint - lo;
    if (den <= 0.0f) {
        den = 1000.0f;
    }
    return (float)num / den;
}
