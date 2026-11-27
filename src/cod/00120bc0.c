/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/cGameObj.h"

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
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern unsigned int D_00747A24;
extern char D_005864F0[];
__attribute__((section(".text.func_00120BC0")))
void func_00120BC0(void *a0)
{
    cGameObj *s1 = a0;
    char *s0;
    float buf[4];
    s1->hitFlash = 5.0f;
    s0 = *(char **)((char *)s1 + 0x694);
    s1->objFlags = s1->objFlags | 0x10000;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (s1->step) {
    case 0:
    {
        float z;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        if (s0 != 0)
            func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 30.0f));
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        buf[1] = 0.0f;
        buf[0] = 0.0273f;
        buf[2] = 1.369f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x22, z, z);
        if (s1->hp <= 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD6, a0, 0, 0, 0, 0);
            func_0012C348(s1, 2);
        } else {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, a0, 0, 0, 0, 0);
            func_0012C348(s1, 2);
        }
        *(int *)((char *)s1 + 0x15B0) = 1;
        *(short *)((char *)s1 + 0x56E) = 0xF;
        (s1->step)++;
    }
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (s1->hp <= 0) {
                D_00747A24 |= 8;
            } else {
                pl00_clearMotionCam(s1, 0, 0);
                *(char *)((char *)s1 + 0x2F4) = 1;
                *(char *)((char *)s1 + 0x2F5) = 4;
                *(char *)((char *)s1 + 0x2F6) = 0;
                *(char *)((char *)s1 + 0x2F7) = 0;
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
}
