/* sn-2.95.3-136 */
#include "godhand/espSys.h"

#define EMITTER_SLOT_NUM    0x100
#define EMITTER_VT_DESTROY  1
#define EMITTER_VT_MOVE     4

extern int D_00741940[];                /* bit set: slot in use */
extern int D_00741960[];                /* bit set: destroy the slot next frame */
extern int D_00741980[];                /* bit set: destroy the slot this frame */
extern unsigned char D_0071B940[];      /* the 0x100 emitter slots */
extern unsigned int D_00747A84;         /* GameWork.flags5E4; D_007474A0.flags5E4 changes the code */
extern int D_003C3BC0;
extern char D_0044FC10[];
extern void printf_2E0DA8(int x, int y, int a2, int a3, char *fmt, ...);

/* Nonzero when any bit of mask is set in flags. */
static __inline__ unsigned int flagTest(unsigned int flags, unsigned int mask)
{
    return flags & mask;
}

/* Move every live emitter slot, destroying the ones marked for it; prints and stores the number moved. */
__attribute__((section(".text.MoveEmitter")))
void MoveEmitter(void)
{
    espEmitter *e;
    cGameObj *own;
    cVtEnt *ent;
    unsigned int bit;
    unsigned int w;
    int i;
    int n;
    int paused;
    int ok;
    int mode;

    paused = 0;
    if (flagTest(D_00747A84, 0x10000))
        paused = 1;
    n = 0;
    for (i = 0; i < EMITTER_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if (flagTest(D_00741940[w], bit) == 0)
            continue;
        e = (espEmitter *)(D_0071B940 + i * sizeof(espEmitter));
        if (flagTest(D_00741980[w], bit)) {
            ent = &((cVtEnt *)e->base.vt)[EMITTER_VT_DESTROY];
            ((void (*)(void *, int))ent->pfn)((char *)e + ent->delta, 2);
            D_00741940[w] &= ~bit;
            continue;
        }
        if (flagTest(D_00741960[w], bit)) {
            D_00741980[w] |= bit;
            continue;
        }
        if (flagTest(e->flags, 0x40000000) == 0) {
            own = e->owner;
            if (own != 0 && flagTest(own->objFlags, 0x8000))
                continue;
            ok = own != 0 && flagTest(own->objFlags, 0x8000) == 0;
            if (paused) {
                mode = e->flags2;
                if (flagTest(mode, 2) == 0) {
                    if (((mode >> 6) & 1) == 0) {
                        if (ok == 0)
                            continue;
                    } else if (flagTest(D_00747A84, 0x4000000) == 0) {
                        continue;
                    }
                }
            }
        }
        n++;
        ent = &((cVtEnt *)e->base.vt)[EMITTER_VT_MOVE];
        ((void (*)(void *))ent->pfn)((char *)e + ent->delta);
    }
    printf_2E0DA8(100, 100, 0, 4, D_0044FC10, n);
    D_003C3BC0 = n;
}
