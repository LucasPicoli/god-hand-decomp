/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/cOmHitVolume.h"

#include "godhand/objField.h"
extern void sceVu0ApplyMatrix(void *out, void *mtx, void *vec);
extern float LengthPositionToGivenLine(void *line, void *pos, void *dir, int *flag);
extern int D_00427CF0;
extern int D_00574380;
extern int D_005CAE50;
extern void ClearAndResetFields_1FE278(void *a, void *b);
extern void cDamageManage_ReleaseDamageGive(void *a, int b);
extern void func_0012EC58(void *a, int b);
extern void KillEffect(void *a0, int a1, int a2);
extern void SetField214PtrThenInit_1B6F38(void *a, void *b);
extern float D_00747B00[];
extern void cDamageUnit_SetDamageCollRadius(void *unit, int id, float radius);
extern void cDamageUnit_SetDamageCollActive(void *unit, int on);
extern void cDamageGive_SetDmgGiveHitVec(void *give, float *dir);
extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void cDamageUnit_AddDamageCollCylinder(void *unit, void *pos, float *a, float *b, float height, float radius);
extern void func_001FD9D8(void *unit, void *pos, float *a, float *b, float *size);

/* True when the distance from the line, taken from the matrix position along its turned offset vector, is at most k. */
__attribute__((section(".text.LengthFromLineAtTurnedOffset")))
int LengthFromLineAtTurnedOffset(void *line, void *mtx, void *offset, float k)
{
    char buf[0x40] __attribute__((aligned(16)));
    float *zp;
    int never;
    float *v;
    float *d;

    VU0_SQC2_VF0(buf, 0x0);
    VU0_LQC2(4, offset, 0x0);
    VU0_SQC2(4, buf, 0x10);
    ForwardVec3At30_147C60(buf, mtx);
    /* The empty loop on a zero flag is a barrier: it keeps the stack addresses below from being hoisted above the call. */
    never = 0;
    do { } while (never);
    v = (float *)(buf + 0x10);
    d = (float *)(buf + 0x30);
    zp = (float *)(buf + 0x18);
    VU0_LQC2(4, v, 0x0);
    VU0_SQC2(4, buf, 0x30);
    sceVu0ApplyMatrix(d, mtx, d);
    VU0_LQC2(4, d, 0x0);
    VU0_SQC2(4, buf, 0x20);
    {
        float x = *(float *)(buf + 0x20);
        float y = *(float *)(buf + 0x24);
        float z = *(float *)(buf + 0x28);

        *(float *)(buf + 0x10) = x;
        *(float *)(buf + 0x14) = y;
        *zp = z;
    }
    return LengthPositionToGivenLine(line, buf, v, 0) <= k;
}

/* An object that owns a slot (0x604), a damage give (0x608) and three effect handles from 0x60C. */
typedef struct EffectOwner {
    char unk000[0x214];
    int *vt;                    /* 0x214 */
    char unk218[0x604 - 0x218];
    int slot;                   /* 0x604 */
    int damageGive;             /* 0x608 */
    int handle[3];              /* 0x60C */
} EffectOwner;

/* EffectOwner_destruct: destructor body. Set the method table, release the slot, the damage give and the three
 * handles, kill effects 3, 0xB and 0xA, then run the shared base teardown. */
__attribute__((section(".text.EffectOwner_destruct")))
void EffectOwner_destruct(EffectOwner *self, void *flag)
{
    int i;
    self->vt = &D_00427CF0;
    if (self->slot != 0) {
        ClearAndResetFields_1FE278(&D_00574380, (void *)self->slot);
        self->slot = 0;
    }
    if (self->damageGive != 0) {
        cDamageManage_ReleaseDamageGive(&D_00574380, self->damageGive);
        self->damageGive = 0;
    }
    for (i = 0; i < 3; i++) {
        if (self->handle[i] != 0) {
            func_0012EC58(&D_005CAE50, self->handle[i]);
        }
    }
    KillEffect(self, 3, 2);
    KillEffect(self, 0xB, 2);
    KillEffect(self, 0xA, 2);
    SetField214PtrThenInit_1B6F38(self, flag);
}

/* The attack volume record the enemy keeps at 0x680 (a cDamageUnit with its own tail fields). */
typedef struct AtkRec {
    char unk00[0x40];
    int unk40;          /* 0x40 set to -1 when the volume is armed */
    short unk44;        /* 0x44 cleared */
    short unk46;        /* 0x46 set to 0x49 */
    char unk48[4];
    int unk4C;          /* 0x4C cleared */
} AtkRec;
#define EM_ATK_REC(self)  (*(AtkRec **)((char *)(self) + 0x680))
#define EM_ATK_NEXT(self) (*(int *)((char *)(self) + 0x684))






