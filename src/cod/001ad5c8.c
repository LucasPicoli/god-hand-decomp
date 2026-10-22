/* sn-2.95.3-136: func_001AD5C8, two-phase gimmick move: on a trigger start the rise or the slide with its sound,
 * then run the move and reset the phase bytes when it ends. */
#include "godhand/cOmBase.h"

#define GIMMICK_START_SE  0x82
#define GIMMICK_END_SE    0x83
#define GIMMICK_MOVING    0x100         /* flags2 bit set while the move runs */

/* A gimmick that rises or slides once when triggered. */
typedef struct cOmGimmickMove {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    int slide;                          /* 0x600 0 rises, otherwise slides */
    char unk604[0x60D - 0x604];
    unsigned char triggered;            /* 0x60D set by the trigger, cleared when the move ends */
    unsigned char moving;               /* 0x60E */
    char unk60F[0x630 - 0x60F];
    char move[0x790 - 0x630];           /* 0x630 cOmSub move work */
    float dist;                         /* 0x790 how far it rises or slides */
} cOmGimmickMove;

extern unsigned char D_005FEE00[];
extern char D_00747B00[];
extern void cOmSub_initMove3_y(char *mv, unsigned char *p, int a2, void *a3, float f12, float f13, float f14);
extern void cOmSub_initMove1_pos(char *mv, char *p, int a2, int a3, void *pos, float f12, float f13);
extern void cOmSub_setVibration(void *mv, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(char *mv);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, void *f, int g, int h);

static inline cOmBase *getPart(cOmGimmickMove *self, int i)
{
    int frame[3];

    return cOmBase_childAt(&self->base, frame, i);
}

static inline void movePart(cOmGimmickMove *self)
{
    float v[4];
    float z;

    v[0] = 0.0f;
    v[1] = self->dist;
    v[2] = 0.0f;
    v[3] = 1.0f;
    z = v[0];
    cOmSub_initMove1_pos(self->move, (char *)self, -1, 0x3C, v, 0.2f, z);
    cOmSub_setVibration(self->move, 0, 5, z, 1.0f, 2.0f);
}

static inline void resetPart(cOmGimmickMove *self)
{
    self->base.mode = 0;
    self->base.phase = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
}

__attribute__((section(".text.func_001AD5C8")))
void func_001AD5C8(cOmGimmickMove *self)
{
    switch (self->base.phase) {
    case 0:
        if (self->triggered == 0) {
            resetPart(self);
            break;
        }
        self->moving = 1;
        if (self->slide == 0) {
            cOmSub_initMove3_y(self->move, (unsigned char *)self, -1, D_00747B00, -0.02f, -self->dist, 0.2f);
        } else {
            movePart(self);
        }
        self->base.flags2 |= GIMMICK_MOVING;
        if (getPart(self, 1))
            getPart(self, 1)->posPrev.y = 0.0f;
        if (getPart(self, 2))
            getPart(self, 2)->posPrev.y = 0.0f;
        self->base.step = 0;
        self->base.stepArg = 0;
        self->base.phase = 1;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, GIMMICK_START_SE, self, 0, 0, 0, 0);
        /* fall through: the move starts this frame */
    case 1:
        if (cOmSub_move(self->move))
            return;
        self->triggered = 0;
        self->moving = 0;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, GIMMICK_END_SE, self, 0, 0, 0, 0);
        resetPart(self);
        break;
    }
}
