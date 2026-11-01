/* sn-2.95.3-136 matched TU. */
/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"

typedef struct ActorSlot {
    cOmBase *actor;
    char padding[0x3c];
} ActorSlot;

static __inline__ void slotPosition(cVec *position, ActorSlot *slot)
{
    cVec zero __attribute__((aligned(16)));
    if (slot->actor) {
        cVec_copy3(position, slot->actor->pos);
    } else {
        cVec_set4(&zero, 0, 0, 0, 1);
        cVec_copy3(position, &zero);
    }
}

/* Return one of five actor slots sorted by ascending position z. */
__attribute__((section(".text.func_001EC388")))
ActorSlot *func_001EC388(char *self, unsigned char rank)
{
    ActorSlot *slots[5];
    cVec positions[2] __attribute__((aligned(16)));
    int i, first, second;
    if (rank >= 5U) return 0;
    for (i = 0; i < 5; i++) slots[i] = (ActorSlot *)(self + 0x5c) + i;
    for (first = 0; first < 4; first++) {
        for (second = first + 1; second < 5; second++) {
            cVec *p = positions;
            int count = 1;
            do {
                VU0_SQC2_VF0(p, 0);
                p++;
            } while (--count != -1);
            slotPosition(&positions[0], slots[first]);
            slotPosition(&positions[1], slots[second]);
            if (positions[0].z > positions[1].z) {
                ActorSlot *a = slots[first], *b = slots[second];
                slots[first] = b;
                slots[second] = a;
            }
        }
    }
    return slots[rank];
}
