/* sn-2.95.3-136 matched TU. */

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

#include "godhand/cCollisionSolid.h"
#include "godhand/effectPos.h"
#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cGameObj.h"























__attribute__((section(".text.func_001179C8")))
void func_001179C8(cGameObj *s1)
{
    float buf[4];
    char *s0;
    char *s2;

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
    {
        float v;

        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.181799993f;
        buf[2] = 1.17859995f;
        buf[3] = 1.0f;
        func_001299F0(s1, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x3A, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        s1->unk56A = 1;
        (s1->step)++;
    }
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
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 2:
    {
        float v;

        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.233600006f;
        buf[2] = 1.21519995f;
        buf[3] = 1.0f;
        func_001299F0(s1, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x3B, v, v);
        s1->unk568 = 0x5A;
        (s1->step)++;
        *(int *)((char *)s1 + 0x15B0) = 0;
        *(int *)((char *)s1 + 0x15B4) = 0;
        *(int *)((char *)s1 + 0x15B8) = 0;
    }
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
        case 2: s1->speedRate = 1.29999995f; break;
        case 3: s1->speedRate = 1.60000002f; break;
        case 4: s1->speedRate = 2.0f; break;
        }
        SetMotionStep(s1, s1->speedRate);
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (s1->unk568 <= 0) {
                (s1->step)++;
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    case 4:
    {
        float v;

        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.254200011f;
        buf[2] = 1.16869998f;
        buf[3] = 1.0f;
        func_001299F0(s1, s2, buf, 1, v);
        cEm00_GetPlMotion(s2, 0x3C, v, v);
        *(short *)((char *)s1 + 0x56E) = 0xF;
        (s1->step)++;
    }
        /* fallthrough */
    case 5:
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
    if ((s1->seqFlags & 1) != 0) {
        if (s1->unk56A != 0) {
            int lo = 0x17;
            int b;
            unsigned char ok;
            char *e;

            ok = ((*(int *)buf = b = s1->partNum), (lo < b));
            if (ok) {
                e = *(char **)(*(int *)((char *)s1 + 0x278) + 0x5C);
            } else {
                e = 0;
            }
            if (e != 0) {
                SetEffectPos(0, 0x4F, 0, *(void **)(e + 0xF0), 1.0f, -1);
            }
            s1->unk56A = 0;
        } else {
            s1->unk56A = 1;
        }
    } else {
        s1->unk56A = 1;
    }
}
