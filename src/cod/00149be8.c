/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"

extern void Forward1494F8_149350(cModelNode *node);
extern void func_001F8A88(cBox *box, float x0, float x1, float y0, float y1, float z0, float z1);
extern int D_007476B0;
extern char D_00754C80[];
extern void func_0031A650(void *queue, int kind, int id, void *start, void *end);
extern cModelNode *cModel_getMeshPtr(cModel *self, int idx);
extern void func_0031A600(void *queue, int kind, int id, void *start);
extern int GetField_2B1_14B638(cModel *self);
extern void func_00155D60(cModelNode *node, int value, int slot);

/* Part number n of the model's part list, or 0 when the list is shorter. */
__attribute__((section(".text.func_00149BE8")))
cParts *func_00149BE8(cModel *self, int n) {
    int i = n - 1;
    cParts *part = self->next;
    if (n != 0) {
        do {
            part = part->next;
            if (part == 0) return 0;
            i--;
        } while (i != -1);
    }
    return part;
}

/* Free every mesh node of the model and reset the bounding box to zero. */
__attribute__((section(".text.cModel_removeMesh")))
void cModel_removeMesh(cModel *self) {
    cModelNode *node = self->meshHead;
    cModelNode *next;
    if (node != 0) {
        do {
            next = node->next;
            self->meshNum--;
            Forward1494F8_149350(node);
            self->meshHead = next;
            node = next;
        } while (node != 0);
    }
    func_001F8A88(&self->box, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
}

/* Queue the node's draw packet for this frame's parity. A model that sorts
 * per node goes in as kind 6, id 4; any other model uses its own kind and id. */
__attribute__((section(".text.func_0014B918")))
void func_0014B918(cModel *self, cModelNode *node) {
    int parity = D_007476B0 & 1;
    if (node->dispFlags & CMODEL_NODE_HIDE) {
        return;
    }
    if (self->drawKind == CMODEL_KIND_PER_NODE) {
        func_0031A650(D_00754C80, 6, 4, node->packet[parity], node->packet[parity] + 0xA0);
    } else {
        func_0031A650(D_00754C80, self->drawKind, self->id, node->packet[parity], node->packet[parity] + 0xA0);
    }
}

/* Queue the node's draw packet for this frame's parity. A model that sorts
 * per node goes in as kind 4, id 5; any other model uses its own kind and id. */
__attribute__((section(".text.func_0014BDB0")))
void func_0014BDB0(cModel *self, cModelNode *node) {
    int parity = D_007476B0 & 1;
    if (node->dispFlags & CMODEL_NODE_HIDE) {
        return;
    }
    if (self->drawKind == CMODEL_KIND_PER_NODE) {
        func_0031A650(D_00754C80, 4, 5, node->packet[parity], node->packet[parity] + 0xA0);
    } else {
        func_0031A650(D_00754C80, self->drawKind, self->id, node->packet[parity], node->packet[parity] + 0xA0);
    }
}

#define CMODEL_NODE_SORTED 0x4080       /* dispFlags bits that pick draw kind 2 */

/* Queue the model's own packet for this frame's parity. The first mesh's
 * flags pick the kind for a per-node model, as in func_0014B810. */
__attribute__((section(".text.func_0014C6B8")))
void func_0014C6B8(cModel *self, short id) {
    char *start = self->packet[D_007476B0 & 1];
    unsigned int flags = cModel_getMeshPtr(self, 0)->dispFlags;
    int kind = self->drawKind;
    char *end = start + 0x70;
    if (kind == CMODEL_KIND_PER_NODE) {
        if (flags & CMODEL_NODE_SORTED) {
            if (end == 0) func_0031A600(D_00754C80, 2, id, start);
            else func_0031A650(D_00754C80, 2, id, start, end);
        } else {
            if (end == 0) func_0031A600(D_00754C80, 1, 0xD, start);
            else func_0031A650(D_00754C80, 1, 0xD, start, end);
        }
    } else {
        if (end == 0) func_0031A600(D_00754C80, kind, self->id, start);
        else func_0031A650(D_00754C80, kind, self->id, start, end);
    }
}

/* Set value in both slots of every mesh node, by index. */
__attribute__((section(".text.func_0014E778")))
void func_0014E778(cModel *self, int value) {
    int num = GetField_2B1_14B638(self);
    int i = 0;
    if (num > 0) {
        do {
            cModelNode *node = cModel_getMeshPtr(self, i);
            i++;
            func_00155D60(node, value, 0);
            func_00155D60(node, value, 1);
        } while (i < num);
    }
}
