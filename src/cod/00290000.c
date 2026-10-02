/* cygnus-2.96 matched TU. */
#include "godhand/cEmManage.h"

/* Slot constructor: empty, out of the list, kind EM_KIND_NONE. */
__attribute__((section(".text.cEmManage_constructSlot")))
cEmSlot *cEmManage_constructSlot(cEmSlot *slot) {
    slot->prev = 0;
    slot->kind = EM_KIND_NONE;
    slot->next = 0;
    slot->em = 0;
    slot->used = 0;
    return slot;
}
