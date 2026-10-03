/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"

extern char D_005FEE00[];
extern int cSnd_SeFadeOut(void *snd, int handle, short fade);
extern float Adjust_theta(float theta);
extern void MtxInitRotY(float *mtx, float angle);
extern void sceVu0ApplyMatrix(void *dst, void *mtx, void *src);
extern void StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);
extern void func_002E6B88(void *obj, float y);

/* Per-frame check of one scripted sound emitter: stop its sound when it is switched off or the sound system is busy, otherwise let it run (or start it when it has no mode set). */
typedef struct SeEmitter {
    struct SeEmitter *next;             /* 0x00 list link */
    char unk04[8];
    unsigned char flags;                /* 0x0C bit 0: emitter on */
    char unk0D[3];
    unsigned short unk10;               /* 0x10 */
    unsigned char mode;                 /* 0x12 */
    unsigned char state;                /* 0x13 */
    int handle;                         /* 0x14 sound handle, 0 when none */
    char unk18[0x12];
    unsigned short delay;               /* 0x2A frames before the sound starts */
} SeEmitter;

#define SEEMITTER_STATE_STOP  4
#define SEEMITTER_FADE_FRAMES 10




extern void func_002C8B68(SeEmitter *self);

__attribute__((section(".text.func_002C8AD8")))
void func_002C8AD8(SeEmitter *self)
{
    /* (flags ^ 1) & 1 is the "off" test; retail keeps the xori, `!(flags & 1)` drops it. */
    if (((self->flags ^ 1) & 1) || func_002CB198(D_005FEE00) == 1) {
        if (self->handle != 0) {
            self->state = SEEMITTER_STATE_STOP;
            if (self->delay == 0)
                cSnd_SeFadeOut(D_005FEE00, self->handle, SEEMITTER_FADE_FRAMES);
            self->handle = 0;
        }
    } else if (self->mode == 0) {
        func_002C8B68(self);
    }
}

/* Scale the object's offset vector by its scale factor, except when the source is flagged and the object is still on its first frame pair. */


typedef struct ScaleSrc {
    int unk00;
    unsigned int flags;                 /* 0x04 */
} ScaleSrc;

typedef struct ScaleObj {
    char unk000[0x110];
    ScaleSrc *src;                      /* 0x110 */
    char unk114[8];
    unsigned char unk11C;
    unsigned char scaleOn;              /* 0x11D bit 0 */
    char unk11E[6];
    float vec[3];                       /* 0x124 offset vector (x at 0x124) */
    float factor;                       /* 0x130 */
    char unk134[0xFA];
    short frameA;                       /* 0x22E */
    short frameB;                       /* 0x230 */
} ScaleObj;

#define SCALESRC_F_FORCE  0x2000

__attribute__((section(".text.func_002FDD10")))
void func_002FDD10(ScaleObj *self)
{
    float v[4] __attribute__((aligned(16)));
    v[0] = self->vec[0];
    v[1] = self->vec[1];
    v[2] = self->vec[2];
    v[3] = 1.0f;
    if ((self->src->flags & SCALESRC_F_FORCE) != 0
        || (self->scaleOn & 1) == 0
        || self->frameB != self->frameA) {
        VU0_VSCALE_XYZ_MEM(v, 0, self->factor);
    }
    self->vec[0] = v[0];
    self->vec[1] = v[1];
    self->vec[2] = v[2];
}

/* Queue a new request: take a free job, give it the next id and fill it in, make it the head when the queue was empty. Returns the id, 0 when no job is free. */
typedef struct ReqJob ReqJob;

typedef struct ReqQueue {
    ReqJob *head;                       /* 0x00 first job in the queue, 0 when empty */
} ReqQueue;

extern ReqJob *func_002D3110(ReqQueue *self);               /* take a free job */
extern int func_002D3190(ReqQueue *self);                   /* next request id */
extern void func_002D3240(ReqJob *job, int kind, int a2, int a3, int a4, int id);

