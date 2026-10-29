/* sn-2.95.3-136 matched TU. */

#include "godhand/cTaskWork.h"
#include "godhand/cObjBase.h"
#include "godhand/cDataManager.h"
#include "godhand/CustomIDWork.h"
#include "godhand/ColiseumBattle.h"
#include "godhand/cGameObj.h"

extern int CreateThread(void *param);
extern void func_003B0BA8(int tid, cTaskWork *self);
extern void WakeupThread(int tid);
extern void WaitSema(int sema);
extern void cTaskWork_kill(cTaskWork *self);
extern char D_0041EAF0[];
extern cDataManager D_005864E0;
extern cDataManager D_00580D20;
extern int cDataManager_isLoaded(cDataManager *self, int kind);
extern void cDataManager_resetKind(cDataManager *self, int kind, int arg);
extern void CustomIDWork_SetOffsetPosY(CustomIDWork *self, int y);
extern void CustomIDWork_SetMoveOffsetPosY(CustomIDWork *self, int from, int to, int frames);
extern void SetCustomIDDispOneOrAll_1DD258(void *self, int sel, int on);
extern void ColiseumBattle_DefeatAllEnemies(ColiseumBattle *self);
extern int IsEntryActive_1C2490(int entry);
extern void displayScrollLayer(int id, int on);

/* The sleep counter at 0xE sits in cTaskWork's unnamed span; the thread parameters start at 0x20. */
#define TASKWORK_COUNT(self)   (*(unsigned short *)((char *)(self) + 0xE))
#define TASKWORK_THREAD_ARGS(self) ((char *)(self) + 0x20)
#define TASKWORK_STATE_DONE    0x7F







/* cTaskWork_step: one step of the task, switched on its state (0xC). State 2 creates the thread, state 1
 * counts the sleep down and wakes the thread at zero, state 4 and the ends of the other two mark the task
 * done and wait on the manager's semaphore. Once the state is DONE the task is killed. */
__attribute__((section(".text.cTaskWork_step")))
void cTaskWork_step(cTaskWork *self)
{
    switch (self->running) {
    case 2:
        self->tid = CreateThread(TASKWORK_THREAD_ARGS(self));
        func_003B0BA8(self->tid, self);
        goto done;
    case 1:
        TASKWORK_COUNT(self) = TASKWORK_COUNT(self) - 1;
        if (TASKWORK_COUNT(self) != 0) {
            break;
        }
        WakeupThread(self->tid);
    case 4:
    done:
        self->running = TASKWORK_STATE_DONE;
        WaitSema(self->owner[TASKWORK_SEMA_WORD]);
        break;
    }
    if (self->running == TASKWORK_STATE_DONE) {
        cTaskWork_kill(self);
    }
}

/* cObj__dtor: the cObj part of the destructor. Put this class's vtable back, release the actor's data
 * kind from whichever manager holds it, then run the cModel part. */
__attribute__((section(".text.cObj__dtor")))
int cObj__dtor(cObjBase *self, int flag)
{
    self->vtable = (cVtEnt *)D_0041EAF0;
    if (self->actorId != 0) {
        if (cDataManager_isLoaded(&D_005864E0, self->actorId) == 1) {
            cDataManager_resetKind(&D_005864E0, self->actorId, 0);
        } else if (cDataManager_isLoaded(&D_00580D20, self->actorId) == 1) {
            cDataManager_resetKind(&D_00580D20, self->actorId, 0);
        }
    }
    return cModel_destroy(self, flag);
}

/* The element that slides in and out sits at 0xDC of the owner. */
#define OWNER_SLIDE_IDW(self) ((CustomIDWork *)((char *)(self) + 0xDC))
#define SLIDE_HIDDEN_Y  (-0x46)

/* CustomIDOwner_setSlideState: place or slide the element in (sel 2: down from hidden to shown over 10 frames; sel 3:
 * the way back; sel 1: shown at once; others: hidden). */
