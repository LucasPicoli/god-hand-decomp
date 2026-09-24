/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_00747A24;
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_0012C540(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern void cSnd_SeCall_2CB8A0(char *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void Obj293_SetByte_53B_3C(void *a0);
extern void func_00102418(void *a0);
extern int cCollisionSolidManage_ChkHit(void *a0, void *a1);
extern int ChkCollScrWall(void *a0, void *a1, int a2, void *a3, int t0, int t1, float f12);
extern int func_001329C0(void *a0, void *a1, int a2, void *a3, float f12);
extern void cObjBase_SetSeqEffect(void *a0);
extern void cModel_calcParts(void *a0);
extern void IK_InverseKinematics(void *a0, void *a1);
extern void cModel_calcWorldParts(void *a0);
extern int D_00747A78;
extern void cSnd_BattleBgmAllPause(void *a0, float f12);
extern void cSnd_BgmEventFade(void *a0, int a1, float f12, float f13, float f14);
extern void func_001F6A80(void *a0);
extern void func_001F6AF8(void *a0);
extern char D_007474A0[];
extern int *D_003BF0C0[];
extern int D_003BF0D0[];
extern void func_00294AD8(void *a0);
extern void func_00125F38(void *a0);
extern float SetField444SignedByFlag434_158288(void *a0, float f);
extern void func_00291D48(void *a0);
extern void func_00292F68(void *a0);

__attribute__((section(".text.func_00121798")))
void func_00121798(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;

    *(float *)(s0 + 0x54C) = 5.0f;
    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10000;
    s1 = *(char **)(s0 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        (*(float **)(s0 + 0xF0))[0] = 0.0f;
        (*(float **)(s0 + 0xF0))[2] = 0.0f;
        if (s1 != 0) {
            float *q = *(float **)(s1 + 0xF0);
            float *p = *(float **)(s0 + 0xF0);
            if (q != p) {
                q[0] = p[0];
                q[1] = p[1];
                q[2] = p[2];
            }
        }
        buf[1] = 0.0f;
        buf[0] = -0.128133342f;
        z = buf[1];
        buf[2] = 0.870266676f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x2E, z, z);
        *(int *)(s0 + 0x15B0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s0, 0, 0);
                *(char *)(s0 + 0x2F4) = 1;
                *(char *)(s0 + 0x2F5) = 4;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
            if (*(int *)(s0 + 0x15B0) != 0) {
                *(int *)(s0 + 0x15B0) = 0;
                cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
                if (s1 != 0)
                    func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 100.0f));
                if (*(short *)(s0 + 0x54A) <= 0) {
                    *(short *)(s0 + 0x54A) = 0;
                    OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
                    cCoreSave_addGameLevelPoint(D_00569B70, -0x3E8);
                    *(short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
                }
                func_0012C348(s0, 2);
            }
        } else {
            *(int *)(s0 + 0x15B0) = 1;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s1, 0x2F, 0.0f, 0.0f);
        *(int *)(s0 + 0x15B0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
        /* fallthrough */
    case 3:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            ClearField15F4Bit1_124F60(s0, 0, 0);
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}

__attribute__((section(".text.func_00102418")))
void func_00102418(void *a0)
{
    int frame[4];
    char *s1 = (char *)a0;
    char *s3;
    char *p;
    int n;
    char *s2;
    short k;

    s3 = Obj0000_Get_D_00747A94_2DB6B0();
    if ((*(int *)(s1 + 0x14B0) & 1) == 0)
        return;
    if (*(short *)(s3 + 0x54A) > 0 && *(unsigned char *)(s1 + 0x2F4) == 0 &&
        *(int *)(s1 + 0x14B4) <= 0) {
        func_0012C540(s3, 0);
        *(float *)(s1 + 0x54C) = 5.0f;
        return;
    }
    if ((*(int *)(s1 + 0x14B0) & 1) == 0)
        return;
    p = *(char **)(s1 + 0x5B0);
    if (p == 0)
        return;
    {
        long f = *(unsigned int *)(p + 0x60);
        if ((f & 1) == 0)
            return;
    }
    if (*(float *)(s1 + 0x54C) > 0.0f)
        return;
    n = *(int *)(p + 0x4C);
    s2 = *(char **)(p + 0x34);
    func_0012C0F8(s3, n);
    if (n > 0)
        cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
    {
        char *q = *(char **)(s1 + 0x5B0);
        int id = *(int *)(q + 0x40);
        int v = *(short *)(q + 0x44);

        if (id != -1)
            cSnd_SeCall_2CBA48(D_005FEE00, id, v, s1, 0, 0, 0, 0);
        else
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xA, s1, 0, 0, 0, 0);
    }
    switch (*(short *)(*(char **)(s1 + 0x5B0) + 0x46)) {
    default:
    {
        int cnt;
        char *obj;
        int idx;

        idx = 4;
        if ((frame[0] = cnt = *(unsigned char *)(s1 + 0x2B4)), (idx >= 0 && idx < cnt))
            obj = *(char **)(*(int *)(s1 + 0x278) + idx * 4);
        else
            obj = 0;
        if (obj != 0)
            SetEffectPos(0, 3, 0, *(void **)(obj + 0xF0), -1, 1.0f);
        break;
    }
    case 0x4A:
        SetEffect(0x58, 0x2A, 0, 0, -1, -1);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(D_005FEE00, 1, (short)(Obj0000_Get_Field_424_1595F0(s2) + 0x1F), -1, -1, 0, 0);
        break;
    case 0x4B:
        SetEffect(0xA8, 0xE, 0, 0, -1, -1);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(D_005FEE00, 1, (short)(Obj0000_Get_Field_424_1595F0(s2) + 0x1F), -1, -1, 0, 0);
        break;
    case 0x4C:
        SetEffect(0x63, 0xE, 0, 0, -1, -1);
        if (s2 != 0)
            cSnd_SeCall_2CB8A0(D_005FEE00, 1, (short)(Obj0000_Get_Field_424_1595F0(s2) + 0x1F), -1, -1, 0, 0);
        break;
    }
    *(float *)(s1 + 0x54C) = 5.0f;
    ClearField15F4Bit1_124F60(s3, 0, 0);
    k = *(short *)(*(char **)(s1 + 0x5B0) + 0x46);
    if (k == 0x48 || k == 0x52)
        Obj293_SetByte_53B_3C(D_005864F0);
    if (*(short *)(s3 + 0x54A) > 0) {
        *(char *)(s1 + 0x2F4) = 1;
        *(char *)(s1 + 0x2F5) = 0;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F7) = 0;
    } else {
        *(char *)(s1 + 0x2F4) = 2;
        *(char *)(s1 + 0x2F5) = 0;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F7) = 0;
    }
}

