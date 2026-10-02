/* TU: cEmManage [enemy] - recovered C++ class. */
#include "godhand/cEmManage.h"

extern float D_00747A14;

/* The manager's speed rate scaled by the global rate in D_00747A14. */
__attribute__((section(".text.cEmManage_GetSpeedRate")))
float cEmManage_GetSpeedRate(cEmManage *self) {
    return self->speedRate * D_00747A14;
}
extern int cDataManager_isLoaded(void *a0, int a1);
extern void cDataManager_loadWait(void *a0, int a1, void *a2, int a3);
extern void cDataManager_loadSeWait(void *a0, int a1, int a2, int a3);
extern char *CreateObj(int a0, int a1);
extern char D_005864E0[];
extern char D_00754220[];

/* Creates the actor a room's SET_EM_DATA names, links it into a free slot at
 * the end of the list and runs its entry setup. Returns the actor, or 0 when
 * no slot is free, the actor can't be made, or its setup fails. */
__attribute__((section(".text.cEmManage_EntryEm")))
cEmActor *cEmManage_EntryEm(cEmManage *self, SET_EM_DATA *data, int kind, void *parent)
{
    int no;
    cEmActor *em;
    cEmSlot *slot;
    cEmList *list;
    cEmActorVt *vt;

    if (data == 0)
        goto ng;
    if (kind < EM_KIND_NONE)
        return 0;
    no = cEmManage_findFreeSlot(self);
    if (no == -1)
        goto ng;
    if (cDataManager_isLoaded(D_005864E0, data->objId) == 0)
        cDataManager_loadWait(D_005864E0, data->objId, D_00754220, 1);
    cDataManager_loadSeWait(D_005864E0, data->objId, data->seBank, data->seNo);
    em = (cEmActor *)CreateObj(data->objId, 0xFFFF);
    if (em == 0)
        return 0;
    slot = &self->slot[no];
    cEmManage_setSlot(slot, em, kind);
    if (slot != 0) {
        list = &self->list;
        if (list->last == 0) {
            list->top = slot;
            slot->prev = 0;
            list->top->next = 0;
            list->last = slot;
        } else {
            list->last->next = slot;
            slot->prev = list->last;
            list->last = slot;
            slot->next = 0;
        }
    }
    self->emNum += 1;
    if (cEmManage_countKind(self, kind) == 1)
        self->kindNum += 1;
    em->entryNo = data->entryNo;
    vt = em->vt;
    if (vt->entry((char *)em + vt->entryDelta, data, parent) != 0)
        return em;
    cEmManage_ReleaseEm(self, em);
ng:
    return 0;
}
