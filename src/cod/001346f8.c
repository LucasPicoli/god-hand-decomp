/* sn-2.95.3-136 matched TU. */

extern int D_003C2388;
extern int D_003C11B0;
extern void *cIDManager_getTexAddr(int a, int b, int c);
extern void cIDBase_trans(void *p);
extern void func_002BC6C8(void *a0, void *a1, void *pts);
extern void func_002BB760(void *a0, void *a1, void *pts, float h);
extern void *cModel_getMeshPtr(void *m, int i);
extern void *D_00754C38;
extern void *D_00754C58;
extern void *InitFields_1B6E90(void *this);
extern void Obj0000_Set_Byte_54(void *obj, int v);
extern unsigned char D_00424B68[];

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"




extern void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                             int t0, int t1, void *cfg, int t3, int extra);


static __inline__ void SetVec4(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = 1.0f;
}

static __inline__ void CopyVec3(float *d, float *s)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

__attribute__((section(".text.BlackJackId__Trans")))
void BlackJackId__Trans(char *self)
{
    char cfg[0x50];
    float v[4][4];
    float ta[4];
    float tb[4];
    float tmp[4];
    void *tex;
    void *r;
    char *z;
    int i;

    *(int *)(cfg + 0x0) = 1;
    z = (char *)v;
    i = 3;
    do {
        VU0_SQC2_VF0(z, 0x0);
        z += 0x10;
    } while (--i != -1);
    VU0_SQC2_VF0((char *)ta - 0xA0, 0xA0);
    VU0_SQC2_VF0((char *)ta - 0xA0, 0xB0);

    SetVec4(tmp, -1.0f, -1.0f, 0.0f);
    CopyVec3(ta, tmp);
    SetVec4(tmp, 513.0f, 448.0f, 0.0f);
    CopyVec3(tb, tmp);

    tex = cIDManager_getTexAddr(D_003C2388, 0x13, 1);

    SetVec4(v[0], ta[0], ta[1], 0.0f);
    SetVec4(v[1], tb[0], ta[1], 0.0f);
    SetVec4(v[2], ta[0], tb[1], 0.0f);
    SetVec4(v[3], tb[0], tb[1], 0.0f);

    *(int *)(cfg + 0x4) = 0;
    *(int *)(cfg + 0x8) = 0;
    *(float *)(cfg + 0xC) = 1.0f;
    *(float *)(cfg + 0x10) = 0.875f;

    r = Gp_draw_polyFT4(v, 0x80808080, 1, tex, D_003C11B0, 0x1CF0, cfg, 0, 5);
    if (r != 0) {
        *(long *)((char *)r + 0x1A0) = 0x3001D;
    }
    cIDBase_trans(self + 0x10);
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"



__attribute__((section(".text.func_002BCB80")))
void func_002BCB80(void *a0, void *a1, float *ext)
{
    char buf[0x90];
    char *p;
    float *v1;
    float *v2;
    float *v3;
    float *v4;
    float *v5;
    float *v6;
    float *v7;
    float w;
    float t;
    int i;

    p = buf;
    i = 7;
    do {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    } while (--i != -1);

    VU0_LQC2(4, ext, 0x0);
    VU0_SQC2(4, buf, 0x80);
    t = 0.5f;
    VU0_LQC2(4, buf, 0x80);
    VU0_LOAD_SCALAR(5, t);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x80);

    v1 = (float *)(buf + 0x10);
    v2 = (float *)(buf + 0x20);
    v3 = (float *)(buf + 0x30);
    v4 = (float *)(buf + 0x40);
    v5 = (float *)(buf + 0x50);
    v6 = (float *)(buf + 0x60);
    v7 = (float *)(buf + 0x70);
    w = ext[1];

    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        *(float *)(buf + 0x0) = -xx;
        *(float *)(buf + 0x4) = 0.0f;
        *(float *)(buf + 0x8) = -zz;
        v1[0] = xx;
        v1[1] = 0.0f;
        v1[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v2[0] = -xx;
        v2[1] = 0.0f;
        v2[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v3[0] = xx;
        v3[1] = 0.0f;
        v3[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v4[0] = -xx;
        v4[1] = w;
        v4[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v5[0] = xx;
        v5[1] = w;
        v5[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v6[0] = -xx;
        v6[1] = w;
        v6[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v7[0] = xx;
        v7[1] = w;
        v7[2] = zz;
    }

    func_002BC6C8(a0, a1, buf);
}

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"



__attribute__((section(".text.cCollisionUtils_checkRectboxPoint")))
void cCollisionUtils_checkRectboxPoint(void *a0, float *ext, void *a2)
{
    char buf[0x90];
    char *p;
    float *v1;
    float *v2;
    float *v3;
    float *v4;
    float *v5;
    float *v6;
    float *v7;
    float w;
    float t;
    int i;

    p = buf;
    i = 7;
    do {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    } while (--i != -1);

    VU0_LQC2(4, ext, 0x0);
    VU0_SQC2(4, buf, 0x80);
    t = 0.5f;
    VU0_LQC2(4, buf, 0x80);
    VU0_LOAD_SCALAR(5, t);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x80);

    v1 = (float *)(buf + 0x10);
    v2 = (float *)(buf + 0x20);
    v3 = (float *)(buf + 0x30);
    v4 = (float *)(buf + 0x40);
    v5 = (float *)(buf + 0x50);
    v6 = (float *)(buf + 0x60);
    v7 = (float *)(buf + 0x70);
    w = ext[1];

    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        *(float *)(buf + 0x0) = -xx;
        *(float *)(buf + 0x4) = 0.0f;
        *(float *)(buf + 0x8) = -zz;
        v1[0] = xx;
        v1[1] = 0.0f;
        v1[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v2[0] = -xx;
        v2[1] = 0.0f;
        v2[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v3[0] = xx;
        v3[1] = 0.0f;
        v3[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v4[0] = -xx;
        v4[1] = w;
        v4[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v5[0] = xx;
        v5[1] = w;
        v5[2] = -zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v6[0] = -xx;
        v6[1] = w;
        v6[2] = zz;
    }
    {
        float xx = *(float *)(buf + 0x80);
        float zz = *(float *)(buf + 0x88);
        v7[0] = xx;
        v7[1] = w;
        v7[2] = zz;
    }

    func_002BB760(a2, a0, buf, 0.0f);
}

/* sn-2.95.3-136 candidate. */





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

__attribute__((section(".text.HideModelMgr_ResetHiddenModels")))
void HideModelMgr_ResetHiddenModels(void)
{
    char *n;
    char **p;
    char **q;
    unsigned short k;
    long found;

    p = *(char ***)((char *)D_00754C38 + 4);
    while ((unsigned int)p < *(unsigned int *)((char *)D_00754C38 + 8)) {
        n = (char *)cModel_getMeshPtr(*p, 0);
        while (n != 0) {
            *(unsigned int *)(n + 0x380) =
                *(unsigned int *)(n + 0x380) & 0xFFFFFFFE;
            n = *(char **)(n + 0x404);
        }
        p++;
    }
    q = *(char ***)((char *)D_00754C58 + 4);
    while ((unsigned int)q < *(unsigned int *)((char *)D_00754C58 + 8)) {
        found = 0;
        k = *(unsigned short *)(*q + 0x2FE);
        if ((inrange(k, 0x100, 0x1FF) & 0xFF) || (inrange(k, 0x200, 0x300) & 0xFF) ||
            (inrange(k, 0x300, 0x500) & 0xFF) || (inrange(k, 0x500, 0x600) & 0xFF))
            found = 1;
        if (found & 0xFF) {
            *(int *)(*q + 0x5A0) = *(int *)(*q + 0x5A0) & ~2;
        }
        q++;
    }
}

/* sn-2.95.3-136 candidate. */





#include "godhand/vu0.h"

__attribute__((section(".text.func_00193EA8")))
void *func_00193EA8(unsigned char *this) {
    unsigned char *p;
    unsigned char *q;
    int *r;
    int i;
    unsigned int j;

    InitFields_1B6E90(this);

    *(unsigned char **)(this + 0x214) = D_00424B68;
    VU0_SQC2_VF0(this, 0x620);
    p = this + 0x630;

    i = 9;
    while (i--) {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }

    q = this + 0x990;

    VU0_SQC2_VF0(this, 0x9E0);
    VU0_SQC2_VF0(this, 0x9F0);
    VU0_SQC2_VF0(this, 0xA00);
    VU0_SQC2_VF0(this, 0xA10);
    VU0_SQC2_VF0(this, 0xA20);
    VU0_SQC2_VF0(this, 0xA30);
    VU0_SQC2_VF0(this, 0xA40);
    VU0_SQC2_VF0(this, 0xA50);
    VU0_SQC2_VF0(this, 0xA60);
    VU0_SQC2_VF0(this, 0xA70);
    VU0_SQC2_VF0(this, 0xA80);
    VU0_SQC2_VF0(this, 0xA90);
    VU0_SQC2_VF0(this, 0xAA0);
    VU0_SQC2_VF0(this, 0xAB0);

    *(unsigned char *)(this + 0x990) = 0;
    q[0x1] = 0;
    q[0x2] = 0;
    *(int *)(q + 0x4) = 0;
    *(int *)(q + 0x8) = 0;
    *(int *)(q + 0x30) = 0;
    *(int *)(q + 0x34) = 0;
    *(int *)(q + 0x38) = 0;
    *(int *)(q + 0x3C) = 0;
    *(int *)(q + 0x130) = 0;
    *(int *)(q + 0x134) = 0;
    *(int *)(q + 0x138) = 0;
    *(int *)(q + 0x13C) = 0;

    j = 0;
    r = (int *)(this + 0x99C);
    for (; j < 8; j++) {
        *r = 0;
        r++;
    }

    VU0_SQC2_VF0(this, 0xB10);
    *(int *)(this + 0x614) = 0;
    *(int *)(this + 0xB20) = 0;

    return this;
}

/* sn-2.95.3-136 candidate. */

typedef struct Unit {
    char pad[0x10];
    struct Unit *next;
} Unit;

typedef struct {
    Unit *head;
    int count;
} Mgr;



extern Unit *func_00134430(void *mem, void *a, int b, float f);

__attribute__((section(".text.cCollisionSolidManage_CreateUnit")))
void cCollisionSolidManage_CreateUnit(Mgr *m, void *a, int b, float f)
{
    Unit *p;
    Unit *q;

    if (a != 0) {
        if (func_001346C8(m, a) == 0) {
            if (m->head != 0) {
                q = m->head;
                while (q->next != 0) {
                    q = q->next;
                }
                p = func_00134430(func_0030F550(0x40), a, b, f);
                q->next = p;
            } else {
                p = func_00134430(func_0030F550(0x40), a, b, f);
                m->head = p;
            }
            if (p != 0) {
                do { m->count = m->count + 1; } while (0);
            }
        }
    }
}
