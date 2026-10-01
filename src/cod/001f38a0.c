/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageUnit.h"
#include "godhand/ColiseumEmSelect.h"
#include "godhand/cSceAtManager.h"

extern ColiseumHost **D_003C2384;
extern void func_001F46E0(void *idBase);
extern void UnlinkAndCoalesceNode_2A9680(int heap, int *node);

/* Set the radius of the hit volume with the given id (first match only). */
__attribute__((section(".text.cDamageUnit_SetDamageCollRadius")))
void cDamageUnit_SetDamageCollRadius(cDamageUnit *self, int id, float radius)
{
    cDamageNode *node = self->nodes;
    if (node == 0) return;
    do {
        if (node->id == id) {
            cCollisionShape *shape = node->data->shape;
            cDamageVtEnt *ent = &shape->vt[CDAMAGE_SHAPE_SETRADIUS];
            ((void (*)(void *, float))ent->pfn)((char *)shape + ent->delta, radius);
            return;
        }
        node = node->next;
    } while (node != 0);
}

/* Close the screen: release its id, clear the two scenario words and free the card node. */
__attribute__((section(".text.func_001F38A0")))
void func_001F38A0(ColiseumEmSelect *self)
{
    ColiseumHost *host;
    func_001F46E0(self->idBase);
    host = *D_003C2384;
    host->pickB = 0;
    host->pickA = 0;
    if (self->cardNode != 0) {
        UnlinkAndCoalesceNode_2A9680(self->cardNode[-8], self->cardNode);
    }
}

/* cSceAtManager_AtDataSet_exec_2C2750: set hit kind, data and frame count on one unit. */


__attribute__((section(".text.cSceAtManager_AtDataSet_exec_2C2750")))
void cSceAtManager_AtDataSet_exec_2C2750(cSceAtManager *self, cSceAtUnit *unit, int a2, int a3, int a4, int a5) {
    if (unit != 0) {
        if (a5 != 0) {
            if (unit->prevHitKind == 0) {
                unit->prevHitKind = unit->hitKind;
            }
            unit->hitKind = a5;
        }
        unit->data44 = a2;
        unit->dataC = a3;
        unit->data40 = a4;
    }
}
