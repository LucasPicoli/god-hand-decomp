/* sn-2.95.3-136 */
#include "godhand/cModel.h"

/* The part of an effect slot this file reads: its vtable and its group numbers. */
typedef struct EspSlotView {
    char unk000[0xF0];
    cVtEnt *vt;                         /* 0x0F0 */
    char unk0F4[0x146];
    short group;                        /* 0x23A */
    unsigned short subGroup;            /* 0x23C */
    char unk23E[0x1C2];
} EspSlotView;                          /* 0x400 */

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: destroy the slot next frame */
extern int D_0071B8C0[];                /* bit set: destroy the slot this frame */
extern EspSlotView D_0061B7C0[];        /* the 0x400 effect slots */

#define ESP_SLOT_NUM    0x400
#define ESP_VT_NOTIFY   6               /* vtable entry called with arg */

/* Call vtable entry 6 with arg on every live effect slot (in use and not marked for destroy) that is in group/sub
 * (match 0) or not in it (match 1). */
__attribute__((section(".text.func_002FBB78")))
void func_002FBB78(int group, int sub, unsigned char arg, int match)
{
    EspSlotView *p;
    cVtEnt *e;
    unsigned int bit;
    int w;
    int i;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0 || (D_0071B840[w] & bit) != 0 || (D_0071B8C0[w] & bit) != 0) {
            continue;
        }
        p = &D_0061B7C0[i];
        if ((match == 0 && p->group == group && p->subGroup == sub)
            || (match == 1 && (p->group != group || p->subGroup != sub))) {
            e = &p->vt[ESP_VT_NOTIFY];
            ((void (*)(void *, int))e->pfn)((char *)p + e->delta, arg);
        }
    }
}
