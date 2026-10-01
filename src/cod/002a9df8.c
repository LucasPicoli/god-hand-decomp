/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDBase.h"

extern const float D_003BD880[4];

/* Put a cIDBase in its empty state: no entries, not stopped or hidden, the
 * two vectors copied from D_003BD880, default scale and colour mode. */
__attribute__((section(".text.cIDBase_clear")))
void cIDBase_clear(cIDBaseObj *self) {
    const float *src1;
    const float *src2;
    float *d1;
    float *d2;
    int i;
    int j;

    self->src = 0;
    self->ent = 0;
    self->packed = 0;
    self->entNum = 0;
    self->stop = 0;
    self->hide = 0;
    self->frame = 0;
    self->playing = 0;
    self->b1D = 0;
    self->b1E = 0;

    d1 = self->vecA;
    i = 3;
    src1 = D_003BD880;
    for (; i != -1; i--) {
        *d1++ = *src1++;
    }

    src2 = D_003BD880;
    d2 = self->vecB;
    j = 3;
    for (; j != -1; j--) {
        *d2++ = *src2++;
    }

    self->f40 = 0.01f;
    self->h44 = 0x80;
    self->mode = 6;
}