struct Entry_00102150 { short f0; short f2; short f4; short f6; };
struct Table_00102150 { struct Entry_00102150 e[1]; };
extern struct Table_00102150 D_003BC748;

#include "godhand/vu0.h"

__attribute__((section(".text.func_00102150")))
void func_00102150(void *a0)
{
    float buf[4];
    int w;
    unsigned short *hit;
    char *s1 = (char *)a0;
    char *s3;

    s3 = Obj0000_Get_D_00747A94_2DB6B0();
    if (D_00747A78 < 0)
        return;
    if (*(int *)(s1 + 0x14B4) != 0)
        *(int *)(s1 + 0x14B4) = *(int *)(s1 + 0x14B4) - 1;
    func_00102418(s1);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 1);
    *(int *)(s1 + 0x250) &= 0xFFFEFFFF;
    {
        char *e;
        int i8;
        int f0;
        int type; int arg; int (*fp)(int); long entry;

        i8 = *(unsigned char *)(s1 + 0x2F4) * 8;
        e = (char *)&D_003BC748 + i8;
        type = *(short *)(e + 2);
        if (type >= 0) {
            int base = *(int *)(s1 + *(short *)(e + 4));
            entry = *(long *)(base + type * 8 - 8);
            fp = (int (*)(int))(int)(entry >> 32);
        } else {
            fp = *(int (**)(int))((char *)&D_003BC748 + i8 + 4);
        }
        f0 = D_003BC748.e[*(unsigned char *)(s1 + 0x2F4)].f0;
        if (type >= 0)
            arg = (short)entry + f0;
        else
            arg = f0;
        fp((int)(s1 + arg));
    }
    cCollisionSolidManage_ChkHit(D_00462FC0, s1);
    if ((*(volatile int *)(s1 + 0x14B0) & 1) != 0) {
        VU0_SQC2_VF0(buf, 0);
        if (ChkCollScrWall(s1, buf, 0, &w, 0, 0, 0.400000006f) != 0) {
            (*(float **)(s1 + 0xF0))[0] = buf[0];
            (*(float **)(s1 + 0xF0))[2] = buf[2];
        }
    }
    if ((*(int *)(s1 + 0x14B0) & 1) != 0) {
        float y;

        *(int *)(s1 + 0x474) = 0;
        y = (*(float **)(s1 + 0xF0))[1];
        VU0_SQC2_VF0(buf, 0);
        if (func_001329C0(s1, buf, 0, &hit, 20.0f) != 0) {
            y = buf[1];
            *(int *)(s1 + 0x474) = *hit;
        }
        *(float *)(s1 + 0x5BC) = *(float *)(s1 + 0x5BC) - *(float *)(s1 + 0x5B8);
        (*(float **)(s1 + 0xF0))[1] = (*(float **)(s1 + 0xF0))[1] + *(float *)(s1 + 0x5BC);
        if ((*(float **)(s1 + 0xF0))[1] < y) {
            (*(float **)(s1 + 0xF0))[1] = y;
            *(float *)(s1 + 0x5BC) = 0.0f;
        }
    }
    cObjBase_SetSeqEffect(s1);
    cModel_calcParts(s1);
    IK_InverseKinematics(s1 + 0x448, s1);
    cModel_calcWorldParts(s1);
    {
        char *s = *(char **)(s1 + 0xF0);
        char *d = s1 + 0x490;

        if (d != s) {
            *(float *)(s1 + 0x490) = *(float *)(s + 0);
            *(float *)(d + 4) = *(float *)(s + 4);
            *(float *)(d + 8) = *(float *)(s + 8);
        }
    }
    if ((*(int *)(s1 + 0x14B0) & 1) != 0) {
        {
            float *d = *(float **)(s3 + 0xF0);
            float *s = *(float **)(s1 + 0xF0);

            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
        {
            char *d = s3 + 0x100;
            char *s = s1 + 0x100;

            if (d != s) {
                *(float *)(s3 + 0x100) = *(float *)(s1 + 0x100);
                *(float *)(d + 4) = *(float *)(s + 4);
                *(float *)(d + 8) = *(float *)(s + 8);
            }
        }
    }
}

