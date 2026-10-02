#include "godhand/cEmManage.h"

/* Empties a slot. */
__attribute__((section(".text.cEmManage_clearSlot")))
void cEmManage_clearSlot(cEmSlot *slot) {
    slot->kind = EM_KIND_NONE;
    slot->em = 0;
    slot->used = 0;
    slot->prev = 0;
    slot->next = 0;
}
