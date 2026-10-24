/* sn-2.95.3-136 */
#include "godhand/cNode.h"

/* An effect node that follows the state bytes of the object it is anchored to. */
typedef struct cFxStateWatch {
    cNode base;                         /* 0x000 */
    char unkF4[0x14];
    cOmBase *anchor;                    /* 0x108 */
    char unk10C[0x134];
    int state[4];                       /* 0x240 anchor state bytes seen last */
} cFxStateWatch;

extern void func_00302918(int *p);
extern void func_003029C0(cFxStateWatch *self);

static __inline__ unsigned char isAnchorMode(cOmBase *om, int mode)
{
    if (om->mode != mode) {
        return 0;
    }
    return 1;
}

/* Calls func_00302918 when the anchor's byte for its current mode differs from the cached one, then func_003029C0. */
__attribute__((section(".text.func_00304C48")))
void func_00304C48(cFxStateWatch *self)
{
    int same;

    same = 1;
    if (isAnchorMode(self->anchor, 0) && (self->anchor->mode ^ self->state[0]) != 0)
        same = 0;
    if (isAnchorMode(self->anchor, 1) && (self->anchor->phase ^ self->state[1]) != 0)
        same = 0;
    if (isAnchorMode(self->anchor, 2) && (self->anchor->step ^ self->state[2]) != 0)
        same = 0;
    if (isAnchorMode(self->anchor, 3) && (self->anchor->stepArg ^ self->state[3]) != 0)
        same = 0;
    if (same == 0)
        func_00302918(self);
    func_003029C0(self);
}
