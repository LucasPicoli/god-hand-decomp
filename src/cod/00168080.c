/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cRoomSave.h"

extern char D_00585240[];
extern char D_00585450[];
extern void Obj0000_Set_D_007474A0_Fields_5D8_5E0(int a0);
extern int cIDBase_release(int a0);
extern void func_00161590(int a0);
extern char **D_003C2384;
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float f, int t0, int t1);
extern float fRand1_1(void);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern char D_00462FC0[];

/* Fill the 11 trail-sprite records of the table at D_00585240: each is a 0x30-byte record holding two kind bytes, a position pair and two vectors with the same Y. */



#define SET_ENT(e, a, b, x, y, vy)                  \
    {                                               \
        float *v;                                   \
        float *w;                                   \
                                                    \
        func_003A52F0(e, 0, 0x30);                  \
        *(unsigned char *)(e + 0x2) = a;            \
        *(unsigned char *)(e + 0x3) = b;            \
        *(float *)(e + 0x4) = x;                    \
        *(float *)(e + 0x8) = y;                    \
        v = (float *)(e + 0x10);                    \
        *(int *)(e + 0x10) = 0;                     \
        v[1] = vy;                                  \
        v[2] = 0.0f;                                \
        v[3] = 1.0f;                                \
        w = (float *)(e + 0x20);                    \
        *(int *)(e + 0x20) = 0;                     \
        w[1] = vy;                                  \
        w[2] = 0.0f;                                \
        w[3] = 1.0f;                                \
    }

__attribute__((section(".text.InitTrailSpriteTableA")))
void InitTrailSpriteTableA(void *a0, int a1)
{
    char *e;

    if (a1 != 0xFFFF)
        return;
    if (a0 == 0)
        return;
    e = D_00585240;
    SET_ENT(e, 0x11, 0x11, 1.0f, 0.15f, -0.2f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x12, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x13, 0.66f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x13, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x13, 0x13, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x13, 0x14, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x16, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x17, 0.66f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x17, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x17, 0x17, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x17, 0x18, 0.33f, 0.11f, 0.0f)
}

/* Fill the 11 trail-sprite records of the table at D_00585450: each is a 0x30-byte record holding two kind bytes, a position pair and two vectors with the same Y. */



#define SET_ENT(e, a, b, x, y, vy)                  \
    {                                               \
        float *v;                                   \
        float *w;                                   \
                                                    \
        func_003A52F0(e, 0, 0x30);                  \
        *(unsigned char *)(e + 0x2) = a;            \
        *(unsigned char *)(e + 0x3) = b;            \
        *(float *)(e + 0x4) = x;                    \
        *(float *)(e + 0x8) = y;                    \
        v = (float *)(e + 0x10);                    \
        *(int *)(e + 0x10) = 0;                     \
        v[1] = vy;                                  \
        v[2] = 0.0f;                                \
        v[3] = 1.0f;                                \
        w = (float *)(e + 0x20);                    \
        *(int *)(e + 0x20) = 0;                     \
        w[1] = vy;                                  \
        w[2] = 0.0f;                                \
        w[3] = 1.0f;                                \
    }

__attribute__((section(".text.InitTrailSpriteTableB")))
void InitTrailSpriteTableB(void *a0, int a1)
{
    char *e;

    if (a1 != 0xFFFF)
        return;
    if (a0 == 0)
        return;
    e = D_00585450;
    SET_ENT(e, 0x11, 0x11, 1.0f, 0.15f, -0.2f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x12, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x13, 0.66f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x12, 0x13, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x13, 0x13, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x13, 0x14, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x16, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x17, 0.66f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x16, 0x17, 0.33f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x17, 0x17, 1.0f, 0.11f, 0.0f)
    e += 0x30;
    SET_ENT(e, 0x17, 0x18, 0.33f, 0.11f, 0.0f)
}

/* Reset an object: base reset, clear the flag byte when the mode byte is 1, release its id, clear two counters on the shared record. */





__attribute__((section(".text.ResetObjModeAndReleaseId")))
void ResetObjModeAndReleaseId(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    if (*(unsigned char *)(a0 + 0x64) == 1) {
        *(char *)(a0 + 0x90) = 0;
    }
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0xB4) = 0;
    *(int *)(p + 0xB0) = 0;
    func_00161590(a0);
}

/* Phase machine of the enemy that hops away from the player: it picks a random hop vector, counts
 * the hop down by speedRate, moves along it, then plays the landing motions. */
