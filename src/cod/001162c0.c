/* sn-2.95.3-136 matched TU. */

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/cCamera.h"
#include "godhand/cGameObj.h"
extern int moveMotion(void *a0);
extern void func_00124EC0(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void func_002DB7A8(void);
extern float SetMotionStep(void *a0, float f12);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cSnd_DieDemoStart(void *a0);
extern void func_0012C348(void *a0, int a1);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern char D_005864F0[];
extern int D_007474A8;
extern int D_00747A24;

/* sn-2.95.3-136 matched TU. */


























__attribute__((section(".text.func_001162C0")))
void func_001162C0(void *a0) {
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    *(int *)((char *)s1 + 0x15F4) = *(int *)((char *)s1 + 0x15F4) | 0x200;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    switch (s1->step) {
    case 0: {
        int b;

        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        b = *(int *)((char *)s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x8E0) + b, *(int *)(b + 0x8E4) + b,
                      0, 0.0f, 0, 0);
        moveMotion(s1);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xF5, a0, 0, 0, 0, 0);
        s1->step = s1->step + 1;
    }
        /* fallthrough */
    case 1: {
        float r = Turn_dest((float *)((char *)s1 + 0x580), s1->rot.y,
                            *(float **)((char *)s1 + 0xF0),
                            s1->speedRate * 0.39269909f);

        s1->rot.y = s1->rot.y + r;
        s1->rot.y = Adjust_theta(s1->rot.y);
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            s1->step = s1->step + 1;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        s1->nullSpeed.z = -0.1f;
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    case 2: {
        int b = *(int *)((char *)s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x8E8) + b, *(int *)(b + 0x8EC) + b,
                      0, 0.0f, 0, 0);
        s1->unk568 = 10;
        *(float *)((char *)s1 + 0x15C0) = 30.0f;
        s1->step = s1->step + 1;
        *(int *)((char *)s1 + 0x15B0) = 0;
        *(int *)((char *)s1 + 0x15B4) = 0;
        *(int *)((char *)s1 + 0x15B8) = 0;
    }
        /* fallthrough */
    case 3: {
        float rate;
        float mag;
        float mag2;
        float r;
        int lim;

        func_002DB7A8();
        if (*(int *)((char *)s1 + 0x15B8) != 0) {
            *(int *)((char *)s1 + 0x15B8) = *(int *)((char *)s1 + 0x15B8) - 1;
        }
        *(int *)((char *)s1 + 0x15B0) = *(int *)((char *)s1 + 0x15B0) + 1;
        if ((D_007474A8 & 0xF0) != 0) {
            switch (*(int *)((char *)s1 + 0x15B4)) {
            default:
            case 0: lim = 9; break;
            case 1: lim = 8; break;
            case 2: lim = 7; break;
            case 3: lim = 6; break;
            case 4: lim = 5; break;
            case 5: lim = 4; break;
            case 6: lim = 3; break;
            case 7: lim = 2; break;
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
            if (*(int *)((char *)s1 + 0x15B4) >= 8) {
                *(int *)((char *)s1 + 0x15B4) = 7;
            }
            *(int *)((char *)s1 + 0x15B0) = 0;
            *(int *)((char *)s1 + 0x15B8) = 10;
        } else if (*(int *)((char *)s1 + 0x15B8) <= 0) {
            *(int *)((char *)s1 + 0x15B8) = 5;
            *(int *)((char *)s1 + 0x15B4) = *(int *)((char *)s1 + 0x15B4) - 1;
            if (*(int *)((char *)s1 + 0x15B4) < 0) {
                *(int *)((char *)s1 + 0x15B4) = 0;
            }
        }
        switch (*(int *)((char *)s1 + 0x15B4)) {
        default:
        case 0: s1->speedRate = 1.0f; break;
        case 1: s1->speedRate = 1.2f; break;
        case 2: s1->speedRate = 1.4f; break;
        case 3: s1->speedRate = 1.6f; break;
        case 4: s1->speedRate = 1.8f; break;
        case 5: s1->speedRate = 2.0f; break;
        case 6: s1->speedRate = 2.2f; break;
        case 7: s1->speedRate = 2.5f; break;
        }
        SetMotionStep(s1, s1->speedRate);
        rate = (s1->speedRate - 1.5f) * 0.1f;
        mag = capVu0MagnitudeSqXZ(*(void **)((char *)s1 + 0xF0), (char *)s1 + 0x580);
        if (mag < 0.09f) {
            if (rate < 0.0f) {
                rate = 0.0f;
            }
        }
        r = Turn_dest((float *)((char *)s1 + 0x580), s1->rot.y,
                      *(float **)((char *)s1 + 0xF0),
                      s1->speedRate * 0.39269909f);
        s1->rot.y = s1->rot.y + r;
        s1->rot.y = Adjust_theta(s1->rot.y);
        func_00124EC0(s1);
        moveMotion(s1);
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        s1->nullSpeed.z = rate;
        cObjBase_addNullSpeed(s1, 1.0f);
        if (0.0f < *(float *)((char *)s1 + 0x15C0)) {
            *(float *)((char *)s1 + 0x15C0) =
                *(float *)((char *)s1 + 0x15C0) - s1->speedRate;
        }
        mag2 = capVu0MagnitudeSqXZ(*(void **)((char *)s1 + 0xF0), (char *)s1 + 0x580);
        if (mag2 < 0.25f) {
            if (*(float *)((char *)s1 + 0x15C0) <= 0.0f) {
                s1->step = 4;
                break;
            }
        }
        if (s1->unk590.z * s1->unk590.z < mag2) {
            s1->step = 6;
            break;
        }
        s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
        if (s1->unk568 <= 0) {
            s1->unk568 = 10;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xF6, a0, 0, 0, 0, 0);
        }
        break;
    }
    case 4: {
        int b = *(int *)((char *)s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x8F8) + b, *(int *)(b + 0x8FC) + b,
                      0, 0.0f, 0, 0);
        cSnd_DieDemoStart(&D_005FEE00);
        func_0012C348(s1, 2);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xF7, a0, 0, 0, 0, 0);
        s1->step = s1->step + 1;
    }
        /* fallthrough */
    case 5:
        s1->motionFlags = s1->motionFlags | 8;
        if (moveMotion(s1) != 0) {
            s1->hp = 0;
            D_00747A24 = D_00747A24 | 8;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 6: {
        int b = *(int *)((char *)s1 + 0x304);

        func_002A8578(s1, *(int *)(b + 0x8F0) + b, *(int *)(b + 0x8F4) + b,
                      0, 0.0f, 0, 0);
        s1->step = s1->step + 1;
    }
        /* fallthrough */
    case 7:
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 1, 0);
            s1->mode = 0;
            s1->phase = 0;
            s1->step = 0;
            s1->stepArg = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
}
