/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void func_001268F0(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);
extern int D_00747A24;
extern void cSnd_DieDemoStart(void *a0);
extern void func_0012C348(void *a0, int a1);

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_00115C00")))
void func_00115C00(void *a0)
{
    float va[4], vb[4], vc[4];
    cGameObj *s1 = a0;
    float one;
    float *s;

    VU0_SQC2_VF0(FRAME, 0x30);
    VU0_SQC2_VF0(FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    s1->hitFlash = 5.0f;
    s1->objFlags = s1->objFlags | 0x10000;
    switch (s1->step) {
    case 0: {
        int t;
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        func_001268F0(s1);
        Obj0000_Clear_Fields_640_648_124E58(s1);
        s1->rot.y = *(float *)((char *)s1 + 0x670);
        t = *(int *)((char *)s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x8B0) + t, *(int *)(t + 0x8B4) + t, 0, 0.0f, 0, 0);
        s1->step += 1;
    }
    case 1: {
        func_00124EC0(s1);
        *(int *)((char *)s1 + 0x15F4) |= 0x2080;
        cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
        s1->motionFlags |= 8;
        if (moveMotion(s1) != 0) {
            D_00747A24 |= 8;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        if (s1->seqFlags & 0x10) {
            float *pa = va;
            float *pb;
            s = *(float **)((char *)s1 + 0xF0);
            if (pa != s) {
                va[0] = s[0];
                pa[1] = s[1];
                pa[2] = s[2];
            }
            s = *(float **)((char *)s1 + 0xF0);
            pb = vb;
            if (pb != s) {
                vb[0] = s[0];
                vb[1] = s[1];
                vb[2] = s[2];
            }
            va[1] = va[1] + 0.5f;
            vb[1] = vb[1] - one;
            if (ChkLine(pa, pb, vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                int m1 = ~0x80;
                int m2 = ~0x2000;
                (*(float **)((char *)s1 + 0xF0))[1] = vc[1];
                s1->step = 2;
                *(int *)((char *)s1 + 0x15F4) = *(int *)((char *)s1 + 0x15F4) & m1 & m2;
                cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 1);
                s1->seqFlags &= 0xFFFB;
            }
        }
        if (s1->seqFlags & 1) {
            s1->hp = 0;
            cSnd_DieDemoStart(&D_005FEE00);
            func_0012C348(s1, 2);
        }
        break;
    }
    case 2: {
        int t = *(int *)((char *)s1 + 0x304);
        int p1 = *(int *)(t + 0x8D0) + t;
        int p2 = *(int *)(t + 0x8D4) + t;
        SetEffectParts(0, 0x2D, s1, 0, 0.0f, 0.0f, 0.0f, 1.0f, -1);
        func_002A8578(s1, p1, p2, 0, 0.0f, 0, 0);
        s1->step += 1;
    }
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 1, 0);
            s1->mode = 0;
            s1->phase = 0;
            s1->step = 0;
            s1->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
}
