/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern int cHeatSys_SubHeatGage(void *a0, int a1, float f12);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern char D_005864F0[];
extern char D_005CB000[];

/* sn-2.95.3-136 matched TU. */






















#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.func_0011C988")))
void func_0011C988(void *a0)
{
    cGameObj *s1 = a0;
    char *s2;
    float v[4] __attribute__((aligned(16)));

    s1->hitFlash = 5.0f;
    s1->objFlags |= 0x10000;
    s2 = *(char **)((char *)s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (s1->step) {
    case 0: {
        float z;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0822f;
        v[2] = 0.0009f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 0, z);
        cEm00_GetPlMotion(s2, 0xB, z, z);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            *(float *)((char *)s1 + 0x15C0) = 0.1f;
        case 2:
            *(float *)((char *)s1 + 0x15C0) = 0.2f;
        case 3:
            *(float *)((char *)s1 + 0x15C0) = 0.5f;
        case 4:
            *(float *)((char *)s1 + 0x15C0) = 0.5f;
        case 5:
            *(float *)((char *)s1 + 0x15C0) = 1.0f;
        }
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        *(int *)((char *)s1 + 0x15B0) = 0xA;
        *(short *)((char *)s1 + 0x56E) = 0xF;
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 1: {
        char *q = s2 + 0x550;
        char *p = *(char **)((char *)s1 + 0xF0);
        VU0_VADD_XYZ_IP(p, 0, q);
        func_00124EC0(s1);
        if (moveMotion(s1))
            s1->step = s1->step + 1;
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    case 2: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0822f;
        v[2] = 0.0009f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 0, z);
        cEm00_GetPlMotion(s2, 0xC, z, z);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1:
            *(float *)((char *)s1 + 0x15C0) = 0.1f;
        case 2:
            *(float *)((char *)s1 + 0x15C0) = 0.2f;
        case 3:
            *(float *)((char *)s1 + 0x15C0) = 0.5f;
        case 4:
            *(float *)((char *)s1 + 0x15C0) = 0.5f;
        case 5:
            *(float *)((char *)s1 + 0x15C0) = 1.0f;
        }
        *(int *)((char *)s1 + 0x15B0) = 0xA;
        *(short *)((char *)s1 + 0x56E) = 0xF;
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 3:
        if (*(short *)((char *)s1 + 0x56E) != 0 && s2 != 0) {
            char *p;
            char *q;
            *(short *)((char *)s1 + 0x56E) = *(unsigned short *)((char *)s1 + 0x56E) - 1;
            p = *(char **)((char *)s1 + 0xF0);
             
            q = s2 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(s1);
        moveMotion(s1);
        cHeatSys_SubHeatGage(D_005CB000, 0, *(float *)((char *)s1 + 0x15C0));
        if (*(int *)((char *)s1 + 0x15B0) != 0) {
            *(int *)((char *)s1 + 0x15B0) = *(int *)((char *)s1 + 0x15B0) - 1;
        } else {
            *(int *)((char *)s1 + 0x15B0) = 0xA;
            if (s2 != 0) {
                float t = *(float *)(s2 + 0x76C);
                func_0012C0F8(s1, (int)(t + t));
            }
            if (s1->hp <= 0)
                s1->hp = 1;
        }
        func_0012C348(s1, 4);
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 4: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = 0.1133f;
        v[2] = 0.7251f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 1, z);
        cEm00_GetPlMotion(s2, 0xD, 3.0f, z);
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 5:
        func_00124EC0(s1);
        *(short *)((char *)s1 + 0x434) = s1->motionFlags | 8;
        if (moveMotion(s1)) {
            pl00_clearMotionCam(s1, 0, 0);
            s1->mode = 0;
            s1->phase = 0;
            s1->step = 0;
            s1->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 6: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.1007f;
        v[2] = 0.3456f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 1, z);
        cEm00_GetPlMotion(s2, 0xE, 3.0f, z);
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 7:
        func_00124EC0(s1);
        if (moveMotion(s1)) {
            pl00_clearMotionCam(s1, 0, 0);
            s1->mode = 0;
            s1->phase = 0;
            s1->step = 0;
            s1->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    default:
        break;
    }
}
