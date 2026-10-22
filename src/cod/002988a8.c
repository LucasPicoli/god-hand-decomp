/* sn-2.95.3-136: func_002988A8, picks the mesh set of models 0x600/0x602 for the level (below 13 or not) and hides
 * two meshes of model 0x626. */
#include "godhand/cOmBase.h"
extern char D_0044AB60[];
extern char D_0044AB68[];
extern char D_0044AB70[];
extern char D_0044AB78[];
extern char D_0044AB80[];
extern char D_0044AB88[];
extern char D_0044AB90[];
extern char D_0044AB98[];
extern int cModel_setMeshDisplay(void *model, char *name, int on);

__attribute__((section(".text.func_002988A8")))
void func_002988A8(cOmBase *m, int unused, int level)
{
    if (m == 0)
        return;
    switch (m->actorId) {
    case 0x600:
        if (level < 13) {
            cModel_setMeshDisplay(m, D_0044AB60, 0);
            cModel_setMeshDisplay(m, D_0044AB68, 0);
            cModel_setMeshDisplay(m, D_0044AB70, 1);
            cModel_setMeshDisplay(m, D_0044AB78, 0);
            cModel_setMeshDisplay(m, D_0044AB80, 1);
            cModel_setMeshDisplay(m, D_0044AB88, 0);
        } else {
            cModel_setMeshDisplay(m, D_0044AB60, 1);
            cModel_setMeshDisplay(m, D_0044AB68, 1);
            cModel_setMeshDisplay(m, D_0044AB70, 0);
            cModel_setMeshDisplay(m, D_0044AB78, 0);
            cModel_setMeshDisplay(m, D_0044AB80, 0);
            cModel_setMeshDisplay(m, D_0044AB88, 1);
        }
        break;
    case 0x602:
        if (level < 13) {
            cModel_setMeshDisplay(m, D_0044AB60, 0);
            cModel_setMeshDisplay(m, D_0044AB70, 1);
            cModel_setMeshDisplay(m, D_0044AB78, 0);
            cModel_setMeshDisplay(m, D_0044AB80, 1);
            cModel_setMeshDisplay(m, D_0044AB88, 0);
        } else {
            cModel_setMeshDisplay(m, D_0044AB60, 1);
            cModel_setMeshDisplay(m, D_0044AB70, 0);
            cModel_setMeshDisplay(m, D_0044AB78, 0);
            cModel_setMeshDisplay(m, D_0044AB80, 0);
            cModel_setMeshDisplay(m, D_0044AB88, 1);
        }
        break;
    case 0x626:
        cModel_setMeshDisplay(m, D_0044AB90, 0);
        cModel_setMeshDisplay(m, D_0044AB98, 0);
        break;
    }
}
