/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int cDamageUnit_SetDamageCollActive(void *a0, int a1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern unsigned char D_005FEE00[];
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Forward30F348_31CFE0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f);
extern void Obj2810_SetState_8_a1(char *a0, int a1);
extern void SetBytes2F4Mode7_283270(char *a0, char a1);
extern void ClearBytes2F4To2F7_283170(void *a0);
extern void func_0026DB00(void *a0, int a1, int a2);

__attribute__((section(".text.func_0025FCF8")))
void func_0025FCF8(void *a0)
{
    char *s1 = (char *)a0;
    void *s0;
    int p;
    int nb;
    int b;
    int o;
    float one;

    p = *(int *)(s1 + 0x214);
    s0 = (*(void *(**)(void *))(p + 0xB4))(s1 + *(short *)(p + 0xB0));
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        o = *(int *)(b + 0x108C) + b;
        func_002A8578(s1, o, o, 0.0f, 3, nb, 0);
        cDamageUnit_SetDamageCollActive(s0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)(Obj0000_Get_Field_424_1595F0(s1) + 8),
                           s1, 0, 0, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F4) = 2;
            *(unsigned char *)(s1 + 0x2F5) = 2;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        } else {
            one = 1.0f;
            AddScaledVecToField_100_14F9F0(s1, one);
            AddScaledXfmVecToField_F0_14F928(s1, one);
        }
        break;
    }
    *(unsigned short *)(s1 + 0x3AC) = *(unsigned short *)(s1 + 0x3AC) | 0x400;
}

__attribute__((section(".text.func_0024B218")))
void func_0024B218(void *a0)
{
    char *s0 = (char *)a0;
    float one;

    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x30400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int t0, b, b2, a1v, a2v;
        *(unsigned char *)(s0 + 0x1864) = 0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        a1v = *(int *)(b + 0x3DA4) + b;
        a2v = *(int *)(b + 0x3DA8) + b;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            b2 = *(int *)(s0 + 0x304);
            a2v = *(int *)(b2 + 0x3DAC) + b2;
            if (*(int *)(s0 + 0x748) != 0) Obj2810_SetState_8_a1(*(char **)(s0 + 0x748), 1);
            if (*(int *)(s0 + 0x74C) != 0) SetBytes2F4Mode7_283270(*(char **)(s0 + 0x74C), 1);
            if (*(int *)(s0 + 0x750) != 0) ClearBytes2F4To2F7_283170(*(char **)(s0 + 0x750));
        } else {
            if (*(int *)(s0 + 0x748) != 0) Obj2810_SetState_8_a1(*(char **)(s0 + 0x748), 0);
            if (*(int *)(s0 + 0x74C) != 0) SetBytes2F4Mode7_283270(*(char **)(s0 + 0x74C), 0);
            if (*(int *)(s0 + 0x750) != 0) ClearBytes2F4To2F7_283170(*(char **)(s0 + 0x750));
        }
        func_002A8578(s0, a1v, a2v, 0.0f, 0xA, t0, 0);
    }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0xA1;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        func_0026DB00(s0, 4, 0);
    }
}
