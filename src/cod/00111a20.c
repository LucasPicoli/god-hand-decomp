/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"

extern unsigned int irand(void);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void func_00126770(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void func_0010A438(void *a0);
extern void func_0012BC00(void *a0, int a1, int a2);
extern char D_005864F0[];
extern void cSnd_SeStop(void *a0, int a1);
extern int D_00747A0C;
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

__attribute__((section(".text.func_0011B900")))
void func_0011B900(void *a0)
{
    cGameObj *s1 = a0;
    float one;

    switch (s1->step) {
    case 0: {
        int p1, p2;
        switch (irand() & 3) {
        case 0:
        default:
            {
            char *v0 = s1->pack;
            p1 = *(int *)(v0 + 0x148) + (int)v0;
            p2 = *(int *)(v0 + 0x14C) + (int)v0;
            }
            break;
        case 1:
            {
            char *v1 = s1->pack;
            p1 = *(int *)(v1 + 0x150) + (int)v1;
            p2 = *(int *)(v1 + 0x154) + (int)v1;
            }
            break;
        case 2:
            {
            char *v2 = s1->pack;
            p1 = *(int *)(v2 + 0x4EC) + (int)v2;
            p2 = *(int *)(v2 + 0x4F0) + (int)v2;
            }
            break;
        case 3:
            {
            char *v3 = s1->pack;
            p1 = *(int *)(v3 + 0x4F4) + (int)v3;
            p2 = *(int *)(v3 + 0x4F8) + (int)v3;
            }
            break;
        }
        func_002A8578(s1, p1, p2, 1, 0.0f, 0, 0);
        if (irand() & 1) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, a0, 0, 0, 0, 0);
        } else {
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD0, a0, 0, 0, 0, 0);
        }
        func_0012C348(s1, 1);
        pl00_clearMotionCam(s1, 0, 0);
        func_00126770(s1);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        s1->step += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s1) != 0) {
            if (s1->hp <= 0) {
                goto st;
            }
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s1, one);
        cObjBase_addNullSpeed(s1, one);
        break;
    default:
        break;
    }
    if (s1->hp <= 0) {
        if (s1->seqFlags & 0x10) {
        st:
            *(char *)((char *)s1 + 0x2F7) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F4) = 2;
        }
    } else {
        func_00123938(s1, 1);
    }
}

__attribute__((section(".text.func_001127F8")))
void func_001127F8(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x200;
    switch (s1->step) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x8C, 0x1E, 0x25, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x8C, 0x1E, 0x25, 0, 0x123);
        *(char *)((char *)s1 + 0x1684) = 1;
        cCoreSave_useGodItem(&D_00569B70);
        func_00129578(s1);
        t = *(int *)((char *)s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x4A4) + t, *(int *)(t + 0x4A8) + t,
                      3, 0.0f, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        *(int *)((char *)s1 + 0x15B0) = 1;
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((s1->seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if ((s1->seqFlags & 1) != 0 && *(int *)((char *)s1 + 0x15B0) != 0) {
        *(int *)((char *)s1 + 0x15B0) = 0;
        func_0012BC00(s1, 0x2E, 0);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 1, 0);
    } else {
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}

__attribute__((section(".text.func_00112A48")))
void func_00112A48(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)((char *)s1 + 0x15F4) |= 0x200;
    switch (s1->step) {
    case 0:
    {
        int p1, p2;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        *(char *)((char *)s1 + 0x1684) = 1;
        func_00129578(s1);
        cCoreSave_useGodItem(&D_00569B70);
        if (s1->stepArg != 0) {
            char *v0 = s1->pack;
            p1 = *(int *)(v0 + 0x450) + (int)v0;
            p2 = *(int *)(v0 + 0x458) + (int)v0;
        } else {
            char *v1 = s1->pack;
            p1 = *(int *)(v1 + 0x450) + (int)v1;
            p2 = *(int *)(v1 + 0x454) + (int)v1;
        }
        func_002A8578(s1, p1, p2, 3, 0.0f, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        *(int *)((char *)s1 + 0x15B0) = 1;
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    if ((s1->seqFlags & 1) != 0 && *(int *)((char *)s1 + 0x15B0) != 0) {
        *(int *)((char *)s1 + 0x15B0) = 0;
        if (s1->stepArg != 0) {
            func_0012BC00(s1, 0x2D, 0);
            func_0012BC00(s1, 0x2D, 1);
            func_0012BC00(s1, 0x2D, 2);
        } else {
            func_0012BC00(s1, 0x2C, 0);
        }
    }
    if ((s1->seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 1, 0);
    } else {
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}

struct VtEnt { short delta; short index; void *pfn; };

__attribute__((section(".text.func_00111A20")))
void func_00111A20(void *a0)
{
    cGameObj *s1 = a0;

    s1->hitFlash = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
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
        int p1, p2;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        if (s1->stepArg != 0) {
            char *v0;
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x64, 0x15, 0x21, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x32, 0x15, 0x21, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x3C, 0x15, 0x21, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x3C, 0x15, 0x21, 0, 0x123);
            }
            v0 = s1->pack;
            p1 = *(int *)(v0 + 0x20C) + (int)v0;
            p2 = *(int *)(v0 + 0x214) + (int)v0;
        } else {
            char *v1;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x23, 0x15, 0x21, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x23, 0x15, 0x21, 0, 0x123);
            v1 = s1->pack;
            p1 = *(int *)(v1 + 0x20C) + (int)v1;
            p2 = *(int *)(v1 + 0x210) + (int)v1;
        }
        *(char *)((char *)s1 + 0x1684) = 1;
        func_002A8578(s1, p1, p2, 3, 0.0f, 0, 0);
        func_00129578(s1);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if ((s1->seqFlags & 0x100) != 0) {
            cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)s1, 0);
        }
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            pl00_clearMotionCam(s1, 0, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        if ((s1->seqFlags & 0x100) != 0) {
            char *e = *(char **)((char *)s1 + 0x640);
            if (e != 0) {
                struct VtEnt *vt = *(struct VtEnt **)(e + 0x214);
                float *pos = *(float **)((char *)s1 + 0xF0);
                void *r = ((void *(*)(void *))vt[13].pfn)(e + vt[13].delta);
                if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                    *(int *)((char *)s1 + 0x330) = 0;
                    *(int *)((char *)s1 + 0x338) = 0;
                }
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((s1->seqFlags & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if ((s1->seqFlags & 3) != 0) {
        cSnd *g = &D_005FEE00;
        cSnd_SeStop(g, *(int *)((char *)s1 + 0x161C));
        *(int *)((char *)s1 + 0x161C) = 0;
        g->flagsB0 &= 0xFFBFFFFF;
        g->flagsAC &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        pl00_clearMotionCam(s1, 0, 0);
    } else {
        s1->seqFlags |= 0x800;
        *(float *)((char *)s1 + 0x674) = 0.05f;
    }
}
