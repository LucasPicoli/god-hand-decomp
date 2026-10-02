/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmManage.h"

extern void ReleaseObj(void *a0);
/* The game object list: begin and end of an array of object pointers. */
typedef struct ObjList {
    int unk0;
    cOmBase **begin;            /* 0x4 */
    cOmBase **end;              /* 0x8 */
} ObjList;
extern ObjList *D_00754C58;

/* Releases every listed enemy, then every object of actor id 0x364 in the
 * object list. */
__attribute__((section(".text.cEmManage_ReleaseEmAll")))
void cEmManage_ReleaseEmAll(cEmManage *self) {
    cEmSlot *slot;
    cOmBase **p;
    cOmBase *obj;
    slot = self->list.top;
    while (slot != 0) {
        cEmSlot *next = slot->next;
        cEmManage_ReleaseEm(self, slot->em);
        slot = next;
    }
    p = D_00754C58->begin;
    while (p != D_00754C58->end) {
        obj = *p;
        if (obj->actorId == 0x364) ReleaseObj(obj);
        p++;
    }
}
