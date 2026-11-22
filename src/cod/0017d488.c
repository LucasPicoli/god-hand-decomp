/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cSnd.h"
#include "godhand/effectPos.h"
#include "godhand/vu0.h"

extern void func_001B6FB8(void *self);
extern void cOmDoor_setObjCollision(void *self);
extern int cSnd_SeCall(void *a0, int a1, int a2, void *a3, int a4, int a5);
extern void CustomIDWork_SetOffsetPosY(void *work, int y);
extern void CustomIDWork_SetMoveOffsetPosY(void *work, int from, int to, int frames);
extern void SetCustomIDDispOneOrAll_1DD258(void *self, int entry, int on);

/* func_001BBF68 stays undeclared on purpose: an implicit int declaration keeps retail's jal slot store. */

/* A door object: the fields the constructor sets. */
typedef struct DoorObj {
    char unk000[0x548];
    short life;                         /* 0x548 */
    short lifeMax;                      /* 0x54A */
    char unk54C[0x6C];
    unsigned int flags;                 /* 0x5B8 */
    char unk5BC[0x54];
    float size[3];                      /* 0x610 */
    char unk61C[8];
    unsigned char hasBody;              /* 0x624 */
    char unk625[3];
    void *body;                         /* 0x628 */
    char unk62C[0x24];
    char bodyRec[1];                    /* 0x650 */
} DoorObj;

#define DOOR_FLAG_BOX  0x2

/* Set up a door object: 1 life (0x548, 0x54A), a 1.75 by 3.1 by 0.2 box kept
 * at 0x610, its collision object, a body at 0x650 and flag bit 1 in 0x5B8.
 * Returns 1. */
__attribute__((section(".text.DoorObj_construct1B")))
int DoorObj_construct1B(DoorObj *self) {
    float f[8];
    float *t;
    int hp;
    float one, ca, cb, cc, cd;
    func_001B6FB8(self);
    hp = 1;
    one = 1.0f;
    ca = 1.75f;
    cb = 3.1f;
    cc = 0.2f;
    cd = -0.875f;
    t = &f[4];
    f[0] = ca;
    f[1] = cb;
    f[2] = cc;
    f[4] = cd;
    f[3] = one;
    t[3] = one;
    f[5] = 0.0f;
    f[6] = 0.0f;
    self->life = hp;
    self->lifeMax = hp;
    cVec_copy3((cVec *)self->size, (cVec *)f);
    cOmDoor_setObjCollision(self);
    self->hasBody = hp;
    self->body = self->bodyRec;
    func_001BBF68(self);
    self->flags |= DOOR_FLAG_BOX;
    return 1;
}

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, void *a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Once per object (flag byte 0x640): cast a line from the object's position
 * (0x490) along a zeroed direction; when the hit surface (flags at hit+4)
 * has bit 0x400 (water), spawn effect 0x55 at the hit point and play sound
 * 0x50 on the owner, then set the flag. */
typedef struct LineObjB {
    char unk000[0xF0];
    void *owner;                        /* 0xF0 */
    char unk0F4[0x39C];
    char pos[0x1B0];                    /* 0x490 */
    unsigned char done;                 /* 0x640 */
} LineObjB;

typedef struct HitRec {
    int unk0;
    unsigned int surface;               /* 0x4 */
} HitRec;

/* What ChkLine fills in: the hit point, then the record of the surface it hit. */
typedef struct LineHit {
    cVec point;                         /* 0x00 */
    HitRec *rec;                        /* 0x10 */
    char unk14[0xC];
} LineHit;

#define SURFACE_WATER  0x400
#define FRAME ((char *)&hit - 0x30)

__attribute__((section(".text.LineObjB_checkWaterHit")))
void LineObjB_checkWaterHit(LineObjB *self) {
    LineHit hit;
    if (self->done == 0) {
        cVec *v = &hit.point;
        int one;
        VU0_SQC2_VF0(FRAME, 0x30);
        one = 1;
        if (ChkLine(self->pos, self->owner, v, 0, 7, 0, &hit.rec, 1, 0, 0, 0, 0, one) != 0
            && (hit.rec->surface & SURFACE_WATER) != 0) {
            SetEffectPos(0, 0x55, 0, v, 1.0f, -1);
            cSnd_SeCall(&D_005FEE00, 2, 0x50, self->owner, 0, 0);
            self->done = one;
        }
    }
}

#define PANEL_WORK       0x89C          /* CustomIDWork of the sliding panel */
#define PANEL_Y_HIDDEN   0x46
#define PANEL_SLIDE_FRAMES  0xA

/* Panel mode: 0 hidden, 1 shown, 2 slide in, 3 slide out; entries 0x11 and 0x12 follow the mode. */
__attribute__((section(".text.PanelWork_setModeB")))
void PanelWork_setModeB(char *self, unsigned char mode) {
    switch (mode) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosY(self + PANEL_WORK, PANEL_Y_HIDDEN);
        SetCustomIDDispOneOrAll_1DD258(self, 0x11, 0);
        SetCustomIDDispOneOrAll_1DD258(self, 0x12, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosY(self + PANEL_WORK, 0);
        SetCustomIDDispOneOrAll_1DD258(self, 0x11, 1);
        SetCustomIDDispOneOrAll_1DD258(self, 0x12, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosY(self + PANEL_WORK, PANEL_Y_HIDDEN, 0, PANEL_SLIDE_FRAMES);
        SetCustomIDDispOneOrAll_1DD258(self, 0x11, 1);
        SetCustomIDDispOneOrAll_1DD258(self, 0x12, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosY(self + PANEL_WORK, 0, PANEL_Y_HIDDEN, PANEL_SLIDE_FRAMES);
        SetCustomIDDispOneOrAll_1DD258(self, 0x11, 1);
        SetCustomIDDispOneOrAll_1DD258(self, 0x12, 1);
        break;
    }
}
