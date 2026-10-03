#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00262750(void *a0, int a1);
extern void func_00260B30(void *a0);
extern void func_001C2280(void *a0, void *a1, int a2, void *a3, void *a4);
extern void SetField_2F6_1C2308(void *a0);
extern void func_002705D8(void *a0);
extern void cOmBase_dieCommon(void *a0);

/* sn-2.95.3-136 matched TU. */




















#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"

/* Phase machine on the step byte, 10 case labels. Calls func_00274018,
 * CheckSlotsShort2FEAndSetByte1864_262A10, Obj0000_Get_Byte_17C3_NZ_2_276468,
 * StoreMotionParamsBoth_2609A8, func_002A8578, cGameObj_SetTgtTurn and 12 more. */
__attribute__((section(".text.func_002258C0"))) void func_002258C0(cEm00 *self)
{
    char *s3;
    int gb;

    *(char *)((char *)self + 0x186A) = 2;
    self->emFlags2 |= 0x400;
    s3 = (char *)func_00274018();
    CheckSlotsShort2FEAndSetByte1864_262A10(self);
    switch (self->step) {
        case 0: {
            char *v0;
            *(char *)((char *)self + 0x1864) = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            StoreMotionParamsBoth_2609A8(self, 0x28, 0xA, 0x42, 0, 0xF5);
            v0 = *(char **)((char *)self + 0x304);
            func_002A8578(self, *(int *)(v0 + 0x2060) + (int)v0, *(int *)(v0 + 0x2064) + (int)v0,
                          0xA, 0.0f, gb, 0);
            self->timerC = 0;
            self->step += 1;
        }
            /* fallthrough */
        case 1:
            if (s3 != 0) {
                cGameObj_SetTgtTurn(self, *(int *)(s3 + 0xF0), self->speedRate * 0.19634955f);
            }
            if (moveMotion(self) != 0) {
                self->step += 1;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 2: {
            char *v0;
            int a1v, a2v;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v0 = *(char **)((char *)self + 0x304);
            a1v = *(int *)(v0 + 0x2068) + (int)v0;
            a2v = *(int *)(v0 + 0x206C) + (int)v0;
            if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
                char *v1 = *(char **)((char *)self + 0x304);
                a2v = *(int *)(v1 + 0x2070) + (int)v1;
            }
            func_002A8578(self, a1v, a2v, 3, 0.0f, gb, 0);
            self->timerA = 8;
            self->timer = 150.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 3: {
            float d;
            if (s3 != 0) {
                cGameObj_SetTgtTurn(self, *(int *)(s3 + 0xF0), self->speedRate * 0.19634955f);
                if (capVu0MagnitudeSqXZ(*(void **)((char *)self + 0xF0), *(void **)(s3 + 0xF0)) <
                    4.0f) {
                    self->step = 6;
                }
            } else {
                self->step = 4;
            }
            d = self->timer - self->speedRate;
            self->timer = d;
            if (d <= 0.0f) {
                self->step = 4;
            }
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            func_00262750(self, 3);
            func_00260B30(self);
            break;
        }
        case 4: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = *(char **)((char *)self + 0x304);
            func_002A8578(self, *(int *)(v1 + 0x2074) + (int)v1, *(int *)(v1 + 0x2078) + (int)v1, 3,
                          0.0f, gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 5:
            if (moveMotion(self) != 0) {
                self->step = 8;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        case 6: {
            float z = 0.0f;
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = *(char **)((char *)self + 0x304);
            func_002A8578(self, *(int *)(v1 + 0x207C) + (int)v1, *(int *)(v1 + 0x2080) + (int)v1, 3,
                          z, gb, 0);
            *(int *)((char *)self + 0x70C) = 0;
            if (s3 != 0) {
                float buf[8];
                *(int *)((char *)self + 0x70C) = (int)s3;
                VU0_SQC2_VF0(buf, 0x0);
                VU0_SQC2_VF0(buf, 0x10);
                buf[0] = z;
                buf[1] = z;
                buf[2] = z;
                buf[4] = z;
                buf[5] = z;
                buf[6] = z;
                if (self->unk17C3 != 0) {
                    func_001C2280(s3, self, 0xA, buf, &buf[4]);
                } else {
                    func_001C2280(s3, self, 0x10, buf, &buf[4]);
                }
                SetField_2F6_1C2308(*(void **)((char *)self + 0x70C));
            }
            self->timer = 10.0f;
            self->step += 1;
        }
            /* fallthrough */
        case 7: {
            float cur = self->timer;
            if (0.0f < cur) {
                float dt = self->speedRate;
                self->timer = cur - dt;
                if (s3 != 0) {
                    cGameObj_SetTgtTurn(self, *(int *)(s3 + 0xF0), dt * 0.19634955f);
                }
            }
            func_00262750(self, 3);
            if (moveMotion(self) != 0) {
                *(char *)((char *)self + 0x2F4) = 0;
                self->phase = 0x6C;
                *(char *)((char *)self + 0x2F6) = 0;
                *(char *)((char *)self + 0x2F7) = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            if (self->moveFlags & 2) {
                if (*(int *)((char *)self + 0x70C) != 0) {
                    int nv = *(unsigned short *)((char *)self + 0x54A) + 0x12C;
                    *(unsigned short *)((char *)self + 0x54A) = (unsigned short)nv;
                    if (self->vitalMax < (short)nv) {
                        *(unsigned short *)((char *)self + 0x54A) =
                            *(unsigned short *)((char *)self + 0x548);
                    }
                    cOmBase_dieCommon(*(void **)((char *)self + 0x70C));
                    *(int *)((char *)self + 0x70C) = 0;
                }
            }
            break;
        }
        case 8: {
            int gb;
            char *v1;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v1 = *(char **)((char *)self + 0x304);
            func_002A8578(self, *(int *)(v1 + 0x20A4) + (int)v1, *(int *)(v1 + 0x20A8) + (int)v1, 3,
                          0.0f, gb, 0);
            self->step += 1;
        }
            /* fallthrough */
        case 9:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
    self->emFlags |= 0x1000;
    self->unk16F8 = 0xA;
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}
