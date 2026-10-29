/* sn-2.95.3-136 matched TU. */

#include "godhand/cDvd.h"
#include "godhand/CustomIDWork.h"
#include "godhand/cOmBase.h"
#include "godhand/cObj.h"
#include "godhand/vu0.h"

extern void cDvd_pollJob(cDvd *self);
extern void func_00201250(cDvd *self);
extern void cHeap_free(void *heap, void *p);
extern void BlockOwner_dtor(void *self, int flags);
extern int D_0044F448;
extern CustomIDObj *cIDBase_getIDWork(void *idBase, int idx);
extern int func_001717C0(cOmBase *self, void *target, cVec *pos);
extern void *InitFields_1B6E90(void *self);
extern int D_00429B88;
extern int D_004298B0;
extern int D_00428B58;
extern char D_005FEE00[];
extern void KillEffect(void *obj, int a, int b);
extern void cSnd_SeStop(void *snd, int handle);
extern void SetField214PtrThenInit_1B6F38(void *obj, int flag);

/* Run one step of the disc queue: start the next job, poll the running one, or idle, by the state at +0x1108. */
__attribute__((section(".text.cDvd_step")))
void cDvd_step(cDvd *self) {
    switch ((unsigned int)self->queueNum) {
    case 1:
        func_00201290(self);
        break;
    case 2:
        cDvd_pollJob(self);
        break;
    case 0:
    default:
        func_00201250(self);
        break;
    }
}

/* An object with a method table at 0xF0 and a heap block at 0x2F0. */
typedef struct HeapOwner {
    char unk000[0xF0];
    void *vt;                           /* 0xF0 */
    char unkF4[0x1FC];
    char *buf;                          /* 0x2F0 */
} HeapOwner;

/* Destructor: install the method table, free the block (its heap is stored just before it) and run the base destructor. */
__attribute__((section(".text.cHeapOwner_deletingDtor")))
void cHeapOwner_deletingDtor(HeapOwner *self, int flags) {
    char *buf;
    self->vt = &D_0044F448;
    buf = self->buf;
    if (buf != 0) {
        cHeap_free(*(void **)(buf - 0x20), buf);
    }
    BlockOwner_dtor(self, flags);
}

#define IDWORK_HIGHLIGHT  10            /* index of the id work whose hide bit follows the mode byte */

/* An ID screen: a mode byte at 1 and the id base at 0x30. */
typedef struct IdModeScreen {
    char unk00;
    unsigned char mode;                 /* 0x01 */
    char unk02[0x2E];
    char idBase[1];                     /* 0x30 */
} IdModeScreen;

/* Hide the highlight element when the mode is 2, else show it. */
__attribute__((section(".text.CustomID_toggleBit29")))
void CustomID_toggleBit29(IdModeScreen *self) {
    if (self->mode == 2) {
        CustomIDObj *obj = cIDBase_getIDWork(self->idBase, IDWORK_HIGHLIGHT);
        obj->flags &= ~CIDW_OBJ_HIDE;
    } else {
        CustomIDObj *obj = cIDBase_getIDWork(self->idBase, IDWORK_HIGHLIGHT);
        obj->flags |= CIDW_OBJ_HIDE;
    }
}

/* Copy the vector vec into the aim point posA (0x490) and from there into the object's live position, then run func_001717C0. */
__attribute__((section(".text.cEm_copyPosAndRefresh")))
int cEm_copyPosAndRefresh(cOmBase *self, cVec *vec) {
    cVec *src = &self->posA;
    cVec *dst;
    if (src != vec) {
        src->x = vec->x;
        src->y = vec->y;
        src->z = vec->z;
    }
    dst = self->pos;
    if (dst != src) {
        dst->x = self->posA.x;
        dst->y = src->y;
        dst->z = src->z;
    }
    return func_001717C0(self, self->pos, &self->rot);
}

/* An actor with VU0 quadwords at 0x610, 0x640 and 0x650, a second table pointer at 0x4AC and a small state block at 0x662..0x680. */
typedef struct VuFxObj2 {
    COBJ_FIELDS
    char unk310[0x19C];
    void *table2;                       /* 0x4AC */
    char unk4B0[0x160];
    cVec vecA;                          /* 0x610 */
    char unk620[0x20];
    cVec vecC;                          /* 0x640 */
    cVec vecD;                          /* 0x650 */
    char unk660[2];
    short angle;                        /* 0x662 */
    char unk664[4];
    long pair;                          /* 0x668 */
    char unk670[6];
    char flag676;                       /* 0x676 */
    char flag677;                       /* 0x677 */
    char unk678[8];
    int word680;                        /* 0x680 */
} VuFxObj2;

#define VUFX_OFFSET(field)  ((int)&((VuFxObj2 *)0)->field)

/* Init the base fields, set the tables at 0x214 and 0x4AC, clear three quadwords and the state block. Returns self. */
__attribute__((section(".text.cObj_initVuFields4AC")))
VuFxObj2 *cObj_initVuFields4AC(VuFxObj2 *self) {
    InitFields_1B6E90(self);
    self->vtable = (void *)&D_00429B88;
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecA));
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecC));
    VU0_SQC2_VF0(self, VUFX_OFFSET(vecD));
    self->table2 = &D_004298B0;
    self->flag677 = 0;
    self->angle = 0;
    self->flag676 = 0;
    self->pair = 0;
    self->word680 = 0;
    return self;
}

/* An actor that owns one sound handle at 0x608 past cObj. */
typedef struct SeOwnerObj {
    COBJ_FIELDS
    char unk310[0x2F8];
    int seHandle;                       /* 0x608 */
} SeOwnerObj;

/* Destructor: install the class table, kill the effect, stop the sound handle, run the base destructor. */
__attribute__((section(".text.cGiveOwner_destructB")))
void cGiveOwner_destructB(SeOwnerObj *self, int flag) {
    self->vtable = (void *)&D_00428B58;
    KillEffect(self, 0, 2);
    if (self->seHandle != 0) {
        cSnd_SeStop(D_005FEE00, self->seHandle);
    }
    self->seHandle = 0;
    SetField214PtrThenInit_1B6F38(self, flag);
}
