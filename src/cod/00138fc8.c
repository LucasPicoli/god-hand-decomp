/* sn-2.95.3-136 matched TU. */

#include "godhand/cCamManager.h"
#include "godhand/cEm00.h"
#include "godhand/cEmSetParam.h"
#include "godhand/cScenario.h"
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/SlotUi.h"

extern void func_00137F38(void *state, cCamManager *mgr);
extern void cCamera_move(void *cam);
extern void cEmSetParam_updateSetDataFlag(cEmSetParam *self, int id, unsigned int flags);
extern void cTaskWork_sleep(cTaskWork *work, int frames);
extern SlotUiHost **D_003C2384;
extern int cIDBase_release(void *idBase);
extern void cHeap_free(int heap, int *node);

/* Calls the object's own method at vtable slot 0x10, unless the object
 * has the 0x10000 flag set. */
typedef struct VtEnt { short delta; short pad; void (*fn)(void *self); } VtEnt;
typedef struct Obj002FBE88 {
    char unk000[0xF0];
    VtEnt *vt;                          /* 0x0F0 method table; the call uses entry 2 */
    char unk0F4[0x11C - 0xF4];
    unsigned int flags;                 /* 0x11C */
} Obj002FBE88;

__attribute__((section(".text.func_002FBE88")))
void func_002FBE88(Obj002FBE88 *self)
{
    VtEnt *vt;
    if (self->flags & 0x10000) {
        return;
    }
    vt = self->vt;
    vt[2].fn((char *)self + vt[2].delta);
}

/* Steps the manager's state, then moves the current camera unless the
 * manager is in motion-camera mode. */
__attribute__((section(".text.cCamManager_update")))
void cCamManager_update(cCamManager *self)
{
    func_00137F38(self->unkFF4, self);
    if (!(self->mode & CAMMGR_MODE_NO_MOVE)) {
        cCamera_move(D_005CAFF0);
    }
}

/* Clears two flag bits of the enemy and tells the room's placement table
 * the new flag word for the enemy's entry. */
__attribute__((section(".text.cEm00_clearSetFlags")))
void cEm00_clearSetFlags(cEm00 *self)
{
    unsigned int flags = self->flags1644;
    flags &= ~0x10000000;
    flags &= ~0x8000;
    self->flags1644 = flags;
    cEmSetParam_updateSetDataFlag(&D_00586AB0, self->entryNo, flags);
}

extern cTaskWork *D_00752C04;           /* the main task, used when no script task runs */

/* cScenario 0x50 is the hword just past the embedded task manager. Retail forms
 * the address from the manager pointer, so the body does the same. */
#define TASK_AFTER_WORD(task) (*(unsigned short *)((char *)(task) + sizeof(cTaskManager)))

/* Sleeps the running script task for one step and leaves the frame count
 * at cScenario 0x50; with no script task running, sleeps the main task
 * for `frames` instead. */
__attribute__((section(".text.cScenario_sleepFrames")))
void cScenario_sleepFrames(unsigned short frames)
{
    cTaskManager *task = &D_003C2F84->task;
    cTaskWork *cur = task->cur;
    if (cur != 0) {
        TASK_AFTER_WORD(task) = frames;
        cTaskWork_sleep(cur, 1);
    } else {
        cTaskWork_sleep(D_00752C04, frames);
    }
}

extern float D_00428000[];              /* per game level scale, levels past 5 use entry 5 */

/* The object's speed rate scaled by the table entry for the game level. */
__attribute__((section(".text.cGameObj_getLevelSpeedScale")))
float cGameObj_getLevelSpeedScale(cGameObj *self)
{
    int level = cCoreSave_getGameLevel(&D_00569B70);
    if (level > CORESAVE_LEVEL_NUM) {
        level = CORESAVE_LEVEL_NUM;
    }
    return D_00428000[level] * self->speedRate;
}

/* Releases both id bases of the panel, clears the host's two pick words and
 * frees the panel's heap node. */
__attribute__((section(".text.SlotUi_release")))
void SlotUi_release(SlotUi *self)
{
    SlotUiHost *host;
    cIDBase_release(self->idBase2);
    cIDBase_release(self);
    host = *D_003C2384;
    host->pickB = 0;
    host->pickA = 0;
    if (self->node != 0) {
        cHeap_free(self->node[-8], self->node);
    }
}
