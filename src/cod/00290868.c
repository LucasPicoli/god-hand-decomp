/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

extern int D_00747A0C;
extern char *D_0077E524;
extern char *D_0077E52C;

/* The listed enemy with the given entry number, or 0. */
__attribute__((section(".text.cEmManage_GetEm")))
cEmActor *cEmManage_GetEm(cEmManage *self, unsigned char entryNo) {
    cEmSlot *slot;
    cEmActor *em;
    if (entryNo == EM_ENTRY_NONE) return 0;
    slot = self->list.top;
    while (slot != 0) {
        em = slot->em;
        if (em->entryNo == (unsigned short)entryNo) return em;
        slot = slot->next;
    }
    return 0;
}

__attribute__((section(".text.cMessage_getRubyAddr")))
void *cMessage_getRubyAddr(char *a0, unsigned short code) {
    if (D_00747A0C == 0) {
        int i = (code >> 12) * 4;
        int j = (code & 0xFFF) * 8;
        char *base = *(char **)(a0 + i);
        int off = *(int *)(base + j + 8);
        if (off != 0) return base + off;
        return 0;
    }
    return 0;
}

__attribute__((section(".text.func_003B2500")))
void func_003B2500(int id) {
    if (id < 0) {
        *(int *)(D_0077E524 + (id & 0x7FFFFFFF) * 12) = 0;
    } else {
        *(int *)(D_0077E52C + id * 12) = 0;
    }
}
