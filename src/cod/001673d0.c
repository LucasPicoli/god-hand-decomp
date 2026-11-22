/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDBase.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"
#include "godhand/globals.h"

extern void displayScrollLayer(int layer, int on);
extern void Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(void *self);
extern void cIDManager_setIDData(void *mgr, int kind, int res);
extern void cIDBase_initialize(void *self, int kind, int arg);
extern void cIDBase_resetAnim(void *self);
extern int cIDBase_setPackedMessData(void *self, int kind, int arg);
extern void **D_003C2384;
extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollision(void *self);

/* sn-2.95.3-136 */


/* Show or hide the four scroll layers of a slot machine mark; showing also sets the mark's flag word (bit 15 start lit, bit 14 on). */
#define SLOT2MARK_F_START_LIT  0x8000
#define SLOT2MARK_F_ON         0x4000

typedef struct Slot2Marks {
    char unk000[0x430];
    int layerA;                         /* 0x430 */
    char unk434[0x38];
    int layerC;                         /* 0x46C */
    int layerD;                         /* 0x470 */
    char unkD[0x8];
    int layerB;                         /* 0x47C */
    char unk480[0x24];
    unsigned short markFlag;            /* 0x4A4 */
} Slot2Marks;

__attribute__((section(".text.Slot2_setMarkLayersAt46C")))
void Slot2_setMarkLayersAt46C(Slot2Marks *self, int show, int startLit)
{
    self->markFlag = 0;
    if (startLit) {
        self->markFlag = SLOT2MARK_F_START_LIT;
    }
    if (show) {
        self->markFlag = self->markFlag | SLOT2MARK_F_ON;
        displayScrollLayer(self->layerA, 1);
        displayScrollLayer(self->layerB, 1);
        displayScrollLayer(self->layerC, 1);
        displayScrollLayer(self->layerD, 1);
    } else {
        displayScrollLayer(self->layerA, 0);
        displayScrollLayer(self->layerB, 0);
        displayScrollLayer(self->layerC, 0);
        displayScrollLayer(self->layerD, 0);
    }
}

/* sn-2.95.3-136 */


/* Slot2 blink step, once a frame: while armed (bit 15), count 8 frames, then flip the shown bit (14) and show or hide the four mark layers. */
#define SLOT2_OFFSET_BLINK    0x4A6     /* blink word, not named in Slot2.h */
#define SLOT2_OFFSET_LAYER_A  0x430     /* layer ids, not named in Slot2.h */
#define SLOT2_OFFSET_LAYER_B  0x47C
#define SLOT2_OFFSET_LAYER_C  0x474
#define SLOT2_OFFSET_LAYER_D  0x478
#define SLOT2_LAYER(self, off) (*(int *)((char *)(self) + (off)))
#define BLINK_ARMED    0x8000
#define BLINK_ON       0x4000
#define BLINK_COUNT    0x3FFF
#define BLINK_DELAY    8

typedef struct Slot2Blink {
    char unk00[4];
} Slot2Blink;

__attribute__((section(".text.Slot2_blinkMarksAt4A6")))
void Slot2_blinkMarksAt4A6(Slot2Blink *self)
{
    unsigned short *blink = (unsigned short *)((char *)self + SLOT2_OFFSET_BLINK);
    unsigned int v = *blink;
    unsigned short w;
    if (v & BLINK_ARMED) {
        v = v + 1;
        *blink = v;
        if ((v & BLINK_COUNT) >= BLINK_DELAY) {
            w = (~v & BLINK_ON) | BLINK_ARMED;
            *blink = w;
            if (w & BLINK_ON) {
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_A), 1);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_B), 1);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_C), 1);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_D), 0);
            } else {
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_A), 0);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_B), 0);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_C), 0);
                displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_D), 1);
            }
        }
    }
}

/* sn-2.95.3-136 */












/* Constructor of a 0x1B-part display object with a second part record: base setup, then (when its data table matches) the ID data, initial animation and message of both records, and the 0x10 display works. */
#define IDOBJ_WORK_NUM  0x10
#define IDOBJ_KIND      0x1B

typedef struct IdDispObj {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[8];
    int resHandle;                      /* 0x50 */
    char unk54[6];
    unsigned char b5A;                  /* 0x5A */
    unsigned char b5B;                  /* 0x5B */
    unsigned char b5C;                  /* 0x5C */
    unsigned char b5D;                  /* 0x5D */
    char unk5E[2];
    int state;                          /* 0x60 */
    char unk64[0x1C];
    void *work[IDOBJ_WORK_NUM];         /* 0x80 */
    char sub[0x50];                     /* 0xC0 second part record */
    char unkSubEnd[0x0];
    unsigned char b110;                  /* 0x110 */
    unsigned char b111;                  /* 0x111 */
} IdDispObj;

__attribute__((section(".text.IdDispObj_constructKind1B")))
void IdDispObj_constructKind1B(IdDispObj *self)
{
    unsigned short i;
    Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0(self);
    if (func_00161500(self, D_0041FBA0) != 0) {
        cIDManager_setIDData(*D_003C2384, IDOBJ_KIND, self->resHandle);
        cIDBase_initialize(self, IDOBJ_KIND, 0);
        cIDBase_resetAnim(self);
        cIDBase_setPackedMessData(self, IDOBJ_KIND, 2);
        cIDBase_initialize(self->sub, IDOBJ_KIND, 1);
        cIDBase_resetAnim(self->sub);
        self->b5A = 0;
        self->state = 5;
        self->b5B = 0;
        self->b5C = 0;
        self->b5D = 0;
    }
    for (i = 0; i < IDOBJ_WORK_NUM; i++) {
        self->work[i] = cIDBase_getIDWork(&self->base, i);
    }
    self->b110 = 0;
    self->b111 = 0;
}

/* sn-2.95.3-136 */









/* Set up the door-like object: 1 life, a hit cylinder through the damage manager, the collision box copied from the
 * stack record, solid collision and the hit sub-record. */
#define OBJ_LIFE      1
#define OBJ_SOLID_ID  7                 /* value of the solid-collision byte */

/* The object past cOmBase: damage unit, collision box, solid byte and hit record. */
typedef struct DoorLikeObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
    char unk604[0xC];
    cVec box;                           /* 0x610 collision box size, xyz */
    char unk620[4];
    unsigned char solid;                /* 0x624 */
    char unk625[3];
    void *hitRec;                       /* 0x628 */
    char unk62C[0x24];
    char hitRecData[0x20];              /* 0x650 */
} DoorLikeObj;

__attribute__((section(".text.DoorBox_initWithBoxD")))
int DoorBox_initWithBoxD(DoorLikeObj *self) {
    float f[16];
    float *t;
    float *m;
    float *nv;
    void *slot;
    char *rec;
    float one, ca, cb, cc;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.5f;
    cb = 3.1f;
    cc = 0.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[4] = ca;
    f[1] = cb;
    f[2] = cc;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[8] = -f[0] * 0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)self->base.mtx, (const cVec *)m, (const cVec *)nv, (const cVec *)t);
    }
    self->base.hpMax = OBJ_LIFE;
    self->base.hp = OBJ_LIFE;
    cVec_copy3(&self->box, (cVec *)f);
    cOmDoor_setObjCollision(self);
    self->hitRec = self->hitRecData;
    self->solid = OBJ_SOLID_ID;
    func_001BBF68(self);
    return 1;
}
