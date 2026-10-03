#include "godhand/cModel.h"

/* TU: cModel [gfx] - recovered C++ class. */

/* Mesh node number n of the model's list; the first node when the list is
 * shorter than n. */
__attribute__((section(".text.cModel_getMeshPtr")))
cModelNode *cModel_getMeshPtr(cModel *self, int n) {
    int i = n - 1;
    cModelNode *node = self->meshHead;
    if (n != 0) {
        do {
            node = node->next;
            if (node == 0) {
                return self->meshHead;
            }
            i--;
        } while (i != -1);
    }
    return node;
}
#include "include_asm.h"

INCLUDE_ASM("nonmatching", cModel_calcParts);
