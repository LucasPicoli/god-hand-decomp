/* sn-2.95.3-136: func_001C0450, re-register the object's collision / lock-on entry with &D_00569B70 when its drop
 * item, its state bits or its position changed since the last call (or, when only bit 1 of the state bits
 * is set, when the rotation changed), then latch the current state. */
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cCoreSave.h"
extern void func_001FB1C0(void *a0, int a1, int a2, int a3, int a4, void *a5);

#include "godhand/vecInline.h"

/* An object with an entry in the D_00569B70 table, registered again whenever it changes. */
typedef struct cOmEntry {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x662 - 0x5E0];
    unsigned short entryId;             /* 0x662 id the entry is registered under */
    char unk664[0x676 - 0x664];
    unsigned char state;                /* 0x676 state bits; with bit 1 the rotation is watched too */
    unsigned char statePrev;            /* 0x677 state at the last registration */
    char unk678[0x67C - 0x678];
    int dropItemPrev;                   /* 0x67C dropItem at the last registration */
} cOmEntry;

/* vtable slots 16 and 17 of the object give the two words the table keeps for it. */
static inline int vcall(cOmEntry *self, int slot)
{
    cVtEnt *e = &self->base.vtable[slot];

    return ((int (*)(char *))e->pfn)((char *)self + e->delta);
}

static inline void regist(cOmEntry *self)
{
    func_001FB1C0(&D_00569B70, self->entryId, vcall(self, 16), vcall(self, 17), self->base.dropItem, &self->state);
}

__attribute__((section(".text.func_001C0450")))
void func_001C0450(cOmEntry *self)
{
    long flags;
    unsigned long bit;
    long state;

    flags = (unsigned int)self->base.flags0;
    bit = (flags >> 5) & 1;
    if (bit == 1)
        return;
    if (self->base.dropItem != self->dropItemPrev
        || self->state != self->statePrev
        || vec4_ne(&self->base.posA.x, &self->base.pos->x)) {
        regist(self);
    } else {
        state = self->state;
        bit = (state >> 1) & 1;
        if (bit == 1) {
            if (vec4_ne(&self->base.posB.x, &self->base.rot.x))
                regist(self);
        }
    }
    self->dropItemPrev = self->base.dropItem;
    self->statePrev = self->state;
}
