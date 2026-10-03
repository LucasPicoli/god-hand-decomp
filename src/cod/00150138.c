/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cModel.h"
#include "godhand/cOm1f.h"

extern void func_001B6FB8(void *a0);
extern void *cDamageManage_CreateDamageTake(void *a0, void *a1, int a2);
extern void func_001FD9D8(void *a0, void *a1, float *a2, float *a3, float *t0);
extern void func_001BFB28(void *a0);
extern int D_00574380;
extern int D_0071B7C0[];
extern int D_0071B840[];
extern int D_0071B8C0[];
extern unsigned char D_0061B7C0[];
extern void func_002FEB80(char *p, int a0, int a1);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00262750(void *a0, int a1);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_0026E7A8(void *a0, int a1);
extern float fRand0_1(void);
extern void func_002705D8(void *a0);
extern void Adjust_theta_vec(cVec *v);
extern void MtxInitTransVec(cParts *part, cVec *trans);
extern void MtxMulRotVec(cParts *dst, cParts *src, cVec *rot, int order);
extern void MtxMulScaleVec(cParts *dst, cParts *src, cVec *scale);

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.SpawnDamageTakeVolumeF")))
int SpawnDamageTakeVolumeF(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 1.0f;
    cb = 1.36f;
    cc = 0.2f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[3] = one;
    f[4] = ca;
    f[1] = cb;
    f[2] = cc;
    f[6] = cc;
    f[5] = cb;
    t[3] = one;
    f[8] = 0.0f;
    f[10] = 0.0f;
    f[9] = f[1] * -0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    return 1;
}

/* Spawn the damage-take volume of an object: build the three float vectors and register them, then set the two shorts at +0x548 and +0x54A. */






__attribute__((section(".text.SpawnDamageTakeVolumeG")))
int SpawnDamageTakeVolumeG(char *p)
{
    float f[16];
    float *m;
    float *nv;
    float *t;
    void *slot;
    float one, ca, cb, cc;

    func_001B6FB8(p);
    one = 1.0f;
    ca = 2.0f;
    cb = 2.0f;
    cc = 0.4f;
    t = &f[4];
    m = &f[8];
    f[0] = ca;
    f[1] = cb;
    f[2] = cc;
    f[4] = ca;
    f[6] = cc;
    f[5] = cb;
    f[3] = one;
    t[3] = one;
    f[8] = 0.0f;
    f[10] = 0.0f;
    f[9] = f[5] * -0.5f;
    m[3] = one;
    slot = cDamageManage_CreateDamageTake(&D_00574380, p, 2);
    *(void **)(p + 0x600) = slot;
    if (slot != 0) {
        nv = &f[12];
        f[12] = 0.0f;
        f[13] = 0.0f;
        f[14] = 0.0f;
        nv[3] = one;
        func_001FD9D8(slot, p + 0x80, m, nv, t);
    }
    *(short *)(p + 0x548) = 1;
    *(short *)(p + 0x54A) = 1;
    func_001BFB28(p);
    *(int *)(p + 0x5B8) |= 0x200;
    return 1;
}

/* Walk the 0x400 object slots; for each live, non-paused slot whose id pair equals (a0, a1) run its handler. */






__attribute__((section(".text.ForEachSlotRunHandler")))
void ForEachSlotRunHandler(int a0, int a1)
{
    char *p;
    int i;
    unsigned int mask;
    int w;

    for (i = 0; i < 0x400; i++) {
        w = (unsigned int)i >> 5;
        mask = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & mask) == 0) goto next;
        if ((D_0071B840[w] & mask) != 0) goto next;
        if ((D_0071B8C0[w] & mask) != 0) goto next;
        p = (char *)D_0061B7C0 + i * 0x400;
        if (*(int *)(p + 0x10C) != a1) goto next;
        if (*(int *)(p + 0x108) != a0) goto next;
        func_002FEB80(p, a0, a1);
next: ;
    }
}

/* cEm00_stepDropToFloor: 190/194 exact (97.9%), insn delta 0, REG 4: in case 2 the vector-sub block, retail holds the *(F0) pointer in a0 and the s0+0x6D0 pointer in v1, ours v1 and v0. Bodies 3 (see w/), permuter run ~9k iters no better. */








extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);




