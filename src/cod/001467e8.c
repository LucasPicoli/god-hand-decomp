/* sn-2.95.3-136 matched TU. */

#include "godhand/cSceAtManager.h"

extern int cIDBase_initialize();
extern int cIDBase_getIDWork(void *a, int b);
extern void IdPair_init(void *a);

/* sn-2.95.3-136. Loop shape inherited verbatim from the matched
   func_0013C220 in src/cod/001342b8.c (same dead-head class, wave 18 K3). */





__attribute__((section(".text.func_001467E8")))
void func_001467E8(void *a0) {
    int *tbl;
    unsigned short i;
    tbl = (int *)((char *)a0 + 0x90);
    cIDBase_initialize(a0, 1, 0x1D);
    cIDBase_initialize((char *)a0 + 0xA0, 1, 0x1E);
    i = 0;
    do {
        *(int *)((char *)tbl + (i << 2)) = cIDBase_getIDWork(a0, i);
        i = i + 1;
    } while (i < 4);
    *(short *)((char *)a0 + 0x100) = 0;
    IdPair_init(a0);
}

/* SN ProDG ee-gcc 2.95.3. House style inherited from the matched
   src/cod/002c2138.c, which calls all three of these callees. */





__attribute__((section(".text.cSceAtManager_AtHitCheckNo")))
int cSceAtManager_AtHitCheckNo(cSceAtManager *self, float *pt, int id) {
    float pos[4];
    cArea area;
    cSceAtUnit *u;

    u = cSceAtManager_getUnit(self, id);
    pos[0] = pt[0];
    pos[1] = pt[1];
    pos[2] = pt[2];
    pos[3] = 1.0f;
    if (u == 0) return 0;
    func_002C1D68(self, &area, u);
    return cArea_HitCheck_1F83E8(&area, pos);
}
