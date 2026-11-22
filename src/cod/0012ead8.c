/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cGrid.h"

extern cCoreSaveData D_005686D0;   /* the record itself */

/* sn-2.95.3-136 candidate. */





__attribute__((section(".text.func_0012EAD8")))
cCollisionScrollSolid *func_0012EAD8(char *self, void *obj, void *mtx, void *half, void *zero,
                    void *center, void *ax0, void *ax1, void *ax2, void *ax3,
                    void *ax4, void *ax5)
{
    cCollisionScrollSolid *q;
    cCollisionScrollSolid *p;

    if (obj != 0) {
        if (*(cCollisionScrollSolid **)(self + 0x190) != 0) {
            q = *(cCollisionScrollSolid **)(self + 0x190);
            while (q->next != 0) {
                q = q->next;
            }
            p = cHitRec_constructSixBlob(func_0030F550(0x190), obj, mtx, half, zero, center, ax0, ax1, ax2, ax3, ax4, ax5);
            q->next = p;
            if (p != 0) {
                *(int *)(self + 0x194) = *(int *)(self + 0x194) + 1;
                return q->next;
            }
        } else {
            p = cHitRec_constructSixBlob(func_0030F550(0x190), obj, mtx, half, zero, center, ax0, ax1, ax2, ax3, ax4, ax5);
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
