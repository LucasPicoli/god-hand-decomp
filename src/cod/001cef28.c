#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern unsigned char D_00462FC0[];
extern unsigned char D_005FEE00[];
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int cOmbb_ckFire(int a0);
extern void cOmbb_setFire(int a0);
extern float SetMotionStep(void *a0, float f12);
extern float cEmManage_GetSpeedRate(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

#include "godhand/vu0.h"
/* Phase machine on the step byte, 2 case labels. Calls func_002948C8, VU0_SQC2_VF0,
 * cCollisionSolidManage_SetActive, Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578,
 * cSnd_SeCall_2CBA48 and 9 more. */
__attribute__((section(".text.func_00244708"))) void func_00244708(cEm00 *self)
{
    float buf[4];

    int s1;

    s1 = func_002948C8(D_005864F0, *(unsigned char *)((char *)self + 0x17B1));
    VU0_SQC2_VF0(buf, 0);
    cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    self->emFlags = self->emFlags | 0x10000;
    switch (self->step) {
        case 0: {
            int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            char *v1 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v1, 0x4FC), EM_RES_REC((int)v1, 0x500), 0.0f, 3, gb,
                          0);
        }
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x64, self, 0, 0, 0, 0);
            self->step++;
        case 1: {
            float *p = (float *)(*(char **)(Getplayer() + 0xF0));
            if (buf != p) {
                buf[0] = p[0];
                buf[1] = p[1];
                buf[2] = p[2];
            }
            if (s1 != 0) {
                float *q = (float *)func_001B8720(s1);
                if (buf != q) {
                    buf[0] = q[0];
                    buf[1] = q[1];
                    buf[2] = q[2];
                }
            }
        }
            cGameObj_SetTgtTurn(self, buf, self->speedRate * 0.392699093f);
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (self->moveFlags & 1) {
        if (s1 != 0) {
            if (cOmbb_ckFire(s1) == 0)
                cOmbb_setFire(s1);
        }
    }
}

/* Phase machine on the step byte, 4 case labels. Calls cEmManage_GetSpeedRate, SetMotionStep,
 * func_002A8578, moveMotion, capVu0MagnitudeSqXZ, Getplayer and 2 more. */
__attribute__((section(".text.func_001CEF28"))) void func_001CEF28(cEm00 *self)
{
    float sp;
    float one;
    float t;

    sp = cEmManage_GetSpeedRate(D_005864F0);
    self->speedRate = sp;
    SetMotionStep(self, sp);
    switch (self->step) {
        case 0: {
            int res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), 0, 0.0f, 0, 0, 0);
        }
            self->unk568 = 0;
            *(float *)((char *)self + 0x674) = 150.0f;
            self->step++;
        case 1:
            moveMotion(self);
            if (capVu0MagnitudeSqXZ(*(void **)(Getplayer() + 0xF0), (void *)self->pos) < 4.0f)
                self->unk568 = 1;
            if (self->unk568 != 0) {
                t = *(float *)((char *)self + 0x674) - sp;
                *(float *)((char *)self + 0x674) = t;
                if (t <= 0.0f)
                    self->step++;
            }
            break;
        case 2: {
            int res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x10), 0, 0.0f, 0, 0, 0);
        }
            *(float *)((char *)self + 0x674) = 90.0f;
            self->step++;
        case 3:
            one = 1.0f;
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            t = *(float *)((char *)self + 0x674) - sp;
            *(float *)((char *)self + 0x674) = t;
            if (t <= 0.0f) {
                float u = self->animRate - sp * 0.1f;
                self->objFlags = self->objFlags | 0x10;
                self->animRate = u;
                if (u < 0.0f) {
                    self->animRate = 0.0f;
                    self->mode = 1;
                    self->phase = 0;
                    self->step = 0;
                    self->stepArg = 0;
                }
            }
            break;
    }
}
