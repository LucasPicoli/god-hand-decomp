/* sn-2.95.3-136 */
#include "godhand/cModel.h"

/* The part of an effect's owner this file reads. */
typedef struct EspOwner {
    char unk000[0x250];
    int flags;                          /* 0x250 */
} EspOwner;

/* The part of an effect slot this file reads. */
typedef struct EspSlot {
    char unk000[0xF0];
    cVtEnt *vt;                         /* 0x0F0 */
    char unk0F4[0x10];
    int mode;                           /* 0x104 */
    char unk108[0xC];
    EspOwner *owner;                    /* 0x114 */
    char unk118[0x2E8];
} EspSlot;                              /* 0x400 */

#define ESP_SLOT_NUM    0x400
#define ESP_VT_DESTROY  1
#define ESP_VT_MOVE     4

struct cAreaFx;

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: destroy the slot next frame */
extern int D_0071B8C0[];                /* bit set: destroy the slot this frame */
extern char D_0061B7C0[];               /* the 0x400 effect slots */
extern int D_00747A84;                 /* GameWork.flags5E4; D_007474A0.flags5E4 changes the code */
extern int D_003C3BB8;
extern char D_007419A0;
extern char D_00743250[];
extern void func_00305C20(struct cAreaFx *self);
extern void func_00306E38(char *pool);

/* Nonzero when any bit of mask is set in flags. */
static __inline__ unsigned int flagTest(unsigned int flags, unsigned int mask)
{
    return flags & mask;
}

/* Update the area effects and the pool, then move every live effect slot, destroying the ones marked for it. */
__attribute__((section(".text.MoveEsp")))
void MoveEsp(void)
{
    EspSlot *e;
    EspOwner *own;
    cVtEnt *ent;
    unsigned int bit;
    unsigned int w;
    int i;
    int n;
    int paused;
    int ok;
    int mode;
    unsigned long flags;

    flags = D_00747A84;
    if ((flags & 0x20000000) == 0 && ((flags >> 6) & 1) == 0)
        func_00305C20((struct cAreaFx *)&D_007419A0);
    else if (flagTest(D_00747A84, 0x4000000))
        func_00305C20((struct cAreaFx *)&D_007419A0);
    func_00306E38(D_00743250);
    n = 0;
    paused = 0;
    if (flagTest(D_00747A84, 0x10000))
        paused = 1;
    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if (flagTest(D_0071B7C0[w], bit) == 0)
            continue;
        e = (EspSlot *)(D_0061B7C0 + i * sizeof(EspSlot));
        if (flagTest(D_0071B8C0[w], bit)) {
            ent = &e->vt[ESP_VT_DESTROY];
            ((void (*)(void *, int))ent->pfn)((char *)e + ent->delta, 2);
            D_0071B7C0[w] &= ~bit;
            continue;
        }
        if (flagTest(D_0071B840[w], bit)) {
            D_0071B8C0[w] |= bit;
            continue;
        }
        own = e->owner;
        if (own != 0 && flagTest(own->flags, 0x8000))
            continue;
        ok = 0;
        if (paused) {
            if (own != 0)
                ok = flagTest(own->flags, 0x8000) == 0;
            mode = e->mode;
            if (flagTest(mode, 2) == 0) {
                if (((mode >> 6) & 1) == 0) {
                    if (ok == 0)
                        continue;
                } else if (flagTest(D_00747A84, 0x4000000) == 0) {
                    continue;
                }
            }
        }
        n++;
        ent = &e->vt[ESP_VT_MOVE];
        ((void (*)(void *))ent->pfn)((char *)e + ent->delta);
    }
    D_003C3BB8 = n;
}
