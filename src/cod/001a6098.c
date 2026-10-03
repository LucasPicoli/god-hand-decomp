/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cOm60.h"
#include "godhand/vu0.h"

extern void func_001B6FB8(void *self);
extern void *cDamageManage_CreateDamageTake(void *mgr, void *owner, int kind);
extern void cDamageUnit_AddDamageCollCylinder(void *unit, void *mtx, float *pos, float *dir, float radius, float half);
extern int D_00574380;
extern float fRand1_1(void);
extern void capVu0ApplyMatrixXYZ(cVec *dst, float *mtx, cVec *v);
extern void cOm60_setThrow(cOm60 *self, cVec *dir, float speed);
extern void CustomIDWork_SetOffsetPosX(void *work, int x);
extern void CustomIDWork_SetMoveOffsetPosX(void *work, int from, int to, int frames);
extern void func_001DEE60(void *self, int element, int show);

/* Set the object up: 40 life, a 1.6 by 2.24 hit cylinder through the damage manager, no flag byte. */


#define OBJ_LIFE  0x28






/* The object past cOmBase: the damage unit handle and a flag byte. */
typedef struct DamagedObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x24];
    unsigned char flag604;              /* 0x604 */
    char unk605[3];
    void *damage;                       /* 0x608 */
} DamagedObj;

__attribute__((section(".text.DamagedObj_setupHitCylinder")))
int DamagedObj_setupHitCylinder(DamagedObj *self) {
    float f[16];
    float *pos;
    float *dir;
    void *slot;
    float one, ca, cb;

    func_001B6FB8(self);
    one = 1.0f;
    ca = 1.6f;
    cb = 2.24f;
    pos = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[7] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    f[6] = ca;
    pos[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, self, 1);
    self->damage = slot;
    if (slot != 0) {
        dir = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        dir[3] = one;
        cDamageUnit_AddDamageCollCylinder(slot, self->base.mtx, pos, dir, f[5], f[4] * 0.5f);
    }
    self->flag604 = 0;
    self->base.hpMax = OBJ_LIFE;
    self->base.hp = OBJ_LIFE;
    return 1;
}

/* Throw the held object in slot `no` with a random small tilt; `fast` selects speed 0 or 150. The slot is emptied. */



#define THROW_SLOT_OFFSET  0x6E4        /* object handles the enemy holds */
#define THROW_SLOW         0.0f
#define THROW_FAST         150.0f
#define THROW_SIDE         0.02f        /* random scale, x and z */
#define THROW_UP_RAND      0.01f        /* random scale, y */
#define THROW_UP_BASE      0.2f





/* The enemy record with the held object slots. */
typedef struct EmThrower {
    char unk000[0x80];
    float mtx[16];                      /* 0x080 */
    char unk0C0[0x624];
    cOm60 *held[3];                     /* 0x6E4 */
} EmThrower;

__attribute__((section(".text.EmThrower_throwHeld")))
void EmThrower_throwHeld(EmThrower *self, int no, int fast) {
    cVec dir;
    cOm60 *obj;
    float side;
    float up;
    float depth;
    VU0_SQC2_VF0(&dir, 0);
    obj = self->held[no];
    if (obj == 0) {
        return;
    }
    self->held[no] = 0;
    side = fRand1_1() * THROW_SIDE;
    up = fRand1_1() * THROW_UP_RAND + THROW_UP_BASE;
    depth = fRand1_1() * THROW_SIDE;
    dir.x = side;
    dir.y = up;
    dir.z = depth;
    capVu0ApplyMatrixXYZ(&dir, self->mtx, &dir);
    if (fast != 0) {
        cOm60_setThrow(obj, &dir, THROW_SLOW);
    } else {
        cOm60_setThrow(obj, &dir, THROW_FAST);
    }
}

/* Slide the UI panel (element at +0x728) on or off and show or hide its two child elements 0xE and 0xF.
 * Mode 0: off screen, children hidden. 1: on screen. 2: slide in from the right. 3: slide out to the right. */




#define PANEL_WORK_OFFSET  0x728
#define PANEL_OFF_X        200          /* pixels to the right of its resting place */
#define PANEL_SLIDE_FRAMES 10
#define PANEL_ELEM_A       0xE
#define PANEL_ELEM_B       0xF

__attribute__((section(".text.UiPanel_setSlideMode")))
void UiPanel_setSlideMode(char *self, unsigned char mode) {
    switch (mode) {
    default:
    case 0:
        CustomIDWork_SetOffsetPosX(self + PANEL_WORK_OFFSET, PANEL_OFF_X);
        func_001DEE60(self, PANEL_ELEM_A, 0);
        func_001DEE60(self, PANEL_ELEM_B, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosX(self + PANEL_WORK_OFFSET, 0);
        func_001DEE60(self, PANEL_ELEM_A, 1);
        func_001DEE60(self, PANEL_ELEM_B, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosX(self + PANEL_WORK_OFFSET, PANEL_OFF_X, 0, PANEL_SLIDE_FRAMES);
        func_001DEE60(self, PANEL_ELEM_A, 1);
        func_001DEE60(self, PANEL_ELEM_B, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosX(self + PANEL_WORK_OFFSET, 0, PANEL_OFF_X, PANEL_SLIDE_FRAMES);
        func_001DEE60(self, PANEL_ELEM_A, 1);
        func_001DEE60(self, PANEL_ELEM_B, 1);
        break;
    }
}
