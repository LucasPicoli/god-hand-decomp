/* TU: cIDBase [id] - recovered C++ class. */
#include "godhand/vu0.h"
#include "godhand/cIDBase.h"
extern int *D_003C2384;

/* The stores go through a raw byte offset: through the struct fields the
 * scheduler floats the D_003C2384 load above them and the bytes change. */
extern void cIDBase_clear(cIDBaseObj *self);
extern void *func_002ACD78(int a0, int a1, int a2);
extern int cIDBase_setWorkFromData(cIDBaseObj *self, void *data);
extern void cIDBase_resetAnim(cIDBaseObj *self);
/* Load resource `resNo` and build the entry table from it. 1 on success. */
__attribute__((section(".text.cIDBase_initialize")))
int cIDBase_initialize(cIDBaseObj *self, int resNo, int id)
{
    void *res;
    cIDBase_clear(self);
    *(int *)((char *)self + IDBASE_OFFSET(id)) = id;
    *(char *)((char *)self + IDBASE_OFFSET(mode)) = 6;
    *(int *)((char *)self + IDBASE_OFFSET(resNo)) = resNo;
    res = func_002ACD78(*D_003C2384, resNo, id + 1);
    if (res == 0)
        return 0;
    if (cIDBase_setWorkFromData(self, res) != 0)
        cIDBase_resetAnim(self);
    return 1;
}

/* Reset every entry's animation and start playing. */
__attribute__((section(".text.cIDBase_restartAnim")))
void cIDBase_restartAnim(cIDBaseObj *self)
{
    cIDBase_resetAnim(self);
    self->playing = 1;
}
#include "include_asm.h"

extern unsigned char *D_003C23A4;
extern int cMessage_create(int a0, int a1, int a2, int a3, int t0);

/* Constructor: clear the two vectors at 0x20 and 0x30, then the common init. */
__attribute__((section(".text.cIDBase")))
cIDBaseObj *cIDBase(cIDBaseObj *self)
{
    VU0_SQC2_VF0(self, 0x20);
    VU0_SQC2_VF0(self, 0x30);
    cIDBase_clear(self);
    return self;
}

extern cIDBaseEnt *cIDBase_getIDWork(cIDBaseObj *self, int id);
extern void cIDBase_setDispParent(cIDBaseObj *self, cIDBaseEnt *ent, int show);
extern void cIDBase_setDispChildren(cIDBaseObj *self, cIDBaseEnt *ent, int show);
/* Show or hide the entry with id `id`, its parent chain and its children. */
__attribute__((section(".text.cIDBase_setDispFamily")))
void cIDBase_setDispFamily(cIDBaseObj *self, int id, int show)
{
    cIDBaseEnt *ent = cIDBase_getIDWork(self, id);
    cIDBase_setDispParent(self, ent, show);
    cIDBase_setDispChildren(self, ent, show);
}


