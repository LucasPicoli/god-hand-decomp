/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/pl00.h"
#include "godhand/vu0.h"
#include "godhand/cMovie.h"
#include "godhand/motion.h"
#include "godhand/cDamageUnit.h"

extern void func_001268F0(void *a0);
extern void func_00124540(void *a0, int a1);
extern void cSnd_SeStop(void *a0, int a1);
extern unsigned int irand(void);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern void pl00_addComboHit(void *a0);
extern char D_005FEE00[];
extern void func_002D42E0(cMovieTrack *track);
extern int D_00747A84;

/* Counted attack step of the player (a state of the pl00 table D_003BD0F0): step 1 counts
 * stepCount down each frame, and when it reaches zero with a unit near, it raises the 0x15B0
 * state to 2 and calls pl00_addComboHit. */
__attribute__((section(".text.pl00_stepCountedAttack"))) void pl00_stepCountedAttack(pl00 *self)
{
    cVec v __attribute__((aligned(16)));
    float one;
    int s2v, s0v, n;

    switch (self->base.step) {
        case 0:
            self->comboSlot = 0;
            self->comboSet = 0;
            func_001268F0(self);
            func_00124540(self, 5);
            cSnd_SeStop(D_005FEE00, self->unk1620);
            self->unk1620 = 0;
            switch (self->unk1614) {
                case 0:
                default: {
                    int t = EM_RES(&self->base);
                    s2v = EM_RES_REC(t, 0x284);
                    s0v = EM_RES_REC(t, 0x288);
                }
                    if ((irand() & 1) != 0) {
                        self->unk1614 = 1;
                    } else {
                        self->unk1614 = 2;
                    }
                    break;
                case 1: {
                    int t = EM_RES(&self->base);
                    s2v = EM_RES_REC(t, 0x27C);
                    s0v = EM_RES_REC(t, 0x280);
                }
                    if ((irand() & 1) != 0) {
                        self->unk1614 = 0;
                    } else {
                        self->unk1614 = 2;
                    }
                    break;
                case 2: {
                    int t = EM_RES(&self->base);
                    s2v = EM_RES_REC(t, 0x28C);
                    s0v = EM_RES_REC(t, 0x290);
                }
                    if ((irand() & 1) != 0) {
                        self->unk1614 = 0;
                    } else {
                        self->unk1614 = 1;
                    }
                    break;
            }
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x41, self, 0, 0, 0, 0);
            func_002A8578(self, s2v, s0v, 3, 2.0f, 0, 0);
            self->stepCount = 8;
            self->unk15B0 = 0;
            self->base.step += 1;
        case 1:
            if (self->held != 0) {
                self->unk648 = 0x14;
            }
            InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
            if (moveMotion(self) != 0) {
                self->base.mode = 0;
                self->base.phase = 0;
                self->base.step = 0;
                self->base.stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            self->comboSet = 0;
            if (self->stepCount != 0) {
                self->stepCount -= 1;
                self->unk15F4 |= 0x10000;
                self->unk1603 = 2;
                if (self->unk15B0 == 0) {
                    VU0_LQC2(4, (char *)self->base.pos, 0);
                    VU0_SQC2(4, &v, 0);
                    v.y = v.y + one;
                    if (cCollisionManager_checkNearCollision(&D_005E8040, 2, &v, 1.5f) != 0) {
                        self->unk15B0 = 1;
                    }
                }
                if (self->stepCount == 0) {
                    if (self->unk15B0 == 1) {
                        self->unk15B0 = 2;
                        pl00_addComboHit(self);
                    }
                }
            }
            break;
    }
    if (func_00123938(self, 1) != 0) {
        if (self->unk15B0 == 1) {
            self->unk15B0 = 2;
            pl00_addComboHit(self);
        }
    }
}

/* 1 while the track holds a player (a branch-built 0/1, as in retail). */
static __inline__ unsigned char cMovieTrack_inUse(cMovieTrack *t) {
    if (t->handle != 0) return 1;
    return 0;
}

/* Stop every track that holds a player, then clear the "movie playing" bit.
 * Two byte offsets walk the table, as in retail; the read offset is added
 * to the table pointer as an integer, which keeps retail's operand order. */
__attribute__((section(".text.cMovie_stopAllTracks")))
void cMovie_stopAllTracks(cMovie *self) {
    int off2 = 0;
    int off = 0;
    int n = MOVIE_TRACK_NUM - 1;
    for (; n >= 0; n--) {
        if (cMovieTrack_inUse((cMovieTrack *)(off + (int)self->track))) {
            func_002D42E0((cMovieTrack *)((char *)self->track + off2));
        }
        off2 += sizeof(cMovieTrack);
        off += sizeof(cMovieTrack);
    }
    D_00747A84 &= ~MOVIE_SYS_PLAYING;
}
