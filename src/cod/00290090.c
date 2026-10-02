/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cEmManage.h"

/* Constructor: builds the 64 slots, empties the list and sets unk520 to
 * (0, 0, 0, 1) from $vf0. */
__attribute__((section(".text.cEmManage_construct")))
cEmManage *cEmManage_construct(cEmManage *self) {
    cEmSlot *slot;
    int i;

    slot = self->slot;
    /* `!= -1`, not `>= 0`: retail materialises -1 and closes with `bne`. */
    for (i = EM_SLOT_NUM - 1; i != -1; i--) {
        cEmManage_constructSlot(slot);
        slot++;
    }

    self->list.top = 0;
    self->list.last = 0;
    VU0_SQC2_VF0(self, EMMANAGE_OFFSET(unk520));
    self->emNum = 0;
    self->kindNum = 0;
    return self;
}
