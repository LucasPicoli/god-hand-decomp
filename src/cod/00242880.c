#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_0026B9E8(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_00462FC0[];
extern char D_005FEE00[];

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"














typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct S {
    float f00;            /* 0x00 */
    float f04;
    float f08;
    float f0C;
    Vec4 v10;             /* 0x10 sqc2 */
    Vec4 v20;             /* 0x20 sqc2 */
    float f30;            /* 0x30 */
    float f34;
    float f38;
    float f3C;
    float f40;            /* 0x40 */
    int i44;
    int i48;
    signed char b4C;      /* 0x4C */
    signed char b4D;
    signed char b4E;
    unsigned char b4F;
    int i50;              /* 0x50 */
    char pad54[0xC];
    char q60[0x10];       /* 0x60 sqc2 */
    short h70;            /* 0x70 */
    short h72;
    signed char b74;      /* 0x74 */
    char pad75[3];
    int i78;              /* 0x78 */
    char pad7C[4];
} S;

/* Phase machine on the step byte, 7 case labels. Calls VU0_SQC2_VF0,
 * cCollisionSolidManage_SetActive, func_002A8578, cCoreSave_getGameLevel, func_0026B9E8,
 * cSnd_SeCall_2CBA48 and 4 more. */
__attribute__((section(".text.func_00242880"))) void func_00242880(cEm00 *self)
{
    S fr;
    S *e = &fr;

    e->f00 = 1.0f;
    e->f04 = 1.0f;
    e->f08 = 1.0f;
    e->f0C = 1.0f;
    VU0_SQC2_VF0(&fr, 0x10);
    VU0_SQC2_VF0(&fr, 0x20);
    {
        float *q = &e->f30;
        q[0] = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    e->f40 = 1.0f;
    fr.i44 = 0;
    fr.i48 = 0;
    e->b4C = -1;
    fr.b4D = 0;
    fr.b4E = 0;
    e->b4F = 0xFF;
    fr.i50 = 0;
    VU0_SQC2_VF0(&fr, 0x60);
    e->f40 = self->unk114;
    self->hitFlash = 3.0f;
    fr.h70 = 0;
    fr.h72 = 0;
    fr.b74 = 0;
    fr.i78 = 0;
    cCollisionSolidManage_SetActive(D_00462FC0, self, 0);

    self->emFlags |= 0x10000;
    switch (self->step) {
        case 0: {
            int w = self->resource;
            func_002A8578(self, EM_RES_REC(w, 0x245C), EM_RES_REC(w, 0x2460), 0.0f, 3, 0, 0);
            self->timer = 45.0f;
            self->timer2 = 0.053333335f;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    *(float *)((char *)self + 0x172C) = 450.0f;
                    break;
                case 2:
                    *(float *)((char *)self + 0x172C) = 600.0f;
                    break;
                case 3:
                    *(float *)((char *)self + 0x172C) = 750.0f;
                    break;
                case 4:
                    *(float *)((char *)self + 0x172C) = 750.0f;
                    break;
                case 5:
                    *(float *)((char *)self + 0x172C) = 900.0f;
                    break;
            }
            func_0026B9E8(self);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x107, self, 0, 0, 0, 0);
            SetEffect(0x69, 1, self, &fr, 1, 0xFFFFFFFFU);
            self->emFlags2 |= 0x20;
            self->step++;
        }
        /* fallthrough */
        case 1: {
            float t = self->timer;
            float *p;
            if (0.0f < t) {
                self->timer = t - self->speedRate;
            } else {
                self->timer2 = self->timer2 * (1.0f - self->speedRate * 0.1f);
            }
            p = (float *)((int)self->pos + 4);
            *p = *p + self->timer2 * self->speedRate;
            if (moveMotion(self)) {
                float fv = *(float *)((int)self->pos + 4);
                self->phase = 0x7F;
                *(float *)((char *)self + 0x1738) = fv;
                self->mode = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        default:
            break;
    }
}
