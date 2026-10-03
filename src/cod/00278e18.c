/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"

extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern float fRand1_1(void);
extern unsigned int Rnd(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern char *D_00586A7C;
extern unsigned char D_005FEE00[];

#include "godhand/vu0.h"

/* Phase machine of the enemy that circles the player: it turns toward the player, drifts its height
 * toward the player's, and steps along the 0x580 vector scaled by speedRate until the countdown
 * ends. */
__attribute__((section(".text.cEm00_stepCirclePlayer"))) void cEm00_stepCirclePlayer(cEm00 *self)
{
    char *g = D_00586A7C;
    float dist = 1.0e16f;
    float one;
    float z;
    char buf[0x20] __attribute__((aligned(16)));

    if (g != 0) {
        dist = capVu0MagnitudeSqXZ(*(void **)(g + 0xF0), (void *)self->pos);
    }
    switch (self->step) {
        case 0: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x1C), EM_RES_REC(v, 0x20), 0.0f, 2, 0, 0);
            self->timer3 = 30.0f;
            self->step += 1;
        }
        case 1:
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
        case 2: {
            int v = self->resource;
            z = 0.0f;
            func_002A8578(self, EM_RES_REC(v, 0x24), EM_RES_REC(v, 0x28), z, 0, 0, 0);
            self->unk580.x = z;
            self->timer = 1.0f;
            self->unk580.y = z;
            self->unk580.z = 0.1f;
            self->timer2 = 450.0f;
            self->step += 1;
        }
        case 3:
            if (g != 0) {
                if (16.0f < dist) {
                    cGameObj_SetTgtTurn(self, *(int *)(g + 0xF0), self->speedRate * 0.024543693f);
                }
                if (*(float *)((char *)self->pos + 4) <
                    *(float *)(*(char **)(g + 0xF0) + 4) + 2.5f) {
                    char *p = (char *)self->pos;
                    *(float *)(p + 4) = *(float *)(p + 4) + self->speedRate * 0.05f;
                }
            }
            moveMotion(self);
            {
                float t = self->speedRate;
                char *p = &self->unk580;
                char *q = buf + 0x10;
                float *d;
                VU0_LQC2(4, p, 0x0);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, buf, 0x10);
                VU0_LOAD_SCALAR(5, t);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, q, 0x0);
                VU0_SQC2(4, buf, 0x0);
                d = (float *)(&self->stepVec);
                if (d != (float *)buf) {
                    float t0 = ((float *)buf)[0];
                    float t1 = ((float *)buf)[1];
                    float t2;
                    d[0] = t0;
                    *(volatile float *)(d + 1) = t1;
                    t2 = *(volatile float *)((float *)buf + 2);
                    d[2] = t2;
                }
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            {
                float x = self->timer2 - self->speedRate;
                self->timer2 = x;
                if (x <= 0.0f) {
                    self->step = self->step + 1;
                }
            }
            break;
        case 4: {
            int v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x24), EM_RES_REC(v, 0x28), 0.0f, 0, 0, 0);
            self->timer = 1.0f;
            self->step += 1;
        }
        case 5:
            if (g != 0) {
                if (4.0f < dist) {
                    cGameObj_SetTgtTurn(self, *(int *)(g + 0xF0), self->speedRate * 0.09817477f);
                }
                if (*(float *)(*(char **)(g + 0xF0) + 4) + 2.0f <
                    *(float *)((char *)self->pos + 4)) {
                    char *p = (char *)self->pos;
                    *(float *)(p + 4) = *(float *)(p + 4) - self->speedRate * 0.05f;
                }
            }
            moveMotion(self);
            {
                float t = self->speedRate;
                char *p = &self->unk580;
                char *q = buf + 0x10;
                float *d;
                VU0_LQC2(4, p, 0x0);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, buf, 0x10);
                VU0_LOAD_SCALAR(5, t);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, buf, 0x10);
                VU0_LQC2(4, q, 0x0);
                VU0_SQC2(4, buf, 0x0);
                d = (float *)(&self->stepVec);
                if (d != (float *)buf) {
                    float t0 = ((float *)buf)[0];
                    float t1 = ((float *)buf)[1];
                    float t2;
                    d[0] = t0;
                    *(volatile float *)(d + 1) = t1;
                    t2 = *(volatile float *)((float *)buf + 2);
                    d[2] = t2;
                }
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            if (dist < 0.25f) {
                self->mode = 0;
                self->phase = 4;
                self->step = 0;
                self->stepArg = 0;
            }
            if (g != 0) {
                if (*(unsigned char *)(g + 0x2F4) == 1) {
                    self->step = 2;
                }
            }
            break;
    }
    {
        float x = self->timer3 - self->speedRate;
        self->timer3 = x;
        if (x <= 0.0f) {
            self->timer3 = fRand1_1() * 150.0f + 150.0f;
            switch ((unsigned char)(Rnd() % 6)) {
                default:
                case 0:
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, 0, self, 0, 0, 0, 0);
                    break;
                case 1:
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, 1, self, 0, 0, 0, 0);
                    break;
                case 2:
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, 2, self, 0, 0, 0, 0);
                    break;
                case 3:
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, 3, self, 0, 0, 0, 0);
                    break;
                case 4:
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, 4, self, 0, 0, 0, 0);
                    break;
                case 5:
                    cSnd_SeCall_2CBA48(D_005FEE00, 1, 5, self, 0, 0, 0, 0);
                    break;
            }
        }
    }
}
