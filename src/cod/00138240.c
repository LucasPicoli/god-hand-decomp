/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cPlCamera.h"
#include "godhand/cCamera.h"
#include "godhand/vu0.h"

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj1D00_SetState_7_16(void *a0);
extern char *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_00260B30(void *a0);
extern void func_0026EC60(void *a0);
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern unsigned char D_00462FC0[];
extern void cCamera_resetVib(struct cCamera *self);
extern void cCamera__calcRotation(cVec *out, struct cCamera *self, cVec *a, cVec *b);
extern void MtxInitRotVec(void *mtx, cVec *dir, int roll);

/* Phase machine of the enemy that turns toward its target: it starts the motion, turns toward the
 * 0x17A0 object while the motion runs, then runs the end-of-motion bookkeeping. */
__attribute__((section(".text.cEm00_stepTurnToLinkedObject"))) void cEm00_stepTurnToLinkedObject(cEm00 *self)
{
    self->unk186A = 2;
    self->emFlags2 |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10();
    switch (self->step) {
        case 0: {
            int gb;
            int a1v;
            int a2v;
            self->unk1864 = 0;
            gb = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            if ((self->emNo != 0x213) && (self->emNo != 0x217)) {
                int v0 = self->resource;
                a1v = *(int *)(v0 + 0x1B8) + ((int)v0);
                a2v = *(int *)(v0 + 0x1BC) + ((int)v0);
            } else {
                int v1 = self->resource;
                void *o = (void *)self->fx6;
                a1v = *(int *)(v1 + 0x2F6C) + ((int)v1);
                a2v = *(int *)(v1 + 0x2F70) + ((int)v1);
                if (o != 0) {
                    Obj1D00_SetState_7_16(o);
                }
            }
            func_002A8578(self, a1v, a2v, 0.0f, 5, gb, 0);
            self->timerA = 0x16;
            self->unk5F8 = 0xF;
            self->step += 1;
            self->timerB = 0;
            self->timerC = 0;
        }

        case 1:
            if (self->unk5F8 != 0) {
                self->unk5F8 -= 1;
            }
            if (self->timerA != 0) {
                int v1;
                self->timerA -= 1;
                v1 = self->unk17A0;
                if (v1 != 0) {
                    cGameObj_SetTgtTurn(self, *(int *)(v1 + 0xF0), self->speedRate * 0.19634955f);
                } else if (self->unk5F8 <= 0) {
                    char *v0 = Getplayer();
                    cGameObj_SetTgtTurn(self, *(int *)(v0 + 0xF0), self->speedRate * 0.19634955f);
                }
            }
            if (moveMotion(self) != 0) {
                func_002705D8(self);
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
    }

    if (((self->moveFlags & 2) != 0) && (self->timerB == 0)) {
        self->timerB = 1;
        func_0026EC60(self);
        self->unk17A0 = 0;
    }
    if ((self->moveFlags & 0x20) != 0) {
        cCollisionSolidManage_SetActive(&D_00462FC0, self, 0);
    }
    if ((self->moveFlags & 1) != 0) {
        StoreMotionParamsBoth_2609A8(self, 0x1E, 2, 0x3E, -1, 0);
        func_00260B30(self);
    }
    if (self->moveFlags & 3) {
        self->timerC = 1;
    }
    if (self->timerC != 0) {
        self->emFlags2 &= 0xFFFFFBFF;
    }
}

extern char D_0041DBA0[];           /* the follow routine table, one pointer to member per mode */

typedef struct { char b[0x10]; } cPlCamTbl;

/* Call the follow routine for the current mode. The table is copied to the
 * stack and the pointer to member is decoded by hand, as retail does. */
__attribute__((section(".text.cPlCamera_callFollow")))
void cPlCamera_callFollow(struct cPlCamera *self) {
    char frame[0x10];
    char *s2 = (char *)self;
    cPlCamPmf *pm;
    cPlCamVtEnt *vt;
    void *fn;
    long ve;
    int ix, off8;
    char *q4;
    int dl;
    int *new_var;
    cPlCamPmf *pm3;

    *(cPlCamTbl *)frame = *(cPlCamTbl *)D_0041DBA0;
    pm = (cPlCamPmf *)frame + self->followMode;
    ix = pm->index;
    if (ix >= 0) {
        vt = *(cPlCamVtEnt **)(s2 + pm->u.vo);
        ve = *(long *)((char *)vt + (ix - 1) * 8);
        fn = (void *)(int)(ve >> 32);
    } else {
        q4 = frame + 4;
        off8 = self->followMode * 8;
        fn = *(void **)(q4 + off8);
    }
    dl = (pm3 = (cPlCamPmf *)frame + self->followMode)->delta;
    new_var = &dl;
    dl = (ix >= 0) ? (short)ve + (*new_var) : dl;
    ((void (*)(void *))fn)(s2 + dl);
}

/* Advance both screen-shake channels one frame. */
__attribute__((section(".text.cCamera_stepVib")))
void cCamera_stepVib(struct cCamera *self) {
    if (self->vib[1].count != 0) {
        self->vib[1].amp = self->vib[1].amp * self->vib[1].decay;
        self->vib[1].phase = self->vib[1].phase + self->vib[1].speed;
        self->vib[1].phase = Adjust_theta(self->vib[1].phase);
        self->vib[1].count = self->vib[1].count - 1;
    }
    if (self->vib[0].count != 0) {
        self->vib[0].amp = self->vib[0].amp * self->vib[0].decay;
        self->vib[0].phase = self->vib[0].phase + self->vib[0].speed;
        self->vib[0].phase = Adjust_theta(self->vib[0].phase);
        self->vib[0].count = self->vib[0].count - 1;
    }
}

/* Put the camera back to its default view: eye at the origin, target at
 * (2.8, 2.1, 2.8), rotation recomputed from them, up straight up, field of
 * view 31, vibration cleared. */
__attribute__((section(".text.cCamera_reset")))
void cCamera_reset(struct cCamera *self) {
    struct {
        cVec v;                         /* 0x00 */
        float mtx[16];                  /* 0x10 */
    } f;
    f.v.x = 0.0f; f.v.y = 0.0f; f.v.z = 0.0f; f.v.w = 1.0f;
    cVec_copy3(&self->eye, &f.v);
    f.v.x = 2.8f; f.v.y = 2.1f; f.v.z = 2.8f; f.v.w = 1.0f;
    cVec_copy3(&self->target, &f.v);
    cCamera__calcRotation(&f.v, self, &self->target, &self->eye);
    cVec_copy3(&self->rot, &f.v);
    MtxInitRotVec(f.mtx, &self->rot, 4);
    f.v.x = 0.0f; f.v.y = 1.0f; f.v.z = 0.0f; f.v.w = 1.0f;
    cVec_copy3(&self->up, &f.v);
    self->unk1C0 = 0;
    self->fov = 31.0f;
    cCamera_resetVib(self);
}