/* cEm00_armAttackVolume: arm the enemy's attack volume: radius 3.0 for enemy 0x260 else 2.0, active, hit vector
 * D_00747B00, then reset its counters. */
__attribute__((section(".text.cEm00_armAttackVolume")))
void cEm00_armAttackVolume(cEm00 *self)
{
    float radius;
    volatile AtkRec *rec;  /* volatile keeps the epilogue restores below these stores */
    float *dir;
    if (self->emNo != 0x260) {
        EM_ATK_REC(self)->unk46 = 0x49;
        radius = 2.0f;
    } else {
        EM_ATK_REC(self)->unk46 = 0x49;
        radius = 3.0f;
    }
    cDamageUnit_SetDamageCollRadius(EM_ATK_REC(self), EM_ATK_NEXT(self), radius);
    EM_ATK_REC(self)->unk4C = 0;
    cDamageUnit_SetDamageCollActive(EM_ATK_REC(self), 1);
    dir = D_00747B00;
    cDamageGive_SetDmgGiveHitVec(EM_ATK_REC(self), dir);
    rec = EM_ATK_REC(self);
    rec->unk40 = -1;
    do { } while (0);
    rec->unk44 = 0;
}

extern int D_00574380;                  /* damage manager */

#define CYL_HEIGHT  4.0f
#define CYL_RADIUS  0.8f


/* Set up a hit-volume object: a damage-take unit with a cylinder at its matrix, a hit point of 1, cleared state words and an eight entry table. */
__attribute__((section(".text.cOmHitVolume_setupCylinder")))
int cOmHitVolume_setupCylinder(cOmHitVolume *self)
{
    float f[8];
    float *nv;
    void *slot;
    float one;

    func_001B6FB8(self);
    one = 1.0f;
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &f[4];
        f[4] = 0.0f;
        f[5] = 0.0f;
        f[6] = 0.0f;
        nv[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, self->base.mtx, f, nv, CYL_HEIGHT, CYL_RADIUS);
    }
    self->base.hpMax = 1;
    self->base.hp = 1;
    self->table = self->tableData;
    self->count = 8;
    self->unk5E8 = 0;
    self->unk5E4 = 0;
    self->unk5F4 = -1;
    self->unk5F0 = 0;
    self->unk5EC = 0;
    self->unk5F6 = 0;
    func_001C28A0(self);
    return 1;
}

extern int D_00574380;                  /* damage manager */

#define VOL_HALF_X  2.4f
#define VOL_HALF_Y  1.1f
#define VOL_HALF_Z  0.2f


/* Set the object up: one hit point, a damage-take unit with a 2.4 x 1.1 x 0.2 volume at its position, cleared state words and a four entry table at 0x620. */
__attribute__((section(".text.cOmHitVolume_setupThinBox")))
int cOmHitVolume_setupThinBox(cOmHitVolume *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = VOL_HALF_X;
    cb = VOL_HALF_Y;
    cc = VOL_HALF_Z;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[2] = cc;
    f[3] = one;
    f[4] = ca;
    f[5] = cb;
    f[6] = cc;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
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

__attribute__((section(".text.cOmHitVolume_setupBox"))) int cOmHitVolume_setupBox(cOmHitVolume *self)
{
  float f[16];
  float *m;
  float *nv;
  float *t;
  void *slot;
  float one;
  float ca;
  float cb;
  func_001B6FB8(self);
  one = 1.0f;
  ca = 1.2f;
  cb = 1.5f;
  t = &f[4];
  m = &f[8];
  f[0] = ca;
  f[1] = cb;
  f[2] = ca;
  f[3] = one;
  f[4] = ca;
  f[5] = cb;
  f[6] = ca;
  t[3] = one;
  f[8] = 0.0f;
  f[9] = 0.0f;
  f[10] = 0.0f;
  m[3] = one;
  slot = cDamageManage_CreateDamageTake(&D_00574380, self, 2);
  self->damageTake = slot;
  if (slot != 0)
  {
    nv = &f[12];
    f[12] = 0.0f;
    f[13] = 0.0f;
    f[14] = 0.0f;
    nv[3] = one;
    func_001FD9D8(slot, self->base.mtx, m, nv, t);
  }
  self->unk5E8 = 0;
  self->unk5E4 = 0;
  self->unk5F0 = 0;
  self->base.hpMax = 1;
  self->base.hp = 1;
  self->unk5F4 = -1;
  self->table = self->tableData;
  self->count = 6;
  self->unk5EC = 0x11;
  self->unk5F6 = 0x2E;
  func_001C28A0(self);
  return 1;
}
