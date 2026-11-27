/* sn-2.95.3-136 matched TU. */

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
extern void SetMotionStep(void *a0, float f12);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

__attribute__((section(".text.func_00119750")))
void func_00119750(void *a0)
{
    cGameObj *s1 = a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));

    s1->hitFlash = 5.0f;
    s1->objFlags = s1->objFlags | 0x10000;
    s2 = *(char **)((char *)s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) = *(int *)((char *)s1 + 0x15F4) | 0x80000;
    switch (s1->step) {
    case 0: {
        float v;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = 0.0085f;
        buf[2] = 3.0808f;
        buf[3] = 1.0f;
        func_001299F0(s1, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x4C, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        s1->unk56A = 1;
        s1->step = s1->step + 1;
    }
    /* fallthrough */
    case 1:
        func_002DB7A8();
        if (s2 != 0) {
            char *q = s2 + 0x550;
            char *p = *(char **)((char *)s1 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        func_00124EC0(s1);
        if (moveMotion(s1))
            s1->step = s1->step + 1;
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 2:
        cEm00_GetPlMotion(s2, 0x4D, 0.0f, 0.0f);
        s1->unk568 = 0x5A;
        *(int *)((char *)s1 + 0x15B0) = 0;
        s1->step = s1->step + 1;
        *(int *)((char *)s1 + 0x15B4) = 0;
        *(int *)((char *)s1 + 0x15B8) = 0;
    /* fallthrough */
    case 3:
        func_002DB7A8();
        if (s2 != 0) {
            char *q = s2 + 0x550;
            char *p = *(char **)((char *)s1 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (s1->unk568 != 0)
            s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
        if (*(int *)((char *)s1 + 0x15B8) != 0)
            *(int *)((char *)s1 + 0x15B8) = *(int *)((char *)s1 + 0x15B8) - 1;
        *(int *)((char *)s1 + 0x15B0) = *(int *)((char *)s1 + 0x15B0) + 1;
        if ((D_007474A8 & 0xF0) != 0) {
            int lim;
            switch (*(int *)((char *)s1 + 0x15B4)) {
            default:
            case 0:
                lim = 0x3E7;
                break;
            case 1:
                lim = 6;
                break;
            case 2:
                lim = 5;
                break;
            case 3:
                lim = 4;
                break;
            case 4:
                lim = 3;
                break;
            case 5:
                lim = 2;
                break;
            }
            if (*(int *)((char *)s1 + 0x15B0) < lim)
                *(int *)((char *)s1 + 0x15B4) = *(int *)((char *)s1 + 0x15B4) + 1;
            if (lim < *(int *)((char *)s1 + 0x15B0))
                *(int *)((char *)s1 + 0x15B4) = *(int *)((char *)s1 + 0x15B4) - 1;
            if (*(int *)((char *)s1 + 0x15B4) < 0)
                *(int *)((char *)s1 + 0x15B4) = 0;
            if (*(int *)((char *)s1 + 0x15B4) >= 5)
                *(int *)((char *)s1 + 0x15B4) = 4;
            *(int *)((char *)s1 + 0x15B0) = 0;
            *(int *)((char *)s1 + 0x15B8) = 0xA;
        } else if (*(int *)((char *)s1 + 0x15B8) <= 0) {
            int t;
            *(int *)((char *)s1 + 0x15B8) = 5;
            t = *(int *)((char *)s1 + 0x15B4) - 1;
            *(int *)((char *)s1 + 0x15B4) = t;
            if (t < 0)
                *(int *)((char *)s1 + 0x15B4) = 0;
        }
        switch (*(int *)((char *)s1 + 0x15B4)) {
        default:
        case 0:
            s1->speedRate = 0.7f;
            break;
        case 1:
            s1->speedRate = 1.0f;
            break;
        case 2:
            s1->speedRate = 1.5f;
            break;
        case 3:
            s1->speedRate = 2.0f;
            break;
        case 4:
            s1->speedRate = 2.5f;
            break;
        }
        SetMotionStep(s1, s1->speedRate);
        func_00124EC0(s1);
        if (moveMotion(s1) && s1->unk568 <= 0)
            s1->step = 4;
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 4:
        cEm00_GetPlMotion(s2, 0x4E, 0.0f, 0.0f);
        *(short *)((char *)s1 + 0x56E) = 0xF;
        s1->step = s1->step + 1;
    /* fallthrough */
    case 5:
        if (*(short *)((char *)s1 + 0x56E) != 0 && s2 != 0) {
            char *p;
            char *q;
            *(short *)((char *)s1 + 0x56E) = *(unsigned short *)((char *)s1 + 0x56E) - 1;
            p = *(char **)((char *)s1 + 0xF0);
            q = (char *)s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
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
