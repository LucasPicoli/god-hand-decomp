/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cOmb2.h"
#include "godhand/Slot2.h"
#include "godhand/cMessDrawFont.h"

extern void displayScrollLayer(int layer, int show);
extern char D_005FEE00[];
extern void cSnd_BgmEventStart(void *snd, int event, int a2, int a3);
extern void func_002B00A0(cMessDrawFont *self, void *cmd);
extern void func_002B0208(cMessDrawFont *self, void *cmd);
extern void func_002B0420(cMessDrawFont *self, void *cmd);

/* Enemy: set the position copy at 0x490, push it into the live position, then update the model. */




__attribute__((section(".text.func_001A9588")))
int func_001A9588(cEm00 *self, cVec *pos) {
    cVec *posA = &self->posA;
    cVec_copy3(posA, pos);
    cVec_copy3(self->pos, posA);
    return func_001A9210(self, self->pos, &self->rot);
}

/* Aim the object along `dir`, start the scripted move on its move record and put it in mode 1. */


#define COMB2_MOVE_DROP  (-50.0f)       /* third move parameter */

extern void cOmSub_initMove3_y(void *dst, void *obj, int idx, int a3,
                               float f12, float f13, float f14);

__attribute__((section(".text.cOmb2_SetMove")))
void cOmb2_SetMove(cOmb2 *self, cVec *dir, int moveArg, float rate) {
    cVec_copy3(&self->base.posPrev, dir);
    cOmSub_initMove3_y(self->move, self, -1, moveArg, rate, COMB2_MOVE_DROP, 0.0f);
    self->base.mode = COMB2_MODE_MOVE;
}

/* Slot2 line mark 1, once a frame: while lit (bit 15), count 8 frames, then flip the shown bit (14) and update the layer. */


#define MARK_BLINK   0x8000     /* markFlag: start lit, counting */
#define MARK_ON      0x4000     /* markFlag: line shown */
#define MARK_COUNT   0x3FFF     /* markFlag: frames since the last flip */
#define MARK_PERIOD  8



__attribute__((section(".text.func_001E6CD8")))
void func_001E6CD8(Slot2 *self) {
    unsigned int flag = self->markFlag[1];
    if (flag & MARK_BLINK) {
        unsigned short next;    /* short: the store keeps retail's andi 0xFFFF */
        flag = flag + 1;
        self->markFlag[1] = flag;
        if ((flag & MARK_COUNT) >= MARK_PERIOD) {
            next = (~flag & MARK_ON) | MARK_BLINK;
            self->markFlag[1] = next;
            if (next & MARK_ON) {
                displayScrollLayer(self->lineLayer, 1);
            } else {
                displayScrollLayer(self->lineLayer, 0);
            }
        }
    }
}

/* Fill the wave table: entry 0 is 0, then pairs of -x and +x with x growing by `step` after each +x. */
#define WAVE_TABLE_MAX  0x20

/* The ripple object: only the entry count is read here. */
typedef struct WaveObj {
    char unk000[0x2BC];
    unsigned int count;                 /* 0x2BC table entries to fill */
} WaveObj;

extern int D_0061B540[WAVE_TABLE_MAX];  /* wave heights */

__attribute__((section(".text.func_002E8168")))
void func_002E8168(WaveObj *self, float step) {
    unsigned int i;
    float x;
    D_0061B540[0] = 0;
    x = 0.0f;
    for (i = 1; i < self->count; i++) {
        if ((i & 1) == 0) {
            D_0061B540[i] = (int)-x;
        } else {
            D_0061B540[i] = (int)x;
            x += step;
        }
    }
}

/* Start the background music event named by the object's record, then arm its 30 frame timer. */



/* The scene record: its second halfword is the event number. */
typedef struct BgmRec {
    unsigned short unk00;
    unsigned short event;               /* 0x02 */
} BgmRec;

typedef struct BgmObj {
    char unk00[0x2E];
    short timer;                        /* 0x2E */
    char unk30[0x5C];
    BgmRec *rec;                        /* 0x8C */
} BgmObj;

__attribute__((section(".text.func_002B3CF8")))
int func_002B3CF8(BgmObj *self) {
    int event = self->rec->event;
    cSnd_BgmEventStart(D_005FEE00, event, 0, 0);
    /* Every arm arms the same timer; retail keeps the four-way compare tree. */
    switch (event) {
    case 6:
        self->timer = 0x1E;
        break;
    case 0xB:
        self->timer = 0x1E;
        break;
    case 0x2E:
        self->timer = 0x1E;
        break;
    case 0x2F:
        self->timer = 0x1E;
        break;
    default:
        self->timer = 0x1E;
        break;
    }
    return 0;
}

/* Run the message command at the read cursor: 0x93, 0x94 and 0xA8 are the three handled groups. */


#define MESS_CMD_93  0x9300
#define MESS_CMD_94  0x9400
#define MESS_CMD_A8  0xA800





__attribute__((section(".text.func_002B0028")))
void func_002B0028(cMessDrawFont *self, void *cmd) {
    unsigned short *code = (unsigned short *)self->cursor;
    switch (*code & 0xFF00) {
    case MESS_CMD_A8:
        func_002B00A0(self, cmd);
        break;
    case MESS_CMD_93:
        func_002B0208(self, cmd);
        break;
    case MESS_CMD_94:
        func_002B0420(self, cmd);
        break;
    }
}
