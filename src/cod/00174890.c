/* sn-2.95.3-136 matched TU. */

extern float D_00567FC0[];
extern int cOmSub_move(void *a0);
extern float D_00568020[];
extern void func_001B6FB8(void *a0);
extern int cModel_getMeshPtr(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/vu0.h"
#include "godhand/cObj.h"



extern void cOmSub_initMove1_ang(void *dst, void *obj, int idx, int a3, void *a4,
                                 float f12, float f13, int a5);



__attribute__((section(".text.func_00180140")))
void func_00180140(cObj *p)
{
    unsigned char hold[0x10] __attribute__((aligned(16)));
    unsigned char a10[0x10];
    unsigned char a20[0x10];
    float *s;
    char *q;
    char *r;
    unsigned char *b20;
    int i;
    int cnt;
    unsigned char ok;
    char *e;
    float k;
    int flag, one, n;

    switch (p->phase) {
    case 0:
        if (*(int *)((char *)p + 0xA24) == 0) {
            ((char *)p)[0x2F4] = 0;
            ((char *)p)[0x2F5] = 0;
            ((char *)p)[0x2F6] = 0;
            ((char *)p)[0x2F7] = 0;
            return;
        }
        k = 0.100000001f;
        s = D_00567FC0;
        i = 0;
        b20 = a20;
        q = (char *)p + 0x600;
        do {
            ok = ((*(int *)hold = cnt = p->partNum),
                  (i >= 0 && i < cnt));
            if (ok) e = *(char **)(*(char **)((char *)p + 0x278) + i * 4); else e = 0;
            if (e != 0) {
                char *ep = e + 0x100;
                VU0_SQC2_VF0(hold, 0x20);
                VU0_LQC2(4, s, 0);
                VU0_LQC2(5, ep, 0);
                VU0_VSUB_XYZ(4, 4, 5);
                VU0_SQC2(4, hold, 0x20);
                VU0_LQC2(4, b20, 0);
                VU0_SQC2(4, hold, 0x10);
                cOmSub_initMove1_ang(q, p, i, 0x3C, a10, k, k, 0);
            }
            i++;
            q += 0x160;
            s += 4;
        } while (i < 3);
        {
            int lim = 1;
            int b2;
            unsigned char ok2;
            cOmBase *e2;
            ok2 = ((*(int *)hold = b2 = p->partNum), (lim < b2));
            if (ok2) e2 = (*(cOmBase ***)((char *)p + 0x278))[1]; else e2 = 0;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xDF, (cObj *)p, 0, (cParts *)e2, 0, 0);
        }
        ((char *)p)[0xA28] = 1;
        ((char *)p)[0x2F5] = 1;
        ((char *)p)[0x2F6] = 0;
        ((char *)p)[0x2F7] = 0;
    case 1:
        break;
    default:
        return;
    }
    flag = 0;
    one = 1;
    r = (char *)p + 0x600;
    n = 2;
    do {
        if (cOmSub_move(r) != 0) flag = one;
        n--;
        r += 0x160;
    } while (n >= 0);
    if (flag != 0) return;
    *(int *)((char *)p + 0xA24) = 0;
    ((char *)p)[0xA28] = 0;
    ((char *)p)[0x2F4] = 0;
    ((char *)p)[0x2F5] = 0;
    ((char *)p)[0x2F6] = 0;
    ((char *)p)[0x2F7] = 0;
}

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"
#include "godhand/cDamageManage.h"



extern void cOmSub_initMove1_ang(void *dst, void *obj, int idx, int a3, void *a4,
                                 float f12, float f13, int a5);



