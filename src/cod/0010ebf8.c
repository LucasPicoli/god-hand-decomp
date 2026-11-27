/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cSnd.h"
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
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern float capVu0Atan2(float y, float x);
extern float Turn_dest_dir(float f12, float f13, float f14);
extern float Adjust_theta(float f12);
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern int cOmBase_checkDamage(void *a0, int a1);
extern void StunObj_startStun(void *a0);
extern void func_001B48E0(void *a0);
extern void func_001B54E8(void *a0);
extern void func_002A87E8(void *a0, int a1);
extern void func_001B76D8(void *a0);

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

__attribute__((section(".text.func_0010EBF8")))
void func_0010EBF8(void *a0)
{
    pl00 *s1 = a0;
    int one = 1;

    if (s1->base.hp <= 0)
        s1->base.hp = one;
    switch (s1->base.step) {
    case 0:
    {
        cGameObj *e;
        int t;

        func_00124540(s1, 0);
        s1->comboSlot = 0;
        s1->comboSet = 0;
        if (s1->unk648 > 0)
            s1->unk648 = 0x2D;
        e = s1->held;
        if (e != 0) {
            if (inrange(e->actorId, 0x200, 0x300) & 0xFF)
                cCoreSave_addGameLevelPoint(&D_00569B70, 0x14);
        }
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(a0, (int)(s1->unk600 * 10.0f), 0xB, 0xA, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(a0, (int)(s1->unk600 * 10.0f), 0xB, 0xA, 0, 0xA);
        t = (int)s1->base.pack;
        func_002A8578(s1, *(int *)(t + 0x100) + t, *(int *)(t + 0x108) + t, 5, 0.0f, 0, 0);
        s1->unk15C4 = 0.0f;
        s1->unk15B0 = 1;
        s1->stepCount = 0;
        s1->unk15B8 = 1;
        s1->stepScale = 1.0f;
        s1->unk1588 = 0.0f;
        s1->base.unk568 = 0x32;
        (s1->base.step)++;
    }
        /* fallthrough */
    case 1:
    {
        cGameObj *e;

        if (s1->base.unk568 != 0) {
            s1->base.unk568 = s1->base.unk568 - 1;
            InvokeVirtualAtField214AndForward_124E68(s1, 0.196349546f);
        }
        if (s1->held != 0)
            s1->unk648 = 0x14;
        if (moveMotion(s1) != 0) {
            pl00_clearMotionCam(s1, 1, 0);
            s1->base.mode = 0;
            s1->base.phase = 0;
            s1->base.step = 0;
            s1->base.stepArg = 0;
        }
        e = s1->held;
        if (e != 0) {
            cGameObjVt *vt = cGameObj_vt(e);
            cVec *pos = s1->base.pos;
            cVec *r = vt->getPos((char *)e + vt->getPosDelta);
            if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                s1->base.nullSpeed.x = 0.0f;
                s1->base.nullSpeed.z = 0.0f;
            }
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1) != 0)
        pl00_clearMotionCam(s1, 1, 0);
}

#include "godhand/vu0.h"
#include "godhand/cEm00.h"

__attribute__((section(".text.func_00241C18")))
void func_00241C18(void *a0)
{
    char buf[0x30] __attribute__((aligned(16)));
    cEm00 *s0 = a0;

    s0->hitFlash = 3.0f;
    switch (s0->step) {
    case 0:
    {
        int gb;
        char *v;

        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        v = s0->pack;
        func_002A8578(s0, *(int *)(v + 0x111C) + (int)v, *(int *)(v + 0x1120) + (int)v, 3, 0.0f, gb, 0);
        s0->unk6D0.x = 1.954f;
        s0->unk6D0.y = 4.0f;
        s0->unk6D0.z = -14.8719997f;
        s0->unk6E0 = 0.0f;
        {
            cVec *a = &s0->unk6D0;
            cVec *b = s0->pos;

            VU0_SQC2_VF0(buf, 0x10);
            VU0_LQC2(4, a, 0);
            VU0_LQC2(5, b, 0);
        }
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0);
        VU0_SQC2(4, buf, 0);
        {
            cVec *d = &s0->unk580;

            if ((char *)d != buf) {
                float t0 = *(float *)(buf + 0);
                float t1 = *(float *)(buf + 4);
                float t2;

                s0->unk580.x = t0;
                *(volatile float *)&d->y = t1;
                t2 = *(volatile float *)(buf + 8);
                d->z = t2;
            }
        }
        s0->unk580.y = 0.0f;
        s0->timer = 22.0f;
        VU0_LQC2(4, &s0->unk580, 0);
        VU0_SQC2(4, buf, 0x10);
        {
            float k = 0.0454545468f;

            VU0_LQC2(4, buf, 0x10);
            VU0_LOAD_SCALAR(5, k);
        }
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf + 0x10, 0);
        VU0_SQC2(4, buf, 0);
        {
            cVec *d = &s0->unk590;

            if ((char *)d != buf) {
                float t0 = *(float *)(buf + 0);
                float t1 = *(float *)(buf + 4);
                float t2;

                s0->unk590.x = t0;
                *(volatile float *)&d->y = t1;
                t2 = *(volatile float *)(buf + 8);
                d->z = t2;
            }
        }
        s0->timer2 = capVu0Atan2(-s0->unk580.x, -s0->unk580.z);
        (s0->step)++;
    }
        /* fallthrough */
    case 1:
    {
        float th;

        s0->emFlags |= 0x21000;
        s0->unk617 = 1;
        s0->emFlags |= 0x10000;
        th = Turn_dest_dir(s0->rot.y, s0->timer2, s0->speedRate * 0.392699093f);
        s0->rot.y += th;
        s0->rot.y = Adjust_theta(s0->rot.y);
        if (moveMotion(s0) != 0) {
            s0->mode = 0;
            s0->phase = 0x79;
            s0->step = 0;
            s0->stepArg = 0;
        }
        if ((s0->seqFlags & 4) != 0) {
            float k;
            cVec *p;
            char *t2;

            VU0_SQC2_VF0(buf, 0);
            k = s0->speedRate;
            t2 = buf + 0x20;
            VU0_LQC2(4, &s0->unk590, 0);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, buf, 0x20);
            VU0_LOAD_SCALAR(5, k);
            VU0_VMULX_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x20);
            VU0_LQC2(4, t2, 0);
            VU0_SQC2(4, buf, 0x10);
            {
                float *d = (float *)buf;
                float *s = (float *)(buf + 0x10);

                if (d != s) {
                    float x = *(float *)(buf + 0x10);
                    float y = *(float *)(buf + 0x14);
                    float z = *(float *)(buf + 0x18);

                    *(float *)(buf + 0x0) = x;
                    *(float *)(buf + 0x4) = y;
                    *(float *)(buf + 0x8) = z;
                }
            }
            p = s0->pos;
            VU0_VADD_XYZ_IP(p, 0, buf);
        }
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }
    }
}

