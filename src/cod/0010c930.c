/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cPlCamera.h"

extern float SetMotionStep(void *a0, float f12);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void cPlCamera_setCamUpdate(struct cPlCamera *self, int snap);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void func_0012BFB8(void *a0);
extern float D_003BD478;
extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern void cCollisionSolidManage_SetActive(void *a0, void *a1, int a2);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern void pl00_clearMotionCam(void *a0, int a1, int a2);
extern void *Getplayer(void);
extern unsigned short D_00747A50;

/* sn-2.95.3-136 matched TU. */











__attribute__((section(".text.func_0010C930")))
void func_0010C930(void *a0)
{
    char *s0 = (char *)a0;
    int t0;
    int v0;
    void *q;
    int p1;
    int p2;
    float v;

    if (*(short *)(s0 + 0x54A) <= 0) {
        *(short *)(s0 + 0x54A) = 1;
    }
    *(float *)(s0 + 0x5A8) = 1.5f;
    SetMotionStep(s0, 1.5f);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        if (*(char *)(s0 + 0x648) >= 0xB) {
            *(char *)(s0 + 0x648) = 0xA;
        }
        t0 = *(int *)(s0 + 0x304);
        q = *(void **)(s0 + 0x6A0);
        p1 = *(int *)(t0 + 0x60) + t0;
        p2 = *(int *)(t0 + 0x64) + t0;
        if (q != 0) {
            func_002A8578(q, *(int *)(t0 + 0x374) + t0, *(int *)(t0 + 0x390) + t0,
                          0.0f, 0xA, 0, 0);
            v0 = *(int *)(s0 + 0x304);
            p1 = *(int *)(v0 + 0x354) + v0;
            p2 = *(int *)(v0 + 0x358) + v0;
        }
        func_002A8578(s0, p1, p2, 0.0f, 0xA, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (*(unsigned char *)(s0 + 0x61F) != 0) {
            v = 3.14159274f - *(float *)(s0 + 0x608) - 0.52359879f;
            if (v < 0.0f) {
                v = 0.0f;
            }
            v = v * 0.400000006f;
            if (D_003BD478 < v) {
                v = D_003BD478;
            }
            if (*(float *)(s0 + 0x604) < 0.0f) {
                v = -v;
            }
            *(float *)(s0 + 0x104) = *(float *)(s0 + 0x104) + v;
            *(float *)(s0 + 0x104) = Adjust_theta(*(float *)(s0 + 0x104));
        }
        moveMotion(s0);
        cObjBase_addNullSpeed_Rotation(s0, 1.0f);
        cObjBase_addNullSpeed(s0, 1.0f);
        break;
    }
    if (func_00123938(s0, 0) == 0) {
        func_0012BFB8(s0);
    }
}

/* sn-2.95.3-136 matched TU. */


















#include "godhand/vu0.h"



















__attribute__((section(".text.func_00117F78")))
void func_00117F78(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s2 = *(char **)(s1 + 0x694);
    cCollisionSolidManage_SetActive(&D_00462FC0, s1, 0);
    cEmManage_SetPlCatched(&D_005864F0);
    cEmManage_SetSlotWait(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x80000;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = -0.51910001f;
        buf[1] = 0.0f;
        buf[2] = 0.0427000001f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x3D, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        if (*(short *)(s1 + 0x54A) <= 0)
            *(short *)(s1 + 0x54A) = 1;
        *(short *)(s1 + 0x56E) = 0x1E;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (*(short *)(s1 + 0x56E) != 0 && s2 != 0) {
            char *d;
            char *e = s2 + 0x550;
            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            d = *(char **)(s1 + 0xF0);
            VU0_VADD_XYZ_IP(d, 0, e);
        }
        if (moveMotion(s1)) {
            pl00_clearMotionCam(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
}

/* sn-2.95.3-136 matched TU. */





#include "godhand/vu0.h"

static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

/* Switch the camera to the normal zoom-out pose: take the pose in `src`, or
 * the player with the default offsets (two sets, picked by the stage state),
 * make it the current pose, restart the wait counters and place the camera. */
__attribute__((section(".text.cPlCamera_SetNormalZoomOutMode")))
void cPlCamera_SetNormalZoomOutMode(struct cPlCamera *self, cPlCamPose *src, int snap)
{
    cPlCamPose *d;
    cPlCamPose *e;
    float *m;
    int v;

    if (src != 0) {
        self->nextPose.obj = src->obj;
        cVec_copy3(&self->nextPose.ofs, &src->ofs);
        cVec_copy3(&self->nextPose.rotOfs, &src->rotOfs);
        self->nextPose.dist = src->dist;
    } else if (D_00747A50 != 0x104) {
        self->nextPose.obj = Getplayer();
        self->nextPose.ofs.x = -0.200000003f;
        self->nextPose.ofs.y = 1.05999994f;
        self->nextPose.rotOfs.x = 0.0700000003f;
        self->nextPose.dist = 4.0f;
        self->nextPose.ofs.z = 0;
        self->nextPose.rotOfs.y = 0;
        self->nextPose.rotOfs.z = 0;
    } else {
        self->nextPose.obj = Getplayer();
        self->nextPose.ofs.x = -0.200000003f;
        self->nextPose.ofs.y = 1.15999997f;
        self->nextPose.rotOfs.x = 0.0500000007f;
        self->nextPose.dist = 4.0f;
        self->nextPose.ofs.z = 0;
        self->nextPose.rotOfs.y = 0;
        self->nextPose.rotOfs.z = 0;
    }
    d = &self->pose;
    e = &self->nextPose;
    d->obj = e->obj;
    cVec_copy3(&d->ofs, &e->ofs);
    cVec_copy3(&d->rotOfs, &e->rotOfs);
    d->dist = e->dist;
    self->unk51C = 0;
    v = self->unk520;
    self->unk520 = 0;
    self->unk524 = v;
    self->flags528 = 0;
    if (snap != 0) {
        cPlCamera_setCamUpdate(self, 1);
    } else {
        cPlCamera_setCamUpdate(self, 0);
    }
    m = self->base.mtx[6];
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m, 0x30);
    VU0_SQC2(5, m, 0x20);
    VU0_SQC2(6, m, 0x10);
    VU0_SQC2(7, m, 0x0);
}
