#include "godhand/cGameObj.h"

/* ee-2.9-991111 matched TU. */

extern int IsTargetVisible_14B470();

/* 1 when the object is cut off by the screen frustum or lies behind the camera,
 * else whether it is visible at all. */
__attribute__((section(".text.cGameObj_isClip")))
int cGameObj_isClip(cGameObj *self) {
    long f = (unsigned)self->scrFlags;
    long t;
    t = f & GAMEOBJ_SCR_CLIP;
    if (t != 0) {
        return 1;
    }
    t = (f >> 1) & 1;
    if (t != 0) {
        return 1;
    }
    return IsTargetVisible_14B470(self) != 0;
}