extern void cIDBase_calcEntries(cIDBaseObj *self);
extern void func_002ABDC0(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002AC048(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002AC1C0(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002AC298(cIDBaseObj *self, cIDBaseEnt *ent);
extern void func_002AC378(cIDBaseObj *self, cIDBaseEnt *ent);
/* One frame: lay out the entries, advance the frame counter (wraps at
 * IDBASE_FRAME_MAX), step each entry, and post a message once an icon entry
 * (kind 4) with a message id has been shown. */
__attribute__((section(".text.cIDBase_move")))
void cIDBase_move(cIDBaseObj *self)
{
    int i;
    int frame;
    unsigned long flags;
    if (self->stop != 0) return;
    if (self->ent == 0) return;
    cIDBase_calcEntries(self);
    if (self->playing == 0) return;
    frame = self->frame + 1;
    self->frame = (short)frame;
    if ((short)frame >= IDBASE_FRAME_MAX) self->frame = 0;
    i = 0;
    while (i < self->entNum) {
        cIDBaseEnt *ent = &self->ent[i];
        if (ent != 0) {
            func_002ABDC0(self, ent);
            func_002AC048(self, ent);
            func_002AC1C0(self, ent);
            func_002AC298(self, ent);
            func_002AC378(self, ent);
            if (ent->kind == IDENT_KIND_ICON) {
                flags = ent->flags;
                if (((flags >> 1) & 1) == 0) {
                    if (ent->msg != 0xFFFF) {
                        cMessage_create((int)D_003C23A4, ent->msg, 0, 0, 0);
                        ent->flags = ent->flags | IDENT_FLAG_MSG_SENT;
                    }
                }
            }
        }
        i++;
    }
}

extern void *D_003C2380;
extern int D_005E7510;
extern int D_007474A0;
extern char D_0044AF20[];
extern char D_0044AF28[];
extern char D_0044AF30[];
extern void *SearchData(void *a, void *b, int c);
extern void cFont_setTextureAddr(void *a0, int a1, void *a2, void *a3);
extern void cScrSpriteDraw_drawInit(void *p);
extern void cMessDrawFont_setEnvInit(void *a0);
extern void func_002AF6A8(void *a0, int a1, int a2);

extern void cIDBase_transSprite(cIDBaseObj *self, cIDBaseDraw *draw, cIDBaseEnt *ent);
extern void cIDBase_transText(cIDBaseObj *self, cIDBaseEnt *ent);
extern void cIDBase_transIcon(cIDBaseObj *self, cIDBaseEnt *ent);
extern void cIDBase_transPanel(cIDBaseObj *self, cIDBaseEnt *ent);
extern void cIDBase_transTex(cIDBaseObj *self, cIDBaseDraw *draw, cIDBaseEnt *ent);
/* Draw every visible entry, layer 4 first and layer -4 last, picking the
 * draw routine from the entry's kind. An entry is skipped when it is HIDDEN
 * or NO_DRAW, or when a CHILD-flagged entry in its parent chain is NO_DRAW. */
__attribute__((section(".text.cIDBase_trans")))
void cIDBase_trans(cIDBaseObj *self)
{
    int draw[0x10];
    int layer;
    int i;

    if (self->hide != 0) return;
    if (self->ent == 0) return;
    cScrSpriteDraw_drawInit(draw);
    ((cIDBaseDraw *)draw)->unk30 = 0;
    if (self->packed != 0) {
        char *g = (char *)&D_007474A0;
        int mode = *(int *)(g + 0x56C);
        if (mode == 0) {
            void *t = SearchData(self->packed, D_0044AF20, 0);
            cFont_setTextureAddr(D_003C2380, 3, t, SearchData(self->packed, D_0044AF28, 0));
        } else if (mode >= 0) {
            if (mode < 7) {
                void *t = SearchData(*(void **)(g + 0x558), D_0044AF20, 0);
                cFont_setTextureAddr(D_003C2380, 3, t, SearchData(self->packed, D_0044AF28, 0));
            }
        }
        *(void **)(D_003C23A4 + 0x8) = SearchData(self->packed, D_0044AF30, 0);
    }
    cMessDrawFont_setEnvInit(&D_005E7510);
    func_002AF6A8(&D_005E7510, 2, 0);
    for (layer = IDBASE_LAYER_MAX; layer >= -IDBASE_LAYER_MAX; layer--) {
        for (i = 0; i < self->entNum; i++) {
            int m29 = IDENT_FLAG_HIDDEN;
            int one = 1;
            long m27 = IDENT_FLAG_NO_DRAW;
            cIDBaseEnt *ent = &self->ent[i];
            unsigned long flags;
            if (ent == 0) continue;
            if (ent->layer != layer) continue;
            flags = (int)ent->flags;
            if (ent->flags & m29) continue;
            if (ent->parentRef >= 0) {
                int hidden = 0;
                cIDBaseEnt *p;
                for (p = ent->parent; p != 0; p = p->parent) {
                    unsigned long w = (int)p->flags;
                    long b = (w >> 3) & 1;
                    if (b != 0) {
                        if (w & IDENT_FLAG_NO_DRAW) hidden = 1;
                    }
                }
                if (hidden == one) continue;
            }
            if (flags & m27) continue;
            switch (ent->kind) {
            case IDENT_KIND_SPRITE:
                cIDBase_transSprite(self, (cIDBaseDraw *)draw, ent);
                break;
            case IDENT_KIND_TEXT:
                cIDBase_transText(self, ent);
                break;
            case IDENT_KIND_ICON:
                cIDBase_transIcon(self, ent);
                break;
            case IDENT_KIND_PANEL:
                cIDBase_transPanel(self, ent);
                break;
            default:
                cIDBase_transTex(self, (cIDBaseDraw *)draw, ent);
                break;
            }
        }
    }
}
