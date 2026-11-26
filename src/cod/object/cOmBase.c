/* TU: cOmBase [object] - recovered C++ class. */
#include "godhand/cOmBase.h"

extern char D_005CAE50[];
extern void cCollisionScroll_SetCollEnableByName(char *a0, long a1, int a2);

/* Show or hide every mesh node on one layer. */
__attribute__((section(".text.cOmBase_setMeshDispFromLayer")))
void cOmBase_setMeshDispFromLayer(void *model, int layer, int show) {
    cModelNode *node = (cModelNode *)cModel_getMeshPtr(model, 0);
    if (node != 0) {
        do {
            if (node->layer == layer) {
                if (show == 1) {
                    node->dispFlags &= 0xFFFFFFFE;
                } else {
                    node->dispFlags |= 1;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
#include "include_asm.h"

/* Set the colour of every mesh node on one layer. */
__attribute__((section(".text.cOmBase_setMeshColorFromLayer")))
void cOmBase_setMeshColorFromLayer(void *model, int layer, float r, float g, float b) {
    cModelNode *node = (cModelNode *)cModel_getMeshPtr(model, 0);
    if (node != 0) {
        do {
            if (node->layer == layer) {
                float *c = node->color;
                c[0] = r;
                c[1] = g;
                c[2] = b;
            }
            node = node->next;
        } while (node != 0);
    }
}


/* Turn the scroll-collision (ScrSoll) test of this object's model on or off. */
__attribute__((section(".text.cOmBase_setScrSollEnable")))
void cOmBase_setScrSollEnable(cOmBase *self, int enable) {
    long handle = self->modelHandle;

    cCollisionScroll_SetCollEnableByName(D_005CAE50, handle, enable);
}

