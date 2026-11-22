/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/player.h"

extern void cHeap_free(void *heap, void *p);
extern void __builtin_delete(void *p);
extern char D_0044E538[];
extern void func_002FBE28(void *self, int flags);
extern char D_0044A528[];
extern char D_007419A0[];
extern void func_002A84A8(void *);
extern void espSys_effDataRelease(void *, int);
extern void cSnd_SeStop(void *, int);
extern void NoOp_28E418(void *);
extern void func_0028EB88(void *, int);
extern char D_00580D20[];
extern void cDataManager_addPinnedData(void *mgr, int id, void *data);
extern void sceVu0ApplyMatrix(void *dst, void *mtx, void *v);

/* Tick down the button's countdown (0x32) while its state (0x36) is 1;
 * when the countdown is spent, call cActionButtonEnt_reset. */
typedef struct TimedButton {
    char unk00[0x32];
    short timer;                        /* 0x32 frames left */
    char unk34[2];
    unsigned char state;                /* 0x36 */
} TimedButton;

#define BUTTON_STATE_COUNTING  1

extern void cActionButtonEnt_reset(TimedButton *self);

__attribute__((section(".text.TimedButton_tick")))
void TimedButton_tick(TimedButton *self) {
    if (self->state == BUTTON_STATE_COUNTING) {
        if (self->timer <= 0) {
            cActionButtonEnt_reset(self);
        } else {
            self->timer = (unsigned short)self->timer - 1;
        }
    }
}

/* Deleting destructor: free the block held at +0x408, then free the object
 * itself when the delete flag (bit 0) is set. */
typedef struct BufHolder {
    char unk000[0x408];
    char *buf;                          /* 0x408 heap block, 0 when none */
} BufHolder;

#define HEAP_OF_BLOCK(p)  (*(void **)((p) - 0x20))     /* the heap a block came from sits in front of it */
#define DELETE_SELF       0x1




__attribute__((section(".text.BufHolder_deletingDtor")))
void BufHolder_deletingDtor(BufHolder *self, int flags) {
    char *buf = self->buf;
    if (buf != 0)
        cHeap_free(HEAP_OF_BLOCK(buf), buf);
    if ((flags & DELETE_SELF) != 0)
        __builtin_delete(self);
}

/* Destructor of the object with vtable D_0044E538: reset the vtable, release
 * the owned object at +0x2B0 if any, then run the base destructor. */
typedef struct OwnerObj {
    char unk000[0xF0];
    void *vt;                           /* 0xF0 */
    char unkF4[0x1BC];
    void *owned;                        /* 0x2B0 */
} OwnerObj;





__attribute__((section(".text.OwnerObj_destroyOwned")))
void OwnerObj_destroyOwned(OwnerObj *self, int flags) {
    self->vt = D_0044E538;
    if (self->owned != 0)
        ReleaseObj(self->owned);
    func_002FBE28(self, flags);
}

/* Tear down an effect object: restore its vtable, release the effect data,
 * stop the sound handle at 0x1550 if one is set, then run the no-op hook and
 * the base teardown. */
typedef struct EffObj {
    char unk000[0x214];
    void *vt;                           /* 0x214 */
    char unk218[0x1338];
    int seHandle;                       /* 0x1550 */
} EffObj;

#define EFFDATA_SLOT  0xD7










__attribute__((section(".text.EffObj_teardown")))
void EffObj_teardown(EffObj *self, int flag) {
    self->vt = D_0044A528;
    func_002A84A8(self);
    espSys_effDataRelease(D_007419A0, EFFDATA_SLOT);
    if (self->seHandle != 0)
        cSnd_SeStop(&D_005FEE00, self->seHandle);
    NoOp_28E418(self);
    func_0028EB88(self, flag);
}

/* Spawn the effect object 0x3BF at the owner: pin the data block (the record
 * at the owner's data pointer 0x304 plus its length at 0x310), create the
 * object, call its initial method, put it 3 units above and 0.3
 * behind the owner in the owner's frame (0x80), copy the owner's angles
 * (0x100) and set the spin to -5 degrees. */



typedef struct DataRef {
    char unk000[0x310];
    int length;                         /* 0x310 */
} DataRef;

typedef struct Owner {
    char unk000[0x80];
    float mtx[16];                      /* 0x80 */
    char unkC0[0x40];
    cVec rot;                           /* 0x100 */
    char unk110[0x1F4];
    DataRef *data;                      /* 0x304 */
} Owner;

#define FX_ID          0x3BF
#define FX_OFFSET_Y    3.0f
#define FX_OFFSET_Z    (-0.3f)
#define FX_SPIN        (-0.17453292f)



#define FRAME ((char *)&off - 0x0)

__attribute__((section(".text.Owner_spawnEffect")))
void Owner_spawnEffect(Owner *self)
{
    cVec off;                           /* sp+0x00 */
    cVec w;                             /* sp+0x10 */
    cVec u;                             /* sp+0x20 */
    cGameObj *fx;
    float spin;
    cVec *up;
    float *mtx;
    cDataManager_addPinnedData(D_00580D20, FX_ID, (void *)(self->data->length + (int)self->data));
    fx = CreateObj(FX_ID, 0xFFFF);
    if (fx != 0) {
        VU0_SQC2_VF0(FRAME, 0x0);
        off.x = 0.0f;
        off.y = FX_OFFSET_Y;
        off.z = FX_OFFSET_Z;
        {
            cGameObjVt *vt = cGameObj_vt(fx);
            vt->initial((char *)fx + vt->initialDelta);
        }
        mtx = self->mtx;
        up = &u;
        VU0_LQC2(4, &off, 0);
        VU0_SQC2(4, FRAME, 0x20);
        sceVu0ApplyMatrix(up, mtx, up);
        VU0_LQC2(4, &u, 0);
        VU0_SQC2(4, FRAME, 0x10);
        cVec_copy3(fx->pos, &w);
        cVec_copy3(&fx->rot, &self->rot);
        spin = FX_SPIN;
        fx->rot.x = spin;
        fx->rot.z = spin;
    }
}

/* Step the selection of a 4-slot list back: pick the nearest filled slot below
 * the current index; if none, the highest filled slot above it. */
#define SLOT_MAX 3

typedef struct SlotList {
    char unk00[0xC];
    int cur;                            /* 0x0C current index */
    void *slot[4];                      /* 0x10 */
} SlotList;

__attribute__((section(".text.SlotList_selectPrev")))
void SlotList_selectPrev(SlotList *self) {
    int i = self->cur - 1;
    int j;
    for (; i >= 0; i--) {
        if (self->slot[i] != 0) {
            self->cur = i;
            return;
        }
    }
    for (j = SLOT_MAX; j > self->cur; j--) {
        if (self->slot[j] != 0) {
            self->cur = j;
            return;
        }
    }
}
