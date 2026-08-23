/* sn-2.95.3-136 matched TU. */

extern void MtxInitRotY(void *a0, float angle);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern void MtxInverse(void *a0, void *a1);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void func_001B6FB8(void *);
extern int AllocActiveSlot_1FE218(int a0, int a1, int a2);
extern int cDamageUnit_AddDamageCollSphere(int a0, int a1, int a2, float f);
extern void cCollisionSolidManage_CreateUnit(void *a, void *b, int c, float d);
extern void cCollisionSolidManage_CreateSphere(void *a, void *b, void *c, void *d, float e);
extern int D_00574380;
extern int D_00462FC0;
extern void func_001331B8(char *a0, long a1, int a2);
extern int cDamageManage_CreateDamageGive(int a0, int a1, int a2);
extern void cDamageUnit_SetDamageCollActive(int a0, int a1);
extern char D_005CAE50[];
extern int cModel_setupModel(void *a0, int a1, int a2, int a3, int t0);
extern void cModel_calcParts(void *a0);
extern void func_00100870(void *a0);
extern char *D_00747A98;
extern float D_003BD880[];

#include "godhand/vu0.h"






__attribute__((section(".text.func_00260A10")))
void func_00260A10(char *this, int idx, float *dst)
{
    char frame[0xC0];
    char *m;
    char *inv;
    char *tmp;
    int b;
    int obj;
    unsigned char ok;

    {
        float *s = *(float **)(this + 0xF0);
        if (dst != s) { dst[0] = s[0]; dst[1] = s[1]; dst[2] = s[2]; }
    }
    ok = ((*(int *)frame = b = *(unsigned char *)(this + 0x2B4)), (idx >= 0 && idx < b));
    if (ok) obj = *(int *)(*(int *)(this + 0x278) + idx * 4); else obj = 0;
    if (obj == 0) return;
    VU0_SQC2_VF0(frame, 0x90);
    m = frame + 0x10;
    MtxInitRotY(m, *(float *)(this + 0x104));
    CopyVec3ToField30_147C40((float *)m, *(float **)(this + 0xF0));
    inv = frame + 0x50;
    MtxInverse(inv, m);
    tmp = frame + 0xB0;
    VU0_LQC2(4, *(char **)(obj + 0xF0), 0);
    VU0_SQC2(4, frame, 0xB0);
    sceVu0ApplyMatrix(tmp, inv, tmp);
    VU0_LQC2(4, tmp, 0);
    VU0_SQC2(4, frame, 0xA0);
    *(float *)(frame + 0x90) = *(float *)(frame + 0xA0);
    *(float *)(frame + 0x94) = *(float *)(frame + 0xA4);
    *(float *)(frame + 0x98) = *(float *)(frame + 0xA8);
    if (dst != (float *)(frame + 0x90)) {
        dst[0] = *(float *)(frame + 0x90);
        dst[1] = *(float *)(frame + 0x94);
        dst[2] = *(float *)(frame + 0x98);
    }
}

__attribute__((section(".text.func_001B0340")))
int func_001B0340(char *p)
{
    float buf[12];
    int n;
    int flag;

    func_001B6FB8(p);
    buf[0] = 0.0f;
    buf[1] = 0.0f;
    buf[2] = 0.0f;
    buf[3] = 1.0f;
    *(int *)(p + 0x600) = AllocActiveSlot_1FE218((int)&D_00574380, (int)p, 1);
    if (*(int *)(p + 0x600) != 0) {
        flag = *(unsigned char *)(p + 0x2B4);
        *(int *)(buf + 4) = flag;
        if (flag) n = **(int **)(p + 0x278); else n = 0;
        cDamageUnit_AddDamageCollSphere(*(int *)(p + 0x600), n + 0x80, (int)buf, 1.5f);
        *(int *)(*(int *)(p + 0x600)) |= 1;
    }
    *(short *)(p + 0x548) = 0x3E8;
    *(short *)(p + 0x54A) = 0x3E8;
    cCollisionSolidManage_CreateUnit(&D_00462FC0, p, 1, 0.3f);
    {
        float *sph = buf + 8;
        buf[8] = 0.0f;
        sph[1] = 1.5f;
        buf[10] = 0.0f;
        sph[3] = 1.0f;
        cCollisionSolidManage_CreateSphere(&D_00462FC0, p, p + 0x80, sph, 1.5f);
    }
    *(int *)(p + 0x5B8) |= 8;
    *(char *)(p + 0x624) = 0;
    *(short *)(p + 0x622) = 0;
    return 1;
}