__attribute__((section(".text.func_001F6208")))
void func_001F6208(void *a0)
{
    char *s0 = (char *)a0;
    char *pad = D_007474A0;
    long b;

    if (*(long *)(pad + 0x1A0) & 0x10000000) {
        if (*(int *)(s0 + 0x24) != D_003BF0C0[*(int *)(s0 + 0xC)][*(int *)(s0 + 0x20)]) {
            if (*(int *)(s0 + 0x24) == -2)
                cSnd_BattleBgmAllPause(D_005FEE00, 20.0f);
            cSnd_BgmEventFade(D_005FEE00, *(int *)(s0 + 0x24), 20.0f, 0.0f, -1.0f);
            *(char *)(s0 + 0x5) = 1;
            *(int *)(s0 + 0x8) = 10;
            *(int *)(s0 + 0x24) = D_003BF0C0[*(int *)(s0 + 0xC)][*(int *)(s0 + 0x20)];
        }
        return;
    }
    b = *(long *)(pad + 0x1B0);
    if (b & 0x8000000) {
        if (D_003BF0D0[*(int *)(s0 + 0xC)] >= 7) {
            if (*(int *)(s0 + 0x20) >= 6) {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) - 6;
            } else {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) + 6;
                if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
                    *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
            }
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x4000000) {
        if (D_003BF0D0[*(int *)(s0 + 0xC)] >= 7) {
            if (*(int *)(s0 + 0x20) >= 6) {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) - 6;
            } else {
                *(int *)(s0 + 0x20) = *(int *)(s0 + 0x20) + 6;
                if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
                    *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
            }
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x2000000) {
        int o = *(int *)(s0 + 0x20);
        int n = o + 1;

        *(int *)(s0 + 0x20) = n;
        if (n == 6 || n == D_003BF0D0[*(int *)(s0 + 0xC)]) {
            *(int *)(s0 + 0x20) = o;
            *(char *)(s0 + 0x1) = 2;
            *(char *)(s0 + 0x2) = 0;
            *(char *)(s0 + 0x3) = 0;
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x1000000) {
        int o = *(int *)(s0 + 0x20);
        int n = o - 1;

        *(int *)(s0 + 0x20) = n;
        if (n == -1 || n == 5) {
            *(int *)(s0 + 0x20) = o;
            *(char *)(s0 + 0x1) = 2;
            *(char *)(s0 + 0x2) = 0;
            *(char *)(s0 + 0x3) = 0;
        }
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x1000000000) {
        func_001F6A80(s0);
        if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
            *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    } else if (b & 0x10000000000) {
        func_001F6AF8(s0);
        if (D_003BF0D0[*(int *)(s0 + 0xC)] - 1 < *(int *)(s0 + 0x20))
            *(int *)(s0 + 0x20) = D_003BF0D0[*(int *)(s0 + 0xC)] - 1;
        cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
    }
}

