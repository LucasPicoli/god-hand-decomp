/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cGrid.h"

extern cCoreSaveData D_005686D0;   /* the record itself */

/* sn-2.95.3-136 candidate. */





__attribute__((section(".text.func_0012EAD8")))
cCollisionScrollSolid *func_0012EAD8(char *self, void *obj, void *mtx, void *v70, void *v90,
                    void *extent, void *face0, void *face1, void *face2, void *face3,
                    void *face4, void *face5)
{
    cCollisionScrollSolid *q;
    cCollisionScrollSolid *p;

    if (obj != 0) {
        if (*(cCollisionScrollSolid **)(self + 0x190) != 0) {
            q = *(cCollisionScrollSolid **)(self + 0x190);
            while (q->next != 0) {
                q = q->next;
            }
            p = cHitRec_constructSixBlob(func_0030F550(0x190), obj, mtx, v70, v90, extent, face0, face1, face2, face3, face4, face5);
            q->next = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return q->next;
            }
        } else {
            p = cHitRec_constructSixBlob(func_0030F550(0x190), obj, mtx, v70, v90, extent, face0, face1, face2, face3, face4, face5);
            *(cCollisionScrollSolid **)(self + 0x190) = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return p;
            }
        }
    }
    return 0;
}

/* sn-2.95.3-136 candidate. */








__attribute__((section(".text.cCoreSave_systemInit")))
void cCoreSave_systemInit(cCoreSave *self)
{
    unsigned int i;

    func_003A52F0(&D_005686D0, 0, sizeof(cCoreSaveData));
    D_00569B70.data = &D_005686D0;
    cCoreSave_initItem(self);
    for (i = 0; i < 0x80; i++) {
        self->data->skill[i] = -1;
    }
    cCoreSave_clearPaper(self);
    cCoreSave_setGameDifficulty(self, 1);
}
