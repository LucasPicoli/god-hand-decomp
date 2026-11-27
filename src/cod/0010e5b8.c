/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"
#include "godhand/pl00.h"
#include "godhand/cObjBase.h"
#include "godhand/cGameObj.h"

extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern int  moveMotion(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0010A438(void *a0);

extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void SetMotionStep(void *a0, float f12);
extern void cSnd_SeStop(void *a0, int a1);
extern void KillEffect(void *a0, int a1, int a2);
extern char *Getplayer(void);
extern int D_007474A0;

struct VtEnt { short delta; short index; void *pfn; };

static __inline__ long inrange(unsigned short k, int lo, int hi)
{
    long c;
    int t;
    c = 0;
    if (k >= lo) {
        t = (k < hi);
        c = t;
    }
    return c;
}

__attribute__((section(".text.func_0010E5B8")))
void func_0010E5B8(void *a0)
{
    cGameObj *s1 = a0;
    int one = 1;

    if (s1->hp <= 0)
        s1->hp = one;
    switch (s1->step) {
    case 0:
    {
        char *e;
        char *e2;
        int t;

        func_00124540(s1, 0);
        *(short *)((char *)s1 + 0x5E0) = 0;
        *(short *)((char *)s1 + 0x5E2) = 0;
        if (*(signed char *)((char *)s1 + 0x648) > 0)
            *(char *)((char *)s1 + 0x648) = 0x2D;
        e = *(char **)((char *)s1 + 0x640);
        if (e != 0) {
            if (inrange(*(unsigned short *)(e + 0x2FE), 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, (int)(*(float *)((char *)s1 + 0x600) * 10.0f), 8, 0x13, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, (int)(*(float *)((char *)s1 + 0x600) * 10.0f), 8, 0x13, 0, 0xA);
        t = *(int *)((char *)s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x18C) + t, *(int *)(t + 0x194) + t, 5, 0.0f, 0, 0);
        *(float *)((char *)s1 + 0x15C0) = 1.0f;
        *(float *)((char *)s1 + 0x15C4) = 0.0f;
        *(int *)((char *)s1 + 0x15B0) = 1;
        *(int *)((char *)s1 + 0x15B8) = 1;
        *(float *)((char *)s1 + 0x1588) = 0.0f;
        *(int *)((char *)s1 + 0x15B4) = 0;
        e2 = *(char **)((char *)s1 + 0x640);
        if (e2 != 0) {
            struct VtEnt *vt = *(struct VtEnt **)(e2 + 0x214);
            float *pos = *(float **)((char *)s1 + 0xF0);
            void *r = ((void *(*)(void *))vt[13].pfn)(e2 + vt[13].delta);
            float d = capVu0MagnitudeXZ(pos, r) - 1.20000005f;
            if (*(unsigned short *)((char *)s1 + 0x5E0) == 0 && *(unsigned char *)((char *)s1 + 0x61F) != 0) {
                if (1.0f < d) d = 1.0f;
            } else {
                if (0.5f < d) d = 0.5f;
            }
            if (0.0f < d)
                *(float *)((char *)s1 + 0x1588) = d * 0.150000006f;
        }
        *(short *)((char *)s1 + 0x5F0) = 0xA;
        s1->unk568 = 0x32;
        (s1->step)++;
    }
        /* fallthrough */
    case 1:
    {
        if (s1->unk568 != 0) {
            s1->unk568 = *(unsigned short *)((char *)s1 + 0x568) - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.196349546f);
        }
        if (*(int *)((char *)s1 + 0x640) != 0)
            *(char *)((char *)s1 + 0x648) = 0x14;
        s1->speedRate = 1.0f;
        *(float *)((char *)s1 + 0x5DC) = 1.0f;
        if (s1->seqFlags & 0x80) {
            if (*(int *)((char *)s1 + 0x15B0) != 0) {
                if (*(float *)((char *)s1 + 0x15C4) <= 0.0f)
                    *(float *)((char *)s1 + 0x15C4) = 1.0f;
            }
        }
        if (*(float *)((char *)s1 + 0x15C4) > 0.0f && *(int *)((char *)s1 + 0x15B0) != 0) {
            if (*(int *)((char *)s1 + 0x15B4) == 0) {
                *(int *)((char *)s1 + 0x15B4) = 1;
                InitRenderStruct_2A8608(s1, 0, 0x31, 2, 2, 0);
            }
            if ((D_007474A0 & 0xD0) != 0) {
                float sp = 0.0250000004f;
                s1->speedRate = sp;
                *(float *)((char *)s1 + 0x5DC) = sp;
                *(float *)((char *)s1 + 0x15C4) = *(float *)((char *)s1 + 0x15C4) - sp;
                SetMotionStep(s1, sp);
                *(float *)((char *)s1 + 0x15C0) = *(float *)((char *)s1 + 0x15C0) + 0.0500000007f;
                if (*(float *)((char *)s1 + 0x15C4) <= 0.0f)
                    *(float *)((char *)s1 + 0x15C0) = *(float *)((char *)s1 + 0x15C0) + 1.0f;
                if (*(float *)((char *)s1 + 0x15C0) >= 1.10000002f) {
                    if (*(int *)((char *)s1 + 0x15B8) != 0) {
                        *(int *)((char *)s1 + 0x15B8) = 0;
                        *(int *)((char *)s1 + 0x1620) = cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x11B, a0, 0, 0, 0, 0);
                    }
                }
            } else {
                *(float *)((char *)s1 + 0x15C4) = 0.0f;
                *(int *)((char *)s1 + 0x15B0) = 0;
            }
            if (*(float *)((char *)s1 + 0x15C4) <= 0.0f)
                *(int *)((char *)s1 + 0x15B0) = 0;
        } else {
            if (s1->seqFlags & 3)
                KillEffect(Getplayer(), 2, 2);
            if (*(int *)((char *)s1 + 0x15B4) != 0) {
                *(int *)((char *)s1 + 0x15B4) = 0;
                if (*(float *)((char *)s1 + 0x15C0) >= 2.5f) {
                    KillEffect(Getplayer(), 2, 2);
                    SetEffect(0, 0x32, a0, 0, -1, EFFECT_FOLLOW_OWNER);
                }
                cSnd_SeStop(&D_005FEE00, *(int *)((char *)s1 + 0x1620));
                *(int *)((char *)s1 + 0x1620) = 0;
            }
        }
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 1, 0);
            *(char *)((char *)s1 + 0x2F4) = 0;
            *(char *)((char *)s1 + 0x2F5) = 0;
            *(char *)((char *)s1 + 0x2F6) = 0;
            *(char *)((char *)s1 + 0x2F7) = 0;
        }
        {
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
        s1->nullSpeed.z = s1->nullSpeed.z + *(float *)((char *)s1 + 0x1588);
        *(float *)((char *)s1 + 0x1588) = *(float *)((char *)s1 + 0x1588) * 0.899999976f;
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    }
    *(float *)((char *)s1 + 0x1610) = *(float *)((char *)s1 + 0x15C0);
    if (2.5f < *(float *)((char *)s1 + 0x15C0)) {
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, 0x10, 8, 0x14, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, 0x10, 8, 0x14, 0, 0xA);
    }
    func_0010A438(s1);
    if (s1->seqFlags & 0x10) {
        if (*(short *)((char *)s1 + 0x5F0) != 0) {
            *(short *)((char *)s1 + 0x5F0) = *(unsigned short *)((char *)s1 + 0x5F0) - 1;
            *(int *)((char *)s1 + 0x15F4) |= 0x20000;
        } else {
            *(short *)((char *)s1 + 0x5E0) = 0;
            *(short *)((char *)s1 + 0x5E2) = 0;
        }
    }
    if (func_00123938(s1, 1) != 0)
        pl00_clearMotionCam(s1, 1, 0);
}
