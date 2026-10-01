/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"
#include "godhand/ColiseumBattle.h"

extern int D_0044E808;
extern void func_002D9F68(void *, int, ...);

/* Sets the element's local position and stops its animation. */
__attribute__((section(".text.CustomIDWork_SetLocalPosXY")))
void CustomIDWork_SetLocalPosXY(CustomIDWork *self, int x, int y) {
    if (self->obj != 0) {
        self->localFlags = 0;
        self->obj->localPos[0] = (float)x;
        self->obj->localPos[1] = (float)y;
    }
}

/* Slides the X offset from `from` to `to` over `frames` frames. */
__attribute__((section(".text.CustomIDWork_SetMoveOffsetPosX")))
void CustomIDWork_SetMoveOffsetPosX(CustomIDWork *self, int from, int to, unsigned short frames) {
    if (self->obj == 0) {
        return;
    }
    self->offsFlags = CIDW_ANIM_ON | CIDW_ANIM_LINEAR;
    self->offsTotal = frames;
    self->offsFrom[0] = (float)from;
    self->offsTo[0] = (float)to;
    self->offsCount = 0;
}

/* Swings the X offset by +-`amp` as a sine over `frames` frames. */
__attribute__((section(".text.CustomIDWork_SetMoveOffsetPosXSin")))
void CustomIDWork_SetMoveOffsetPosXSin(CustomIDWork *self, int amp, unsigned short frames) {
    if (self->obj != 0) {
        self->offsFlags = CIDW_ANIM_ON | CIDW_ANIM_SINE;
        self->offsTotal = frames;
        self->offsAmp[0] = (float)amp;
        self->offsCount = 0;
    }
}

/* Slides the Y offset from `from` to `to` over `frames` frames. */
__attribute__((section(".text.CustomIDWork_SetMoveOffsetPosY")))
void CustomIDWork_SetMoveOffsetPosY(CustomIDWork *self, int from, int to, unsigned short frames) {
    if (self->obj == 0) {
        return;
    }
    self->offsFlags = CIDW_ANIM_ON | CIDW_OFFS_LINEAR_Y;
    self->offsTotal = frames;
    self->offsFrom[1] = (float)from;
    self->offsTo[1] = (float)to;
    self->offsCount = 0;
}

/* Sets the element's offset position and stops its offset animation. */
__attribute__((section(".text.CustomIDWork_SetOffsetPosXY")))
void CustomIDWork_SetOffsetPosXY(CustomIDWork *self, int x, int y) {
    if (self->obj != 0) {
        self->offsFlags = 0;
        self->obj->offsetPos[0] = (float)x;
        self->obj->offsetPos[1] = (float)y;
    }
}

/* Starts the battle clock at ring time limit * 30 frames. */
__attribute__((section(".text.SetField_B98_1EFD50")))
void SetField_B98_1EFD50(ColiseumBattle *self)
{
    self->countdown = (float)(self->ring.timeLimit * 30);
}

/* Swings the Y offset by +-`amp` as a sine over `frames` frames. */
__attribute__((section(".text.func_002D6838")))
void func_002D6838(CustomIDWork *self, int amp, unsigned short frames) {
    if (self->obj != 0) {
        self->offsFlags = CIDW_ANIM_ON | CIDW_OFFS_SINE_Y;
        self->offsTotal = frames;
        self->offsAmp[1] = (float)amp;
        self->offsCount = 0;
    }
}

/* NOTE: needs "fp_hazard_rules": "mtc1" on its compile_units entry. */
/* sn-2.95.3-136 */




__attribute__((section(".text.func_002EA908")))
int func_002EA908(char *p)
{
    char *q;
    int m;
    unsigned int t;

    *(int *)(p + 0x2B8) = 0;
    *(int *)(p + 0x2BC) = 0;
    q = *(char **)(p + 0x110);
    *(float *)(p + 0x2C0) = *(float *)(q + 0x13C) * 0.1f;
    *(float *)(p + 0x2C4) = *(float *)(q + 0x140) * 0.1f;
    m = *(signed char *)(q + 0x18C) + 2;
    *(int *)(p + 0x2C8) = m;
    *(float *)(p + 0x2B0) = *(signed char *)(q + 0x18D) * 0.1f + 1.0f;
    *(float *)(p + 0x2B4) = *(signed char *)(q + 0x18E) * 0.1f + 1.0f;
    t = *(unsigned char *)(q + 0x18F);
    *(int *)(p + 0x2CC) = t;
    if (t >= 4) {
        func_002D9F68(p, (int)&D_0044E808, t);
        *(int *)(p + 0x2CC) = 0;
        return 0;
    }
    if (t != 0 && m == 2) {
        *(int *)(p + 0x2C8) = 3;
    }
    return 1;
}
