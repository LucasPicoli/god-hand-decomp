/* sn-2.95.3-136 matched TU. */

extern int D_003C2388;
extern int D_003C11B0;
extern void *cIDManager_getTexAddr(int a, int b, int c);
extern void func_001DEE20(void *p);
extern void func_001DD1F8(void *p);
extern int InitFields_1B6E90(void *);
extern char D_00428650[];
extern char D_00421A08[];

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

__attribute__((section(".text.PokerId__Trans")))
void PokerId__Trans(char *self)
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

    func_001DEE20(self + 0x25B0);
    func_001DD1F8(self);

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

    tex = cIDManager_getTexAddr(D_003C2388, 0x12, 1);

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
}

/* sn-2.95.3-136 matched TU. */




#include "godhand/vu0.h"




__attribute__((section(".text.func_001B36E0")))
void *func_001B36E0(void *arg) {
    char *self = (char *)arg;
    char *q;
    int *r;
    unsigned int i;

    InitFields_1B6E90(self);
    *(char **)(self + 0x214) = D_00428650;
    q = self + 0x610;
    VU0_SQC2_VF0(self, 0x660);
    VU0_SQC2_VF0(self, 0x670);
    VU0_SQC2_VF0(self, 0x680);
    VU0_SQC2_VF0(self, 0x690);
    VU0_SQC2_VF0(self, 0x6A0);
    VU0_SQC2_VF0(self, 0x6B0);
    VU0_SQC2_VF0(self, 0x6C0);
    VU0_SQC2_VF0(self, 0x6D0);
    VU0_SQC2_VF0(self, 0x6E0);
    VU0_SQC2_VF0(self, 0x6F0);
    VU0_SQC2_VF0(self, 0x700);
    VU0_SQC2_VF0(self, 0x710);
    VU0_SQC2_VF0(self, 0x720);
    VU0_SQC2_VF0(self, 0x730);

    *(char *)(q + 0x0) = 0;
    *(char *)(q + 0x1) = 0;
    *(char *)(q + 0x2) = 0;
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

    i = 0;
    r = (int *)(q + 0xC);
    for (; i < 8; i++) {
        *r = 0;
        r++;
    }

    *(int *)(self + 0x600) = 0;
    return self;
}

/* sn-2.95.3-136 candidate. */




#include "godhand/vu0.h"

__attribute__((section(".text.func_0017AAD8")))
void *func_0017AAD8(void *arg) {
    char *self = (char *)arg;
    char *q;
    int *r;
    unsigned int i;

    InitFields_1B6E90(self);
    *(char **)(self + 0x214) = D_00421A08;
    q = self + 0x610;
    VU0_SQC2_VF0(self, 0x660);
    VU0_SQC2_VF0(self, 0x670);
    VU0_SQC2_VF0(self, 0x680);
    VU0_SQC2_VF0(self, 0x690);
    VU0_SQC2_VF0(self, 0x6A0);
    VU0_SQC2_VF0(self, 0x6B0);
    VU0_SQC2_VF0(self, 0x6C0);
    VU0_SQC2_VF0(self, 0x6D0);
    VU0_SQC2_VF0(self, 0x6E0);
    VU0_SQC2_VF0(self, 0x6F0);
    VU0_SQC2_VF0(self, 0x700);
    VU0_SQC2_VF0(self, 0x710);
    VU0_SQC2_VF0(self, 0x720);
    VU0_SQC2_VF0(self, 0x730);

    *(char *)(q + 0x0) = 0;
    *(char *)(q + 0x1) = 0;
    *(char *)(q + 0x2) = 0;
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

    i = 0;
    r = (int *)(q + 0xC);
    for (; i < 8; i++) {
        *r = 0;
        r++;
    }

    q = self + 0x770;
    VU0_SQC2_VF0(self, 0x7C0);
    VU0_SQC2_VF0(self, 0x7D0);
    VU0_SQC2_VF0(self, 0x7E0);
    VU0_SQC2_VF0(self, 0x7F0);
    VU0_SQC2_VF0(self, 0x800);
    VU0_SQC2_VF0(self, 0x810);
    VU0_SQC2_VF0(self, 0x820);
    VU0_SQC2_VF0(self, 0x830);
    VU0_SQC2_VF0(self, 0x840);
    VU0_SQC2_VF0(self, 0x850);
    VU0_SQC2_VF0(self, 0x860);
    VU0_SQC2_VF0(self, 0x870);
    VU0_SQC2_VF0(self, 0x880);
    VU0_SQC2_VF0(self, 0x890);

    *(char *)(q + 0x0) = 0;
    *(char *)(q + 0x1) = 0;
    *(char *)(q + 0x2) = 0;
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

    i = 0;
    r = (int *)(q + 0xC);
    for (; i < 8; i++) {
        *r = 0;
        r++;
    }

    VU0_SQC2_VF0(self, 0x8D0);
    return self;
}
