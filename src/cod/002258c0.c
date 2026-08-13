/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00262750(void *a0, int a1);
extern void func_00260B30(void *a0);
extern void func_001C2280(void *a0, void *a1, int a2, void *a3, void *a4);
extern void SetField_2F6_1C2308(void *a0);
extern void func_002705D8(void *a0);
extern void Tramp_00312708_1B79B0(void *a0);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */




















#include "godhand/vu0.h"

__attribute__((section(".text.func_002258C0")))
void func_002258C0(void *a0)
{
    char *s0 = (char *)a0;
    char *s3;
    int gb;

    *(char *)(s0 + 0x186A) = 2;
    *(int *)(s0 + 0x16D4) |= 0x400;
    s3 = (char *)func_00274018();
    CheckSlotsShort2FEAndSetByte1864_262A10(s0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        char *v0;
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s0, 0x28, 0xA, 0x42, 0, 0xF5);
        v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x2060) + (int)v0,
                      *(int *)(v0 + 0x2064) + (int)v0, 0xA, 0.0f, gb, 0);
        *(int *)(s0 + 0x5FC) = 0;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (s3 != 0) {
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(s3 + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634955f);
        }
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2: {
        char *v0;
        int a1v, a2v;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v0 = *(char **)(s0 + 0x304);
        a1v = *(int *)(v0 + 0x2068) + (int)v0;
        a2v = *(int *)(v0 + 0x206C) + (int)v0;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = *(char **)(s0 + 0x304);
            a2v = *(int *)(v1 + 0x2070) + (int)v1;
        }
        func_002A8578(s0, a1v, a2v, 3, 0.0f, gb, 0);
        *(int *)(s0 + 0x5F0) = 8;
        *(float *)(s0 + 0x600) = 150.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        float d;
        if (s3 != 0) {
            AddScaledDeltaToField_104_2A7498(s0, *(int *)(s3 + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.19634955f);
            if (capVu0MagnitudeSqXZ(*(void **)(s0 + 0xF0), *(void **)(s3 + 0xF0)) < 4.0f) {
                *(unsigned char *)(s0 + 0x2F6) = 6;
            }
        } else {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        d = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
        *(float *)(s0 + 0x600) = d;
        if (d <= 0.0f) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        func_00262750(s0, 3);
        func_00260B30(s0);
        break;
    }
    case 4: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x2074) + (int)v1,
                      *(int *)(v1 + 0x2078) + (int)v1, 3, 0.0f, gb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 8;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6: {
        float z = 0.0f;
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x207C) + (int)v1,
                      *(int *)(v1 + 0x2080) + (int)v1, 3, z, gb, 0);
        *(int *)(s0 + 0x70C) = 0;
        if (s3 != 0) {
            float buf[8];
            *(int *)(s0 + 0x70C) = (int)s3;
            VU0_SQC2_VF0(buf, 0x0);
            VU0_SQC2_VF0(buf, 0x10);
            buf[0] = z;
            buf[1] = z;
            buf[2] = z;
            buf[4] = z;
            buf[5] = z;
            buf[6] = z;
            if (*(unsigned char *)(s0 + 0x17C3) != 0) {
                func_001C2280(s3, s0, 0xA, buf, &buf[4]);
            } else {
                func_001C2280(s3, s0, 0x10, buf, &buf[4]);
            }
            SetField_2F6_1C2308(*(void **)(s0 + 0x70C));
        }
        *(float *)(s0 + 0x600) = 10.0f;
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 7: {
        float cur = *(float *)(s0 + 0x600);
        if (0.0f < cur) {
            float dt = *(float *)(s0 + 0x5A8);
            *(float *)(s0 + 0x600) = cur - dt;
            if (s3 != 0) {
                AddScaledDeltaToField_104_2A7498(s0, *(int *)(s3 + 0xF0),
                                                 dt * 0.19634955f);
            }
        }
        func_00262750(s0, 3);
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 2) {
            if (*(int *)(s0 + 0x70C) != 0) {
                int nv = *(unsigned short *)(s0 + 0x54A) + 0x12C;
                *(unsigned short *)(s0 + 0x54A) = (unsigned short)nv;
                if (*(short *)(s0 + 0x548) < (short)nv) {
                    *(unsigned short *)(s0 + 0x54A) = *(unsigned short *)(s0 + 0x548);
                }
                Tramp_00312708_1B79B0(*(void **)(s0 + 0x70C));
                *(int *)(s0 + 0x70C) = 0;
            }
        }
        break;
    }
    case 8: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x20A4) + (int)v1,
                      *(int *)(v1 + 0x20A8) + (int)v1, 3, 0.0f, gb, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 9:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    *(int *)(s0 + 0x16D0) |= 0x1000;
    *(int *)(s0 + 0x16F8) = 0xA;
    if (*(unsigned short *)(s0 + 0x3AC) & 3) {
        *(int *)(s0 + 0x5FC) = 1;
    }
    if (*(int *)(s0 + 0x5FC) != 0) {
        *(int *)(s0 + 0x16D4) &= 0xFFFFFBFF;
    }
}
