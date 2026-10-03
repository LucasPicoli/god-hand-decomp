#include "godhand/cGameObj.h"

/* sn-2.95.3-136 matched TU. */

/* Copies the remembered position to *out and returns the wait byte kept with it. */
__attribute__((section(".text.func_002A7CA0")))
unsigned char func_002A7CA0(cGameObj *self, cVec *out) {
    cVec *stored = &self->stored;
    if (out != stored) {
        out->x = self->stored.x;
        out->y = stored->y;
        out->z = stored->z;
    }
    return self->storedWait;
}
