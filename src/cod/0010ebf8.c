/* sn-2.95.3-136 matched TU. */

extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int a4, int a5);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0010A438(void *a0);
extern char D_00569B70[];
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float capVu0Atan2(float y, float x);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float f12);
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern int cOmBase_checkDamage(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_001B5430(void *a0);
extern void func_001B48E0(void *a0);
extern void func_001B54E8(void *a0);
extern int func_001329C0(void *a0, void *a1, int a2, void *a3, float f12);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);
extern char D_005FEE00[];

struct VtEnt { short delta; short index; void *pfn; };

static __inline__ long inrange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

__attribute__((section(".text.func_0010EBF8")))
void func_0010EBF8(void *a0)
{
    char *s1 = (char *)a0;
    int one = 1;

    if (*(short *)(s1 + 0x54A) <= 0)
        *(short *)(s1 + 0x54A) = one;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        char *e;
        int t;

        func_00124540(s1, 0);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        if (*(signed char *)(s1 + 0x648) > 0)
            *(char *)(s1 + 0x648) = 0x2D;
        e = *(char **)(s1 + 0x640);
        if (e != 0) {
            if (inrange(*(unsigned short *)(e + 0x2FE), 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(D_00569B70, 0x14);
        }
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 0xB, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, (int)(*(float *)(s1 + 0x600) * 10.0f), 0xB, 0xA, 0, 0xA);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x100) + t, *(int *)(t + 0x108) + t, 5, 0.0f, 0, 0);
        *(float *)(s1 + 0x15C4) = 0.0f;
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B4) = 0;
        *(int *)(s1 + 0x15B8) = 1;
        *(float *)(s1 + 0x15C0) = 1.0f;
        *(float *)(s1 + 0x1588) = 0.0f;
        *(short *)(s1 + 0x568) = 0x32;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
    {
        char *e;

        if (*(short *)(s1 + 0x568) != 0) {
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.196349546f);
        }
        if (*(int *)(s1 + 0x640) != 0)
            *(char *)(s1 + 0x648) = 0x14;
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        e = *(char **)(s1 + 0x640);
        if (e != 0) {
            struct VtEnt *vt = *(struct VtEnt **)(e + 0x214);
            float *pos = *(float **)(s1 + 0xF0);
            void *r = ((void *(*)(void *))vt[13].pfn)(e + vt[13].delta);
            if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                *(int *)(s1 + 0x330) = 0;
                *(int *)(s1 + 0x338) = 0;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0)
        ClearField15F4Bit1_124F60(s1, 1, 0);
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_00241C18")))
void func_00241C18(void *a0)
{
    char buf[0x30] __attribute__((aligned(16)));
    char *s0 = (char *)a0;

    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int gb;
        char *v;

        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v + 0x111C) + (int)v, *(int *)(v + 0x1120) + (int)v, 3, 0.0f, gb, 0);
        *(float *)(s0 + 0x6D0) = 1.954f;
        *(float *)(s0 + 0x6D4) = 4.0f;
        *(float *)(s0 + 0x6D8) = -14.8719997f;
        *(float *)(s0 + 0x6E0) = 0.0f;
        {
            char *a = s0 + 0x6D0;
            char *b = *(char **)(s0 + 0xF0);

            VU0_SQC2_VF0(buf, 0x10);
            VU0_LQC2(4, a, 0);
            VU0_LQC2(5, b, 0);
        }
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0);
        VU0_SQC2(4, buf, 0);
        {
            char *d = s0 + 0x580;

            if (d != buf) {
                float t0 = *(float *)(buf + 0);
                float t1 = *(float *)(buf + 4);
                float t2;

                *(float *)(s0 + 0x580) = t0;
                *(volatile float *)(d + 4) = t1;
                t2 = *(volatile float *)(buf + 8);
                *(float *)(d + 8) = t2;
            }
        }
        *(float *)(s0 + 0x584) = 0.0f;
        *(float *)(s0 + 0x600) = 22.0f;
        VU0_LQC2(4, s0 + 0x580, 0);
        VU0_SQC2(4, buf, 0x10);
        {
            float k = 0.0454545468f;

            VU0_LQC2(4, buf, 0x10);
            VU0_LOAD_SCALAR(5, k);
        }
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0);
        VU0_SQC2(4, buf, 0);
        {
            char *d = s0 + 0x590;

            if (d != buf) {
                float t0 = *(float *)(buf + 0);
                float t1 = *(float *)(buf + 4);
                float t2;

                *(float *)(s0 + 0x590) = t0;
                *(volatile float *)(d + 4) = t1;
                t2 = *(volatile float *)(buf + 8);
                *(float *)(d + 8) = t2;
            }
        }
        *(float *)(s0 + 0x604) = capVu0Atan2(-*(float *)(s0 + 0x580), -*(float *)(s0 + 0x588));
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
    {
        float th;

        *(int *)(s0 + 0x16D0) |= 0x21000;
        *(char *)(s0 + 0x617) = 1;
        *(int *)(s0 + 0x16D0) |= 0x10000;
        th = Turn_dest_dir(*(float *)(s0 + 0x104), *(float *)(s0 + 0x604), *(float *)(s0 + 0x5A8) * 0.392699093f);
        *(float *)(s0 + 0x104) += th;
        *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x79;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 4) != 0) {
            float k;
            char *p;
            char *t2;

            VU0_SQC2_VF0(buf, 0);
            k = *(float *)(s0 + 0x5A8);
            t2 = buf + 0x20;
            VU0_LQC2(4, s0 + 0x590, 0);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, buf, 0x20);
            VU0_LOAD_SCALAR(5, k);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, t2, 0);
            VU0_SQC2(4, buf, 0x10);
            {
                float *d = (float *)buf;
                float *s = (float *)(buf + 0x10);

                if (d != s) {
                    float x = *(float *)(buf + 0x10);
                    float y = *(float *)(buf + 0x14);
                    float z = *(float *)(buf + 0x18);

                    *(float *)(buf + 0x0) = x;
                    *(float *)(buf + 0x4) = y;
                    *(float *)(buf + 0x8) = z;
                }
            }
            p = *(char **)(s0 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0, buf);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    }
}

