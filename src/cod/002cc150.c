/* sn-2.95.3-136 */
#include "godhand/cSnd.h"
#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"
#include "godhand/player.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/gameWork.h"

#define LISTEN_AT_CAMERA  0
#define LISTEN_AT_PLAYER  1
#define LISTEN_BETWEEN    2

#define LISTEN_HEAD_HEIGHT  1.5f        /* the ear's height above the player's origin, and the point it faces */
#define LISTEN_EAR_BACK     (-0.1f)     /* the ear sits just behind the player's head */
#define LISTEN_HALF         0.5f        /* LISTEN_BETWEEN: halfway between the camera and the player */

/* The SDK's quadword type: the listener copies the camera's eye with one lq/sq. */
typedef int u_long128 __attribute__((mode(TI)));


/* Set m to the identity matrix. */
static __inline__ void unitMatrix(float m[4][4])
{
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, m, 0x30);
    VU0_SQC2(5, m, 0x20);
    VU0_SQC2(6, m, 0x10);
    VU0_SQC2(7, m, 0x0);
}

/* out = (a - b) in x, y and z with w cleared; returns out. */
static __inline__ cVec *subVecXYZ(cVec *out, cVec *a, cVec *b)
{
    VU0_ZERO_VSUB_XYZ_TO(out, 0, a, b);
    return out;
}

/* Place the sound listener for this frame: at the camera, just behind the
 * player's head looking at the player, or halfway between the two. */
__attribute__((section(".text.cSnd_UpdateListener")))
void cSnd_UpdateListener(cSnd *self)
{
    unsigned long flags = D_007474A0.flags5E4;
    cGameObj *pl;
    int mode;
    cVecQuad ear;
    cVec eye;
    float m[4][4];
    cVec at;
    cVec dir;
    cVec diff;
    cVec d;
    cVec up;

    if (flags & SYSFLAG_EVENT_RUNNING) {
        self->f110 = LISTEN_AT_CAMERA;
    } else if (flags & SYSFLAG_SOFT_EVENT4) {
        self->f110 = LISTEN_AT_CAMERA;
    } else if (((flags >> SYSFLAG_ENDING_BIT) & 1) == 1) {
        self->f110 = LISTEN_AT_CAMERA;
    } else {
        self->f110 = LISTEN_AT_PLAYER;
    }
    pl = Getplayer();
    mode = self->f110;
    if (pl == 0) {
        mode = LISTEN_AT_CAMERA;
    }
    switch (mode) {
    case LISTEN_AT_CAMERA:
        *(u_long128 *)&self->listenPos = *(u_long128 *)&D_005CAFF0->eye;
        func_0030A548(self->listenMtx, D_005CAFF0->mtx[5]);
        break;
    case LISTEN_AT_PLAYER:
        ear.x = 0.0f;
        ear.y = LISTEN_HEAD_HEIGHT;
        ear.z = LISTEN_EAR_BACK;
        ear.w = 1.0f;
        sceVu0ApplyMatrix(&ear, pl->mtx, &ear);
        self->listenPos = ear;
        eye.x = ear.x;
        eye.y = ear.y;
        eye.z = ear.z;
        eye.w = 1.0f;
        VU0_LQC2_SQC2_MEM(4, &at, pl->pos);
        at.y += LISTEN_HEAD_HEIGHT;
        VU0_SQC2_VF0_MEM(&dir, 0);
        unitMatrix(m);
        sceVu0ApplyMatrix(&eye, m, &eye);
        sceVu0ApplyMatrix(&dir, m, &at);
        VU0_LQC2_SQC2_MEM(4, &diff, subVecXYZ(&d, &dir, &ear));
        d.x = diff.x;
        d.y = diff.y;
        d.z = diff.z;
        d.w = 1.0f;
        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        up.w = 1.0f;
        sceVu0CameraMatrix(self->listenMtx, &eye, &d, &up);
        break;
    case LISTEN_BETWEEN:
        sceVu0AddVector(&self->listenPos, &D_005CAFF0->eye, pl->pos);
        sceVu0ScaleVectorXYZ(&self->listenPos, &self->listenPos, LISTEN_HALF);
        func_0030A548(self->listenMtx, D_005CAFF0->mtx[5]);
        break;
    }
}