__attribute__((section(".text.cEm00_stepHopAway"))) void cEm00_stepHopAway(cEm00 *self)
{
    float va[4];
    float vb[4];
    float vc[4];
    float zero;
    float k;
    float f;
    int gb;
    int v;
    char *p;
    char *q;
    float *dp;
    float *pb;
    VU0_SQC2_VF0((char *)va, 0);
    switch (self->step) {
        case 0:
            zero = 0.0f;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x1D80), EM_RES_REC(v, 0x1D84), 0, 0.0f, gb, 0);
            self->unk580.x = (fRand1_1() * 5.0f) + zero;
            self->unk580.y = 2.724f;
            self->unk580.z = (fRand1_1() * 5.0f) + zero;
            self->timer = 90.0f;
            self->timer2 = 30.0f;
            switch (self->emNo) {
                case 0x220:

                default:
                    InitRenderStruct_2A8608(self, 0xC2, 0x14, 0, 2, 0);
                    break;

                case 0x221:
                    InitRenderStruct_2A8608(self, 0xC2, 0x1A, 0, 2, 0);
                    break;

                case 0x222:
                    InitRenderStruct_2A8608(self, 0xC2, 0x18, 0, 2, 0);
                    break;
            }

            self->step += 1;

        case 1:
            self->emFlags |= 0x30000;
            cCollisionSolidManage_SetActive(D_00462FC0, self, 0);
            if (0.0f < self->timer2) {
                self->timer2 = self->timer2 - self->speedRate;
                self->hitFlash = 3.0f;
            } else {
                p = (char *)self->pos;
                q = &self->unk580;
                pb = vb;
                VU0_SQC2_VF0((char *)va, 0x20);
                CEM00_REGALLOC_NUDGE(self);
                VU0_LQC2(4, q, 0);
                VU0_LQC2(5, p, 0);
                VU0_VSUB_XYZ(4, 4, 5);
                VU0_SQC2(4, (char *)va, 0x20);
                VU0_LQC2(4, vc, 0);
                VU0_SQC2(4, (char *)va, 0x10);
                dp = va;
                if (dp != pb) {
                    float t0;
                    float t1;
                    float t2;
                    t0 = vb[0];
                    t1 = vb[1];
                    t2 = vb[2];
                    dp[0] = t0;
                    dp[1] = t1;
                    dp[2] = t2;
                }
                k = self->speedRate * 0.05f;
                VU0_LQC2(4, (char *)va, 0);
                VU0_LOAD_SCALAR(5, k);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, (char *)va, 0);
                VU0_VADD_XYZ_IP((char *)self->pos, 0, (char *)va);
                f = self->timer;
                f = f - self->speedRate;
                self->timer = f;
                if (f <= 0.0f) {
                    self->step += 1;
                }
            }
            moveMotion(self);
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;

        case 2:
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            v = self->resource;
            func_002A8578(self, EM_RES_REC(v, 0x1D88), EM_RES_REC(v, 0x1D8C), 3, 0.0f, gb, 0);
            switch (self->emNo) {
                case 0x220:

                default:
                    InitRenderStruct_2A8608(self, 0xC2, 0x15, 0, 2, 0);
                    break;

                case 0x221:
                    InitRenderStruct_2A8608(self, 0xC2, 0x1B, 0, 2, 0);
                    break;

                case 0x222:
                    InitRenderStruct_2A8608(self, 0xC2, 0x19, 0, 2, 0);
                    break;
            }

            self->step += 1;

        case 3:
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }
}

/* Enemy record number idx of the current page, or 0 past the used count. */
__attribute__((section(".text.cRoomSave_getEm")))
cRoomSaveEm *cRoomSave_getEm(cRoomSave *self, unsigned int idx) {
    if (idx < func_002BEDD8(self)) {
        return &self->data->em[idx];
    }
    return 0;
}

/* The enemy record whose id is `id` (0xFF means none), or 0. */
__attribute__((section(".text.cRoomSave_findEm")))
cRoomSaveEm *cRoomSave_findEm(cRoomSave *self, unsigned int id) {
    unsigned int i;
    cRoomSaveEm *em;
    if (id == 0xFF) return 0;
    for (i = 0; i < func_002BEDD8(self); i++) {
        em = cRoomSave_getEm(self, i);
        if (em != 0 && em->id == id) return em;
    }
    return 0;
}
