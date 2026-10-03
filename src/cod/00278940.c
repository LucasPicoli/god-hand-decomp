#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float f12);
extern float SetMotionStep(void *a0, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

#include "godhand/vu0.h"









/* Phase machine on the step byte, 13 case labels. Calls func_002A8578, Getplayer,
 * cGameObj_SetTgtTurn, SetMotionStep, moveMotion, VU0_LQC2 and 5 more. */
__attribute__((section(".text.func_00278940"))) void func_00278940(cEm00 *self)
{
    float buf[8];

    self->hitFlash = 3.0f;
    switch (self->step) {
        case 0: {
            int p = self->resource;
            int k;
            unsigned char m;

            func_002A8578(self, EM_RES_REC(p, 0x24), EM_RES_REC(p, 0x28), 0.0f, 0, 0, 0);
            k = self->unk2FC & 7;
            self->unk580.x = 0.0f;
            self->timer = 1.0f;
            self->unk580.y = 0.1f;
            self->unk580.z = 0.1f;
            switch (k) {
                default:
                case 0:
                    self->timer2 = 16.0f;
                    break;
                case 1:
                    self->timer2 = 12.0f;
                    break;
                case 2:
                    self->timer2 = 18.0f;
                    break;
                case 3:
                    self->timer2 = 14.0f;
                    break;
                case 4:
                    self->timer2 = 11.0f;
                    break;
                case 5:
                    self->timer2 = 13.0f;
                    break;
                case 6:
                    self->timer2 = 17.0f;
                    break;
                case 7:
                    self->timer2 = 15.0f;
                    break;
            }
            m = self->unk2FC % 3;
            switch (m) {
                default:
                case 0:
                    *(float *)((char *)self + 0x608) = 0.012271846644580364f;
                    break;
                case 1:
                    *(float *)((char *)self + 0x608) = 0.01602853462100029f;
                    break;
                case 2:
                    *(float *)((char *)self + 0x608) = 0.02094395086169243f;
                    break;
            }
            self->step++;
        }
        /* fallthrough */
        case 1: {
            char *q;
            char *r;
            float k;
            float *dp;

            if (900.0f < self->playerDist) {
                char *o = Getplayer();

                cGameObj_SetTgtTurn(self, *(int *)(o + 0xF0),
                                    *(float *)((char *)self + 0x608) * self->speedRate);
            }
            SetMotionStep(self, self->speedRate * self->timer);
            moveMotion(self);
            {
                char *o = Getplayer();
                float d = *(float *)((int)self->pos + 4) - *(float *)(*(int *)(o + 0xF0) + 4);

                if (self->timer2 < d)
                    self->unk580.y = 0.0f;
                else
                    self->unk580.y = 0.1f;
            }
            k = self->speedRate;
            q = (char *)buf + 0x10;
            k = k * self->timer;
            r = &self->unk580;
            VU0_LQC2(4, r, 0);
            VU0_SQC2(4, buf, 0x10);
            VU0_LQC2(4, buf, 0x10);
            VU0_LOAD_SCALAR(5, k);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x10);
            VU0_LQC2(4, q, 0);
            VU0_SQC2(4, buf, 0);
            dp = (float *)(((char *)self + 0x330));
            if (dp != buf) {
                float t0, t1, t2;

                t0 = buf[0];
                t1 = buf[1];
                dp[0] = t0;
                *(volatile float *)&dp[1] = t1;
                t2 = *(volatile float *)&buf[2];
                dp[2] = t2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        default:
            break;
    }
}
