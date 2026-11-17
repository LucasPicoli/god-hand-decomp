/* sn-2.95.3-136 matched TU. */

#include "godhand/cDoor.h"
#include "godhand/cOmHitVolume.h"
#include "godhand/cDataManager.h"
#include "godhand/cSnd.h"

extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void func_001FD9D8(void *unit, void *pos, float *m, float *nv, float *t);
extern void cHeap_free(int heap, int *node);
extern cSnd D_005FEE00;
extern void cSnd_CheckSeEnd(cSnd *snd, int handle);

/* The jump table: groups of 0x30-byte records, found through a header at the table address. */
typedef struct RecGroup {
    char unk00[2];
    unsigned char count;                /* 0x02 records in the group */
    unsigned char first;                /* 0x03 index of the group's first record */
} RecGroup;

typedef struct RecTable {
    char unk00[8];
    int recOfs;                         /* 0x08 byte offset of the record array */
} RecTable;

#define REC_SIZE 0x30



/* Returns record `n` of `group`, or 0 if the group is missing or has fewer records. */
__attribute__((section(".text.cRoomJump_getRecord")))
void *cRoomJump_getRecord(cRoomJump *self, unsigned short group, unsigned char n)
{
    RecGroup *grp = func_002BEAA8(self, group);
    char *rec = 0;
    if (grp != 0 && n < grp->count) {
        char *tbl = (char *)self->tbl;
        rec = tbl + ((RecTable *)tbl)->recOfs;
        rec += (grp->first + n) * REC_SIZE;
    }
    return rec;
}

extern int D_00574380;                  /* damage manager */





/* Volume size, also the extents of the unused box vector. */
#define VOL_SIZE_X  0.8f
#define VOL_SIZE_Y  1.7f
#define VOL_SIZE_Z  0.8f

/* Set the object up: a damage-take unit with a 0.8 x 1.7 x 0.8 volume at its position, one hit point, a four entry table at 0x620 and the state words cleared; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox08x17x08")))
int cOmHitVolume_setupBox08x17x08(cOmHitVolume *self)
{
    float box[4];
    float size[4];
    float origin[4];
    float origin2[4];
    float *m;                           /* origin, addressed through a register as retail does */
    float *nv;                          /* origin2 */
    float *t;                           /* size */
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = VOL_SIZE_X;
    cb = VOL_SIZE_Y;
    cc = VOL_SIZE_Z;
    t = &size[0];
    m = &origin[0];
    box[0] = ca;
    box[1] = cb;
    box[2] = cc;
    box[3] = one;
    size[0] = ca;
    size[2] = cc;
    size[1] = cb;
    t[3] = one;
    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2[0];
        origin2[0] = 0.0f;
        origin2[1] = 0.0f;
        origin2[2] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 4;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}

extern int D_00574380;                  /* damage manager */





/* Volume size, also the extents of the unused box vector. */
#define VOL_SIZE_X  1.5f
#define VOL_SIZE_Y  1.1f
#define VOL_SIZE_Z  1.2f

/* Set the object up: a damage-take unit with a 1.5 x 1.1 x 1.2 volume at its position, one hit point, a six entry table at 0x620 and the state words cleared; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox15x11x12")))
int cOmHitVolume_setupBox15x11x12(cOmHitVolume *self)
{
    float box[4];
    float size[4];
    float origin[4];
    float origin2[4];
    float *m;                           /* origin, addressed through a register as retail does */
    float *nv;                          /* origin2 */
    float *t;                           /* size */
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = VOL_SIZE_X;
    cb = VOL_SIZE_Y;
    cc = VOL_SIZE_Z;
    t = &size[0];
    m = &origin[0];
    box[0] = ca;
    box[1] = cb;
    box[2] = cc;
    box[3] = one;
    size[0] = ca;
    size[1] = cb;
    size[2] = cc;
    t[3] = one;
    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2[0];
        origin2[0] = 0.0f;
        origin2[1] = 0.0f;
        origin2[2] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 6;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}

extern int D_00574380;                  /* damage manager */





/* Volume size, also the extents of the unused box vector. */
#define VOL_SIZE_X  1.3f
#define VOL_SIZE_Y  1.9f
#define VOL_SIZE_Z  0.8f

/* Set the object up: a damage-take unit with its volume at its position, one hit point, a table at 0x620 and the state words cleared; returns 1. */
__attribute__((section(".text.cOmHitVolume_setupBox13x19x08")))
int cOmHitVolume_setupBox13x19x08(cOmHitVolume *self)
{
    float box[4];
    float size[4];
    float origin[4];
    float origin2[4];
    float *m;                           /* origin, addressed through a register as retail does */
    float *nv;                          /* origin2 */
    float *t;                           /* size */
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = VOL_SIZE_X;
    cb = VOL_SIZE_Y;
    cc = VOL_SIZE_Z;
    t = &size[0];
    m = &origin[0];
    box[0] = ca;
    box[1] = cb;
    box[2] = cc;
    box[3] = one;
    size[0] = ca;
    size[1] = cb;
    size[2] = cc;
    t[3] = one;
    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &origin2[0];
        origin2[0] = 0.0f;
        origin2[1] = 0.0f;
        origin2[2] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 5;
    self->unk5EC = 7;
    self->unk5E8 = 0;
    self->unk5F4 = -1;
    self->unk5E4 = 0;
    self->unk5F0 = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}

#define SLOT_SE_NUM         10
#define SLOT_SE_NONE        (-1)

/* cDataSlot with the fields this reset uses spelled out (the header keeps 0x0C, 0x18, 0x1C and 0x24 as padding;
 * the names are in cDataSlot_fields.h for the orchestrator to merge). Same 0x5C bytes, same offsets. */
typedef struct cDataSlotSe {
    int state;                          /* 0x00 */
    int useCount;                       /* 0x04 */
    int flags;                          /* 0x08 */
    int unk0C;                          /* 0x0C set to -1 on reset */
    int *data;                          /* 0x10 heap node, 0 when none */
    char unk14[4];
    int unk18;                          /* 0x18 */
    int unk1C;                          /* 0x1C */
    int kind;                           /* 0x20 */
    int seHandle[SLOT_SE_NUM];          /* 0x24 sound-effect handles */
    char unk4C[0x10];
} cDataSlotSe;
typedef char cDataSlotSe_size[sizeof(cDataSlotSe) == CDATA_SLOT_SIZE ? 1 : -1];

/* Resets the slot: frees its heap node, ends every sound effect it started and goes back to the idle state. */
__attribute__((section(".text.cDataSlot_resetSeHandles")))
void cDataSlot_resetSeHandles(cDataSlotSe *self)
{
    int i;
    self->useCount = 0;
    self->flags = 0;
    if (self->data != 0) {
        cHeap_free(self->data[-8], self->data);
    }
    self->data = 0;
    self->unk0C = -1;
    self->unk1C = 0;
    self->unk18 = 0;
    for (i = 0; i < SLOT_SE_NUM; i++) {
        cSnd_CheckSeEnd(&D_005FEE00, self->seHandle[i]);
        self->seHandle[i] = SLOT_SE_NONE;
    }
    self->state = SLOT_STATE_IDLE;
}
