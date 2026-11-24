/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

__attribute__((section(".text.func_00155D60")))
unsigned char *func_00155D60(unsigned char *base, long val, int idx) {
    unsigned char *p;
    int i;

    for (i = base[0x385] - 1; i != 0; i--) {
        ;
    }
    p = base + idx * 0xB0;
    *(long *)(p + 0x30) = val;
    return p;
}

__attribute__((section(".text.cSceAtManager_initFreeList")))
void cSceAtManager_initFreeList(void *unused, unsigned int *arr, int count) {
    int i;

    arr[0] = 0xFFFFFFFF;
    for (i = 0; i < count - 1; i++) {
        arr[i + 1] = ((unsigned int)&arr[i]) & 0x7FFFFFFF;
    }
}

__attribute__((section(".text.func_001FD988")))
void func_001FD988(cDamageUnit *self, int kind) {
    cDamageNode *p;
    int group;

    self->unitKind = kind;
    group = func_001FD908(self);
    for (p = self->nodes; p != 0; p = p->next) {
        p->unit->group = group;
    }
}
