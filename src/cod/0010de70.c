/* sn-2.95.3-136 matched TU. */

#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cGameObj.h"
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0010A438(void *a0);


struct VtEnt { short delta; short index; void *pfn; };

__attribute__((section(".text.func_0010DE70")))
void func_0010DE70(void *a0)
{
    cGameObj *s1 = a0;

    if (s1->hp <= 0)
        s1->hp = 1;
    if (func_0010B2E8(s1, 0) != 0 && *(int *)((char *)s1 + 0x15BC) >= 3)
        *(int *)((char *)s1 + 0x15BC) = 2;
    switch (s1->step) {
    case 0:
    {
        int p, q;
        float f;

        func_00124540(s1, 1);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        if (*(signed char *)((char *)s1 + 0x648) > 0)
            *(char *)((char *)s1 + 0x648) = 0x2D;
        switch (s1->stepArg) {
        default:
        case 0:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, (int)(*(float *)((char *)s1 + 0x600) * 15.0f), 4, 0x1A, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, (int)(*(float *)((char *)s1 + 0x600) * 15.0f), 4, 0x1A, 0, 0x77);
            {
                int t = *(int *)((char *)s1 + 0x304);
                f = 2.0f;
                p = *(int *)(t + 0x830) + t;
                q = *(int *)(t + 0x834) + t;
            }
            break;
        case 1:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, (int)(*(float *)((char *)s1 + 0x600) * 10.0f), 4, 0x1A, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, (int)(*(float *)((char *)s1 + 0x600) * 10.0f), 4, 0x1A, 0, 0x77);
            {
                int t = *(int *)((char *)s1 + 0x304);
                f = 5.0f;
                p = *(int *)(t + 0x61C) + t;
                q = *(int *)(t + 0x624) + t;
            }
            break;
        case 2:
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, (int)(*(float *)((char *)s1 + 0x600) * 10.0f), 3, 0x1B, 0, 0x77);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, (int)(*(float *)((char *)s1 + 0x600) * 10.0f), 3, 0x1B, 0, 0x77);
            {
                int t = *(int *)((char *)s1 + 0x304);
                f = 2.0f;
                p = *(int *)(t + 0x838) + t;
                q = *(int *)(t + 0x83C) + t;
                *(char *)((char *)s1 + 0x1603) = 0xF;
            }
            break;
        }
        func_002A8578(s1, p, q, 3, f, 0x40, 0);
        *(float *)((char *)s1 + 0x15C4) = 0.0f;
        *(int *)((char *)s1 + 0x15B0) = 1;
        *(int *)((char *)s1 + 0x15B4) = 0;
        *(float *)((char *)s1 + 0x1588) = 0.0f;
        *(float *)((char *)s1 + 0x15C0) = 1.0f;
        *(int *)((char *)s1 + 0x15B8) = 1;
        *(int *)((char *)s1 + 0x15BC) = 999;
        s1->unk568 = 10;
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
    {
        char *e;

        if (s1->unk568 != 0) {
            s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.392699093f);
        }
        if (*(int *)((char *)s1 + 0x640) != 0)
            *(char *)((char *)s1 + 0x648) = 0x14;
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        e = *(char **)((char *)s1 + 0x640);
        if (e != 0 && s1->stepArg != 0) {
            struct VtEnt *vt = *(struct VtEnt **)(e + 0x214);
            float *pos = *(float **)((char *)s1 + 0xF0);
            void *r = ((void *(*)(void *))vt[13].pfn)(e + vt[13].delta);
            if (capVu0MagnitudeSqXZ(pos, r) < 1.95999992f) {
                *(int *)((char *)s1 + 0x330) = 0;
                *(int *)((char *)s1 + 0x338) = 0;
            }
        }
        if ((s1->seqFlags & 0x200) != 0)
            s1->nullSpeed.z = s1->nullSpeed.z * 1.5f;
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    }
    if (*(int *)((char *)s1 + 0x15BC) > 0) {
        *(int *)((char *)s1 + 0x15BC) = *(int *)((char *)s1 + 0x15BC) - 1;
        func_0010A438(s1);
    }
    if (func_00123938(s1, 1) != 0)
        pl00_clearMotionCam(s1, 1, 0);
}
