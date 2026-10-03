/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/cGameObj.h"

extern float cEmManage_GetSpeedRate(void *manager);
extern int D_00586AF0;
extern void func_002987F8(void);
extern void func_002988A8(void);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern int D_00422240;
extern char D_007419A0[];
extern void espSys_effDataRelease(void *sys, int effNo);
extern void SetField214PtrThenInit_1B6F38(cGameObj *self, int flag);

/* An object with a start time and a countdown past cOmBase. */
typedef struct WaitObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x4C];
    float startTime;                    /* 0x62C */
    float timeLeft;                     /* 0x630 */
} WaitObj;


extern int D_005864F0;                  /* enemy manager */
extern float D_00747A14;                /* global speed rate */

/* Wait step: load the countdown from the start time, count it down by the frame rate, and when it is spent go back to phase 0 in mode 1. */
__attribute__((section(".text.WaitObj_stepCountdown")))
void WaitObj_stepCountdown(WaitObj *self)
{
    switch (self->base.phase) {
    case 0:
        self->timeLeft = self->startTime;
        self->base.phase = 1;
        /* falls through */
    case 1:
        if (self->timeLeft <= 0.0f) {
            self->base.phase = 0;
            self->base.mode = 1;
        } else {
            self->timeLeft -= cEmManage_GetSpeedRate(&D_005864F0) * D_00747A14;
        }
        break;
    }
}

/* Register the scroll-layer callback pair on the hook list at D_00586AF0. */






__attribute__((section(".text.RegisterScrollLayerHooks")))
void RegisterScrollLayerHooks(void) {
    func_00297B20(&D_00586AF0, (void *)&func_002987F8);
    func_00297B40(&D_00586AF0, (void *)&func_002988A8);
}

/* State 4 of the screen-corner panel: set three screen points, then rebuild the layout. */
typedef struct CornerPanel {
    char unk00[0xA4];
    unsigned char state;                /* 0xA4 switch index of the panel update */
    char unkA5;
    short x0;                           /* 0xA6 */
    short y0;                           /* 0xA8 */
    short x1;                           /* 0xAA */
    short y1;                           /* 0xAC */
    short x2;                           /* 0xAE */
    short y2;                           /* 0xB0 */
} CornerPanel;

extern void func_002B1C80(CornerPanel *self);

__attribute__((section(".text.CornerPanel_setPointsState4")))
void CornerPanel_setPointsState4(CornerPanel *self)
{
    self->x0 = 0x100;
    self->y0 = 0x170;
    self->x1 = 0x1E0;
    self->y1 = 0x78;
    self->x2 = 0x100;
    self->y2 = 0x170;
    func_002B1C80(self);
}

/* 1 if the squared XZ distance from target to the object's position is within range, else 0. */
__attribute__((section(".text.cGameObj_isWithinRangeXZ")))
int cGameObj_isWithinRangeXZ(cGameObj *self, cVec *target, float range) {
    int in = 0;
    cVec *pos = self->pos;
    if (capVu0MagnitudeSqXZ(target, pos) <= range) {
        in = 1;
    }
    return in;
}

/* Destructor of a game object subclass: set its method table, release effect data 0x27D, run the base destructor. */
__attribute__((section(".text.cGameObj_destructSubclass")))
void cGameObj_destructSubclass(cGameObj *self, int flag) {
    self->vt = (cGameObjVt *)&D_00422240;
    espSys_effDataRelease(D_007419A0, 0x27D);
    SetField214PtrThenInit_1B6F38(self, flag);
}

/* Arena header: block start, size, and a user word. */
typedef struct Arena {
    char *block;                        /* 0x0 start of the managed block */
    int size;                           /* 0x4 size in bytes */
    int user;                           /* 0x8 */
} Arena;

extern void func_002A94F0(Arena *self);

/* Set up an arena over a block; an empty block or size leaves it cleared. */
__attribute__((section(".text.Arena_init")))
void Arena_init(Arena *self, char *block, int size, int user) {
    if (block == 0 || size == 0) {
        self->block = 0;
        self->size = 0;
    } else {
        self->block = block;
        self->size = size;
        func_002A94F0(self);
    }
    self->user = user;
}
