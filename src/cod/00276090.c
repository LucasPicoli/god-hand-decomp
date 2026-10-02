/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

__attribute__((section(".text.func_00276090")))
void func_00276090(int *a0, int a1) {
    if (a1) {
        *(int*)((char*)a0+0x16D4) |= 0x200000;
    } else {
        *(int*)((char*)a0+0x16D4) &= ~0x200000;
    }
}

/* Index of the first unused slot, or -1 when all 64 are in use. */
__attribute__((section(".text.cEmManage_findFreeSlot")))
int cEmManage_findFreeSlot(cEmManage *self) {
    cEmSlot *slot = self->slot;
    unsigned int i;
    for (i = 0; i < EM_SLOT_NUM; i++) {
        if (slot->used == 0) {
            return i;
        }
        slot++;
    }
    return -1;
}

/* Puts an actor into the first empty unk5AC entry; does nothing when both
 * are taken. */
__attribute__((section(".text.func_00294898")))
void func_00294898(cEmManage *self, cEmActor *actor) {
    cEmActor **p = self->unk5AC;
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (*p == 0) {
            *p = actor;
            return;
        }
        p++;
    }
}

__attribute__((section(".text.func_002AED40")))
void *func_002AED40(void *a0, int a1) {
    void *v1 = *(void**)((char*)a0 + 0x10);
    unsigned short w = (unsigned short)(a1 & 0xFFFF);
    while (v1 != 0) {
        if (*(unsigned short*)((char*)v1 + 0x64) == w) return v1;
        v1 = *(void**)((char*)v1 + 8);
    }
    return 0;
}

typedef struct Node_00276090 {
    int pad0;
    struct Node_00276090 *prev;
    struct Node_00276090 *next;
} Node_00276090;

__attribute__((section(".text.func_002B2318")))
Node_00276090 *func_002B2318(Node_00276090 *a0) {
    Node_00276090 *prev;
    Node_00276090 *next;
    prev = a0->prev;
    if (prev != 0) {
        prev->next = a0->next;
    }
    next = a0->next;
    if (next != 0) {
        next->prev = a0->prev;
    }
    return a0->next;
}
