/* sn-2.95.3-136 matched TU. */
extern int espSys_effDataRegist(void *a0, int a1, void *a2);
extern void cOmBase_setMeshDispFromLayer(void *a0, int a1, int a2);
extern int D_00747B00;
extern int D_007419A0;

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/player.h"
#include "godhand/cDamageManage.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cObjBase.h"
#include "godhand/cObj.h"















__attribute__((section(".text.func_001C9268")))
int func_001C9268(cObj *p)
{
    float buf[12];
    char *n;
    int flag;
    float *sph;

    if (func_001B6FB8(p) == 0) {
        return 0;
    }
    *(int *)((char *)p + 0x600) = 0;
    *(int *)((char *)p + 0x604) = 0;
    *(int *)((char *)p + 0x630) = 0;
    switch (p->actorId) {
    default:
        *(int *)((char *)p + 0x668) = 0x64;
        break;
    case 0x361:
        *(int *)((char *)p + 0x668) = 0x78;
        break;
    case 0x362:
        *(int *)((char *)p + 0x668) = 0x5A;
        break;
    case 0x363:
        *(int *)((char *)p + 0x668) = 0x3C;
        break;
    case 0x368:
        *(int *)((char *)p + 0x668) = 0x96;
        break;
    case 0x3B7:
        *(int *)((char *)p + 0x668) = 0x28;
        break;
    case 0x3B4:
        *(int *)((char *)p + 0x668) = 0x3C;
        break;
    case 0x3AD:
        *(int *)((char *)p + 0x668) = 0x3C;
        break;
    case 0x3AE:
        *(int *)((char *)p + 0x668) = 0x3C;
        break;
    case 0x3AA:
        *(int *)((char *)p + 0x668) = 0x3C;
        break;
    case 0x3AB:
        *(int *)((char *)p + 0x668) = 0x3C;
        break;
    case 0x3AF:
        *(int *)((char *)p + 0x668) = 0x1;
        break;
    case 0x36D:
        *(int *)((char *)p + 0x668) = 0x50;
        break;
    case 0x3A9:
        *(int *)((char *)p + 0x668) = 0x5A;
        break;
    case 0x3A8:
        *(int *)((char *)p + 0x668) = 0x5A;
        break;
    case 0x379:
        *(int *)((char *)p + 0x668) = 0x5A;
        break;
    case 0x375:
        *(int *)((char *)p + 0x668) = 0x64;
        break;
    case 0x377:
        *(int *)((char *)p + 0x668) = 0x64;
        break;
    case 0x378:
        *(int *)((char *)p + 0x668) = 0x64;
        break;
    case 0x37B:
        *(int *)((char *)p + 0x668) = 0x5A;
        break;
    case 0x380:
        *(int *)((char *)p + 0x668) = 0x96;
        break;
    case 0x390:
        *(int *)((char *)p + 0x668) = 0x3E7;
        break;
    }

    *(cDamageGive **)((char *)p + 0x650) = cDamageManage_CreateDamageGive(&D_00574380, 1, (cGameObj *)p);
    flag = p->partNum;
    *(int *)buf = flag;
    if (flag) {
        n = **(char ***)((char *)p + 0x278);
    } else {
        n = 0;
    }
    buf[4] = 0.0f;
    buf[5] = 0.0f;
    buf[6] = 0.0f;
    sph = buf + 4;
    sph[3] = 1.0f;
    *(int *)((char *)p + 0x654) = cDamageUnit_AddDamageCollSphere(*(cDamageUnit **)((char *)p + 0x650), (const struct cMatrix *)(n + 0x80),
                                                          (const cVec *)sph, 0.3f);
    cDamageUnit_SetDamageCollActive(*(cDamageUnit **)((char *)p + 0x650), 0);

    *(cDamageGive **)((char *)p + 0x658) = cDamageManage_CreateDamageGive(&D_00574380, 0, (cGameObj *)p);
    if (*(int *)((char *)p + 0x658) != 0) {
        int flag2 = p->partNum;
        char *n2;
        *(int *)buf = flag2;
        if (flag2) {
            n2 = **(char ***)((char *)p + 0x278);
        } else {
            n2 = 0;
        }
        buf[3] = 1.0f;
        buf[0] = 0.0f;
        buf[1] = 0.0f;
        buf[2] = 0.0f;
        *(int *)((char *)p + 0x65C) = cDamageUnit_AddDamageCollSphere(*(cDamageUnit **)((char *)p + 0x658), (const struct cMatrix *)(n2 + 0x80),
                                                              (const cVec *)buf, 0.4f);
        cDamageUnit_SetDamageCollActive(*(cDamageUnit **)((char *)p + 0x658), 0);
        *(short *)(*(int *)((char *)p + 0x658) + 0x46) = 0x2F;
        *(int *)(*(int *)((char *)p + 0x658) + 0x4C) = 0x32;
        cDamageGive_SetDmgGiveHitVec(*(cDamageGive **)((char *)p + 0x658), (const cVec *)&D_00747B00);
        {
            char *dg = *(char **)((char *)p + 0x658);
            *(int *)(dg + 0x40) = -1;
            *(short *)(dg + 0x44) = 0;
        }
    }

    if (p->actorId == 0x3B7) {
        SetEffect(0x58, 0x8D, (cObj *)p, 0, 8, EFFECT_FOLLOW_OWNER);
    }
    switch (p->actorId) {
    case 0x3AE:
        {
            char *e = p->pack;
            espSys_effDataRegist(&D_007419A0, 0x206,
                                 (void *)(*(int *)(e + 0xC) + (int)e));
        }
        SetEffect(0x206, 1, (cObj *)p, 0, 8, EFFECT_FOLLOW_OWNER);
        break;
    case 0x3B7:
        SetEffect(0x58, 0x8D, (cObj *)p, 0, 8, EFFECT_FOLLOW_OWNER);
        break;
    case 0x3B8:
        SetEffect(0x69, 4, (cObj *)p, 0, 8, EFFECT_FOLLOW_OWNER);
        SetEffect(0x69, 9, (cObj *)p, 0, -1, EFFECT_FOLLOW_OWNER);
        break;
    case 0x3B9:
        SetEffect(0x69, 5, (cObj *)p, 0, 8, EFFECT_FOLLOW_OWNER);
        SetEffect(0x69, 0xA, (cObj *)p, 0, -1, EFFECT_FOLLOW_OWNER);
        break;
    case 0x3BA:
        SetEffect(0x69, 6, (cObj *)p, 0, 8, EFFECT_FOLLOW_OWNER);
        SetEffect(0x69, 0xB, (cObj *)p, 0, -1, EFFECT_FOLLOW_OWNER);
        break;
    case 0x369:
        break;
    }
    cOmBase_setMeshDispFromLayer(p, 0x40, 0);

    switch (p->actorId) {
    default:
        *(char *)((char *)p + 0x2F4) = 0;
        *(char *)((char *)p + 0x2F6) = 2;
        *(char *)((char *)p + 0x2F5) = 0;
        *(char *)((char *)p + 0x2F7) = 0;
        break;
    case 0x3A8:
    case 0x3A9:
    case 0x3AA:
    case 0x3AB:
    case 0x3AD:
    case 0x3AE:
    case 0x3B4:
        *(char *)((char *)p + 0x2F4) = 0;
        *(char *)((char *)p + 0x2F6) = 3;
        *(char *)((char *)p + 0x2F5) = 0;
        *(char *)((char *)p + 0x2F7) = 0;
        break;
    case 0x36A:
        p->scale.z = 1.3f;
        p->scale.y = 1.3f;
        p->scale.x = 1.3f;
        break;
    case 0x382:
        *(char *)((char *)p + 0x2F4) = 0;
        *(char *)((char *)p + 0x2F5) = 0x17;
        *(char *)((char *)p + 0x2F6) = 0;
        *(char *)((char *)p + 0x2F7) = 0;
        break;
    case 0x42A:
        *(char *)((char *)p + 0x2F4) = 0;
        *(char *)((char *)p + 0x2F5) = 0x16;
        *(char *)((char *)p + 0x2F6) = 0;
        *(char *)((char *)p + 0x2F7) = 0;
        break;
    }

    if (p->actorId == 0x42A) {
        *(int *)((char *)p + 0x5B8) |= 0x40;
    } else {
        *(int *)((char *)p + 0x5B8) &= ~0x40;
    }

    *(char *)((char *)p + 0x688) = 0;
    *(int *)((char *)p + 0x68C) = 0;
    if (p->actorId == 0x37B || p->actorId == 0x390) {
        cGameObj *obj = CreateObj(0x37C, 0xFFFF);
        *(cGameObj **)((char *)p + 0x68C) = obj;
        if (obj != 0) {
            cGameObjVt *vt;
            float *src;
            float *src2;
            float *dst;
            float *d490;
            int *p100;

            VU0_SQC2_VF0(buf, 0x0);
            VU0_SQC2_VF0(buf, 0x20);
            vt = cGameObj_vt(obj);
            vt->initial((char *)obj + vt->initialDelta);

            dst = *(float **)(*(char **)((char *)p + 0x68C) + 0xF0);
            src = *(float **)((char *)p + 0xF0);
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            src2 = *(float **)((char *)p + 0xF0);
            d490 = (float *)(*(char **)((char *)p + 0x68C) + 0x490);
            if (d490 != src2) {
                d490[0] = src2[0];
                d490[1] = src2[1];
                d490[2] = src2[2];
            }
            p100 = (int *)(*(char **)((char *)p + 0x68C) + 0x100);
            p100[0] = 0;
            p100[1] = 0;
            p100[2] = 0;
            buf[0] = 0.0f;
            buf[1] = 0.0f;
            buf[2] = 0.0f;
            buf[8] = 0.0f;
            buf[9] = 0.0f;
            buf[10] = 0.0f;
            cOmWeapon_setParent(*(cOmWeapon **)((char *)p + 0x68C), (cGameObj *)p, 2, (cVec *)buf, (cVec *)&buf[8]);
        }
    }

    if (p->actorId == 0x376) {
        int f = *(int *)((char *)p + 0x2D0);
        f &= ~0x20000000;
        f |= 0x80000000;
        *(int *)((char *)p + 0x2D0) = f;
    }
    return 1;
}
