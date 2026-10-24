/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"
#include "godhand/vu0.h"
#include "godhand/heapArena.h"
#include "godhand/heapList.h"

extern int cDamageUnit_SetDamageCollActive(void *unit, int on);
extern cMeshNode *cModel_getMeshPtr(void *model, int idx);
extern void *cSnd_GetSeData(cSnd *self, int i);
extern cBgmData *cSnd_GetBgmData(cSnd *self, int i);
extern void cSeData_Update(void *se);
extern void cBgmData_UpdateLoad(cBgmData *bgm);
extern void SetEffectPos(int kind, int effNo, int a2, void *pos, int a4, float scale);
extern void func_002FBED0(void *self);
extern void BufHolder_deletingDtor(int entry, int mode);
extern void cHeap_free(int heap, int *node);
extern void *EnsureInitThenForward_2A9538_30EE08(int a0, int a1, int a2);
extern void func_001DBF18(void *self, unsigned short *a, unsigned short *b, unsigned short *c, unsigned short *d);

#define MESH_DISP_HIDE      0x0001      /* node is not drawn */
#define MESH_DISP_TAGGED    0x2000
#define OBJ_FLAG_NO_DAMAGE  0x10000     /* objFlags bit 16 */

/* An object whose damage unit sits at 0x600, past cOmBase. */
typedef struct DamageObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damageUnit;                   /* 0x600 */
} DamageObj;

/* Switch the object's damage volumes off and hide its first mesh node. */
__attribute__((section(".text.DamageObj_disableDamage")))
void DamageObj_disableDamage(DamageObj *self)
{
    if (self->damageUnit != 0) {
        cDamageUnit_SetDamageCollActive(self->damageUnit, 0);
    }
    cModel_getMeshPtr(self, 0)->dispFlags |= MESH_DISP_HIDE;
    cModel_getMeshPtr(self, 0)->dispFlags |= MESH_DISP_TAGGED;
    self->base.objFlags |= OBJ_FLAG_NO_DAMAGE;
}

#define CSND_BGM_DATA_NUM  2     /* BGM data slots, not named in cSnd.h */

/* Per-frame load update of every sound-effect slot and every BGM data slot. */
__attribute__((section(".text.cSnd_updateLoads")))
void cSnd_updateLoads(cSnd *self)
{
    int i;
    for (i = 0; i < CSND_SE_ENTRY_NUM; i++)
        cSeData_Update(cSnd_GetSeData(self, i));
    for (i = 0; i < CSND_BGM_DATA_NUM; i++)
        cBgmData_UpdateLoad(cSnd_GetBgmData(self, i));
}

/* Virtual method at 0x80/0x84 of the method table that returns the object's position vector. */
typedef float *(*GetPosFn)(void *);

#define VT_GETPOS_DELTA  0x80   /* this adjustment of the position method */
#define VT_GETPOS_FN     0x84   /* the position method */

typedef struct EffObj {
    char unk000[0x214];
    char *vt;                           /* 0x214 method table */
    char unk218[0x3D4];
    int effNo;                          /* 0x5EC effect number */
} EffObj;

/* Start effect kind 1 at the object's position. */
__attribute__((section(".text.EffObj_startEffectAtPos")))
void EffObj_startEffectAtPos(EffObj *self)
{
    float pos[4] __attribute__((aligned(16)));
    float *p;
    VU0_SQC2_VF0(pos, 0);
    p = (*(GetPosFn *)(self->vt + VT_GETPOS_FN))((char *)self + *(short *)(self->vt + VT_GETPOS_DELTA));
    if (pos != p) {
        pos[0] = p[0];
        pos[1] = p[1];
        pos[2] = p[2];
    }
    SetEffectPos(1, self->effNo, 0, pos, -1, 1.0f);
}

typedef struct ScrollObj {
    char unk000[0x2D8];
    float scroll;                       /* 0x2D8 scroll position, wrapped into 0..1 */
    float speed;                        /* 0x2DC scroll step per call */
} ScrollObj;

/* Run the base update, then advance the scroll position by its speed and wrap it into 0..1. */
__attribute__((section(".text.ScrollObj_advanceScroll")))
void ScrollObj_advanceScroll(ScrollObj *self)
{
    float speed;
    func_002FBED0(self);
    speed = self->speed;
    if (speed != 0.0f) {
        self->scroll += speed;
        if (self->scroll > 1.0f) {
            self->scroll -= 1.0f;
        }
        if (self->scroll < 0.0f) {
            self->scroll += 1.0f;
        }
    }
}

#define ENTLIST_ENTRY_SIZE  0x480
#define ENTLIST_ALIGN       0x80

/* Release every entry of the list in order, then reset the list and free its heap block. */
__attribute__((section(".text.EntList_destroy")))
void EntList_destroy(HeapList *self)
{
    int cur = func_002A9860((int)self, 0);
    int *block;

    while (cur != 0) {
        int next = func_002A9860((int)self, cur);
        BufHolder_deletingDtor(cur, 2);
        cur = next;
    }
    block = self->block;
    func_002A9790(self);
    if (block != 0) {
        cHeap_free(block[-8], block);
    }
}

/* Empty the list, then give it a fresh heap block for `num` entries. */
__attribute__((section(".text.func_00149400")))
void func_00149400(HeapList *self, int num)
{
    int size;

    EntList_destroy(self);
    size = func_002A96C0(ENTLIST_ENTRY_SIZE, num, ENTLIST_ALIGN);
    func_002A96D8((int *)self, (int)EnsureInitThenForward_2A9538_30EE08(size, ENTLIST_ALIGN, (int)D_003C3CF0),
                  ENTLIST_ENTRY_SIZE, num, ENTLIST_ALIGN);
    self->unk18 = num;
    self->unk1C = num;
    self->capacity = num;
    self->size = size;
}

#define PART_NUM         5          /* parts held in the table */
#define PART_KIND_FOUND  5          /* kind value the check looks for */
#define PART_FLAG_MARK   0x4

typedef struct Part {
    int unk00;
    unsigned int flags;                 /* 0x04 */
} Part;

typedef struct PartHolder {
    char unk0000[0x3004];
    Part *part[PART_NUM];               /* 0x3004 */
} PartHolder;

/* Mark every part when any of the four kinds the lookup returns is PART_KIND_FOUND. Returns 1 when it marked them. */
__attribute__((section(".text.PartHolder_markIfFound")))
int PartHolder_markIfFound(PartHolder *self)
{
    unsigned short kind[4];
    Part **p;
    int i;

    func_001DBF18(self, &kind[0], &kind[1], &kind[2], &kind[3]);
    if (kind[0] == PART_KIND_FOUND || kind[1] == PART_KIND_FOUND ||
        kind[2] == PART_KIND_FOUND || kind[3] == PART_KIND_FOUND) {
        p = self->part;
        for (i = PART_NUM - 1; i >= 0; i--) {
            (*p++)->flags |= PART_FLAG_MARK;
        }
        return 1;
    }
    return 0;
}
