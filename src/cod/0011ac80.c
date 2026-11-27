/* sn-2.95.3-136 matched TU. */

extern void *Getplayer(void);
#include "godhand/cCollisionSolid.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_00262750(void *a0, int a1);

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"







__attribute__((section(".text.func_00239570")))
void func_00239570(void *a0)
{
    cGameObj *s0 = a0;
    char *s1 = (char *)Getplayer();
    float one;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s0, 0);
    switch (s0->step) {
    case 0:
    {
        int p;
        *(char *)((char *)s0 + 0x1864) = 0;
        p = *(int *)((char *)s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3B38) + p, *(int *)(p + 0x3B3C) + p,
                      0, 0.0f, 0, 0);
        *(short *)((char *)s0 + 0x56E) = 0xF;
        (s0->step)++;
    }
    case 1:
        if (*(short *)((char *)s0 + 0x56E) != 0) {
            char *q;
            int p0;
            (*(short *)((char *)s0 + 0x56E))--;
            q = s1 + 0x550;
            p0 = *(int *)((char *)s0 + 0xF0);
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        s0->hitFlash = 3.0f;
        if (moveMotion(s0) != 0) {
            s0->mode = 0; s0->phase = 0x6C;
            s0->step = 0; s0->stepArg = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s0, one);
        cObjBase_addNullSpeed(s0, one);
        break;
    }
}

__attribute__((section(".text.func_0011AC80")))
void func_0011AC80(void *a0)
{
    cGameObj *s1 = a0;
    float one;
    switch (s1->step) {
    case 0: {
        char *v0 = s1->pack;
        int p1 = *(int *)(v0 + 0x878) + (int)v0;
        int p2 = *(int *)(v0 + 0x87C) + (int)v0;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, a0, 0, 0, 0, 0);
        s1->hitFlash = 10.0f;
        func_002A8578(s1, p1, p2, 1, 0.0f, 0, 0);
        pl00_clearMotionCam(s1, 0, 0);
        func_0012C348(s1, 0);
        if (irand() & 1) {
            CallWithAndClearField698_12AC28(s1);
            func_0012B928(s1);
        }
        s1->step += 1;
    }
    case 1:
        if (moveMotion(s1) != 0) {
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
    func_00123938(s1, 1);
}

__attribute__((section(".text.func_0023A950")))
void func_0023A950(void *a0)
{
    cObjBase *s0 = a0;
    float one;
    *(int *)((char *)s0 + 0x16D0) = *(int *)((char *)s0 + 0x16D0) | 0x400;
    switch (s0->step) {
    case 0: {
        int p1, p2;
        int m = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        switch (s0->stepArg) {
        case 0:
        default:
            switch (irand() % 3) {
            case 0:
            default: {
                char *v = s0->pack;
                p1 = *(int *)(v + 0xC00) + (int)v;
                p2 = *(int *)(v + 0xC04) + (int)v;
                break; }
            case 1: {
                char *v = s0->pack;
                p1 = *(int *)(v + 0xC18) + (int)v;
                p2 = *(int *)(v + 0xC1C) + (int)v;
                break; }
            case 2: {
                char *v = s0->pack;
                p1 = *(int *)(v + 0xC20) + (int)v;
                p2 = *(int *)(v + 0xC24) + (int)v;
                break; }
            }
            break;
        case 1: {
            char *v = s0->pack;
            p1 = *(int *)(v + 0xC20) + (int)v;
            p2 = *(int *)(v + 0xC24) + (int)v;
            break; }
        case 2: {
            char *v = s0->pack;
            p1 = *(int *)(v + 0xC20) + (int)v;
            p2 = *(int *)(v + 0xC28) + (int)v;
            break; }
        }
        func_002A8578(s0, p1, p2, 3, 0.0f, m, 0);
        s0->step += 1;
    }
    case 1:
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        } else {
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(s0, one);
            cObjBase_addNullSpeed(s0, one);
        }
        break;
    }
    if (s0->seqFlags & 1) {
        func_00262750(s0, 0);
    }
}
