/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"

extern int D_00460D18;

__attribute__((section(".text.func_00134520")))
void func_00134520(cCollisionSolidManageUnit *self, const struct cMatrix *body, const cVec *center,
                   float radius) {
    cCollisionSolidObj *p;
    cCollisionSolidObj *q;

    if (self->owner != 0) {
        if (self->first != 0) {
            q = self->first;
            while (q->next != 0) {
                q = q->next;
            }
            p = cCollisionSolid_constructSphere(func_0030F550(0x80), body, center, radius);
            q->next = p;
        } else {
            p = cCollisionSolid_constructSphere(func_0030F550(0x80), body, center, radius);
            self->first = p;
        }
        if (p != 0) {
            D_00460D18 = D_00460D18 + 1;
        }
    }
}