struct Entry_001B4068 { short f0; short f2; short f4; short f6; };
struct Table_001B4068 { struct Entry_001B4068 e[1]; };
extern struct Table_001B4068 D_003BDD38;

#include "godhand/vu0.h"

static __inline__ char *GetChild(char *p, int idx, char *fr)
{
    int cnt;

    if ((*(int *)fr = cnt = *(unsigned char *)(p + 0x2B4)), (idx >= 0 && idx < cnt))
        return *(char **)(*(int *)(p + 0x278) + idx * 4);
    return 0;
}

__attribute__((section(".text.func_001B4068")))
void func_001B4068(void *a0)
{
    char buf[0x20] __attribute__((aligned(16)));
    char *s0 = (char *)a0;

    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0)
        return;
    if (cOmBase_checkDamage(s0, *(int *)(s0 + 0x650)) != 0) {
        if (*(short *)(s0 + 0x54A) <= 0) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x89, s0, 0, 0, 0, 0);
            *(char *)(s0 + 0x2F4) = 3;
            *(char *)(s0 + 0x2F5) = 0;
            *(int *)(s0 + 0x5B0) |= 1;
        } else {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x8E, s0, 0, 0, 0, 0);
        }
        func_001B5430(s0);
    }
    {
        char *e;
        int i8;
        int f0;
        int type; int arg; int (*fp)(int); long entry;

        i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
        e = (char *)&D_003BDD38 + i8;
        type = *(short *)(e + 2);
        if (type >= 0) {
            int base = *(int *)(s0 + *(short *)(e + 4));
            entry = *(long *)(base + type * 8 - 8);
            fp = (int (*)(int))(int)(entry >> 32);
        } else {
            fp = *(int (**)(int))((char *)&D_003BDD38 + i8 + 4);
        }
        f0 = D_003BDD38.e[*(unsigned char *)(s0 + 0x2F4)].f0;
        if (type >= 0)
            arg = (short)entry + f0;
        else
            arg = f0;
        fp((int)(s0 + arg));
    }
    func_001B48E0(s0);
    func_001B54E8(s0);
    switch (*(unsigned char *)(s0 + 0x2F4)) {
    case 0:
        if (0.0f < *(float *)(s0 + 0x964)) {
            if (GetChild(s0, 9, buf) != 0)
                *(float *)*(char **)(GetChild(s0, 9, buf) + 0xD0) = *(float *)(s0 + 0x964);
            if (GetChild(s0, 10, buf) != 0)
                *(float *)*(char **)(GetChild(s0, 10, buf) + 0xD0) = -*(float *)(s0 + 0x964);
        }
        break;
    case 1:
        if (0.0f < *(float *)(s0 + 0x964)) {
            *(float *)(s0 + 0x964) = *(float *)(s0 + 0x964) - 0.0500000007f;
            if (*(float *)(s0 + 0x964) < 0.0f)
                *(float *)(s0 + 0x964) = 0.0f;
            if (GetChild(s0, 9, buf) != 0)
                *(float *)*(char **)(GetChild(s0, 9, buf) + 0xD0) = *(float *)(s0 + 0x964);
            if (GetChild(s0, 10, buf) != 0)
                *(float *)*(char **)(GetChild(s0, 10, buf) + 0xD0) = -*(float *)(s0 + 0x964);
        }
        break;
    default:
        *(float *)(s0 + 0x964) = 0.0f;
        break;
    }
    VU0_SQC2_VF0(buf, 0x10);
    if (func_001329C0(s0, buf + 0x10, 0, 0, 10.0f) != 0)
        (*(float **)(s0 + 0xF0))[1] = *(float *)(buf + 0x14);
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}
