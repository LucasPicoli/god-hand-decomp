/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cCoreSave.h"
#include "godhand/cSaveManager.h"
#include "godhand/cGameObj.h"

extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int D_005FEE00[];
extern cSaveRooms D_005E9CB8;
extern cSaveTail D_00755880;
extern cSaveWorld D_007474A0;
extern char D_00568240[];
extern void func_0031C438(void);
extern cGameObj *Getplayer(void);
extern void cCoreSave_loadStageState(cCoreSave *self, int flag);
extern void Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(void *p);

/* Phase machine of the enemy that waits out a counted pause: it plays its start motion, counts
 * 0x900 down once the motion ends, then resets the state bytes and sets bit 0 of 0x5B0. */
__attribute__((section(".text.func_001BE068"))) void func_001BE068(cEm00 *self)
{
    int v0;

    switch (self->phase) {
        case 0:
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 8, self, 0, 0, 0, 0);
            v0 = self->resource;
            func_002A8578(self, EM_RES_REC(v0, 0xC), 0, 0, 0.0f, 0, 0);
            self->phase = 1;
            self->step = 0;
            self->stepArg = 0;
        case 1:
            if (moveMotion(self) != 0) {
                self->unk900 = 10;
                self->phase = 2;
                self->stepArg = (self->step = 0);
            }
            break;
        case 2:
            if (self->unk900 < 0) {
                self->step = 0;
                self->phase = 3;
                self->stepArg = 0;
            }
            self->unk900 = self->unk900 - 1;
            break;
        case 3:
            self->mode = 2;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
            self->unk5B0 = self->unk5B0 | 1;
            break;
    }
}

/* Put a checkpoint snapshot back: the save record, the room pages and the
 * tail block; then restore the stage state, remember where the player
 * stands and (when asked) reset the block at D_00568240. */
__attribute__((section(".text.cSaveManager_getCheckPoint")))
void cSaveManager_getCheckPoint(cSaveSlot *src, int flag) {
    *(cSaveCore *)D_00569B70.data = src->core;
    D_005E9CB8 = src->rooms;
    D_00755880 = src->tail;
    func_0031C438();
    D_007474A0.pos[0] = Getplayer()->pos->x;
    D_007474A0.pos[1] = Getplayer()->pos->y;
    D_007474A0.pos[2] = Getplayer()->pos->z;
    D_007474A0.angle = Getplayer()->rot[1];
    cCoreSave_loadStageState(&D_00569B70, flag);
    if (flag) {
        Obj0000_Clear_Fields_00_08_0C_0E_10_12_1F6CF8(D_00568240);
    }
}
