/* sn-2.95.3-136 matched TU. */

extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(void *a0);
extern void Obj293_SetByte_53D_2(void *a0);
extern void MaxByte538_292EF0(void *a0, int a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void ShiftDownBytesA8_FAC00(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void cCoreSave_setGameLevel(void *a0, int a1);
extern char D_005864F0[];
extern int D_00569B70;
extern int Forward30F348_31CFE0(void);
extern int cEmManage_SetEmAnger(void *a0, void *a1, float f12, float f13, float f14);
extern int cCoreSave_getGameLevel(void *a0);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern int D_005CB000;
extern unsigned int D_00747A78;
extern unsigned int D_00747A80;
extern int D_003C2F84;
extern char D_00747470[];
extern int D_005FEE00;
extern int D_005FEA60;
extern void cScenario_startSoftEvent(int a0, int a1);
extern void cScenario__endSoftEvent(int a0);
extern void cTaskWork_exit(int a0);
extern void classFADE_start(void *p, int b, int c, int d, int e, unsigned int f, int g);
extern void classFADE_kill(void *p);
extern void SetFieldsCESignalSemaSleep_2D5AA0(void *p, int a);
extern void func_001E97B0(void *p);
extern void func_001EA1A8(void *p);
extern void func_001E9E40(void *p);
extern void func_002D14F8(void *p, float f);
extern void cSceAtManager_SetEnable_2C2950(void *p, int a);

/* sn-2.95.3-136 matched TU. */




















__attribute__((section(".text.func_00113F68")))
void func_00113F68(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    Obj293_SetByte_53C_2(D_005864F0);
    MaxByte538_292EF0(D_005864F0, 2);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        func_00129578(s1);
        ShiftDownBytesA8_FAC00(&D_00569B70);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x604) + t, *(int *)(t + 0x608) + t,
                      0.0f, 3, 0, 0);
        *(int *)(s1 + 0x15B0) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x200) != 0) {
            Obj293_SetByte_53D_2(D_005864F0);
        }
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            cCoreSave_setGameLevel(&D_00569B70, 0);
        }
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 0, 0);
    }
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"















__attribute__((section(".text.func_00114460")))
void func_00114460(void *a0)
{
    char *s0 = (char *)a0;
    float v[4] __attribute__((aligned(16)));

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int p1, p2;
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        if (Forward30F348_31CFE0() & 1) {
            p1 = *(int *)(*(char **)(s0 + 0x304) + 0x230) + *(int *)(s0 + 0x304);
            p2 = *(int *)(*(char **)(s0 + 0x304) + 0x234) + *(int *)(s0 + 0x304);
        } else {
            p1 = *(int *)(*(char **)(s0 + 0x304) + 0x8A0) + *(int *)(s0 + 0x304);
            p2 = *(int *)(*(char **)(s0 + 0x304) + 0x8A4) + *(int *)(s0 + 0x304);
        }
        func_002A8578(s0, p1, p2, 0.0f, 3, 0, 0);
        *(short *)(s0 + 0x568) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0 && *(short *)(s0 + 0x568) != 0) {
            *(short *)(s0 + 0x568) = 0;
            VU0_LQC2(4, *(char **)(s0 + 0xF0), 0);
            VU0_SQC2(4, v, 0);
            if (cEmManage_SetEmAnger(D_005864F0, v, *(float *)(s0 + 0x104), 15.0f, 0.523598790f) != 0) {
                if (cCoreSave_getGameLevel(&D_00569B70) != 5) {
                    cHeatSys_AddHeatGage(&D_005CB000, 0, 12.0f);
                    cCoreSave_addGameLevelPoint(&D_00569B70, 0xFA);
                } else {
                    cHeatSys_AddHeatGage(&D_005CB000, 0, 6.0f);
                }
            }
        }
        break;
    }
    func_00123938(s0, 1);
}

/* sn-2.95.3-136 matched TU. */



















static __inline__ int FadeIsEnd(char *f)
{
    return (*(unsigned char *)(f + 0x1C) >> 2) & 1;
}

__attribute__((section(".text.func_001E9F68")))
void func_001E9F68(char *p)
{
    cScenario_startSoftEvent(D_003C2F84, 0);
    D_00747A78 = D_00747A78 & 0xFDFFFFFF;
    classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000, 0xF);
    while (!FadeIsEnd(D_00747470)) {
        SetFieldsCESignalSemaSleep_2D5AA0(*(void **)(D_003C2F84 + 0x20), 1);
    }
    func_001E97B0(p);
    D_00747A80 |= 0x4000000;
    D_00747A80 |= 0x2000000;
    D_00747A80 |= 0x40000000;
    D_00747A80 |= 0x80000000;
    D_00747A80 |= 0x200000;
    D_00747A80 |= 0x10000000;
    D_00747A80 |= 0x8000000;
    {
        long v = *(unsigned int *)(p + 0x54);
        if ((v & 1) == 0) {
            long w;
            do {
                func_001EA1A8(p);
                SetFieldsCESignalSemaSleep_2D5AA0(*(void **)(D_003C2F84 + 0x20), 1);
                w = *(unsigned int *)(p + 0x54);
            } while ((w & 1) == 0);
        }
    }
    D_00747A80 &= 0xFBFFFFFF;
    D_00747A80 &= 0xFDFFFFFF;
    D_00747A80 &= 0xBFFFFFFF;
    D_00747A80 &= 0x7FFFFFFF;
    D_00747A80 &= 0xFFDFFFFF;
    D_00747A80 &= 0xDFFFFFFF;
    D_00747A80 &= 0xEFFFFFFF;
    D_00747A80 &= 0xF7FFFFFF;
    func_001E9E40(p);
    classFADE_start(D_00747470, 0, 0xA, 0, 0xFF000000, 0, 0xF);
    while (!FadeIsEnd(D_00747470)) {
        SetFieldsCESignalSemaSleep_2D5AA0(*(void **)(D_003C2F84 + 0x20), 1);
    }
    func_002D14F8(&D_005FEE00, 20.0f);
    classFADE_kill(D_00747470);
    cSceAtManager_SetEnable_2C2950(&D_005FEA60, *(unsigned short *)(p + 0x1B0));
    cScenario__endSoftEvent(D_003C2F84);
    cTaskWork_exit(*(int *)(D_003C2F84 + 0x20));
}