#define FRAME ((char *)va - 0x30)
__attribute__((section(".text.cEm00_stepDropToFloor")))
void cEm00_stepDropToFloor(cEm00 *self)
{
    float va[4], vb[4], vc[4];
        int gb;
    switch (self->step) {
    case 0:
    {
        int p;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        p = self->resource;
        func_002A8578(self, EM_RES_REC(p, 0x434),
                      EM_RES_REC(p, 0x438), 0.0f, 3, gb, 0);
    }
        self->step += 1;
        /* fallthrough */
    case 1:
        self->emFlags |= 0x1000;
        func_00262750(self, 2);
        self->emFlags |= 0x10000;
        self->emFlags |= 0x20000;
        if (moveMotion(self) != 0) {
            self->step = 2;
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        if (self->moveFlags & 0x10) {
            float *dv = va;
            float *d;
            float *q;
            VU0_SQC2_VF0(FRAME, 0x30);
            VU0_SQC2_VF0(FRAME, 0x40);
            VU0_SQC2_VF0(FRAME, 0x50);
            d = (float *)(&self->posA);
            if (dv != d) {
                va[0] = self->posA.x;
                do { } while (0);
                dv[1] = d[1];
                do { } while (0);
                dv[2] = d[2];
            }
            q = (float *)self->pos;
            if (vb != q) {
                vb[0] = q[0];
                vb[1] = q[1];
                vb[2] = q[2];
            }
            va[1] = va[1] + 0.5f;
            if (ChkLine(va, vb, vc, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                float *r = (float *)self->pos;
                r[1] = vc[1];
                self->step = 2;
            }
        }
        break;
    case 2: {
        int a1v, a2v;
        int p;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        p = self->resource;
        a1v = EM_RES_REC(p, 0x10C);
        a2v = EM_RES_REC(p, 0x110);
        func_0026E7A8(self, (int)self->pos);
        {
            char *b = (char *)self->pos;
            char *a = &self->unk6D0;
            VU0_SQC2_VF0(FRAME, 0x40);
            CEM00_REGALLOC_NUDGE(self);
            VU0_LQC2(4, a, 0);
            VU0_LQC2(5, b, 0);
        }
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, FRAME, 0x40);
        VU0_LQC2(4, (char *)vb, 0);
        VU0_SQC2(4, FRAME, 0x30);
        {
            char *d = &self->unk580;
            char *sv = (char *)va;

            if (d != sv) {
                float t0 = va[0];
                float t1 = *(float *)(sv + 4);
                float t2;

                self->unk580.x = t0;
                *(volatile float *)(d + 4) = t1;
                t2 = *(volatile float *)(sv + 8);
                *(float *)(d + 8) = t2;
            }
        }
        self->rot.y = self->unk6E0;
        func_002A8578(self, a1v, a2v, 0.0f, 3, gb, 0);
        self->step += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(self) != 0) {
            self->idleTimer = fRand0_1() * 5.0f * 30.0f + 150.0f;
            func_002705D8(self);
        }
        cObjBase_addNullSpeed_Rotation(self, 1.0f);
        cObjBase_addNullSpeed(self, 1.0f);
        break;
    }
}

__attribute__((section(".text.cParts_calcLocal")))
void cParts_calcLocal(cParts *part) {
    cVec rot;
    rot.x = part->rot.x + part->rotAdd.x;
    rot.y = part->rot.y + part->rotAdd.y;
    rot.z = part->rot.z + part->rotAdd.z;
    rot.w = 1.0f;
    Adjust_theta_vec(&rot);
    MtxInitTransVec(part, part->anchor);
    MtxMulRotVec(part, part, &rot, 0);
    MtxMulScaleVec(part, part, &part->scale);
}

/* Restart the state bytes from the set type: type 1 enters mode 1 at phase 1,
 * anything else enters mode 1 at phase 0. */
__attribute__((section(".text.cOm1f_setStart")))
void cOm1f_setStart(cOm1f *self) {
    int type = self->setType;
    switch (type) {
    case 0:
    default:
        self->base.stepArg = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.mode = 1;
        return;
    case 1:
        self->base.stepArg = 0;
        self->base.mode = type;
        self->base.step = 0;
        self->base.phase = type;
        return;
    }
}
