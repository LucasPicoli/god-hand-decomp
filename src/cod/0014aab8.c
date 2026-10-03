#include "godhand/cModel.h"

/* sn-2.95.3-136 matched TU. */

extern int D_007476B0;
extern void func_0014D0E8(cModel *self);
extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern void func_00153B00(cModel *self, cModelNode *node);
extern void func_00155BE8(cModel *self, unsigned int flag, int bit);
extern void func_0014B4D0(cModel *self, cModelNode *node);
extern void ForwardAttackByMode_14B5D8(cModel *self, cModelNode *node);
extern int func_0014BEF8(cModel *self, cModelNode *node);
extern void func_00155AE8(cModelNode *node, int a, int b);
extern void func_0014B810(cModel *self, cModelNode *node, int id);
extern void func_0014C6B8(cModel *self, int id);

/* cModel_Tag_set_scr — sn-2.95.3-136, --call-loop-pad.
   The first mesh walk `do { func_00153B00(this, mesh); mesh = mesh->0x404; }
   while (mesh)` is a TWO-arg call-loop: the closing bnel carries `a1 = mesh`
   in its delay slot, so the injected pad is not absorbed. That loop is the
   padded one (delta 4). The big node loop below is long -> not padded. */













/* Tag every mesh of the model for this frame and queue it. A mesh draws when
 * the model forces all meshes (flag 0x400) or when its back-layer flag equals
 * arg2. Each draw layer change closes the previous run of nodes. Runs with
 * --call-loop-pad: the first mesh walk is a two-argument call loop whose
 * closing branch carries the node in its delay slot. */
__attribute__((section(".text.cModel_Tag_set_scr")))
void cModel_Tag_set_scr(cModel *self, int arg1, int arg2) {
    int bit = D_007476B0 & 1;
    cModelNode *mesh;
    cModelNode *node;
    cModelNode *prev;
    int last;
    int layer;

    func_0014D0E8(self);

    mesh = cModel_getMeshPtr(self, 0);
    if (mesh != 0) {
        do {
            func_00153B00(self, mesh);
            mesh = mesh->next;
        } while (mesh != 0);
    }

    func_00155BE8(self, 0x80000000, bit);

    prev = 0;
    last = 0;
    node = cModel_getMeshPtr(self, 0);
    if (node != 0) {
        do {
            if ((node->dispFlags & CMODEL_NODE_HIDE) == 0) {
                int flags = self->objFlags;
                if ((flags & 0x400) != 0 ||
                    arg2 == ((*(volatile int *)&node->info->flags & CMODEL_MESH_BACK) > 0)) {
                    int flags2;
                    if ((flags & 0x80) == 0) {
                        func_0014B4D0(self, node);
                    }
                    flags2 = self->objFlags;
                    if ((flags2 & 0x00400000) != 0) {
                        ForwardAttackByMode_14B5D8(self, node);
                    }
                    layer = func_0014BEF8(self, node);
                    func_00155AE8(node, layer | 0x80000000, bit);
                    if (last != layer && prev != 0) {
                        func_00155AE8(prev, last, bit);
                    }
                    prev = node;
                    last = layer;
                    func_0014B810(self, node, (short)arg1);
                }
            }
            node = node->next;
        } while (node != 0);
    }

    if (prev != 0) {
        func_00155AE8(prev, last, bit);
    }
    func_0014C6B8(self, (short)arg1);
}
