/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

extern char D_0071B940[];
extern unsigned int D_00741960[];

__attribute__((section(".text.func_003005D8")))
void func_003005D8(char *p) {
    unsigned int i = (unsigned int)(p - D_0071B940) / 0x260;
    D_00741960[i >> 5] |= 0x80000000U >> (i & 0x1F);
}

/* 1 when em is listed and its slot is in use. */
__attribute__((section(".text.cEmManage_ChkActiveEm")))
int cEmManage_ChkActiveEm(cEmManage *self, cEmActor *em) {
    cEmSlot *slot;
    if (em == 0) return 0;
    slot = self->list.top;
    while (slot != 0) {
        if (slot->em == em) {
            if (slot->used == EM_SLOT_USED) return 1;
        }
        slot = slot->next;
    }
    return 0;
}
