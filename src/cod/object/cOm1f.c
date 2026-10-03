/* TU: cOm1f [object] - recovered C++ class. */
#include "godhand/cOm1f.h"

extern void cModel_calcParts(cOm1f *self);
extern void cOmBase_setMeshDispFromLayer(cOm1f *self, int a, int b);

/* Switch between the two set types: clear the child's mesh flag bits and
 * rebuild the parts, then show the mesh layer for the type and (type 0)
 * set the child's flag bits again. */
__attribute__((section(".text.cOm1f_changeSetType")))
void cOm1f_changeSetType(cOm1f *self, int type) {
    char frame[16];                     /* cOmBase_childAt stores the child count here, a dead store retail keeps */
    if (cOmBase_childAt(&self->base, (int *)frame, 1) != 0) {
        ((cOm1fChild *)cOmBase_childAt(&self->base, (int *)frame, 1))->meshFlags &= ~COM1F_CHILD_FLAG_A;
        ((cOm1fChild *)cOmBase_childAt(&self->base, (int *)frame, 1))->meshFlags &= ~COM1F_CHILD_FLAG_B;
        cModel_calcParts(self);
    }
    switch (type) {
    case 0:
    default:
        cOmBase_setMeshDispFromLayer(self, 0, 1);
        self->setType = 0;
        if (cOmBase_childAt(&self->base, (int *)frame, 1) != 0) {
            ((cOm1fChild *)cOmBase_childAt(&self->base, (int *)frame, 1))->meshFlags |= COM1F_CHILD_FLAG_A;
            ((cOm1fChild *)cOmBase_childAt(&self->base, (int *)frame, 1))->meshFlags |= COM1F_CHILD_FLAG_B;
        }
        break;
    case 1:
        cOmBase_setMeshDispFromLayer(self, 0, 0);
        self->setType = type;
        break;
    }
}