__attribute__((section(".text.func_0017FF68")))
void func_0017FF68(cObj *p)
{
    unsigned char hold[0x10] __attribute__((aligned(16)));
    unsigned char a10[0x10];
    unsigned char a20[0x10];
    float *s;
    char *q;
    char *r;
    unsigned char *b20;
    int i;
    int cnt;
    unsigned char ok;
    char *e;
    float k;
    int flag, one, n;

    switch (p->phase) {
    case 0:
        if (*(int *)((char *)p + 0xA24) == 2) {
            ((char *)p)[0x2F4] = 0;
            ((char *)p)[0x2F5] = 0;
            ((char *)p)[0x2F6] = 0;
            ((char *)p)[0x2F7] = 0;
            return;
        }
        k = 0.100000001f;
        s = D_00568020;
        i = 0;
        b20 = a20;
        q = (char *)p + 0x600;
        do {
            ok = ((*(int *)hold = cnt = p->partNum),
                  (i >= 0 && i < cnt));
            if (ok) e = *(char **)(*(char **)((char *)p + 0x278) + i * 4); else e = 0;
            if (e != 0) {
                char *ep = e + 0x100;
                VU0_SQC2_VF0(hold, 0x20);
                VU0_LQC2(4, s, 0);
                VU0_LQC2(5, ep, 0);
                VU0_VSUB_XYZ(4, 4, 5);
                VU0_SQC2(4, hold, 0x20);
                VU0_LQC2(4, b20, 0);
                VU0_SQC2(4, hold, 0x10);
                cOmSub_initMove1_ang(q, p, i, 0x3C, a10, k, k, 0);
            }
            i++;
            q += 0x160;
            s += 4;
        } while (i < 3);
        {
            int lim = 1;
            int b2;
            unsigned char ok2;
            cOmBase *e2;
            ok2 = ((*(int *)hold = b2 = p->partNum), (lim < b2));
            if (ok2) e2 = (*(cOmBase ***)((char *)p + 0x278))[1]; else e2 = 0;
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0xDF, (cObj *)p, 0, (cParts *)e2, 0, 0);
        }
        ((char *)p)[0xA28] = 1;
        ((char *)p)[0x2F5] = 1;
        ((char *)p)[0x2F6] = 0;
        ((char *)p)[0x2F7] = 0;
    case 1:
        break;
    default:
        return;
    }
    flag = 0;
    one = 1;
    r = (char *)p + 0x600;
    n = 2;
    do {
        if (cOmSub_move(r) != 0) flag = one;
        n--;
        r += 0x160;
    } while (n >= 0);
    if (flag != 0) return;
    *(int *)((char *)p + 0xA24) = 2;
    ((char *)p)[0xA28] = 0;
    ((char *)p)[0x2F4] = 0;
    ((char *)p)[0x2F5] = 0;
    ((char *)p)[0x2F6] = 0;
    ((char *)p)[0x2F7] = 0;
}

/* sn-2.95.3-136 matched TU. */







/* sn-2.95.3-136, -f=-fno-gcse */
__attribute__((section(".text.func_00174890")))
int func_00174890(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    char *mp;
    char *mq;
    float one, ca, cb;
    int i, n, lo, b1, b2;
    unsigned char ok1, ok2;
    int obj1, obj2;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.05680001f;
    cb = 1.05869997f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[5] = cb;
    f[2] = ca;
    f[3] = one;
    f[4] = ca;
    f[6] = ca;
    t[3] = one;
    f[8] = 0.0f;
    f[9] = 0.0f;
    f[10] = 0.0f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, (cGameObj *)p, 2);
    *(void **)(p + 0x650) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, (const struct cMatrix *)(p + 0x80), (const cVec *)m, (const cVec *)nv, (const cVec *)t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    mp = (char *)cModel_getMeshPtr(p, 0);
    *(int *)(mp + 0x380) |= 1;
    mq = (char *)cModel_getMeshPtr(p, 1);
    *(int *)(mq + 0x380) &= 0xFFFFFFFE;
    i = 1;
    if (*(unsigned char *)(p + 0x2B4) != i) {
        lo = 0;
        n = 1;
        while (1) {
        ok1 = ((*(int *)&f[4] = b1 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b1));
        if (ok1) obj1 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj1 = 0;
        *(int *)(obj1 + 0x154) |= CPARTS_NO_LOCAL;
        ok2 = ((*(int *)&f[4] = b2 = *(unsigned char *)(p + 0x2B4)), (n >= lo && i < b2));
        if (ok2) obj2 = *(int *)(*(int *)(p + 0x278) + i * 4); else obj2 = 0;
        *(int *)(obj2 + 0x154) |= CPARTS_NO_PARENT;
        i++;
        n++;
        if (!(i < 13 && *(unsigned char *)(p + 0x2B4) != i)) break;
        }
    }
    return 1;
}
