/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_0012C0F8(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void func_0012C348(void *a0, int a1);
extern int D_00747A24;
extern int D_00569B70;
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_005FEE00[];
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float a2);
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);
extern int Forward30F348_31CFE0(void);
extern void func_00129718(void *a0, void *a1, int a2);
extern char D_005CB000[];

/* sn-2.95.3-136 matched TU. */














extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4,
                               int a5, int a6, int a7);








#include "godhand/vu0.h"

__attribute__((section(".text.func_00121E88")))
void func_00121E88(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;

    *(float *)(s1 + 0x54C) = 5.0f;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    *(int *)(s1 + 0x250) |= 0x10000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        float buf[4];

        buf[0] = -0.416f;
        buf[1] = 0.0f;
        buf[2] = -0.4255f;
        buf[3] = 1.0f;
        func_001299F0(s1, s0, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s0, 0x32, 0.0f, 0.0f);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(int *)(s1 + 0x15B0) = 1;
        *(short *)(s1 + 0x56E) = 0xF;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s1 + 0x56E) != 0 && s0 != 0) {
            char *p;
            char *q;

            (*(short *)(s1 + 0x56E))--;
            p = *(char **)(s1 + 0xF0);
            do { } while (0);
            q = s0 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s1, 0, 0);
                *(char *)(s1 + 0x2F4) = 1;
                *(char *)(s1 + 0x2F5) = 4;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0
            && *(int *)(s1 + 0x15B0) != 0) {
            char *s2 = (char *)&D_00569B70;

            *(int *)(s1 + 0x15B0) = 0;
            cCoreSave_addGameLevelPoint(s2, -0x140);
            if (s0 != 0)
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 30.0f));
            if (*(short *)(s1 + 0x54A) <= 0) {
                char *g = D_005FEE00;

                *(short *)(s1 + 0x54A) = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, s1, 0, 0, 0, 0);
                OrChildField98AndSelfFieldB0AC_2CA718(g);
                cCoreSave_addGameLevelPoint(s2, -0x3E8);
                *(unsigned short *)(s1 + 0x434) |= 8;
            } else {
                cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD7, s1, 0, 0, 0, 0);
            }
            func_0012C348(s1, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */














extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4,
                               int a5, int a6, int a7);








#include "godhand/vu0.h"

__attribute__((section(".text.func_0011C348")))
void func_0011C348(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) |= 0x10000;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        float z;

        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.5068f;
        buf[2] = 0.1395f;
        buf[3] = 1.0f;
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 6, z, z);
        *(int *)(s1 + 0x15B0) = 1;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(short *)(s1 + 0x56E) = 0xF;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s1 + 0x56E) != 0 && s0 != 0) {
            char *p;
            char *q;

            (*(short *)(s1 + 0x56E))--;
            p = *(char **)(s1 + 0xF0);
            do { } while (0);
            q = s0 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s1, 0, 0);
                *(char *)(s1 + 0x2F4) = 1;
                *(char *)(s1 + 0x2F5) = 4;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0
            && *(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            if (*(int *)(s0 + 0x564) != 0x23B) {
                if (s0 != 0)
                    func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 50.0f));
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
            }
            if (*(short *)(s1 + 0x54A) <= 0) {
                char *g = D_005FEE00;

                *(short *)(s1 + 0x54A) = 0;
                cSnd_SeCall_2CBA48(g, 0, 0xD6, s1, 0, 0, 0, 0);
                OrChildField98AndSelfFieldB0AC_2CA718(g);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(unsigned short *)(s1 + 0x434) |= 8;
            } else {
                cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD7, s1, 0, 0, 0, 0);
            }
            func_0012C348(s1, 2);
        }
        break;
    default:
        break;
    }
}

/* sn-2.95.3-136 matched TU. */

















#include "godhand/vu0.h"

__attribute__((section(".text.func_0025BCC0")))
void func_0025BCC0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        char *vt;
        int (*fp)();
        short saved;
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        vt = *(char **)(s0 + 0x214);
        saved = *(short *)(s0 + 0x54A);
        fp = *(int (**)())(vt + 0xAC);
        fp(s0 + *(short *)(vt + 0xA8), 0x32, s1, 1, 0);
        if (*(short *)(s0 + 0x54A) <= 0) {
            p = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(p + 0x530) + p, *(int *)(p + 0x534) + p,
                          0.0f, 0, 0, 0);
            *(short *)(s0 + 0x568) = 1;
        } else {
            p = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(p + 0x528) + p, *(int *)(p + 0x52C) + p,
                          0.0f, 0, 0, 0);
            *(short *)(s0 + 0x568) = 0;
        }
        *(short *)(s0 + 0x54A) = saved;
        *(int *)(s0 + 0x5F0) = 0x2A;
        *(int *)(s0 + 0x5F4) = 1;
        *(short *)(s0 + 0x56E) = 0x1E;
        *(short *)(s0 + 0x56A) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
        *(int *)(s0 + 0x16EC) = 0;
    }
        /* fallthrough */
    case 1:
        if ((*(unsigned short *)(s0 + 0x3AC) & 8) == 0) {
            *(int *)(s0 + 0x16D0) |= 0x10000;
            *(float *)(*(char **)(s0 + 0xF0) + 4) =
                *(float *)(*(char **)(s1 + 0xF0) + 4)
                - (*(float *)(s0 + 0x114) - 1.0f) * 0.1f;
        }
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;

            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            do { } while (0);
            q = s1 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 2) != 0
            && *(int *)(s0 + 0x5F4) != 0) {
            char *vt;
            int (*fp)();

            vt = *(char **)(s0 + 0x214);
            *(int *)(s0 + 0x5F4) = 0;
            fp = *(int (**)())(vt + 0xAC);
            fp(s0 + *(short *)(vt + 0xA8), 0x32, s1, 1, 0);
            if (*(short *)(s0 + 0x568) != 0)
                *(short *)(s0 + 0x54A) = 0;
            cHeatSys_AddHeatGage(D_005CB000, 0, 10.0f);
        }
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) <= 0) {
                if ((*(int *)(s0 + 0x1644) & 0x800000) != 0) {
                    *(char *)(s0 + 0x2F4) = 2;
                    *(char *)(s0 + 0x2F5) = 3;
                    *(char *)(s0 + 0x2F6) = 0;
                    *(char *)(s0 + 0x2F7) = 0;
                    return;
                } else {
                    func_0025FE30(s0, 0x1000000, 0);
                    *(char *)(s0 + 0x2F4) = 2;
                    *(char *)(s0 + 0x2F5) = 2;
                    *(char *)(s0 + 0x2F6) = 0;
                    *(char *)(s0 + 0x2F7) = 0;
                }
            } else {
                func_00274FE8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s0 + 0x56A) != 0) {
            *(short *)(s0 + 0x56A) = *(unsigned short *)(s0 + 0x56A) - 1;
        } else {
            *(short *)(s0 + 0x56A) = 0x3E7;
            if (*(unsigned char *)(s0 + 0x186B) >= 5
                && *(unsigned char *)(s0 + 0x2F7) == 1
                && (Forward30F348_31CFE0() & 1) != 0) {
                unsigned char t = *(unsigned char *)(s0 + 0x2F7);

                *(char *)(s0 + 0x2F4) = 0;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F5) = 0x4D;
                *(char *)(s0 + 0x2F7) = t;
                func_00129718(s1, s0, 2);
            }
        }
        break;
    default:
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0)
        func_00262750(s0, 0);
}
