/* sn-2.95.3-136 matched TU. */

#include "godhand/CustomIDWork.h"
#include "godhand/cMovie.h"
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/espSys.h"

extern void CustomIDWork_SetScaleAnimSin(CustomIDWork *work, unsigned short frames, float from, float to);
extern void CustomIDWork_ResetScaleAnim(CustomIDWork *work);
extern int SetEffectParts(int kind, int id, void *owner, int part, float f12, float f13, float f14, float f15, int t0);
extern void KillEffect(void *owner, int id, int arg);
extern unsigned int D_00747A84;
extern void func_002FA350(float *frame);
extern char D_00580D40[];
extern void func_003A57C4(void *dst, const void *src);
extern void FreeResourceNode_2D3710(cMovieTrack *track);
extern int FindEntryValue_1FF9C0(char *table, char *name, int *size, char *key);
extern void func_00347BC0(int handle, int a1, int found);
extern void func_00346078(int handle, int a1, int found);
extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *snd, int b, int c, void *obj, int e, int f, int g, int h);
extern float Turn_dest_dir(float cur, float dest, float speed);
extern float Adjust_theta(float f12);

typedef struct IdxTable {
    int w[5];
} IdxTable;

extern IdxTable D_0042B5D0;             /* element number for each of the five slots */



#define IDWORK_FIRST  0x60              /* first CustomIDWork inside the display */
#define IDWORK_SIZE   0x7C

/* Starts (on) or resets (off) the pulsing scale animation of the element slot maps to; slots above 4 do nothing. */
__attribute__((section(".text.CustomIDWork_pulseSlot")))
void CustomIDWork_pulseSlot(char *self, unsigned char slot, int on) {
    IdxTable tbl;

    if (slot < 5) {
        tbl = D_0042B5D0;
        if (on) {
            CustomIDWork_SetScaleAnimSin((CustomIDWork *)(self + (tbl.w[slot] * IDWORK_SIZE + IDWORK_FIRST)), 12, 0.6f, 1.0f);
        } else {
            CustomIDWork_ResetScaleAnim((CustomIDWork *)(self + (tbl.w[slot] * IDWORK_SIZE + IDWORK_FIRST)));
        }
    }
}

#define FX_RUNNING   0x80               /* bit of fxFlags: the aura effect is on */
#define FX_EM_BIG    0x223              /* enemy number whose aura sits on part 6 */

/* An object with a charge value at 0x17CC. */
typedef struct ChargeObj {
    char unk000[0x564];
    int emNo;                           /* 0x564 */
    char unk568[0x16D0 - 0x568];
    unsigned int fxFlags;               /* 0x16D0 */
    char unk16D4[0x17CC - 0x16D4];
    float charge;                       /* 0x17CC */
} ChargeObj;

/* Starts the aura effect when the charge turns positive (on part 6 for enemy 0x223, else part 4) and kills it when the charge drops. */
__attribute__((section(".text.ChargeObj_updateAuraEffect")))
void ChargeObj_updateAuraEffect(ChargeObj *self) {
    if (self->charge > 0.0f) {
        if ((self->fxFlags & FX_RUNNING) == 0) {
            self->fxFlags |= FX_RUNNING;
            if (self->emNo != FX_EM_BIG) {
                SetEffectParts(0, 4, self, 4, 0.0f, 0.0f, 0.0f, 1.0f, 3);
            } else {
                SetEffectParts(0, 4, self, 6, 0.0f, 0.0f, 0.0f, 1.0f, 3);
            }
        }
    } else if ((self->fxFlags & FX_RUNNING) != 0) {
        self->fxFlags &= ~FX_RUNNING;
        KillEffect(self, 3, 2);
    }
}

/* EspAnim, EspData and their flags come from espSys.h. */

extern void UpdateObjByIndexedOp_2FBE50(EspAnim *self);

/* Advances the frame counter by one tick (or through func_002FA350), stores the frame index, and runs the indexed update once the index has reached the frame count. */
__attribute__((section(".text.EspAnim_step")))
int EspAnim_step(EspAnim *self) {
    int index;

    if (self->frameNum == 0) {
        return 0;
    }
    if ((self->data->flags & ESP_DATA_PAUSE) == 0 && (self->lockFlags & 1) != 0) {
        func_002FA350(&self->frame);
    } else if ((D_00747A84 & SYSFLAG_SLOWMO) != 0) {
        func_002FA350(&self->frame);
    } else {
        self->frame = self->frame + 1.0f;
    }
    index = (int)self->frame;
    self->frameNo = index;
    if ((unsigned char)index >= self->frameNum) {
        UpdateObjByIndexedOp_2FBE50(self);
        return 1;
    }
    return 0;
}

