#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float capVu0Atan2(float x, float z);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00281368(void *a0, int a1);
extern void func_002832A0(void *a0, int a1);
extern void cGameObj_placeBeforeAnchor(void *a0, float a1);
extern float fRand1_1(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026DB00(void *a0, int a1, int a2);
extern int D_005850B0;

#include "godhand/vu0.h"
















/* Phase machine on the step byte, 4 case labels. Calls VU0_SQC2_VF0, Getplayer,
 * capVu0MagnitudeSqXZ, Obj0000_Get_Byte_17C3_NZ_2_276468, func_002A8578, func_00281368 and 11 more.
 */
__attribute__((section(".text.func_0024AE50"))) void func_0024AE50(cEm00 *self)
{
    float v[12];
    float dist;
    void *sb;
    char *o;

    VU0_SQC2_VF0(v, 0);
    o = (char *)Getplayer();
    sb = &D_005850B0;
    dist = capVu0MagnitudeSqXZ(*(void **)(o + 0xF0), sb);
    self->emFlags |= 0x30400;
    switch (self->step) {
        case 0: {
            int gb;
            char *p;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            p = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)p, 0x3D3C), EM_RES_REC((int)p, 0x3D40), 0.0f, 0xA,
                          gb, 0);
            if (self->sub0 != 0) {
                func_00281368((void *)self->sub0, 0);
            }
            if (self->sub1 != 0) {
                func_002832A0((void *)self->sub1, 0);
            }
            if (self->sub2 != 0) {
                func_002832A0((void *)self->sub2, 0);
            }
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            *(char *)((char *)self + 0x617) = 1;
            if (moveMotion(self) != 0) {
                self->step = 2;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            int gb;
            float ang;
            void *q = *(void **)((char *)Getplayer() + 0xF0);
            float *cs = v + 4;
            float *tq = v + 8;
            VU0_SQC2_VF0(v, 0x20);
            VU0_LQC2(4, q, 0);
            VU0_LQC2(5, sb, 0);
            VU0_VSUB_XYZ(4, 4, 5);
            VU0_SQC2(4, v, 0x20);
            VU0_LQC2(4, tq, 0);
            VU0_SQC2(4, v, 0x10);
            if (v != cs) {
                v[0] = v[4];
                v[1] = v[5];
                v[2] = v[6];
            }
            ang = capVu0Atan2(v[0], v[2]);
            if (capVu0MagnitudeSqXZ(*(void **)((char *)Getplayer() + 0xF0), sb) < 64.0f) {
                ang = fRand1_1() * 3.14159274f;
            }
            cGameObj_placeBeforeAnchor(self, ang);
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            if (100.0f < dist) {
                char *p = (char *)self->resource;
                func_002A8578(self, EM_RES_REC((int)p, 0x3D44), EM_RES_REC((int)p, 0x3D48), 0.0f,
                              0xA, gb, 0);
                if (self->sub0 != 0) {
                    func_00281368((void *)self->sub0, 1);
                }
                if (self->sub1 != 0) {
                    func_002832A0((void *)self->sub1, 1);
                }
                if (self->sub2 != 0) {
                    func_002832A0((void *)self->sub2, 1);
                }
                self->timer = 35.0f;
            } else {
                char *p = (char *)self->resource;
                func_002A8578(self, EM_RES_REC((int)p, 0x3D4C), EM_RES_REC((int)p, 0x3D50), 0.0f,
                              0xA, gb, 0);
                if (self->sub0 != 0) {
                    func_00281368((void *)self->sub0, 2);
                }
                if (self->sub1 != 0) {
                    func_002832A0((void *)self->sub1, 2);
                }
                if (self->sub2 != 0) {
                    func_002832A0((void *)self->sub2, 2);
                }
                self->timer = 15.0f;
            }
            self->step += 1;
        }
            /* fallthrough */
        case 3:
            if (0.0f < self->timer) {
                *(char *)((char *)self + 0x617) = 1;
                self->timer -= self->speedRate;
            }
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0xA1;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    if (self->moveFlags & 1) {
        func_0026DB00(self, 6, 0);
    }
}
