/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float capVu0Atan2(float y, float x);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj2810_SetState_E_a1(void *a0, int a1);
extern void SetBytes2F4Mode11_283360(void *a0, int a1);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_0026F120(void *a0);

extern void func_00270C78(void *a0);
extern void func_002705D8(void *a0);
/* Phase machine on the step byte, 8 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468, VU0_LQC2,
 * VU0_SQC2, capVu0Atan2, Turn_dest_dir, func_002A8578 and 8 more. */
__attribute__((section(".text.func_0025B6E8"))) void func_0025B6E8(cEm00 *self)
{
    float buf[4];
    switch (self->step) {
        case 0: {
            float f20 = 3.1415927f;
            int s1 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            float z = 0.0f;
            float turn = z;
            int v1 = *(int *)((char *)self + 0x698);
            int p1, p2;
            if (v1 != 0 && *(int *)(v1 + 0x34) != 0) {
                VU0_LQC2(4, (char *)v1 + 0x10, 0);
                VU0_SQC2(4, buf, 0);
                {
                    float bz = buf[2];
                    float at = capVu0Atan2(buf[0], bz);
                    turn = Turn_dest_dir(self->rot.y, at, f20);
                }
                {
                    float ad = turn;
                    if (turn < z)
                        ad = -turn;
                    f20 = ad;
                }
            }
            if (self->stepArg == 2) {
                if (turn < 0.0f)
                    self->stepArg = 2;
                else
                    self->stepArg = 3;
                if (f20 < 0.7853982f)
                    self->stepArg = 4;
                if (2.3561945f < f20)
                    self->stepArg = 5;
            }
            switch (self->stepArg) {
                default:
                case 0: {
                    int b = self->resource;
                    p1 = EM_RES_REC(b, 0x3DC4);
                    p2 = EM_RES_REC(b, 0x3DC8);
                } break;
                case 1: {
                    int b = self->resource;
                    p1 = EM_RES_REC(b, 0x3DBC);
                    p2 = EM_RES_REC(b, 0x3DC0);
                } break;
                case 2: {
                    int b = self->resource;
                    int q1 = *(int *)(b + 0x3DCC);
                    int q2 = *(int *)(b + 0x3DD0);
                    {
                        int fl = self->emFlags & 0xFEFFFFFF;
                        p1 = q1 + b;
                        self->emFlags = fl;
                        p2 = q2 + b;
                    }
                } break;
                case 3: {
                    int b = self->resource;
                    int q1 = *(int *)(b + 0x3DD4);
                    int q2 = *(int *)(b + 0x3DD8);
                    {
                        int fl = self->emFlags & 0xFEFFFFFF;
                        p1 = q1 + b;
                        self->emFlags = fl;
                        p2 = q2 + b;
                    }
                } break;
                case 4: {
                    int b = self->resource;
                    int q1 = *(int *)(b + 0x3DDC);
                    int q2 = *(int *)(b + 0x3DE0);
                    {
                        int fl = self->emFlags & 0xFEFFFFFF;
                        p1 = q1 + b;
                        self->emFlags = fl;
                        p2 = q2 + b;
                    }
                } break;
                case 5: {
                    int b = self->resource;
                    int q1 = *(int *)(b + 0x3DE4);
                    int q2 = *(int *)(b + 0x3DE8);
                    {
                        int fl = self->emFlags & 0xFEFFFFFF;
                        p1 = q1 + b;
                        self->emFlags = fl;
                        p2 = q2 + b;
                    }
                } break;
            }
            func_002A8578(self, p1, p2, 0.0f, 2, s1, 0);
            if (self->sub0)
                Obj2810_SetState_E_a1((void *)self->sub0, self->stepArg);
            if (self->sub1)
                SetBytes2F4Mode11_283360((void *)self->sub1, self->stepArg);
            if (self->sub2)
                ClearBytes2F4To2F7_283170((void *)self->sub2);
            self->step = self->step + 1;
        }
        case 1:
            if (moveMotion(self) != 0) {
                if (self->stepArg >= 2) {
                    func_0026F120(self);
                    if (func_0026F1D8(self) != 0) {
                        func_00270C78(self);
                        return;
                    }
                }
                func_002705D8(self);
            }
            break;
    }
    if (*(float *)((char *)self + 0x176C) <= 0.0f) {
        self->phase = 0xA5;
        self->step = 2;
        self->mode = 0;
        self->stepArg = 0;
    }
}
