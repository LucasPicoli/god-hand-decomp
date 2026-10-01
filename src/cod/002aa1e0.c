/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDBase.h"

extern int *D_003C2384;
extern int D_003C2388;
extern void cIDBase_initEntry(cIDBaseObj *self, cIDBaseSrc *src, cIDBaseEnt *ent);

/* Hide or show an entry and, recursively, its parent chain. */
__attribute__((section(".text.cIDBase_setDispParent")))
void cIDBase_setDispParent(cIDBaseObj *self, cIDBaseEnt *ent, int show)
{
    cIDBaseEnt *parent = ent->parent;
    if (parent != 0) {
        if ((show ^ 1) != 0) {
            parent->flags |= IDENT_FLAG_HIDDEN;
        } else {
            parent->flags &= ~IDENT_FLAG_HIDDEN;
        }
        cIDBase_setDispParent(self, ent->parent, show);
    }
}

/* Hide or show every entry whose parent is `ent`, and recurse into them. */
__attribute__((section(".text.cIDBase_setDispChildren")))
void cIDBase_setDispChildren(cIDBaseObj *self, cIDBaseEnt *ent, int show)
{
    int i;
    for (i = 0; i < self->entNum; i++) {
        cIDBaseEnt *child = &self->ent[i];
        if (ent != child) {
            if (ent == child->parent) {
                if ((show ^ 1) != 0) {
                    child->flags |= IDENT_FLAG_HIDDEN;
                } else {
                    child->flags &= ~IDENT_FLAG_HIDDEN;
                }
                cIDBase_setDispChildren(self, &self->ent[i], show);
            }
        }
    }
}

/* Fill display entry `ent` from source record `src`. */
__attribute__((section(".text.cIDBase_initEntry")))
void cIDBase_initEntry(cIDBaseObj *self, cIDBaseSrc *src, cIDBaseEnt *ent)
{
    ent->src = src;
    ent->seed = 0xBC614E;
    ent->kind = src->kind;
    ent->flags = src->flags;
    ent->posX = src->posX;
    ent->posY = src->posY;
    ent->sclX = src->sclX;
    ent->sclY = src->sclY;
    ent->rotSpeed = src->rotSpeed;
    ent->colorBase.word = src->colorBase;
    ent->f68 = src->f14;
    ent->f6C = src->f18;
    ent->f70[0] = src->f40[0];
    ent->f70[1] = src->f40[1];
    ent->f70[2] = src->f40[2];
    ent->f70[3] = src->f40[3];
    ent->b89 = src->b54;
    ent->b28 = src->b01;
    ent->parentRef = src->parentRef;
    ent->id = src->id;
    ent->b8A = src->b55;
    ent->b8B = src->b56;
    ent->b8D = src->b58;
    ent->h8E = src->h5A;
    ent->f80 = src->f60;
    ent->layer = src->layer;
    ent->b8C = src->b65;
    ent->part[0] = src->partA;
    ent->part[1] = src->partB;
    ent->part[2] = src->partC;
    ent->part[3] = src->partD;
    ent->part[4] = src->partE;
    ent->msg = 0;
}

/* Take `num` source records and build one display entry for each. When the
 * resource is the current one, records marked unused are skipped. */
__attribute__((section(".text.cIDBase_buildEntries")))
void cIDBase_buildEntries(cIDBaseObj *self, cIDBaseSrc *src, int num)
{
    int i;
    self->src = src;
    func_003A52F0(self->ent, 0, num * IDBASE_ENT_SIZE);
    for (i = 0; i < num; i++) {
        if (*D_003C2384 == D_003C2388) {
            while (src->flags & IDENT_FLAG_SRC_SKIP) src++;
        }
        cIDBase_initEntry(self, src, &self->ent[i]);
        src++;
    }
}