__attribute__((section(".text.func_002D2F78")))
int func_002D2F78(ReqQueue *self, int kind, int a2, int a3, int a4)
{
    ReqJob *job;
    int id;
    job = func_002D3110(self);
    if (job == 0)
        return 0;
    id = func_002D3190(self);
    func_002D3240(job, kind, a2, a3, a4, id);
    if (self->head == 0)
        self->head = job;
    return id;
}

/* Two step timer: phase 0 reads the lock-on position and arms a 15 frame timer, phase 1 counts it down and returns the object to state 0 when it runs out. */



#define OMTIMED_FRAMES  0xF

typedef struct cOmTimed {
    cGameObj base;
    char unk5AC[0xA90 - 0x5AC];
    unsigned short timer;                      /* 0xA90 frames left in phase 1 */
} cOmTimed;

__attribute__((section(".text.func_0019B4D0")))
void func_0019B4D0(cOmTimed *self)
{
    cVec pos __attribute__((aligned(16)));
    cGameObjVt *vt;
    cVec *src;
    int n;

    if (self->base.phase == 0)
        goto init;
    if (self->base.phase == 1)
        goto tick;
    return;
init:
    VU0_SQC2_VF0(&pos, 0);
    vt = self->base.vt;
    src = ((cVec *(*)(void *))vt->lockOn)((char *)self + vt->lockOnDelta);
    cVec_copy3(&pos, src);
    self->timer = OMTIMED_FRAMES;
    self->base.phase = 1;
    self->base.step = 0;
    self->base.stepArg = 0;
tick:
    n = self->timer - 1;
    self->timer = n;
    if ((short)n <= 0) {
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* Place the object 26 units in front of the anchor D_005850B0, turned by `angle`, and face it back at the anchor (angle + pi). Only x and z of the position are written. */



#define OBJ_PI            3.1415927f
#define OBJ_ANCHOR_DIST   26.0f

/* One stack object at sp+0: the rotation matrix, then the offset vector at 0x40. */
typedef struct OffsetFrame {
    float mtx[16];                      /* 0x00 */
    cVec off;                           /* 0x40 */
} OffsetFrame;

extern char D_005850B0[];               /* anchor vector */




__attribute__((section(".text.func_002498A8")))
void func_002498A8(cGameObj *self, float angle)
{
    OffsetFrame fr __attribute__((aligned(16)));

    VU0_SQC2_VF0(&fr, 0x40);
    self->rot[1] = angle + OBJ_PI;
    self->rot[1] = Adjust_theta(self->rot[1]);
    MtxInitRotY(fr.mtx, angle);
    fr.off.x = 0.0f;
    fr.off.y = 0.0f;
    fr.off.z = OBJ_ANCHOR_DIST;
    sceVu0ApplyMatrix(&fr.off, fr.mtx, &fr.off);
    VU0_VADD_XYZ_IP(&fr, 0x40, D_005850B0);
    self->pos->x = fr.off.x;
    self->pos->z = fr.off.z;
}

/* Drop test below the object: cast a line from 1 unit above its position to 11 units below it, and when it hits, hand the hit height to func_002E6B88. */



#define DROP_UP     1.0f
#define DROP_DOWN   11.0f

/* The frame holds ChkLine's 0x30 bytes of outgoing arguments first; the vectors sit above them. */
#define FRAME ((char *)&pos - 0x30)


extern int ChkLine(void *a0, void *a1, void *a2, void *a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);


__attribute__((section(".text.func_002E6FD8")))
void func_002E6FD8(cOmBase *self)
{
    cVec pos;                           /* sp+0x30 object position */
    cVec from;                          /* sp+0x40 */
    cVec to;                            /* sp+0x50 */
    cVec hit;                           /* sp+0x60 */
    cVec normal;                        /* sp+0x70 */

    StoreVecFromFieldB0_2B6160(&pos, self);
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_LQC2(4, &pos, 0);
    VU0_SQC2(4, FRAME, 0x50);
    VU0_SQC2_VF0(FRAME, 0x60);
    VU0_SQC2_VF0(FRAME, 0x70);
    from.y += DROP_UP;
    to.y -= DROP_DOWN;
    if (ChkLine(&from, &to, &hit, &normal, 2, 0, 0, 0, 0, 0, 0, 0, 1) != 0)
        func_002E6B88(self, hit.y);
}
