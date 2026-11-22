/* sn-2.95.3-136 matched TU. */

#include "godhand/ColiseumBattle.h"
#include "godhand/cOmBase.h"
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/globals.h"

extern short D_00568240[];
extern void ColiseumEmSelect_close(void);
extern void ColiseumUi_StartFade(void *self, int mode);
extern void func_001F44E0(void *self);
extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);
extern int IsEntryActive_1C2490(int entry);
extern int cIDManager_getLocalFileName();
extern int cDvd_ReadAlloc();
extern void cDvd_CheckWait();
extern void cIDManager_setIDData();
extern void func_001DD0D8(void *self);
extern void func_001DECE0(void *work);
extern int D_003C2388;
extern int *D_003C2384;
extern char D_00583F20[];
extern char D_00754220[];
extern char D_005E8040[];
extern void KeySlotTable_set(char *slot, int a1, int a2);
extern unsigned short D_00747A50;
extern unsigned char D_005FEA60[];
extern int FindEntityAtPosition_2C2638(void *mgr, void *shape, void *centerOut, float *extentOut);
extern void func_002E83D8(int a0, int a1, int a2, int a3, int t0);

/* ColiseumBattle_stepEmSelectStart: two-step start of the enemy-select screen, each step waiting for the fade-done bit
 * (bit 2 of D_0074748C). State 0 closes the select window and starts a fade; state 1 clears the
 * select record, marks the screen entered and starts the next stage. */
__attribute__((section(".text.ColiseumBattle_stepEmSelectStart")))
void ColiseumBattle_stepEmSelectStart(ColiseumBattle *self)
{
    switch (self->state) {
    case 0:
        if ((D_0074748C >> 2) & 1) {
            ColiseumEmSelect_close();
            ColiseumUi_StartFade(self, 0);
            self->state = self->state + 1;
        }
        break;
    case 1:
        if ((D_0074748C >> 2) & 1) {
            D_00568240[8] = 0;
            D_00568240[9] = 0;
            self->flags |= COLISEUM_FLAG_ENTERED;
            func_001F44E0(self);
            self->state = self->state + 1;
        }
        break;
    case 2:
        break;
    }
}

/* ColiseumBattle_stepEntryWait: phase 0 defeats every enemy and moves on; phase 1 clears each of the first three entry
 * handles whose entry reports active. */
__attribute__((section(".text.ColiseumBattle_stepEntryWait")))
void ColiseumBattle_stepEntryWait(ColiseumBattle *self)
{
    switch (self->phase) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->unkC64[0] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[0]) != 0) {
                self->unkC64[0] = 0;
            }
        }
        if (self->unkC64[1] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[1]) != 0) {
                self->unkC64[1] = 0;
            }
        }
        if (self->unkC64[2] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[2]) != 0) {
                self->unkC64[2] = 0;
            }
        }
        break;
    }
}

/* IdScreen_loadIdData: load the ID data file of this screen (set number 0x12) from disc, then initialise the
 * owner and
 * the work area at 0x25B0. */
__attribute__((section(".text.IdScreen_loadIdData")))
void IdScreen_loadIdData(char *self)
{
    char name[0x40];
    int size;
    int r;

    cIDManager_getLocalFileName(D_003C2388, name, D_0042B6E8, -1);
    r = cDvd_ReadAlloc(D_00583F20, name, &size, D_00754220, 0, 0, 0, 0);
    if (r != 0) {
        cDvd_CheckWait(D_00583F20, r);
        cIDManager_setIDData(*D_003C2384, 0x12, size);
        func_001DD0D8(self);
        func_001DECE0(self + 0x25B0);
    }
}

typedef struct KeyHolder {
    char unk00[0xC0];
    cVec *pos;              /* 0xC0 */
} KeyHolder;

typedef struct KeyLink {
    char unk00[0x34];
    KeyHolder *holder;      /* 0x34 */
} KeyLink;

/* An object that follows a position taken from a key-slot holder. */
typedef struct KeyFollower {
    cVec posA;              /* 0x00 */
    cVec posB;              /* 0x10 */
    char unk20[8];
    KeyLink *link;          /* 0x28 */
    short id;               /* 0x2C */
    unsigned char ready;    /* 0x2E */
} KeyFollower;





/* KeyFollower_attach: take a key slot from the table (-1 when none is left), register it, and start both
 * position copies from the holder's position. Returns the object id. */
__attribute__((section(".text.KeyFollower_attach")))
int KeyFollower_attach(KeyFollower *self, int a1, int a2, int a3, int t0, int t1, int key)
{
    char *slot;
    slot = Pool_createObjWithVt(D_005E8040);
    self->link = (KeyLink *)slot;
    if (slot == 0) {
        return -1;
    }
    KeySlotTable_set(slot + 0x14, 1, key);
    cVec_copy3(&self->posB, self->link->holder->pos);
    cVec_copy3(&self->posA, &self->posB);
    self->ready = 1;
    return self->id;
}

/* cEm00_startHitUnitAim: in mode 0x700, for any enemy except 0x220 to 0x223, look for a type-0xC hit unit at the
 * enemy's position; when found, aim at its centre (unk580) and extent (unk590.z) and switch to phase 0x88. */
__attribute__((section(".text.cEm00_startHitUnitAim")))
int cEm00_startHitUnitAim(cEm00 *self)
{
    cVec center;
    float extent;
    VU0_SQC2_VF0(&center, 0);
    if (D_00747A50 != 0x700) {
        return 0;
    }
    if (self->emNo < 0x224) {
        if (self->emNo >= 0x220) {
            return 0;
        }
    }
    if (FindEntityAtPosition_2C2638(D_005FEA60, self->pos, &center, &extent) == 0) {
        return 0;
    }
    cVec_copy3(&self->unk580, &center);
    self->unk590.z = extent;
    self->phase = 0x88;
    self->mode = 0;
    self->step = 0;
    self->stepArg = 0;
    return 1;
}

/* A menu panel record; the flag word at 0x11C has bit 0x800000 set once its setup has run. */
typedef struct Panel {
    char unk000[0x11C];
    unsigned int state;         /* 0x11C */
} Panel;

extern void func_002E9808(Panel *self, int a1, int a2, int a3);
extern void func_002E8B38(Panel *self, int a1, int a2);

extern void func_002E8EE8(Panel *self, int a1, int a2, int a3);

/* Panel_setupOnce: one-time panel setup, skipped once bit 0x800000 of the state word is set. Runs three
 * calls on column 4 with modes 2, 1 and 0, then the border, two ramp calls and the last cell. */
__attribute__((section(".text.Panel_setupOnce")))
void Panel_setupOnce(Panel *self)
{
    if ((self->state & 0x800000) == 0) {
        func_002E9808(self, 4, 12, 2);
        func_002E9808(self, 4, 12, 1);
        func_002E9808(self, 4, 12, 0);
        func_002E8B38(self, 4, 11);
        func_002E83D8(10, 0x3B00, 0x3A00, 0, 1);
        func_002E83D8(10, 0x3A00, 0x3900, 1, 0);
        func_002E8EE8(self, 4, 9, 1);
    }
}
