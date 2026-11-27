/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"

extern unsigned char D_005864F0[];
extern int D_00747A24;
extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void cSnd_DieDemoStart(void *a0);

/* sn-2.95.3-136 matched TU. */






















__attribute__((section(".text.func_001205D8")))
void func_001205D8(void *a0)
{
    cGameObj *s1 = a0;
    char *s0;
    float buf[4] __attribute__((aligned(16)));
    float v;

    s1->hitFlash = 5.0f;
    s1->objFlags = s1->objFlags | 0x10000;
    s0 = *(char **)((char *)s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(&D_005864F0);

    switch (s1->step) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = -0.1346f;
        buf[1] = 0.0f;
        buf[2] = 0.7623f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s0, buf, 0, v);
        cEm00_GetPlMotion(s0, 0x23, v, v);
        *(short *)((char *)s1 + 0x56E) = 0x3C;
        *(int *)((char *)s1 + 0x15B0) = 1;
        *(int *)((char *)s1 + 0x15B4) = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        s1->step = s1->step + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            s1->step = 4;
            if (s1->hp <= 0) {
                s1->hp = 1;
            }
            pl00_clearMotionCam(s1, 0, 0);
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if ((s1->seqFlags & 1) != 0 && *(int *)((char *)s1 + 0x15B4) != 0) {
            *(int *)((char *)s1 + 0x15B4) = 0;
            if (s0 != 0) {
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 5.0f));
            }
            func_0012C348(s1, 2);
        } else {
            *(int *)((char *)s1 + 0x15B4) = 1;
        }
        if ((s1->seqFlags & 2) != 0 && *(int *)((char *)s1 + 0x15B0) != 0) {
            *(int *)((char *)s1 + 0x15B0) = 0;
            if (s0 != 0) {
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 10.0f));
            }
            if (s1->hp <= 0) {
                s1->hp = 1;
                cSnd_DieDemoStart(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(short *)((char *)s1 + 0x434) = s1->motionFlags | 8;
            }
            func_0012C348(s1, 2);
        }
        if ((s1->seqFlags & 0x200) != 0 && s1->hp < 0xB) {
            s1->step = 2;
        }
        break;
    case 2:
        cEm00_GetPlMotion(s0, 0x25, 0.0f, 0.0f);
        s1->hp = 0;
        func_0012C348(s1, 2);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        cSnd_DieDemoStart(&D_005FEE00);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
        s1->step = s1->step + 1;
        /* fallthrough */
    case 3:
        *(short *)((char *)s1 + 0x434) = s1->motionFlags | 8;
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            D_00747A24 = D_00747A24 | 8;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 4:
        pl00_clearMotionCam(s1, 1, 0);
        cEm00_GetPlMotion(s0, 0x24, 0.0f, 0.0f);
        s1->step = s1->step + 1;
        /* fallthrough */
    case 5:
        if (moveMotion(s1) != 0) {
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
}
