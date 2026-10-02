/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void Obj2810_SetState_2_a1(char *a0, int a1);
extern void SetBytes2F4Mode2_2831B0(char *a0, char a1);
extern void ClearBytes2F4To2F7_283170(char *a0);
extern void func_0026DB00(void *a0, int a1, int a2);

__attribute__((section(".text.func_00249EF8")))
void func_00249EF8(void *a0)
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
        a1v = *(int *)(b + 0x3D64) + b;
        a2v = *(int *)(b + 0x3D68) + b;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            b2 = *(int *)(s0 + 0x304);
            a2v = *(int *)(b2 + 0x3D6C) + b2;
            if (*(int *)(s0 + 0x748) != 0) Obj2810_SetState_2_a1(*(char **)(s0 + 0x748), 1);
            if (*(int *)(s0 + 0x74C) != 0) SetBytes2F4Mode2_2831B0(*(char **)(s0 + 0x74C), 1);
            if (*(int *)(s0 + 0x750) != 0) ClearBytes2F4To2F7_283170(*(char **)(s0 + 0x750));
        } else {
            if (*(int *)(s0 + 0x748) != 0) Obj2810_SetState_2_a1(*(char **)(s0 + 0x748), 0);
            if (*(int *)(s0 + 0x74C) != 0) SetBytes2F4Mode2_2831B0(*(char **)(s0 + 0x74C), 0);
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
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        func_0026DB00(s0, 2, 0);
    }
}
