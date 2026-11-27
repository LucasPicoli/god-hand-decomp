/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern int D_00747A24;
extern void cEmManage_SetPlCatched(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void cSnd_DieDemoStart(void *a0);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"
























__attribute__((section(".text.func_00120E00")))
void func_00120E00(void *a0)
{
    cGameObj *s0 = a0;
    char *s1;
    float buf[4] __attribute__((aligned(16)));

    s0->hitFlash = 5.0f;
    s0->objFlags = s0->objFlags | 0x10000;
    s1 = *(char **)((char *)s0 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    switch (s0->step) {
    case 0: {
        float v;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, a0, 0, 0, 0, 0);
        if (s1 != 0)
            func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 30.0f));
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.07f;
        buf[2] = 1.0074f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, v);
        cEm00_GetPlMotion(s1, 0x28, v, v);
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        *(int *)((char *)s0 + 0x15B0) = 0x1E;
        *(short *)((char *)s0 + 0x56E) = 0xF;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 1:
        if (*(short *)((char *)s0 + 0x56E) != 0 && s1 != 0) {
            char *q = s1 + 0x550;
            char *p;
            *(short *)((char *)s0 + 0x56E) = *(unsigned short *)((char *)s0 + 0x56E) - 1;
            p = *(char **)((char *)s0 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(s0);
        if (moveMotion(s0))
            s0->step = s0->step + 1;
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 2: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.07f;
        buf[2] = 0.4842f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x29, v, v);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 3:
        func_00124EC0(s0);
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if ((s0->seqFlags & 1) && *(int *)((char *)s0 + 0x15B4) != 0) {
            *(int *)((char *)s0 + 0x15B4) = 0;
            if (s1 != 0)
                func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 30.0f));
        } else {
            *(int *)((char *)s0 + 0x15B4) = 1;
        }
        break;
    case 4: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.066f;
        buf[2] = 0.488f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x2B, v, v);
        *(int *)((char *)s0 + 0x15B0) = 0x28;
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 5:
        func_00124EC0(s0);
        if (*(int *)((char *)s0 + 0x15B0) != 0) {
            int t = *(int *)((char *)s0 + 0x15B0) - 1;
            *(int *)((char *)s0 + 0x15B0) = t;
            if (t <= 0) {
                s0->hp = 0;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(short *)((char *)s0 + 0x434) = s0->motionFlags | 8;
                func_0012C348(s0, 2);
                D_00747A24 |= 8;
            }
        }
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    case 6: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.066f;
        buf[2] = 0.488f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x2A, v, v);
        s0->step = s0->step + 1;
    }
    /* fallthrough */
    case 7:
        func_00124EC0(s0);
        if (moveMotion(s0)) {
            pl00_clearMotionCam(s0, 0, 0);
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (func_00123938(s0, 1)) {
            pl00_clearMotionCam(s0, 0, 0);
            s0->mode = 0;
            s0->phase = 0;
            s0->step = 0;
            s0->stepArg = 0;
        }
        break;
    default:
        break;
    }
}