__attribute__((section(".text.cOmThrow_SetParent")))
void cOmThrow_SetParent(char *p, char *parent)
{
    float buf[8];
    float *sph;
    int n;
    int flag;
    int obj;

    {
        char *vt = *(char **)(p + 0x214);
        short off = *(short *)(vt + 0xA8);
        void (*fp)() = *(void (**)())(vt + 0xAC);
        fp(p + off);
    }
    func_001331B8(D_005CAE50, *(long *)(p + 0x540), 0);
    *(int *)(p + 0x600) = cDamageManage_CreateDamageGive((int)&D_00574380, 0, (int)p);
    flag = *(unsigned char *)(p + 0x2B4);
    *(int *)buf = flag;
    if (flag) n = **(int **)(p + 0x278); else n = 0;
    buf[4] = 0.0f;
    buf[5] = 0.0f;
    buf[6] = 0.0f;
    sph = buf + 4;
    sph[3] = 1.0f;
    *(int *)(p + 0x604) = cDamageUnit_AddDamageCollSphere(*(int *)(p + 0x600), n + 0x80,
                                                          (int)sph, 0.5f);
    cDamageUnit_SetDamageCollActive(*(int *)(p + 0x600), 0);
    *(int *)(p + 0x644) = (int)parent;
    *(char *)(p + 0x2F4) = 0;
    *(char *)(p + 0x2F5) = 0;
    *(char *)(p + 0x2F6) = 0;
    *(char *)(p + 0x2F7) = 0;
    {
        int flag2 = *(unsigned char *)(p + 0x2B4);
        *(int *)buf = flag2;
        if (flag2) obj = **(int **)(p + 0x278); else obj = 0;
    }
    if (obj != 0) {
        float *s = *(float **)(obj + 0xD0);
        float *d = (float *)(p + 0x630);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
        *(int *)(p + 0x624) = 0;
        *(char *)(p + 0x640) = 0;
    }
}

__attribute__((section(".text.func_00100378")))
int func_00100378(char *p)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int t, ret, b;
    char *o;

    ret = 0;
    t = *(int *)(p + 0x304);
    if (cModel_setupModel(p, *(int *)(t + 4) + t, *(int *)(t + 8) + t, 0, 0) != 0) {
        ret = 1;
        *(int *)(p + 0x2F0) |= 0x80;
        *(int *)(p + 0x250) |= 0x10000;
        *(int *)(p + 0x20D0) = 0;
        b = *(unsigned char *)(p + 0x2B4);
        *(int *)frame = b;
        if (b) o = (char *) **(int **)(p + 0x278); else o = 0;
        if (o != 0) {
            {
                int b2 = *(unsigned char *)(p + 0x2B4);
                char *o2;
                float *d;
                *(int *)frame = b2;
                if (b2) o2 = (char *) **(int **)(p + 0x278); else o2 = 0;
                d = (float *)(o2 + 0xE0);
                d[0] = D_003BD880[0];
                d[1] = D_003BD880[1];
                d[2] = D_003BD880[2];
            }
            {
                int b3 = *(unsigned char *)(p + 0x2B4);
                char *o3;
                float *d;
                *(int *)frame = b3;
                if (b3) o3 = (char *) **(int **)(p + 0x278); else o3 = 0;
                d = *(float **)(o3 + 0xD0);
                d[0] = D_003BD880[0];
                d[1] = D_003BD880[1];
                d[2] = D_003BD880[2];
            }
        }
        cModel_calcParts(p);
        func_00100870(p);
        D_00747A98 = p;
    }
    *(int *)(p + 0x254) |= 0x8000000;
    *(int *)(p + 0x2F0) |= 1;
    return ret;
}
