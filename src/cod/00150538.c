/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/effectPos.h"
#include "godhand/vu0.h"
#include "godhand/cOmSized.h"

extern void func_003A52F0(void *dst, int val, int len);
extern void Esp_killByGroup(int a0);
extern void func_00300C00(int a0, int a1);
extern void cHeap_free(void *heap, void *p);
extern void BlockOwner_dtor(void *self, int flags);
extern char D_0044F7D0[];
extern void func_001B6FB8(cOmSized *self);
extern void cOmDoor_setObjCollisionCenterOnly(cOmSized *self);
extern void SetFlagBit_1BD698(cOmSized *self);
extern void func_001BDD88(cOmSized *self, float f);

#define POOLENT_SIZE  0x220     /* sizeof one pool entry */

typedef struct EntPool {
    char unk00[0x1C];
    unsigned int used;                  /* 0x1C entries in use */
    char unk20[4];
    unsigned int usedMin;               /* 0x24 lowest value of used seen so far */
} EntPool;





/* Take an entry from the pool, count it, clear it and run its initialiser. Returns 0 when the pool is empty. */
__attribute__((section(".text.EntPool_allocClearSmall")))
void *EntPool_allocClearSmall(EntPool *self)
{
    int ent = func_002A97A0(self);
    unsigned int n;

    if (ent == 0) {
        return 0;
    }
    n = self->used - 1;
    self->used = n;
    if (n < self->usedMin) {
        self->usedMin = n;
    }
    func_003A52F0((void *)ent, 0, POOLENT_SIZE);
    return func_0014FF80((void *)ent);
}

/* A cOmBase-derived object with an effect handle at 0x5EC. */
typedef struct cOmEffectHolderB {
    char unk000[0x214];
    cVtEnt *vtable;                     /* 0x214 */
    char unk218[0x5EC - 0x218];
    int effect;                         /* 0x5EC */
} cOmEffectHolderB;

/* Moves the held effect to the position the object reports through virtual method 16. */
__attribute__((section(".text.cOmEffectHolderB_syncEffectPos")))
void cOmEffectHolderB_syncEffectPos(cOmEffectHolderB *self) {
    cVec pos;
    cVec *src;

    VU0_SQC2_VF0(&pos, 0);
    src = ((cVec *(*)(void *))self->vtable[16].pfn)((char *)self + self->vtable[16].delta);
    cVec_copy3(&pos, src);
    if (self->effect != 0) {
        SetEffectPos(0, self->effect, 0, &pos, 1.0f, -1);
    }
}

/* Remove an effect from one or both of its lists: mode 0 the second list, 1 the first, 2 both. */
__attribute__((section(".text.Effect_killByModeB")))
void Effect_killByModeB(int a0, int a1) {
    switch (a1) {
    case 0:
        func_00300C00(a0, 1);
        break;
    case 1:
        Esp_killByGroup(a0);
        break;
    case 2:
        Esp_killByGroup(a0);
        func_00300C00(a0, 1);
        break;
    }
}

/* An object with a method table at 0xF0 that owns five heap buffers. */
typedef struct BufOwner2 {
    char unk000[0xF0];
    void *vt;                           /* 0xF0 */
    char unkF4[0x26C];
    void *buf360;                       /* 0x360 */
    void *buf364;                       /* 0x364 */
    void *buf368;                       /* 0x368 */
    void *buf36C;                       /* 0x36C */
    void *buf370;                       /* 0x370 */
} BufOwner2;

#define FREE_BUF(p) if ((p) != 0) cHeap_free(*(void **)((char *)(p) - 0x20), (p))

/* Deleting destructor: reset the vtable, free the five buffers held at 0x364,
 * 0x368, 0x36C, 0x370 and 0x360, then run the base destructor. */
__attribute__((section(".text.BufOwner2_deletingDtor")))
void BufOwner2_deletingDtor(BufOwner2 *self, int flags) {
    self->vt = D_0044F7D0;
    FREE_BUF(self->buf364);
    FREE_BUF(self->buf368);
    FREE_BUF(self->buf36C);
    FREE_BUF(self->buf370);
    FREE_BUF(self->buf360);
    BlockOwner_dtor(self, flags);
}

/* Init: base setup, extent 4.0 x 4.1 x 0.2, then the shared setters and the 4.2 effect; returns 1. */
__attribute__((section(".text.cOmSized_startC")))
int cOmSized_startC(cOmSized *self)
{
    cVec ext;

    func_001B6FB8(self);
    ext.x = 4.0f;
    ext.y = 4.1f;
    ext.z = 0.2f;
    ext.w = 1.0f;
    cVec_copy3(&self->extent, &ext);
    cOmDoor_setObjCollisionCenterOnly(self);
    SetFlagBit_1BD698(self);
    func_001BDD88(self, 4.2f);
    return 1;
}

/* Init: base setup, extent 4.22 x 3.812 x 0.2, then the shared setters; returns 1. */
__attribute__((section(".text.cOmSized_startB")))
int cOmSized_startB(cOmSized *self) {
    cVec ext;

    func_001B6FB8(self);
    ext.x = 4.22f;
    ext.y = 3.812f;
    ext.z = 0.2f;
    ext.w = 1.0f;
    cVec_copy3(&self->extent, &ext);
    cOmDoor_setObjCollisionCenterOnly(self);
    SetFlagBit_1BD698(self);
    func_001BDD88(self, 4.0f);
    COMSIZED_SCRFLAGS(self) |= COMSIZED_SCR_READY;
    return 1;
}
