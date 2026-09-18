/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void func_00262750(void *a0, int a1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern void func_0026E7A8(void *a0, int a1);
extern int cEmManage__CreateItem(void *a0, int a1, int a2, int a3);
extern void func_001C2280(void *a0, void *a1, int a2, void *a3, void *a4);
extern void SetField_2F6_1C2308(void *a0);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

#include "godhand/vu0.h"

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_00241EB0")))
void func_00241EB0(void *a0)
{
    float va[4], vb[4], vc[4];
    char *s3 = (char *)a0;
    char *mgr = (char *)D_005864F0;
    char *s0 = *(char **)(mgr + 0x588);
    char *cur = *(char **)(s3 + 0x70C);
    int gb;
    char *p;

    if (cur != 0) {
        if (*(long *)(cur + 0x250) & 0x80008000L) {
            *(int *)(s3 + 0x70C) = 0;
        }
    }
    switch (*(unsigned char *)(s3 + 0x2F6)) {
    case 0:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(char **)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0xD60) + (int)p,
                      *(int *)(p + 0xD64) + (int)p, 0, 0.0f, gb, 0);
        {
            int n = *(unsigned char *)(s3 + 0x2F6);
            *(unsigned short *)(s3 + 0x548) = 1;
            n = n + 1;
            *(unsigned short *)(s3 + 0x54A) = 1;
            *(unsigned char *)(s3 + 0x2F6) = (unsigned char)n;
        }
        /* fallthrough */
    case 1:
        *(int *)(s3 + 0x16D0) |= 0x1000;
        func_00262750(s3, 2);
        *(int *)(s3 + 0x16D0) |= 0x10000;
        *(int *)(s3 + 0x16D0) |= 0x20000;
        if (moveMotion(s3) != 0) {
            *(char *)(s3 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        if (*(unsigned short *)(s3 + 0x3AC) & 0x10) {
            float *dv = va;
            float *d;
            float *q;
            VU0_SQC2_VF0(FRAME, 0x30);
            VU0_SQC2_VF0(FRAME, 0x40);
            VU0_SQC2_VF0(FRAME, 0x50);
            d = (float *)(s3 + 0x490);
            if (dv != d) {
                va[0] = *(float *)(s3 + 0x490);
                do { } while (0);
                dv[1] = d[1];
                do { } while (0);
                dv[2] = d[2];
            }
            q = *(float **)(s3 + 0xF0);
            if (vb != q) {
                vb[0] = q[0];
                vb[1] = q[1];
                vb[2] = q[2];
            }
            va[1] = va[1] + 0.5f;
            if (ChkLine(va, vb, vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                float *r = *(float **)(s3 + 0xF0);
                r[1] = vc[1];
                *(char *)(s3 + 0x2F6) = 2;
            }
        }
        break;
    case 2: {
        int a1v, a2v;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(char **)(s3 + 0x304);
        a1v = *(int *)(p + 0xD68) + (int)p;
        a2v = *(int *)(p + 0xD6C) + (int)p;
        func_0026E7A8(s3, *(int *)(s3 + 0xF0));
        func_002A8578(s3, a1v, a2v, 3, 0.0f, gb, 0);
        *(unsigned char *)(s3 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s3) != 0) {
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        break;
    case 4:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(char **)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0xDDC) + (int)p,
                      *(int *)(p + 0xDE0) + (int)p, 0, 0.0f, gb, 0);
        *(unsigned char *)(s3 + 0x2F6) += 1;
        /* fallthrough */
    case 5:
        if (moveMotion(s3) != 0) {
            *(unsigned char *)(s3 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        if (*(unsigned short *)(s3 + 0x3AC) & 1) {
            if (*(int *)(s3 + 0x70C) == 0) {
                int it = cEmManage__CreateItem((void *)D_005864F0, *(int *)(s3 + 0xF0),
                                               0x3D1, 0);
                *(int *)(s3 + 0x70C) = it;
                if (it != 0) {
                    float *ap = va;
                    VU0_SQC2_VF0(FRAME, 0x30);
                    VU0_SQC2_VF0(FRAME, 0x40);
                    va[0] = 0.0f;
                    va[1] = 0.0f;
                    va[2] = 0.0f;
                    vb[0] = 0.0f;
                    vb[1] = 0.0f;
                    vb[2] = 0.0f;
                    func_001C2280((void *)it, s3, 0xA, ap, vb);
                    SetField_2F6_1C2308(*(void **)(s3 + 0x70C));
                }
            }
        }
        break;
    case 6:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(char **)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0xDE4) + (int)p,
                      *(int *)(p + 0xDE8) + (int)p, 3, 0.0f, gb, 0);
        *(unsigned char *)(s3 + 0x2F6) += 1;
        /* fallthrough */
    case 7:
        *(int *)(s3 + 0x16D0) |= 0x400;
        if (s0 != 0) {
            AddScaledDeltaToField_104_2A7498(s3, *(int *)(s0 + 0xF0),
                                             *(float *)(s3 + 0x5A8) * 0.098174770424681f);
            if (capVu0MagnitudeSqXZ(*(void **)(s0 + 0xF0),
                                    *(void **)(s3 + 0xF0)) < 64.0f) {
                *(unsigned char *)(s3 + 0x2F6) = 8;
            }
        } else {
            *(unsigned char *)(s3 + 0x2F6) = 8;
        }
        moveMotion(s3);
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        break;
    case 8:
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        p = *(char **)(s3 + 0x304);
        func_002A8578(s3, *(int *)(p + 0xDEC) + (int)p,
                      *(int *)(p + 0xDF0) + (int)p, 3, 0.0f, gb, 0);
        *(unsigned char *)(s3 + 0x2F6) += 1;
        /* fallthrough */
    case 9:
        moveMotion(s3);
        AddScaledVecToField_100_14F9F0(s3, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        break;
    }
}