#define DEC_W(o) if (*(int *)(s0 + (o)) != 0) *(int *)(s0 + (o)) = *(int *)(s0 + (o)) - 1
#define DEC_B(o) if (*(signed char *)(s0 + (o)) != 0) *(unsigned char *)(s0 + (o)) = *(unsigned char *)(s0 + (o)) - 1
#define CLR_DEAD(o) if (*(char **)(s0 + (o)) != 0 && *(int *)(*(char **)(s0 + (o)) + 0x250) < 0) *(char **)(s0 + (o)) = 0

__attribute__((section(".text.cEmManage_Main")))
void cEmManage_Main(void *a0)
{
    char *s0 = (char *)a0;
    char *n;
    unsigned int i;

    func_00294AD8(s0);
    if (D_00747A78 & 0x40000000)
        return;
    DEC_W(0x510);
    DEC_W(0x514);
    DEC_W(0x530);
    DEC_B(0x538);
    DEC_B(0x539);
    DEC_B(0x53A);
    DEC_B(0x53B);
    DEC_B(0x53C);
    DEC_B(0x53D);
    if (0.0f < *(float *)(s0 + 0x544))
        *(float *)(s0 + 0x544) = *(float *)(s0 + 0x544) - *(float *)(s0 + 0x548);
    DEC_B(0x540);
    DEC_B(0x541);
    if (*(short *)(s0 + 0x542) != 0)
        *(unsigned short *)(s0 + 0x542) = *(unsigned short *)(s0 + 0x542) - 1;
    CLR_DEAD(0x560);
    CLR_DEAD(0x564);
    CLR_DEAD(0x568);
    CLR_DEAD(0x56C);
    CLR_DEAD(0x570);
    CLR_DEAD(0x588);
    CLR_DEAD(0x58C);
    CLR_DEAD(0x590);
    CLR_DEAD(0x594);
    i = 0;
    {
        char **p2 = (char **)(s0 + 0x5AC);
        char **pp;

        for (; i < 5; i++) {
            pp = (char **)(s0 + 0x574) + i;
            if (*pp != 0 && (*(int *)(*pp + 0x250) & 0x80000000))
                *pp = 0;
        }
        for (i = 0, pp = p2; i < 2; i++, pp++) {
            if (*pp != 0 && (*(int *)(*pp + 0x250) & 0x80000000))
                *pp = 0;
        }
    }
    if (*(unsigned char *)(s0 + 0x5A3) == 3)
        *(char *)(s0 + 0x5A0) = 1;
    else
        *(char *)(s0 + 0x5A0) = 0;
    if (*(unsigned char *)(s0 + 0x5A4) == 3)
        *(char *)(s0 + 0x5A1) = 1;
    else
        *(char *)(s0 + 0x5A1) = 0;
    if (*(unsigned char *)(s0 + 0x5A5) != 0)
        *(char *)(s0 + 0x5A2) = 1;
    else
        *(char *)(s0 + 0x5A2) = 0;
    if (*(int *)(s0 + 0x560) == 0 || *(int *)(s0 + 0x564) == 0) {
        *(char *)(s0 + 0x5A0) = 0;
        *(char *)(s0 + 0x5A1) = 0;
        *(char *)(s0 + 0x5A2) = 0;
    }
    func_00125F38(Obj0000_Get_D_00747A94_2DB6B0());
    n = *(char **)(s0 + 0x500);
    if (n != 0) {
        char *g = D_007474A0;

        for (; n != 0; n = *(char **)(n + 4)) {
        char *e = *(char **)(n + 8);

        if (e != 0) {
            float v = *(float *)(s0 + 0x548) * *(float *)(g + 0x574);

            *(float *)(e + 0x5A8) = v;
            SetField444SignedByFlag434_158288(e, v);
        }
        }
    }
    *(float *)(s0 + 0x548) = 1.0f;
    func_00291D48(s0);
    func_00292F68(s0);
}
