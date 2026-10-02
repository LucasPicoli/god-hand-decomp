/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void func_0028FB08(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern unsigned char D_005FEE00[];
extern int D_00462FC0;
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00126770(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern void func_0012A8D8(void *a0);

__attribute__((section(".text.func_0028A9E8")))
void func_0028A9E8(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    cCollisionSolidManage_SetActive(&D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int b;
        func_0028FB08(s0);
        cCoreSave_addKillNpcNum(&D_00569B70);
        if (*(int *)(s0 + 0x564) != 0x2A7 && *(int *)(s0 + 0x564) != 0x2AB) {
            b = *(int *)(s0 + 0x304);
            func_002A8578(s0, *(int *)(b + 0x70) + b, *(int *)(b + 0x74) + b, 0.0f, 5, 0, 0);
        }
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x98) + b, *(int *)(b + 0x9C) + b, 0.0f, 5, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x5F, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 2;
            *(unsigned char *)(s0 + 0x2F5) = 1;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        } else {
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s0, one);
            cObjBase_addNullSpeed(s0, one);
        }
        break;
    }
}

__attribute__((section(".text.func_00114CB8")))
void func_00114CB8(void *a0)
{
    char *s0 = (char *)a0;
    float one;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        char *v0;
        int p1, p2;
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        func_001268F0(s0);
        Obj0000_Clear_Fields_640_648_124E58(s0);
        func_00126770(s0);
        pl00_clearMotionCam(s0, 0, 0);
        v0 = *(char **)(s0 + 0x304);
        p1 = *(int *)(v0 + 0x3D8) + (int)v0;
        p2 = *(int *)(v0 + 0x3DC) + (int)v0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x29, s0, 0, 0, 0, 0);
        func_002A8578(s0, p1, p2, 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
    case 1:
        InvokeVirtualAtField214AndForward_124E68(s0, 0.19634954f);
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) && *(int *)(s0 + 0x698) == 0) {
        func_0012A8D8(s0);
    }
    func_00123938(s0, 1);
}
