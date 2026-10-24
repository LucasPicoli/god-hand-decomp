/* sn-2.95.3-136: func_002006B8, per-frame check of a saved camera/position point: unless the game is paused or the point
 * is locked, the first pass saves the current point, sets the BGM state, opens the sub screen and releases
 * the scenario; then the point is reloaded from the stage start table or restored from the save. */
#include "godhand/cScenario.h"
#include "godhand/cOmBase.h"
#include "godhand/cSubScr.h"

#define GAMEWORK_FLAG_BIT6  6
#define GAMEWORK_SUBSCR_ON  0x8000000   /* flags5E4: the sub screen is still open */
#define ROOM_NOPLAYER       0x20        /* the boot room, as gameWork.h GAMEWORK_ROOM_NOPLAYER */

typedef struct SavePoint {
    float x;                            /* 0x00 */
    float y;                            /* 0x04 */
    float z;                            /* 0x08 */
    float w;                            /* 0x0C */
    unsigned short kind;                /* 0x10 */
    unsigned char f12;                  /* 0x12 */
    unsigned char lock;                 /* 0x13 */
    int f14;                            /* 0x14 */
} SavePoint;

typedef struct SavePointWork {
    char unk00[4];
    SavePoint cur;                       /* 0x04 */
    SavePoint save;                      /* 0x1C */
    char unk34[5];
    signed char step;                   /* 0x39 */
    unsigned char busy;                 /* 0x3A */
} SavePointWork;

/* Game work words read through the two symbols retail addresses them from: D_00747A2C[3] is
 * GameWork.flags598, D_00747A2C[-2] and D_00747A24 are GameWork.flags, and the shorts at
 * D_00747A2C + 0x24 and D_00747A24 + 0x2C are GameWork.room. gameWork.h declares D_00747A2C as
 * a GameSys and D_00747A24 as an int; as GameWork fields these reads take more instructions. */
extern int D_00747A2C[];
extern int D_00747A24;
extern unsigned int D_00747A84;         /* D_007474A0.flags5E4 under its own symbol */
extern char D_005FEE00[];
extern cVec D_00583F00[];
extern float D_003BF198[];
extern void cSnd_SetBgmState(void *snd, int state);

__attribute__((section(".text.func_002006B8")))
int func_002006B8(SavePointWork *self)
{
    unsigned long t;
    unsigned short v;
    MenuScreen *w;
    int idx;
    cVec *sp;

    t = (unsigned int)D_00747A2C[3];
    if (((t >> GAMEWORK_FLAG_BIT6) & 1) == 1)
        return 1;
    if (self->busy != 0)
        return 1;
    if (self->cur.kind == 0xFFFF)
        return 1;
    if (self->cur.lock == 1)
        return 1;
    switch (self->step) {
    case 0:
        t = D_00747A2C[-2];
        if (((t >> GAMEWORK_FLAG_BIT6) & 1) != 1) {
            v = *(unsigned short *)((char *)D_00747A2C + 0x24);
            if (v != 0 && v != ROOM_NOPLAYER)
                self->save = self->cur;
        }
        cSnd_SetBgmState(D_005FEE00, 0);
        cSubScr_SubScrOn(D_003BD930, 3, 2, 0x11);
        cScenario_release(D_003C2F84);
        self->step++;
    case 1:
        if (D_00747A84 & GAMEWORK_SUBSCR_ON)
            return 0;
    }
    w = SUBSCR_SCREEN03(D_003BD930);
    idx = (unsigned short)w->choice;
    if (w->result == 0) {
        sp = &D_00583F00[idx];
        self->cur.x = sp->x;
        self->cur.y = sp->y;
        self->cur.z = sp->z;
        self->cur.w = D_003BF198[idx];
        self->cur.f12 = 0xFF;
        self->cur.kind = 0;
    } else {
        t = D_00747A24;
        if (((t >> GAMEWORK_FLAG_BIT6) & 1) == 1)
            return 1;
        if (*(unsigned short *)((char *)&D_00747A24 + 0x2C) != 0)
            return 1;
        if (self->cur.kind != 0x100)
            return 1;
        self->cur = self->save;
    }
    return 1;
}