__attribute__((section(".text.CustomIDOwner_setSlideState")))
void CustomIDOwner_setSlideState(void *self, unsigned char sel)
{
    switch (sel) {
    case 0:
    default:
        CustomIDWork_SetOffsetPosY(OWNER_SLIDE_IDW(self), SLIDE_HIDDEN_Y);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 0);
        break;
    case 1:
        CustomIDWork_SetOffsetPosY(OWNER_SLIDE_IDW(self), 0);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 1);
        break;
    case 2:
        CustomIDWork_SetMoveOffsetPosY(OWNER_SLIDE_IDW(self), SLIDE_HIDDEN_Y, 0, 10);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 1);
        break;
    case 3:
        CustomIDWork_SetMoveOffsetPosY(OWNER_SLIDE_IDW(self), 0, SLIDE_HIDDEN_Y, 10);
        SetCustomIDDispOneOrAll_1DD258(self, 1, 1);
        break;
    }
}

/* ColiseumBattle_stepEntryWait5: phase 0 defeats every enemy and moves on; phase 1 clears each of the first five entry
 * handles whose entry reports active. */
__attribute__((section(".text.ColiseumBattle_stepEntryWait5")))
void ColiseumBattle_stepEntryWait5(ColiseumBattle *self)
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
        if (self->unkC64[3] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[3]) != 0) {
                self->unkC64[3] = 0;
            }
        }
        if (self->unkC64[4] != 0) {
            if (IsEntryActive_1C2490(self->unkC64[4]) != 0) {
                self->unkC64[4] = 0;
            }
        }
        break;
    }
}

/* A box as centre and half-extents. */
typedef struct Box {
    float x, y, z;              /* 0x00 centre */
    float hx, hy, hz;           /* 0x0C half-extents */
} Box;

extern void func_001F8A88(Box *self, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

/* Box_growToContain: grow the box to contain another box, by taking the lower and upper bound on each axis. */
__attribute__((section(".text.Box_growToContain")))
Box *Box_growToContain(Box *self, Box *other)
{
    float minX, maxX, minY, maxY, minZ, maxZ;
    float t;

    t = self->x - self->hx;
    minX = other->x - other->hx;
    if (t < minX) minX = t;
    t = self->x + self->hx;
    maxX = other->x + other->hx;
    if (maxX < t) maxX = t;

    t = self->y - self->hy;
    minY = other->y - other->hy;
    if (t < minY) minY = t;
    t = self->y + self->hy;
    maxY = other->y + other->hy;
    if (maxY < t) maxY = t;

    t = self->z - self->hz;
    minZ = other->z - other->hz;
    if (t < minZ) minZ = t;
    t = self->z + self->hz;
    maxZ = other->z + other->hz;
    if (maxZ < t) maxZ = t;

    func_001F8A88(self, minX, maxX, minY, maxY, minZ, maxZ);
    return self;
}

/* A screen that owns eight scroll layers and two game objects (0x4B0 and 0x4B4). */
typedef struct LayerScreen {
    char unk000[0x54];
    int flags;                  /* 0x054 bit 0x200: layers shown */
    char unk058[0x454 - 0x58];
    int layer454;               /* 0x454 scroll layer ids */
    int layer458;
    int layer45C;
    int layer460;
    char unk464[0x484 - 0x464];
    int layer484;
    int layer488;
    char unk48C[0x4B0 - 0x48C];
    cGameObj *objA;             /* 0x4B0 */
    cGameObj *objB;             /* 0x4B4 */
} LayerScreen;



/* LayerScreen_hideLayers: with both objects present, hide every layer and clear the shown flag; for sel 1 also
 * zero the objects' x positions and show the two main layers again. */
__attribute__((section(".text.LayerScreen_hideLayers")))
void LayerScreen_hideLayers(LayerScreen *self, unsigned char sel)
{
    if (sel < 2) {
        if (self->objA == 0) return;
        if (self->objB == 0) return;
        displayScrollLayer(self->layer454, 0);
        displayScrollLayer(self->layer458, 0);
        displayScrollLayer(self->layer45C, 0);
        displayScrollLayer(self->layer460, 0);
        displayScrollLayer(self->layer484, 0);
        displayScrollLayer(self->layer488, 0);
        self->flags &= ~0x200;
        if (sel == 0) return;
        if (sel == 1) {
            self->objA->pos->x = 0.0f;
            self->objB->pos->x = 0.0f;
            displayScrollLayer(self->layer454, 1);
            displayScrollLayer(self->layer484, 1);
            self->flags |= 0x200;
        }
    }
}
