/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot2.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"

extern void displayScrollLayer(int id, int on);
extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollision(void *self);

/* sn-2.95.3-136 */




/* Show the scroll layers for the bet level (Slot2.betLv): 0 shows none, 1 shows layer 0, 2 shows layers 0 to 2, 3 shows all five. */
#define SLOT2_OFFSET_LAYER_0  0x3B4     /* layer ids, not named in Slot2.h */
#define SLOT2_OFFSET_LAYER_1  0x3B8
#define SLOT2_OFFSET_LAYER_2  0x3C0
#define SLOT2_OFFSET_LAYER_3  0x3BC
#define SLOT2_OFFSET_LAYER_4  0x3C4
#define SLOT2_LAYER(self, off) (*(int *)((char *)(self) + (off)))

__attribute__((section(".text.Slot2_showLayersForBetLv")))
void Slot2_showLayersForBetLv(Slot2 *self)
{
    switch (self->betLv) {
    case 0:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 0);
        break;
    case 1:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 0);
        break;
    case 2:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 0);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 0);
        break;
    case 3:
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_0), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_1), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_2), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_3), 1);
        displayScrollLayer(SLOT2_LAYER(self, SLOT2_OFFSET_LAYER_4), 1);
        break;
    }
}

/* sn-2.95.3-136 */


/* Slot2 mark selector step, once a frame: while armed (bit 15), count 8 frames, flip the shown bit (14) keeping the selector (bits 11..13), then show only the selected mark layer or hide all five. */
#define SLOT2_OFFSET_BLINK2   0x4AC     /* blink word, not named in Slot2.h */
#define SLOT2_OFFSET_MARKS    0x400     /* layer ids, not named in Slot2.h */
#define BLINK_ARMED    0x8000
#define BLINK_ON       0x4000
#define BLINK_SELECT   0x3800
#define BLINK_COUNT    0x3FF
#define BLINK_DELAY    8
#define MARK_NUM       5

typedef struct { int w[MARK_NUM]; } MarkTbl;
typedef struct Slot2Blink {
    char unk00[4];
} Slot2Blink;

extern MarkTbl D_0042B8D0;              /* layer index of each mark */

__attribute__((section(".text.Slot2_stepMarkSelector")))
void Slot2_stepMarkSelector(Slot2Blink *self)
{
    unsigned short *blink = (unsigned short *)((char *)self + SLOT2_OFFSET_BLINK2);
    unsigned int v = *blink;
    MarkTbl tbl;
    unsigned short w;
    int sel;
    int i;
    int *p;
    char *layers;

    if (v & BLINK_ARMED) {
        v = v + 1;
        *blink = v;
        if ((v & BLINK_COUNT) >= BLINK_DELAY) {
            w = (~v & BLINK_ON) | (v & BLINK_SELECT) | BLINK_ARMED;
            tbl = D_0042B8D0;
            sel = (w >> 11) & 7;
            *blink = w;
            if (w & BLINK_ON) {
                layers = (char *)self + SLOT2_OFFSET_MARKS;
                i = 0;
                p = tbl.w;
                for (; i < MARK_NUM; i++) {
                    displayScrollLayer(*(int *)(layers + (*p << 2)), i == sel);
                    p++;
                }
            } else {
                layers = (char *)self + SLOT2_OFFSET_MARKS;
                p = tbl.w;
                for (i = MARK_NUM - 1; i >= 0; i--) {
                    displayScrollLayer(*(int *)(layers + (*p << 2)), 0);
                    p++;
                }
            }
        }
    }
}

/* sn-2.95.3-136 */









/* Set up a door-like object: 1 life, a 2.13 by 3.78 by 0.2 hit box through the damage manager, the box size kept at 0x610, its collision object and the second body at 0x650. */
#define DOORBOX_RING_OFFSET  0x650      /* second body inside the object */

typedef struct DoorBoxObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    void *damage;                       /* 0x600 */
    char unk604[0xC];
    float size[3];                      /* 0x610 */
    char unk61C[8];
    unsigned char hasBody;              /* 0x624 */
    char unk625[3];
    void *body;                         /* 0x628 */
} DoorBoxObj;

#define COMBASE_F2_BIT1  0x2            /* flags2 bit 1 */

__attribute__((section(".text.DoorBoxObj_constructWideB")))
int DoorBoxObj_constructWideB(DoorBoxObj *self)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;
    int hp;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 2.13f;
    cb = 3.78f;
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
    f[8] = f[0] * -0.5f;
    *(int *)&f[9] = 0;
    *(int *)&f[10] = 0;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)self, 2);
    self->damage = slot;
    if (slot != 0) {
        nv = &f[12];
        *(int *)&f[12] = 0;
        *(int *)&f[13] = 0;
        *(int *)&f[14] = 0;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)((char *)self + 0x80), (const cVec *)m, (const cVec *)nv, (const cVec *)t);
    }
    hp = 1;
    self->base.hpMax = hp;
    self->base.hp = hp;
    cVec_copy3((cVec *)self->size, (cVec *)f);
    cOmDoor_setObjCollision(self);
    self->hasBody = hp;
    self->body = (char *)self + DOORBOX_RING_OFFSET;
    func_001BBF68(self);
    self->base.flags2 |= COMBASE_F2_BIT1;
    return 1;
}
