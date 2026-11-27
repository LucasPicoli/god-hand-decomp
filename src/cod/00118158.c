/* sn-2.95.3-136 matched TU. */

/* func_00118158, 1336 B, sn-2.95.3-136. Wave 2026-08-31 V2 b3 + nested Duff do{}while(0) opened inside case 3 before the state++ (label 0x00118508, 0 mod 8), case 3/1 tails as goto tail3, plain barrier at case 7 (next label 0x00118620, 0 mod 8), cross-block short f15. */
#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"

extern unsigned char D_005864F0[];
extern int D_007474A8;

extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_002DB7A8(void);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern float SetMotionStep(void *a0, float f);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f12);
extern void cObjBase_addNullSpeed(void *a0, float f12);

__attribute__((section(".text.func_00118158")))
void func_00118158(cGameObj *s1)
{
    float buf[4];
    char *s0;
    char *s2;
    char *p1;
    char *q1;
    short f15;

    s1->hitFlash = 5.0f;
    s1->objFlags |= 0x10000;
    s2 = *(char **)((char *)s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    s0 = (char *)&D_005864F0;
    cEmManage_SetPlCatched(s0);
    cEmManage_SetSlotWait(s0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x80000;
    switch (s1->step) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = 0.338200003f;
        buf[1] = 0.0f;
        buf[2] = -0.340299994f;
        buf[3] = 1.0f;
        func_001299F0(s1, s2, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s2, 0x3E, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        (s1->step)++;
        /* fallthrough */
    case 1:
        func_002DB7A8();
        if (s2 != 0) {
            char *p;
            char *q;

            q = s2 + 0x550;
            p = *(char **)((char *)s1 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            (s1->step)++;
        }
        goto tail3;
    case 2:
        cEm00_GetPlMotion(s2, 0x3F, 0.0f, 0.0f);
        s1->unk568 = 0x5A;
        (s1->step)++;
        *(int *)((char *)s1 + 0x15B0) = 0;
        *(int *)((char *)s1 + 0x15B4) = 0;
        *(int *)((char *)s1 + 0x15B8) = 0;
        /* fallthrough */
    case 3:
        func_002DB7A8();
        if (s2 != 0) {
            char *p;
            char *q;

            q = s2 + 0x550;
            p = *(char **)((char *)s1 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0x0, q);
        }
        if (s1->unk568 != 0) {
            s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
        }
        if (*(int *)((char *)s1 + 0x15B8) != 0) {
            *(int *)((char *)s1 + 0x15B8) = *(int *)((char *)s1 + 0x15B8) - 1;
        }
        *(int *)((char *)s1 + 0x15B0) = *(int *)((char *)s1 + 0x15B0) + 1;
        if ((D_007474A8 & 0xF0) != 0) {
            int lim;

            switch (*(int *)((char *)s1 + 0x15B4)) {
            case 0: default: lim = 0x3E7; break;
            case 1: lim = 6; break;
            case 2: lim = 5; break;
            case 3: lim = 4; break;
            case 4: lim = 3; break;
            case 5: lim = 2; break;
            }
            if (*(int *)((char *)s1 + 0x15B0) < lim) {
                *(int *)((char *)s1 + 0x15B4) = *(int *)((char *)s1 + 0x15B4) + 1;
            }
            if (lim < *(int *)((char *)s1 + 0x15B0)) {
                *(int *)((char *)s1 + 0x15B4) = *(int *)((char *)s1 + 0x15B4) - 1;
            }
            if (*(int *)((char *)s1 + 0x15B4) < 0) {
                *(int *)((char *)s1 + 0x15B4) = 0;
            }
            if (*(int *)((char *)s1 + 0x15B4) >= 5) {
                *(int *)((char *)s1 + 0x15B4) = 4;
            }
            *(int *)((char *)s1 + 0x15B0) = 0;
            *(int *)((char *)s1 + 0x15B8) = 0xA;
        } else {
            if (*(int *)((char *)s1 + 0x15B8) <= 0) {
                *(int *)((char *)s1 + 0x15B8) = 5;
                *(int *)((char *)s1 + 0x15B4) = *(int *)((char *)s1 + 0x15B4) - 1;
                if (*(int *)((char *)s1 + 0x15B4) < 0) {
                    *(int *)((char *)s1 + 0x15B4) = 0;
                }
            }
        }
        switch (*(int *)((char *)s1 + 0x15B4)) {
        case 0: default: s1->speedRate = 0.699999988f; break;
        case 1: s1->speedRate = 1.0f; break;
        case 2: s1->speedRate = 1.39999998f; break;
        case 3: s1->speedRate = 1.79999995f; break;
        case 4: s1->speedRate = 2.20000005f; break;
        }
        SetMotionStep(s1, s1->speedRate);
        func_00124EC0(s1);
        if (moveMotion(s1) == 0 || s1->unk568 > 0)
            goto tail3;
    
    
        (s1->step)++;
        goto tail3;
    case 4:
        cEm00_GetPlMotion(s2, 0x41, 0.0f, 0.0f);
        f15 = 0xF;
        *(short *)((char *)s1 + 0x56E) = f15;
        (s1->step)++;
        /* fallthrough */
    case 5:
        if (*(short *)((char *)s1 + 0x56E) == 0 || s2 == 0)
            goto join5;
        (*(short *)((char *)s1 + 0x56E))--;
        p1 = *(char **)((char *)s1 + 0xF0);
    
        q1 = (char *)s1 + 0x550;
        VU0_VADD_XYZ_IP(p1, 0x0, q1);
    join5:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 0, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
    tail3:
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 6:
        cEm00_GetPlMotion(s2, 0x40, 0.0f, 0.0f);
        f15 = 0xF;
        *(short *)((char *)s1 + 0x56E) = f15;
        (s1->step)++;
        /* fallthrough */
    case 7:
        if (*(short *)((char *)s1 + 0x56E) != 0) {
            if (s2 != 0) {
                char *p;
                char *q;

                *(short *)((char *)s1 + 0x56E) = *(unsigned short *)((char *)s1 + 0x56E) - 1;
                p = *(char **)((char *)s1 + 0xF0);
                 
                q = (char *)s1 + 0x550;
                VU0_VADD_XYZ_IP(p, 0x0, q);
            }
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 0, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    default:
        break;
    }
}