struct Entry_001B4068 { short f0; short f2; short f4; short f6; };
struct Table_001B4068 { struct Entry_001B4068 e[1]; };
extern struct Table_001B4068 D_003BDD38;

#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/cOmBase.h"

static __inline__ cOmBase *GetChild(cOmBase *p, int idx, char *fr)
{
    int cnt;

    if ((*(int *)fr = cnt = p->partNum), (idx >= 0 && idx < cnt))
        return p->children[idx];
    return 0;
}

__attribute__((section(".text.func_001B4068")))
void func_001B4068(void *a0)
{
    char buf[0x20] __attribute__((aligned(16)));
    cOmBase *s0 = a0;

    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0)
        return;
    if (cOmBase_checkDamage(s0, *(int *)((char *)s0 + 0x650)) != 0) {
        if (s0->hp <= 0) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x89, a0, 0, 0, 0, 0);
            s0->mode = 3;
            s0->phase = 0;
            s0->flags0 |= 1;
        } else {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x8E, a0, 0, 0, 0, 0);
        }
        StunObj_startStun(s0);
    }
    {
        char *e;
        int i8;
        int f0;
        int type; int arg; int (*fp)(int); long entry;

        i8 = s0->mode * 8;
        e = (char *)&D_003BDD38 + i8;
        type = *(short *)(e + 2);
        if (type >= 0) {
            int base = *(int *)((char *)s0 + *(short *)(e + 4));
            entry = *(long *)(base + type * 8 - 8);
            fp = (int (*)(int))(int)(entry >> 32);
        } else {
            fp = *(int (**)(int))((char *)&D_003BDD38 + i8 + 4);
        }
        f0 = D_003BDD38.e[s0->mode].f0;
        if (type >= 0)
            arg = (short)entry + f0;
        else
            arg = f0;
        fp((int)((char *)s0 + arg));
    }
    func_001B48E0(s0);
    func_001B54E8(s0);
    switch (s0->mode) {
    case 0:
        if (0.0f < *(float *)((char *)s0 + 0x964)) {
            if (GetChild(s0, 9, buf) != 0)
                GetChild(s0, 9, buf)->anchor->x = *(float *)((char *)s0 + 0x964);
            if (GetChild(s0, 10, buf) != 0)
                GetChild(s0, 10, buf)->anchor->x = -*(float *)((char *)s0 + 0x964);
        }
        break;
    case 1:
        if (0.0f < *(float *)((char *)s0 + 0x964)) {
            *(float *)((char *)s0 + 0x964) = *(float *)((char *)s0 + 0x964) - 0.0500000007f;
            if (*(float *)((char *)s0 + 0x964) < 0.0f)
                *(float *)((char *)s0 + 0x964) = 0.0f;
            if (GetChild(s0, 9, buf) != 0)
                GetChild(s0, 9, buf)->anchor->x = *(float *)((char *)s0 + 0x964);
            if (GetChild(s0, 10, buf) != 0)
                GetChild(s0, 10, buf)->anchor->x = -*(float *)((char *)s0 + 0x964);
        }
        break;
    default:
        *(float *)((char *)s0 + 0x964) = 0.0f;
        break;
    }
    VU0_SQC2_VF0(buf, 0x10);
    if (func_001329C0(a0, (cVec *)(buf + 0x10), 0, 0, 10.0f) != 0)
        s0->pos->y = *(float *)(buf + 0x14);
    func_002A87E8(s0, 0);
    func_001B76D8(s0);
}
