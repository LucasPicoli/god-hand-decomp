/* sn-2.95.3-136 matched TU. */

#include "godhand/cFont.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cMessCommon.h"
#include "godhand/cModel.h"
#include "godhand/vu0.h"
#include "godhand/cEmManage.h"
#include "godhand/globals.h"

extern void *SearchData(void *pack, void *name, int id);
extern void cFont_setTextureAddr(cFont *self, int slot, void *tex0, void *tex1);
extern int cEm00_ckDown(cGameObj *em);
extern void func_002B4428(void *win, int a1, int a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);

/* The part of the game state block D_007474A0 that names the resource pack. */
typedef struct GameStatePack {
    char unk000[0x56C];
    int resId;                          /* 0x56C */
    char unk570[0x5AC - 0x570];
    void *pack;                         /* 0x5AC resource pack the font textures come from */
} GameStatePack;

extern GameStatePack D_007474A0;





/* Looks up the two textures of the current resource in the pack and installs them in slot 2. */
__attribute__((section(".text.cFont_setMessageTextures")))
void cFont_setMessageTextures(cFont *self) {
    void *tex0 = SearchData(D_007474A0.pack, D_0044ACE0, D_007474A0.resId);
    void *tex1 = SearchData(D_007474A0.pack, D_0044ACE8, D_007474A0.resId);
    cFont_setTextureAddr(self, 2, tex0, tex1);
}

/* Whether the target is a knocked-down enemy: actor id in 0x200..0x2FF but not in the 0x2A0..0x2FF band. */
__attribute__((section(".text.cGameObj_isDownedEnemy")))
int cGameObj_isDownedEnemy(cGameObj *self, cGameObj *target) {
    if (cGameObj_idInRange(target, 0x200, 0x300) & 0xFF) {
        if (!(cGameObj_idInRange(target, 0x2A0, 0x300) & 0xFF)) {
            return cEm00_ckDown(target) != 0;
        }
    }
    return 0;
}

/* One link of a trail: its current point, the point one step back, and the object that owns the next step. */
typedef struct TrailLink TrailLink;

typedef struct TrailSource {
    char unk00[0x34];
    struct { char unk00[0xC0]; cVec *pos; } *model;   /* 0x34 */
} TrailSource;

struct TrailLink {
    cVec cur;                           /* 0x00 */
    cVec prev;                          /* 0x10 */
    char unk20[4];
    TrailLink *next;                    /* 0x24 */
    TrailSource *source;                /* 0x28 */
};

typedef struct Trail {
    char unk00[0x34];
    int shift;                          /* 0x34 */
    char unk38[4];
    TrailLink *head;                    /* 0x3C */
} Trail;

/* Pulls every link onto its source's position and keeps the old point in prev. */
__attribute__((section(".text.Trail_snapToSources")))
void Trail_snapToSources(Trail *self) {
    TrailLink *link = self->head;
    self->shift = 0;
    while (link != 0) {
        cVec_copy3(&link->cur, link->source->model->pos);
        cVec_copy3(&link->prev, &link->cur);
        link = link->next;
    }
}

/* Window text word at 0x8C of the message window. */
typedef struct MessWin {
    char unk00[0x8C];
    int text;                           /* 0x8C message stream */
} MessWin;

/* Looks for one of the page-end control codes D2, D9 or DA in the text; if none is there, runs the default close. */
__attribute__((section(".text.MessWin_closeIfNoEndCode")))
void MessWin_closeIfNoEndCode(MessWin *win) {
    if (func_002B45F8(win, win->text, MESS_END_D2) != 0) return;
    if (func_002B45F8(win, win->text, MESS_END_D9) != 0) return;
    if (func_002B45F8(win, win->text, MESS_END_DA) != 0) return;
    func_002B4428(win, 0, 0);
}

/* A cOmBase-derived object with an effect handle at 0x5E4. */
typedef struct cOmEffectHolder {
    char unk000[0x214];
    cVtEnt *vtable;                     /* 0x214 */
    char unk218[0x5E4 - 0x218];
    int effect;                         /* 0x5E4 */
} cOmEffectHolder;



/* Moves the held effect to the position the object reports through virtual method 16. */
__attribute__((section(".text.cOmEffectHolder_syncEffectPos")))
void cOmEffectHolder_syncEffectPos(cOmEffectHolder *self) {
    cVec pos;
    cVec *src;

    VU0_SQC2_VF0(&pos, 0);
    src = ((cVec *(*)(void *))self->vtable[16].pfn)((char *)self + self->vtable[16].delta);
    cVec_copy3(&pos, src);
    if (self->effect != 0) {
        SetEffectPos(0, self->effect, 0, &pos, -1, 1.0f);
    }
}

/* Whether the actor id of em lies in [lo, hi), as a long flag (the shape cGameObj_idInRange uses). */
static __inline__ long cEmActor_idInRange(const cEmActor *em, int lo, int hi)
{
    int id = em->actorId;
    long in = 0;

    if (id >= lo) {
        int below = id < hi;

        in = below;
    }
    return in;
}

/* Calls the suspend method of every listed enemy whose actor id is 0x200..0x2FF, passing flag. */
__attribute__((section(".text.cEmManage_suspendRange")))
void cEmManage_suspendRange(cEmManage *self, int flag) {
    cEmSlot *slot = self->list.top;
    while (slot != 0) {
        cEmActor *em = slot->em;
        if (em != 0) {
            if (cEmActor_idInRange(em, 0x200, 0x300) & 0xFF) {
                em->vt->suspend((char *)em + em->vt->suspendDelta, flag);
            }
        }
        slot = slot->next;
    }
}
