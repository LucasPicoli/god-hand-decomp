/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDBase.h"

extern unsigned char *D_003C23A4;
extern void func_002AB9A8(cIDBaseObj *self, int a1);
extern unsigned int Forward30F348_31CFE0(void);
extern void func_002ABC18(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002ABC30(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002ABCE8(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002ABD30(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002ABD78(cIDBaseObj *self, cIDBaseEnt *ent);

/* Place the message window for a message entry: copy its position and scale
 * into the message record and tell the draw side which font to use. */
__attribute__((section(".text.cIDBase_transIcon")))
void cIDBase_transIcon(cIDBaseObj *self, cIDBaseEnt *ent)
{
    unsigned char *rec;
    short x, y;
    float sx, sy;
    int id = 0x3000;
    if (ent->msg != 0) id = ent->msg;
    rec = func_002AED40(D_003C23A4, id);
    if (rec == 0) return;
    x = (short)ent->drawX;
    y = (short)ent->drawY;
    *(short *)(rec + 0xA6) = x;
    *(short *)(rec + 0xA8) = y;
    sx = ent->drawSclX;
    sy = ent->drawSclY;
    *(float *)(rec + 0x54) = sx;
    *(float *)(rec + 0x58) = sy;
    *(short *)(rec + 0x5E) = (short)(-ent->drawSclY * 24.0f + 4.0f);
    *(short *)(rec + 0x5C) = 1;
    func_002AB9A8(self, ent->b8B);
}

/* Restart every entry's animation: clear the frame counter, give flagged
 * entries new random jitter, and run the five per-entry reset steps. */
__attribute__((section(".text.cIDBase_resetAnim")))
void cIDBase_resetAnim(cIDBaseObj *self)
{
    int i;
    self->frame = 0;
    self->b1D = 0;
    self->b1E = 0;
    if (self->ent == 0) return;
    for (i = 0; i < self->entNum; i++) {
        cIDBaseEnt *ent = &self->ent[i];
        unsigned long flags, rnd;
        if (ent != 0) {
            flags = ent->flags;
            rnd = (flags >> IDENT_FLAG_RAND_BIT) & 1;
            if (rnd != 0) {
                ent->jit[0] = Forward30F348_31CFE0() % IDBASE_RAND_MAX;
                ent->jit[1] = Forward30F348_31CFE0() % IDBASE_RAND_MAX;
                ent->jit[3] = Forward30F348_31CFE0() % IDBASE_RAND_MAX;
                ent->jit[4] = Forward30F348_31CFE0() % IDBASE_RAND_MAX;
                ent->jit[2] = Forward30F348_31CFE0() % IDBASE_RAND_MAX;
            } else {
                ent->jit[0] = 0;
                ent->jit[1] = 0;
                ent->jit[3] = 0;
                ent->jit[4] = 0;
                ent->jit[2] = 0;
            }
            func_002ABC18(self, ent);
            func_002ABC30(self, ent);
            func_002ABCE8(self, ent);
            func_002ABD30(self, ent);
            func_002ABD78(self, ent);
        }
    }
}
