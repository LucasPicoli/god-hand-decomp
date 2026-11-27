/* sn-2.95.3-136 matched TU. */

/* func_0011D198 — 0x0011D198, 792 B — sn-2.95.3-136.
 * +0x2F6 phase machine, 0x694 object family; template src/cod/0011c348.c
 * (func_0011C348, jaccard 1.00). */
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"

extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void func_00124EC0(void *a0);
extern int  moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void cSnd_DieDemoStart(void *a0);
extern int  D_00747A24;
extern char D_005864F0[];

__attribute__((section(".text.func_0011D198")))
void func_0011D198(void *a0)
{
    cGameObj *s1 = a0;
    char *s0;
    char *p;
    char *q;

    s1->hitFlash = 5.0f;
    s1->objFlags |= 0x10000;
    s0 = *(char **)((char *)s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (s1->step) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.4165f;
        buf[2] = 1.1225f;
        buf[3] = 1.0f;
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x10, z, z);
        *(short *)((char *)s1 + 0x56E) = 0xF;
        *(int *)((char *)s1 + 0x15B0) = 1;
        *(int *)((char *)s1 + 0x15B4) = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        (s1->step)++;
    }
        /* fallthrough */
    
    
    case 1:
        if (*(short *)((char *)s1 + 0x56E) == 0 || s0 == 0)
            goto join;
        (*(short *)((char *)s1 + 0x56E))--;
        p = *(char **)((char *)s1 + 0xF0);
    
        q = s0 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (s1->hp > 0) {
                pl00_clearMotionCam(s1, 0, 0);
                *(char *)((char *)s1 + 0x2F4) = 1;
                *(char *)((char *)s1 + 0x2F5) = 4;
                *(char *)((char *)s1 + 0x2F6) = 0;
                *(char *)((char *)s1 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        if ((s1->seqFlags & 1) != 0) {
            if (*(int *)((char *)s1 + 0x15B0) != 0) {
                *(int *)((char *)s1 + 0x15B0) = 0;
                if (s0 != 0) {
                    func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 8.0f));
                }
                func_0012C348(s1, 0);
            }
        } else {
            *(int *)((char *)s1 + 0x15B0) = 1;
        }
        if ((s1->seqFlags & 2) != 0) {
            if (*(int *)((char *)s1 + 0x15B4) != 0) {
                *(int *)((char *)s1 + 0x15B4) = 0;
                if (s0 != 0) {
                    func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 16.0f));
                }
                if (s1->hp <= 0) {
                    cSnd *g = &D_005FEE00;

                    s1->hp = 0;
                    cSnd_SeCall_2CBA48(g, 0, 0xD6, a0, 0, 0, 0, 0);
                    cSnd_DieDemoStart(g);
                    cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                    s1->motionFlags |= 8;
                } else {
                    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, a0, 0, 0, 0, 0);
                }
                func_0012C348(s1, 2);
            }
        } else {
            *(int *)((char *)s1 + 0x15B4) = 1;
        }
        break;
    default:
        break;
    }
}
