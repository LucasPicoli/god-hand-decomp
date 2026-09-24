/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_00569B70[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern unsigned char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern void KillEffect(void *a0, int a1, int a2);
extern void func_003063B8(void *a0, int a1, int a2, int a3);
extern void func_001AAB10(void *a0);
extern void SetField5B0Bit2ClearBit8_1B7908(int a0);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00126770(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern char *CreateObj(int a0, int a1);
extern void func_0012A8D8(void *a0);
extern void cIDManager_getLocalFileName();
extern int cDvd_ReadAlloc();
extern void cDvd_CheckWait();
extern void cIDManager_setIDData();
extern void cIDBase_initialize();
extern void cIDBase_resetAnim();
extern char *cIDBase_getIDWork();
extern int D_003C2388;
extern char D_0041E190[];
extern char D_00583F20[];
extern char D_00754220[];
extern int *D_003C2384;
extern void SetField444SignedByFlag434_158288(void *a0, float f12);
extern float D_003BDE70;
extern float D_003BDE74;
extern float D_003BDE78;
extern float D_003BDE7C;
extern float D_003BDE80;
extern float D_003BDE84;
extern int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void SetOrientByType_26AF20(void *a0, int a1, unsigned int a2);

/* sn-2.95.3-136 matched TU. */


















#include "godhand/vu0.h"

__attribute__((section(".text.func_001215C8")))
void func_001215C8(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s2 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = -0.257099986f;
        buf[1] = 0.0f;
        buf[2] = 1.64129996f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x2D, v, v);
        *(int *)(s1 + 0x15B0) = 1;
        *(short *)(s1 + 0x56E) = 0xF;
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        if (*(short *)(s1 + 0x56E) != 0 && s2 != 0) {
            char *d;
            char *e = s2 + 0x550;
            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            d = *(char **)(s1 + 0xF0);
            VU0_LQC2(4, d, 0);
            VU0_LQC2(5, e, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, d, 0);
        }
        func_00124EC0(s1);
        if (moveMotion(s1)) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if (func_00123938(s1, 1)) {
        ClearField15F4Bit1_124F60(s1, 0, 0);
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"









__attribute__((section(".text.func_001AA6C0")))
void func_001AA6C0(void *a0)
{
    char *s1 = (char *)a0;
    float buf[4] __attribute__((aligned(16)));
    int hold[4];

    switch (*(unsigned char *)(s1 + 0x2F5)) {
    case 0: {
        char *vt;
        short off;
        float *(*fp)();
        float *src;
        int b;
        int part;
        KillEffect(s1, 0xB, 0);
        func_003063B8(s1, 3, 2, 0x1E);
        VU0_SQC2_VF0(buf, 0);
        vt = *(char **)(s1 + 0x214);
        off = *(short *)(vt + 0x80);
        fp = *(float *(**)())(vt + 0x84);
        src = fp(s1 + off);
        if (buf != src) {
            buf[0] = src[0];
            buf[1] = src[1];
            buf[2] = src[2];
        }
        SetEffectPos(0, 7, 0, buf, -1, 1.0f);
        {
            int i = 5;
            if ((hold[0] = b = *(unsigned char *)(s1 + 0x2B4)), i < b)
                part = *(int *)(*(int *)(s1 + 0x278) + i * 4);
            else
                part = 0;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x5B, s1, 0, part, 0, 0);
        {
            int i = 5;
            if ((hold[0] = b = *(unsigned char *)(s1 + 0x2B4)), i < b)
                part = *(int *)(*(int *)(s1 + 0x278) + i * 4);
            else
                part = 0;
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x87, s1, 0, part, 0, 0);
        func_001AAB10(s1);
        SetField5B0Bit2ClearBit8_1B7908((int)s1);
        *(short *)(s1 + 0x600) = 0x1E;
        *(unsigned char *)(s1 + 0x2F5) = 1;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
    }
    /* fallthrough */
    case 1: {
        int v = *(unsigned short *)(s1 + 0x600) - 1;
        *(short *)(s1 + 0x600) = v;
        if ((short)v > 0)
            break;
        *(short *)(s1 + 0x600) = 0xF;
        *(unsigned char *)(s1 + 0x2F5) = 2;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
    case 2: {
        int v = *(unsigned short *)(s1 + 0x600) - 1;
        *(short *)(s1 + 0x600) = v;
        if ((short)v > 0)
            break;
        *(unsigned char *)(s1 + 0x2F5) = 3;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
    case 3:
        *(unsigned char *)(s1 + 0x2F4) = 0;
        *(unsigned char *)(s1 + 0x2F5) = 0;
        *(unsigned char *)(s1 + 0x2F6) = 0;
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    }
}

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_00114E28")))
void func_00114E28(void *a0)
{
    char *s1 = (char *)a0;
    int t;
    int p1;
    int p2;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        func_00126770(s1);
        ClearField15F4Bit1_124F60(s1, 0, 0);
        t = *(int *)(s1 + 0x304);
        p1 = *(int *)(t + 0x3D8) + t;
        p2 = *(int *)(t + 0x3DC) + t;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x29, s1, 0, 0, 0, 0);
        func_002A8578(s1, p1, p2, 0.0f, 3, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        InvokeVirtualAtField214AndForward_124E68(s1, 0.19634954f);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0 && *(int *)(s1 + 0x698) == 0) {
        char *obj = CreateObj(0x3AF, 0xFFFF);
        *(char **)(s1 + 0x698) = obj;
        if (obj != 0) {
            char *p2c;
            char *p3;
            float *src1;
            float *src2;
            float *dst;
            float *p490;
            int *p100;

            {
                char *v1 = *(char **)(obj + 0x214);
                short off = *(short *)(v1 + 0x40);
                int (*fn)(char *) = *(int (**)(char *))(v1 + 0x44);
                fn(obj + off);
            }
            src1 = *(float **)(s1 + 0xF0);
            dst = *(float **)(*(char **)(s1 + 0x698) + 0xF0);
            if (dst != src1) {
                dst[0] = src1[0];
                dst[1] = src1[1];
                dst[2] = src1[2];
            }
            p2c = *(char **)(s1 + 0x698);
            src2 = *(float **)(s1 + 0xF0);
            p490 = (float *)(p2c + 0x490);
            if (p490 != src2) {
                p490[0] = src2[0];
                p490[1] = src2[1];
                p490[2] = src2[2];
            }
            p3 = *(char **)(s1 + 0x698);
            p100 = (int *)(p3 + 0x100);
            p100[0] = 0;
            p100[1] = 0;
            p100[2] = 0;
            func_0012A8D8(s1);
        }
    }
    func_00123938(s1, 1);
}

/* sn-2.95.3-136 matched TU. */














typedef struct { char b[0x50]; } IDBase50;

typedef struct {
    char pad00[0x90];
    int f90;             /* 0x90 */
    char pad94[0xC];
    int fA0;             /* 0xA0 */
    int fA4;             /* 0xA4 */
    int fA8[5];          /* 0xA8 */
    char padBC[4];
    IDBase50 id[5];      /* 0xC0 */
    char pad250[0x70];
    float f2C0[5];       /* 0x2C0 */
    float f2D4[5];       /* 0x2D4 */
    float f2E8[5];       /* 0x2E8 */
    short f2FC[5];       /* 0x2FC */
    char pad306[0x6A];
    int f370[5];         /* 0x370 */
} MiddleBoss;

__attribute__((section(".text.cCockMiddleBoss_roomInit")))
void cCockMiddleBoss_roomInit(MiddleBoss *a0) {
    char buf[0x40];
    int r;
    unsigned short i;

    do {
        if (a0->fA0 == 0) {
            cIDManager_getLocalFileName(D_003C2388, buf, D_0041E190, -1);
            r = cDvd_ReadAlloc(D_00583F20, buf, &a0->fA0, D_00754220, 0, 0, 0, 0);
            a0->fA4 = r;
            cDvd_CheckWait(D_00583F20, r);
            cIDManager_setIDData(*D_003C2384, 0xD, a0->fA0);
            cIDBase_initialize(a0, 0xD, 0);
            cIDBase_resetAnim(a0);
            *(float *)(cIDBase_getIDWork(a0, 0) + 0x38) = -100.0f;
            a0->f90 = 0;
            for (i = 0; i < 5; i++) {
                IDBase50 *id = &a0->id[i];
                char *w;
                cIDBase_initialize(id, 0xD, 1);
                cIDBase_resetAnim(id);
                a0->f2C0[i] = 1.0f;
                a0->f2D4[i] = 1.0f;
                a0->f2E8[i] = 1.0f;
                a0->f2FC[i] = 0;
                a0->f370[i] = 0;
                a0->fA8[i] = 0;
                w = cIDBase_getIDWork(id, 0);
                *(float *)(w + 0x3C) = *(float *)(cIDBase_getIDWork(a0, 0) + 0x3C);
            }
        }
    } while (0);
    a0->f90 = 0x80000000;
}

/* sn-2.95.3-136 matched TU. */










__attribute__((section(".text.func_001C8020")))
void func_001C8020(char *s0)
{
    int hold[4];
    char *s1;
    char *p;
    float *d;
    float *s;
    int b;

    {
        int i = 0;
        if ((hold[0] = b = *(unsigned char *)(s0 + 0x2B4)), i < b)
            s1 = *(char **)(*(int *)(s0 + 0x278) + i * 4);
        else
            s1 = 0;
    }
    p = *(char **)(s0 + 0x644);
    if (p == 0) return;
    s = *(float **)(p + 0xF0);
    d = *(float **)(s0 + 0xF0);
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
    {
        char *q = *(char **)(s0 + 0x644);
        float *d2 = (float *)(s0 + 0x100);
        float *s2 = (float *)(q + 0x100);
        if (d2 != s2) {
            d2[0] = s2[0];
            d2[1] = s2[1];
            d2[2] = s2[2];
        }
    }
    *(float *)(s0 + 0x5A8) = *(float *)(*(char **)(s0 + 0x644) + 0x5A8);
    SetField444SignedByFlag434_158288(s0, *(float *)(s0 + 0x5A8));
    moveMotion(s0);
    if (s1 == 0) return;
    switch (*(unsigned short *)(s0 + 0x2FE)) {
    case 0x30A:
    case 0x325:
    case 0x33F:
    case 0x411:
    case 0x41A:
        (*(float **)(s1 + 0xD0))[0] += D_003BDE70 * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[1] += D_003BDE74 * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[2] += D_003BDE78 * *(float *)(s0 + 0x624);
        break;
    case 0x301:
    case 0x30B:
    case 0x30C:
    case 0x332:
    case 0x410:
    case 0x419:
    case 0x41F:
    case 0x42E:
        (*(float **)(s1 + 0xD0))[0] += D_003BDE7C * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[1] += D_003BDE80 * *(float *)(s0 + 0x624);
        (*(float **)(s1 + 0xD0))[2] += D_003BDE84 * *(float *)(s0 + 0x624);
        break;
    }
    *(float *)(s0 + 0x624) = *(float *)(s0 + 0x624) + 0.0500000007f;
    if (1.0f < *(float *)(s0 + 0x624)) *(float *)(s0 + 0x624) = 1.0f;
}

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_00273748")))
void func_00273748(char *s0)
{
    int hold[4];
    char *o;
    char *part;
    int b;
    int big;
    float k;
    float t;
    float v;

    o = *(char **)(s0 + 0x700);
    if (o == 0) return;
    switch (*(int *)(s0 + 0x564)) {
    case 0x208:
        if (Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(o)) {
            if ((*(long *)(s0 + 0x2F0) & 0xFFFF00000000) == 0xE0000000000) return;
            if (!(capVu0MagnitudeSqXZ(*(char **)(*(char **)(s0 + 0x700) + 0xF0), *(char **)(s0 + 0xF0)) < 0.360000014f)) return;
            SetOrientByType_26AF20(s0, *(int *)(s0 + 0x700), 0);
        } else if (*(int *)(s0 + 0x16D0) < 0) {
            SetOrientByType_26AF20(s0, *(int *)(s0 + 0x700), 1);
        } else {
            SetOrientByType_26AF20(s0, *(int *)(s0 + 0x700), 0);
        }
        return;
    case 0x22F:
        big = 1;
        if (Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(o)) {
            if ((*(long *)(s0 + 0x2F0) & 0xFFFF00000000) != 0xE0000000000) {
                if (capVu0MagnitudeSqXZ(*(char **)(*(char **)(s0 + 0x700) + 0xF0), *(char **)(s0 + 0xF0)) < 0.360000014f) {
                    SetOrientByType_26AF20(s0, *(int *)(s0 + 0x700), 2);
                }
            }
        } else if (*(int *)(s0 + 0x16D0) < 0) {
            SetOrientByType_26AF20(s0, *(int *)(s0 + 0x700), 3);
        } else {
            big = 0;
            SetOrientByType_26AF20(s0, *(int *)(s0 + 0x700), 2);
        }
        o = *(char **)(s0 + 0x700);
        {
            int one = 1;
            if ((hold[0] = b = *(unsigned char *)(o + 0x2B4)), one < b)
                part = *(char **)(*(int *)(o + 0x278) + 4);
            else
                part = 0;
        }
        if (part == 0) return;
        k = 1.0f;
        if (big) k = 4.0f;
        t = 1.0f - *(float *)(s0 + 0x5A8) * 0.100000001f;
        v = *(float *)(part + 0x110) * t + k * (1.0f - t);
        *(float *)(part + 0x110) = v;
        *(float *)(part + 0x114) = v;
        *(float *)(part + 0x118) = v;
        *(int *)(*(char **)(s0 + 0x700) + 0x250) |= 0x40000;
        return;
    }
}
