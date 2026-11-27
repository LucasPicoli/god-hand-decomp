/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"

/* func_0010EE80 — 0x0010EE80, 880 B — sn-2.95.3-136.
 * +0x2F6 phase machine; template src/cod/00111750.c. */

extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);

extern void func_00129578(void *a0);

extern void func_00124EC0(void *a0);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void func_00129630(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_0010A438(void *a0);

extern void cSnd_SeStop(void *a0, int a1);
extern int  D_00747A0C;
extern char D_005864F0[];

__attribute__((section(".text.func_0010EE80")))
void func_0010EE80(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x200;
    if (s1->step != 0 &&
        *(unsigned char *)((char *)s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)((char *)s1 + 0x649) = 1;
        cCoreSave_useGodItem(&D_00569B70);
    }
    switch (s1->step) {
    case 0:
    {
        int p, q;

        func_00129578(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        func_00124540(s1, 1);
        if (s1->stepArg != 0) {
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0xE6, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0xE6, 0xD, 0x1D, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0xC8, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0xC8, 0xD, 0x1D, 0, 0x123);
            }
            {
                int t = *(int *)((char *)s1 + 0x304);
                p = *(int *)(t + 0xD4) + t;
                q = *(int *)(t + 0xDC) + t;
            }
        } else {
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x64, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x64, 0xD, 0x1D, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x50, 0xD, 0x1D, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x50, 0xD, 0x1D, 0, 0x123);
            }
            {
                int t = *(int *)((char *)s1 + 0x304);
                p = *(int *)(t + 0xD4) + t;
                q = *(int *)(t + 0xD8) + t;
            }
        }
        *(char *)((char *)s1 + 0x1684) = 1;
        func_002A8578(s1, p, q, 3, 0.0f, 0, 0);
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        InvokeVirtualAtField214AndForward_124E68(s1, 0.13089969754219055f);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
            pl00_clearMotionCam(s1, 1, 0);
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    if ((s1->seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 1, 0);
    } else {
        if ((s1->seqFlags & 1) != 0) {
            cSnd *g = &D_005FEE00;
            cSnd_SeStop(g, *(int *)((char *)s1 + 0x161C));
            *(int *)((char *)s1 + 0x161C) = 0;
            g->flagsB0 &= 0xFFBFFFFF;
            g->flagsAC &= 0xFFBFFFFF;
        }
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}
