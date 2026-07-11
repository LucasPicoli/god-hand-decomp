/* TU: cCockItem [casino] - recovered C++ class. */
#include "include_asm.h"

extern void cIDManager_getLocalFileName();
extern int cDvd_ReadAlloc();
extern void cDvd_CheckWait();
extern void cIDManager_setIDData();
extern void cIDBase_initialize();
extern void cIDBase_restartAnim();
extern int D_003C2388;
extern char D_0041E030[];
extern char D_00583F20[];
extern char D_00754220[];
extern int *D_003C2384;

__attribute__((section(".text.cCockItem_LoadTicket")))
void cCockItem_LoadTicket(char *a0) {
    char buf[0x40];
    char *id;
    int r;

    if (*(int *)(a0 + 0x90) != 0) {
        return;
    }
    cIDManager_getLocalFileName(D_003C2388, buf, D_0041E030, -1);
    id = a0 + 0xB0;
    r = cDvd_ReadAlloc(D_00583F20, buf, a0 + 0x90, D_00754220, 0, 0, 0, 0);
    *(int *)(a0 + 0x94) = r;
    cDvd_CheckWait(D_00583F20, r);
    cIDManager_setIDData(*D_003C2384, 0x19, *(int *)(a0 + 0x90));
    cIDBase_initialize(id, 0x19, 0);
    cIDBase_restartAnim(id);
    *(char *)(id + 0x1C) = 1;
}
