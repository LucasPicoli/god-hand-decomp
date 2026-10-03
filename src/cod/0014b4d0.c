/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"

extern int D_00747AA8;
extern void func_00148BD8(cModelNode *node, int prio, int arg, int mode);
extern void func_00148690(cModelNode *node, int prio, unsigned char *texSlot, int mode);

/* Draw layer of a node when the model is drawn to the screen layer: 2, or 0x14
 * for a late model, 0x1E when the node blends and the model is opaque, and
 * 0x20 for a special node while the special pass is on. */
__attribute__((section(".text.cModel_nodeLayerScreen")))
int cModel_nodeLayerScreen(cModel *self, cModelNode *node) {
    int layer = 2;
    if (self->objFlags & CMODEL_F_LATE) {
        layer = 0x14;
    }
    if (node->dispFlags & CMODEL_NODE_ALPHA) {
        if (cModel_alpha(self) == 1.0f) {
            layer = 0x1E;
        }
    }
    if (node->dispFlags & CMODEL_NODE_SPECIAL) {
        if (D_00747AA8 != 0) {
            layer = 0x20;
        }
    }
    return layer;
}

/* Draw layer of a node: the model's forced layer when it has one, else 0xA
 * (0xE for a back node), 0x14 for a late model, 0x1E when the node blends and
 * the model is opaque, and 0x22 for a special mesh while the special pass is on. */
__attribute__((section(".text.cModel_nodeLayer")))
int cModel_nodeLayer(cModel *self, cModelNode *node) {
    unsigned int flags;
    int layer;
    if (self->layerForce != CMODEL_LAYER_AUTO) {
        return self->layerForce;
    }
    flags = node->dispFlags;
    layer = 0xE;
    if (!(flags & CMODEL_NODE_BACK)) {
        layer = 0xA;
    }
    if (self->objFlags & CMODEL_F_LATE) {
        layer = 0x14;
    }
    if (flags & CMODEL_NODE_ALPHA) {
        if (cModel_alpha(self) == 1.0f) {
            layer = 0x1E;
        }
    }
    if (node->info->flags & CMODEL_MESH_SPECIAL) {
        if (D_00747AA8 != 0) {
            layer = 0x22;
        }
    }
    return layer;
}

/* Set up one node's material: mode 3 when the node blends and the model is
 * opaque, then the special-pass material or the model's own texture exchange. */
__attribute__((section(".text.cModel_setNodeMaterial")))
void cModel_setNodeMaterial(cModel *self, cModelNode *node) {
    int mode = 0;
    if (node->dispFlags & CMODEL_NODE_ALPHA) {
        if (cModel_alpha(self) == 1.0f) {
            mode = 3;
        }
    }
    if ((node->dispFlags & CMODEL_NODE_SPECIAL) && D_00747AA8 != 0) {
        func_00148BD8(node, self->drawPrio, D_00747AA8, mode);
    } else if (self->texFlags & CMODEL_TEX_EXCHANGE) {
        func_00148690(node, self->drawPrio, self->texSlot, mode);
    } else {
        func_00148690(node, self->drawPrio, 0, mode);
    }
}
