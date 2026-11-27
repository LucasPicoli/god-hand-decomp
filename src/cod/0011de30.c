/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f12);
extern void cObjBase_addNullSpeed(void *a0, float f12);
extern void func_0012C348(void *a0, int a1);
extern void cSnd_DieDemoStart(void *a0);
extern unsigned int D_00747A24;
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */






















#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.func_0011DE30")))
void func_0011DE30(void *a0)
{
    cGameObj *s0 = a0;
    char *s1;

    s0->hitFlash = 5.0f;
    s1 = *(char **)((char *)s0 + 0x694);
    s0->objFlags = s0->objFlags | 0x10000;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (s0->step) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        buf[0] = 0.1473f;
        buf[1] = 0.0f;
        buf[2] = 1.406f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(s0, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x15, z, z);
        *(int *)((char *)s0 + 0x15B0) = 1;
        *(int *)((char *)s0 + 0x15B4) = 0;
        *(short *)((char *)s0 + 0x56E) = 0x3C;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        (s0->step)++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)((char *)s0 + 0x56E) != 0 && s1 != 0) {
            char *p;
            char *q;

            *(short *)((char *)s0 + 0x56E) = *(unsigned short *)((char *)s0 + 0x56E) - 1;
            p = *(char **)((char *)s0 + 0xF0);
             
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (s0->hp > 0) {
                pl00_clearMotionCam(s0, 0, 0);
                *(char *)((char *)s0 + 0x2F4) = 1;
                *(char *)((char *)s0 + 0x2F5) = 4;
                *(char *)((char *)s0 + 0x2F6) = 0;
                *(char *)((char *)s0 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        if (*(int *)((char *)s0 + 0x15B4) > 0)
            *(int *)((char *)s0 + 0x15B4) = *(int *)((char *)s0 + 0x15B4) - 1;
        if ((s0->seqFlags & 1) != 0
            && *(int *)((char *)s0 + 0x15B4) <= 0) {
            *(int *)((char *)s0 + 0x15B4) = 5;
            if (s1 != 0) {
                func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 10.0f));
                if (s0->hp < 2)
                    s0->hp = 1;
            }
            func_0012C348(s0, 2);
        }
        if ((s0->seqFlags & 2) != 0
            && *(int *)((char *)s0 + 0x15B0) != 0) {
            *(int *)((char *)s0 + 0x15B0) = 0;
            cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
            if (s1 != 0)
                func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 20.0f));
            if (s0->hp <= 0) {
                s0->hp = 0;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(short *)((char *)s0 + 0x434) = s0->motionFlags | 8;
            }
            func_0012C348(s0, 2);
        }
        break;
    case 2:
        cEm00_GetPlMotion(s1, 0x16, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        (s0->step)++;
        /* fallthrough */
    case 3:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (s0->hp <= 0)
                s0->hp = 1;
            pl00_clearMotionCam(s0, 1, 0);
            *(char *)((char *)s0 + 0x2F4) = 0;
            *(char *)((char *)s0 + 0x2F5) = 0;
            *(char *)((char *)s0 + 0x2F6) = 0;
            *(char *)((char *)s0 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    default:
        break;
    }
}
