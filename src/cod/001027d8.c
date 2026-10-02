/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern unsigned int func_0031ED08(float f12);
extern int setMotionInfo(void *a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void func_0028FB08(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int D_00462FC0;
extern char D_005FEE00[];
extern char *func_002DDAB0(void *a0, int a1, float f);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern int D_00747A78;
extern void *Getplayer(void);
extern float Adjust_theta(float f12);
extern void func_001034E0(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002705D8(void *a0);

__attribute__((section(".text.func_0014ED60")))
void func_0014ED60(void *a0)
{
    char *s0 = (char *)a0;
    float one;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        setMotionInfo(s0, *(int *)(s0 + 0x428), *(int *)(s0 + 0x42C),
                      func_0031ED08(*(float *)(s0 + 0x438)),
                      *(float *)(s0 + 0x440), *(float *)(s0 + 0x430),
                      *(unsigned short *)(s0 + 0x434));
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    case 2:
        moveMotion(s0);
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_00288B78")))
void func_00288B78(void *a0)
{
    char *s0 = (char *)a0;
    int v0;
    float one;

    cCollisionSolidManage_SetActive(&D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        func_0028FB08(s0);
        cCoreSave_addKillNpcNum(&D_00569B70);
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x130) + v0, *(int *)(v0 + 0x134) + v0, 0.0f, 5, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, 0x5F, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F7) = 0;
            *(unsigned char *)(s0 + 0x2F4) = 2;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 2;
        } else {
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s0, one);
            cObjBase_addNullSpeed(s0, one);
        }
        break;
    }
}

__attribute__((section(".text.func_00277B18")))
void func_00277B18(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    int v0;
    float one;

    s1 = func_002DDAB0(*(void **)(s0 + 0xF0), 0, 15.0f);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x14) + v0, *(int *)(v0 + 0x18) + v0, 0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (s1 != 0) {
            cGameObj_SetTgtTurn(s0, *(int *)(s1 + 0xF0),
                                             *(float *)(s0 + 0x5A8) * 0.39269909f);
            if (capVu0MagnitudeSqXZ(*(void **)(s1 + 0xF0), *(void **)(s0 + 0xF0)) < 0.25f) {
                *(unsigned char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 3;
                goto fin;
            }
        } else {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
        fin:
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        moveMotion(s0);
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_001027D8")))
void func_001027D8(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    char *v0;
    float one;
    float f;

    s1 = (char *)Getplayer();
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC) + (int)v0, *(int *)(v0 + 0x10) + (int)v0, 0.0f, 10, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (!(D_00747A78 & 0x2000000) && *(unsigned char *)(s1 + 0x61F) != 0) {
            f = *(float *)(s1 + 0x608) - 0.5235988f;
            if (f < 0.0f) {
                f = 0.0f;
            }
            f = f * 0.2f;
            if (0.06544985f < f) {
                f = 0.06544985f;
            }
            if (*(float *)(s1 + 0x604) < 0.0f) {
                f = -f;
            }
            *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + f;
            *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
        }
        one = 1.0f;
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
    func_001034E0(s0);
}

__attribute__((section(".text.func_00246370")))
void func_00246370(void *a0)
{
    char *s0 = (char *)a0;
    int s1, s2;
    int t0;
    float f, one;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        if (*(int *)(s0 + 0x564) == 0x256) {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2B84) + b;
            s1 = *(int *)(b + 0x2B88) + b;
        } else {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2C38) + b;
            s1 = *(int *)(b + 0x2C3C) + b;
        }
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 10, t0, 0);
        *(float *)(s0 + 0x600) = 30.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        f = *(float *)(s0 + 0x600);
        if (0.0f < f) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
            *(float *)(s0 + 0x600) = f - *(float *)(s0 + 0x5A8);
        }
        cGameObj_SetTgtTurn(s0, *(int *)((char *)Getplayer() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.19634955f);
        if (moveMotion(s0) != 0 || (*(unsigned short *)(s0 + 0x3AC) & 0x10) != 0) {
            func_002705D8(s0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_002461F0")))
void func_002461F0(void *a0)
{
    char *s0 = (char *)a0;
    int s1, s2;
    int t0;
    float f, one;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        if (*(int *)(s0 + 0x564) == 0x256) {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2B7C) + b;
            s1 = *(int *)(b + 0x2B80) + b;
            *(float *)(s0 + 0x600) = 45.0f;
        } else {
            int b = *(int *)(s0 + 0x304);
            s2 = *(int *)(b + 0x2C30) + b;
            s1 = *(int *)(b + 0x2C34) + b;
            *(float *)(s0 + 0x600) = 60.0f;
        }
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, s2, s1, 0.0f, 10, t0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        f = *(float *)(s0 + 0x600);
        if (0.0f < f) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
            *(float *)(s0 + 0x600) = f - *(float *)(s0 + 0x5A8);
        }
        cGameObj_SetTgtTurn(s0, *(int *)((char *)Getplayer() + 0xF0),
                                         *(float *)(s0 + 0x5A8) * 0.19634955f);
        if (moveMotion(s0) != 0 || (*(unsigned short *)(s0 + 0x3AC) & 0x10) != 0) {
            func_002705D8(s0);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}
