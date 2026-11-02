/* sn-2.95.3-136 */
#include "godhand/cModel.h"
#include "godhand/vecInline.h"

#define COMBASE_F2_KEEP_HIDE  9                 /* flags2 bit: stay hidden */
#define COMBASE_F2_RECALC_BIT 4                 /* flags2 bit: rebuild the parts */
#define COMBASE_F2_RECALC     (1 << COMBASE_F2_RECALC_BIT)
#define COMBASE_F2_MOVED      3                 /* flags2 bit */
#define SYS_HIDE_OBJECTS      0x1000000         /* D_00747A84 */
#define FALL_OUT_Y            -1000.0f

extern unsigned int D_00747A84;
extern void cModel_ScrollTexture(cModel *self, float f);
extern void cModel_calcParts(cModel *self);
extern void cOmBase_dieCommon(int a0);

static inline long cOmBase_flag2Bit(cOmBase *self, int bit)
{
    long f2 = (unsigned int)self->flags2;

    return f2 >> bit & 1;
}

/* Per-frame model upkeep: unhide the object, scroll its textures, rebuild the
 * parts when it moved, remember where it was, and kill it once it falls out
 * of the world. */
__attribute__((section(".text.func_001B76D8")))
void func_001B76D8(cOmBase *self)
{
    long f0 = (unsigned int)self->flags0;
    long active = f0 & COMBASE_F0_ACTIVE;

    if (active == 1) {
        if (cOmBase_flag2Bit(self, COMBASE_F2_KEEP_HIDE) == 0 && !(D_00747A84 & SYS_HIDE_OBJECTS)) {
            self->flags2 &= ~COMBASE_FLAG_HIDDEN;
        }
    }
    cModel_ScrollTexture((cModel *)self, 1.0f);
    if (cOmBase_flag2Bit(self, COMBASE_F2_RECALC_BIT) == 1 || cOmBase_flag2Bit(self, COMBASE_F2_MOVED) == 1
        || vec4_ne(&self->posA.x, &self->pos->x) || vec4_ne(&self->posB.x, &self->rot.x)) {
        cModel_calcParts((cModel *)self);
        self->flags2 &= ~COMBASE_F2_RECALC;
    }
    vec3_copy(&self->posA.x, &self->pos->x);
    vec3_copy(&self->posB.x, &self->rot.x);
    if (self->pos->y < FALL_OUT_Y) {
        cOmBase_dieCommon((int)self);
    }
}