#define MOVIE_TRACK_NAME(t)   ((char *)(t) + 0x64)                  /* clip name copied into the track */
#define MOVIE_TRACK_FLAGS(t)  (*(unsigned int *)((char *)(t) + 0x3C))
#define MOVIE_TRACK_LOOP      0x4









/* 1 while the track holds a player. The unsigned char result is what makes
 * the compiler build the 0/1 with a branch, as retail does. */
static __inline__ unsigned char cMovieTrack_inUse(cMovieTrack *t) {
    if (t->handle != 0) return 1;
    return 0;
}

/* Starts a clip on a free track: copies its name, loads it, looks the entry up and starts (or loops) the stream. Returns 1 on success. */
__attribute__((section(".text.cMovieTrack_start")))
int cMovieTrack_start(cMovieTrack *track, const char **clip) {
    char *name;
    int found;

    if (cMovieTrack_inUse(track) == 1) return 0;
    name = MOVIE_TRACK_NAME(track);
    func_003A57C4(name, *clip);
    if (func_002D3C78(track, clip) == 0) {
        FreeResourceNode_2D3710(track);
        return 0;
    }
    found = FindEntryValue_1FF9C0(D_00580D40, name, 0, 0);
    if ((MOVIE_TRACK_FLAGS(track) & MOVIE_TRACK_LOOP) != 0) {
        func_00347BC0(track->handle, 0, found);
    } else {
        func_00346078(track->handle, 0, found);
    }
    return 1;
}

#define TURN_SPEED   0.13962634f        /* 8 degrees in radians */
#define ACTOR_ID_A   0x314              /* actors that turn silently */
#define ACTOR_ID_B   0x354

/* A game object that turns toward a goal heading at 0x638. */
typedef struct cGameObjTurn {
    cGameObj base;
    char unk5AC[0x638 - sizeof(cGameObj)];
    float goalRot;                      /* 0x638 */
} cGameObjTurn;






/* Turn step: the first call plays the turn sound and enters step 1; step 1 turns the heading toward goalRot and, once there, resets the four state bytes. */
__attribute__((section(".text.cGameObjTurn_stepTurn")))
void cGameObjTurn_stepTurn(cGameObjTurn *self) {
    float rot;

    switch (self->base.step) {
    case 0:
        if (self->base.actorId != ACTOR_ID_A && self->base.actorId != ACTOR_ID_B) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 3, self, 0, 0, 0, 0);
        }
        self->base.stepArg = 0;
        self->base.step = 1;
    case 1:
        break;
    default:
        return;
    }
    rot = self->base.rot.y + Turn_dest_dir(self->base.rot.y, self->goalRot, TURN_SPEED);
    self->base.rot.y = rot;
    self->base.rot.y = Adjust_theta(rot);
    if (self->base.rot.y == self->goalRot) {
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

#define PHASE_NUM  0x26

/* One pointer-to-member record, g++ 2.x layout: this adjust, vtable index (-1 for a plain function) and the vtable offset or function. */
typedef struct PhaseMemFn {
    short delta;
    short index;
    short vtOfs;
    short pad6;
} PhaseMemFn;

typedef struct PhaseTbl {
    PhaseMemFn e[1];
} PhaseTbl;

/* A cOmBase object with a handler table indexed by its phase byte. */
typedef struct cOmPhased {
    cOmBase base;
    char unk5E0[0x1603 - sizeof(cOmBase)];
    unsigned char unk1603;              /* 0x1603 */
} cOmPhased;

extern PhaseTbl D_003BD328;
extern void Obj0000_Clear_Fields_640_648_124E58(cOmPhased *self);
extern void func_0012B928(cOmPhased *self);

/* The player's mode-1 handler, entry 1 of the mode table D_003BD0B8. Reset the object, clamp the phase byte into the
 * table, then run the handler for that phase. */
__attribute__((section(".text.StepPlayerMode1ByPhase_11A820")))
void StepPlayerMode1ByPhase_11A820(cOmPhased *self)
{
    char *s0 = (char *)self;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;

    Obj0000_Clear_Fields_640_648_124E58(self);
    *(short *)(s0 + 0x5E0) = 0;
    *(short *)(s0 + 0x5E2) = 0;
    self->unk1603 = 0;
    *(short *)(s0 + 0x1618) = 0;
    func_0012B928(self);
    if (self->base.phase >= PHASE_NUM) {
        self->base.phase = 0;
    }
    i8 = self->base.phase * 8;
    e = (char *)&D_003BD328 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BD328 + i8 + 4);
    }
    f0 = D_003BD328.e[self->base.phase].delta;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}
