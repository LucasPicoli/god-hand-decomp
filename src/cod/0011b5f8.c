/* sn-2.95.3-136 matched TU. */

extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/cGameObj.h"
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_002DB770(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern char D_007474A0[];

__attribute__((section(".text.func_0011B5F8")))
void func_0011B5F8(void *a0)
{
    cGameObj *s1 = a0;
    char *g;
    char *h;

    switch (s1->step) {
    case 0: {
        int p1, p2;
        if (irand() & 1) {
            char *v0 = s1->pack;
            p1 = *(int *)(v0 + 0x148) + (int)v0;
            p2 = *(int *)(v0 + 0x14C) + (int)v0;
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, a0, 0, 0, 0, 0);
        } else {
            char *v1 = s1->pack;
            p1 = *(int *)(v1 + 0x150) + (int)v1;
            p2 = *(int *)(v1 + 0x154) + (int)v1;
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD0, a0, 0, 0, 0, 0);
        }
        pl00_clearMotionCam(s1, 0, 0);
        func_002A8578(s1, p1, p2, 1, 0.0f, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x8C, a0, 0, 0, 0, 0);
        func_0012C348(s1, 0);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        s1->unk568 = 0xF;
        *(int *)((char *)s1 + 0x15B0) = 0x96;
        s1->step += 1;
    }
        /* fallthrough */
    case 1: {
        float one;
        func_002DB770();
        g = D_007474A0;
        if (*(int *)(g + 8) & 0xF0) {
            *(int *)((char *)s1 + 0x15B0) -= 5;
        }
        if (*(int *)(g + 8) & 0xF00000) {
            *(int *)((char *)s1 + 0x15B0) -= 0x14;
        }
        if (moveMotion(s1) != 0) {
            s1->step = 2;
        }
        if (s1->unk568 != 0) {
            s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
        } else {
            s1->step = 2;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
    case 2: {
        char *v0 = s1->pack;
        func_002A8578(s1, *(int *)(v0 + 0x49C) + (int)v0, *(int *)(v0 + 0x4A0) + (int)v0, 0xA, 0.0f, 0, 0);
        s1->step += 1;
    }
        /* fallthrough */
    case 3: {
        float one;
        int t;
        func_002DB770();
        moveMotion(s1);
        t = *(int *)((char *)s1 + 0x15B0);
        h = D_007474A0;
        *(int *)((char *)s1 + 0x15B0) = t - 1;
        if (*(int *)(h + 8) & 0xF0) {
            *(int *)((char *)s1 + 0x15B0) = t - 6;
        }
        if (*(int *)(h + 8) & 0xF00000) {
            *(int *)((char *)s1 + 0x15B0) -= 0x14;
        }
        if (*(int *)((char *)s1 + 0x15B0) <= 0) {
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    }
    }
}
