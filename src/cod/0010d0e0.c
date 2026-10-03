/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/cMovie.h"

extern void func_001268F0(void *a0);
extern void func_00124540(void *a0, int a1);
extern void cSnd_SeStop(void *a0, int a1);
extern unsigned int irand(void);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f12);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float s);
extern void cObjBase_addNullSpeed(void *a0, float s);
extern int cCollisionManager_checkNearCollision(void *a0, int a1, void *a2, float f);
extern void func_00129430(void *a0);
extern char D_005FEE00[];
extern char D_005E8040[];
extern void func_002D42E0(cMovieTrack *track);
extern int D_00747A84;

/* Phase machine of the enemy with the counted attack: step 1 counts 0x15B4 down each frame, and
 * when it reaches zero it raises the 0x15B0 state to 2 and calls func_00129430. */
__attribute__((section(".text.func_0010D0E0"))) void func_0010D0E0(cEm00 *self)
{
    float v[4] __attribute__((aligned(16)));
    float one;
    int s2v, s0v, n;

    switch (self->step) {
        case 0:
            self->unk5E0 = 0;
            self->unk5E2 = 0;
            func_001268F0(self);
            func_00124540(self, 5);
            cSnd_SeStop(D_005FEE00, self->unk1620);
            self->unk1620 = 0;
            switch (self->unk1614) {
                case 0:
                default: {
                    int t = self->resource;
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
                    int t = self->resource;
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
                    int t = self->resource;
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
            func_002A8578(self, s2v, s0v, 2.0f, 3, 0, 0);
            *(int *)&self->unk15B4 = 8;
            self->gotoFlags = 0;
            self->step += 1;
        case 1:
            if (*(int *)((char *)self + 0x640) != 0) {
                self->unk648 = 0x14;
            }
            InvokeVirtualAtField214AndForward_124E68(self, 0.19634954f);
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            self->unk5E2 = 0;
            if (*(int *)&self->unk15B4 != 0) {
                *(int *)&self->unk15B4 -= 1;
                self->unk15F4 |= 0x10000;
                self->unk1603 = 2;
                if (self->gotoFlags == 0) {
                    VU0_LQC2(4, (char *)self->pos, 0);
                    VU0_SQC2(4, v, 0);
                    v[1] = v[1] + one;
                    if (cCollisionManager_checkNearCollision(D_005E8040, 2, v, 1.5f) != 0) {
                        self->gotoFlags = 1;
                    }
                }
                if (*(int *)&self->unk15B4 == 0) {
                    if (self->gotoFlags == 1) {
                        self->gotoFlags = 2;
                        func_00129430(self);
                    }
                }
            }
            break;
    }
    if (func_00123938(self, 1) != 0) {
        if (self->gotoFlags == 1) {
            self->gotoFlags = 2;
            func_00129430(self);
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
__attribute__((section(".text.func_002B4DA8")))
void func_002B4DA8(cMovie *self) {
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
