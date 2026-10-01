/* sn-2.95.3-136 matched TU. */
#include "godhand/cObjSimple.h"

extern int cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_0044B430[];
extern char D_0044B438[];
extern char D_0044B440[];
extern char D_0044B448[];
extern char D_0044B458[];
extern char D_0044B468[];
extern char D_0044B470[];
extern char D_0044B478[];
extern char D_0044B480[];
extern char D_0044B488[];
extern char D_0044B490[];
extern char D_0044B498[];

/* Set the one-body flag; when on, hide the extra body meshes that this object id has. */
__attribute__((section(".text.cObjSimple_SetOneBodyFlag")))
void cObjSimple_SetOneBodyFlag(cObjSimple *self, int on) {
    self->oneBodyFlag = on;
    if (on == 0) {
        return;
    }
    cModel_setMeshDisplay(self, D_0044B430, 0);
    switch (self->objId) {
    case 0x204:
    case 0x22B:
        cModel_setMeshDisplay(self, D_0044B438, 0);
        break;
    case 0x24A:
        cModel_setMeshDisplay(self, D_0044B440, 0);
        cModel_setMeshDisplay(self, D_0044B448, 0);
    case 0x240:
        cModel_setMeshDisplay(self, D_0044B458, 0);
        break;
    case 0x201:
    case 0x228:
        cModel_setMeshDisplay(self, D_0044B468, 0);
        break;
    case 0x242:
        cModel_setMeshDisplay(self, D_0044B470, 0);
        cModel_setMeshDisplay(self, D_0044B478, 0);
    case 0x243:
    case 0x244:
        cModel_setMeshDisplay(self, D_0044B480, 0);
        break;
    case 0x251:
        cModel_setMeshDisplay(self, D_0044B488, 0);
    default:
        break;
    }
    cModel_setMeshDisplay(self, D_0044B490, 0);
    cModel_setMeshDisplay(self, D_0044B498, 0);
}
