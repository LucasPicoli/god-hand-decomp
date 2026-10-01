/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void Obj2810_SetState_9_a1(char *a0, int a1);
extern void SetBytes2F4Mode8_283288(char *a0, char a1);
extern void func_0026DB00(void *a0, int a1, int a2);

__attribute__((section(".text.func_0024B3D0")))
void func_0024B3D0(void *a0)
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
        a1v = *(int *)(b + 0x3DB0) + b;
        a2v = *(int *)(b + 0x3DB4) + b;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            b2 = *(int *)(s0 + 0x304);
            a2v = *(int *)(b2 + 0x3DB8) + b2;
            if (*(int *)(s0 + 0x748) != 0) Obj2810_SetState_9_a1(*(char **)(s0 + 0x748), 1);
            if (*(int *)(s0 + 0x74C) != 0) SetBytes2F4Mode8_283288(*(char **)(s0 + 0x74C), 1);
            if (*(int *)(s0 + 0x750) != 0) SetBytes2F4Mode8_283288(*(char **)(s0 + 0x750), 1);
        } else {
            if (*(int *)(s0 + 0x748) != 0) Obj2810_SetState_9_a1(*(char **)(s0 + 0x748), 0);
            if (*(int *)(s0 + 0x74C) != 0) SetBytes2F4Mode8_283288(*(char **)(s0 + 0x74C), 0);
            if (*(int *)(s0 + 0x750) != 0) SetBytes2F4Mode8_283288(*(char **)(s0 + 0x750), 0);
        }
        func_002A8578(s0, a1v, a2v, 0.0f, 0xA, t0, 0);
    }
        *(float *)(s0 + 0x600) = 30.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (0.0f < *(float *)(s0 + 0x600)) {
            *(float *)(s0 + 0x600) = *(float *)(s0 + 0x600) - *(float *)(s0 + 0x5A8);
            AddScaledDeltaToField_104_2A7498(s0, *(int *)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0), *(float *)(s0 + 0x5A8) * 0.0122718466f);
        }
        if (moveMotion(s0) != 0) {
            if (cCoreSave_getGameLevel(&D_00569B70) < 3 && (Forward30F348_31CFE0() & 1) != 0 && 64.0f < *(float *)(s0 + 0x618)) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                break;
            }
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
        func_0026DB00(s0, 3, 0);
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 2) {
        func_0026DB00(s0, 3, 1);
    }
}
