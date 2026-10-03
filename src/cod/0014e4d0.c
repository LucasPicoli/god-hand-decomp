#include "godhand/cModel.h"

/* sn-2.95.3-136 matched TU. */

extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern void func_00149220(cModelNode *node, float f);

/* Scroll the texture of every mesh node by f. */
__attribute__((section(".text.cModel_ScrollTexture")))
void cModel_ScrollTexture(cModel *self, float f) {
    cModelNode *node = cModel_getMeshPtr(self, 0);
    if (node != 0) {
        do {
            func_00149220(node, f);
            node = node->next;
        } while (node != 0);
    }
}
