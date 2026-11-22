/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"

extern void func_002B45D0(void *self);
extern void func_002B45D8(void *self);
extern void ScriptRun_runDueCommands(void *self);
/* The manager that holds the frame length in 1/10 frames at 0xBDA. */
typedef struct FrameClock {
    char unk000[0xBDA];
    short frameLen;                     /* 0xBDA */
} FrameClock;

extern FrameClock *D_003C23A4;

typedef struct SysFlags {
    char unk000[0x178];
    long f178;                          /* 0x178 */
    char unk180[0x20];
    long f1A0;                          /* 0x1A0 */
} SysFlags;

extern SysFlags D_007474A0;

typedef struct StepObj {
    char unk00[0xD];
    unsigned char state;                /* 0xD */
    char unk0E[6];
    unsigned int flags;                 /* 0x14 */
    char unk18[0x1C];
    int wait;                           /* 0x34 */
    char unk38[0x30];
    int timer;                          /* 0x68 */
    float rate;                         /* 0x6C */
} StepObj;

/* Runs the object's start step once, then its per-frame step; advances the timer by the frame length (times 10 while the fast mode is on and no wait is set). */
__attribute__((section(".text.StepObj_stepTimer")))
void StepObj_stepTimer(StepObj *self) {
    int add;

    switch (self->state) {
    case 0:
        func_002B45D0(self);
        self->state = self->state + 1;
    case 1:
        func_002B45D8(self);
    }
    add = (short)((float)D_003C23A4->frameLen * self->rate);
    if ((D_007474A0.f1A0 & 0x10000000) != 0) {
        self->flags |= 1;
    }
    if (self->wait == 0) {
        if ((self->flags & 1) != 0 || (D_007474A0.f178 & D_003C3D48) != 0) {
            add = add * 10;
        }
    }
    self->timer = self->timer + add;
    ScriptRun_runDueCommands(self);
}
