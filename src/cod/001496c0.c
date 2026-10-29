/* sn-2.95.3-136 matched TU. */

#include "godhand/cModel.h"
#include "godhand/cOmSized.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
#include "godhand/cScenario.h"
#include "godhand/cTaskWork.h"
#include "godhand/espSys.h"

extern char D_0041EA90[];
extern void cHeap_free(int, void *);
extern void cModel_removeMesh(cModel *self);
extern void func_00149E60(cModel *self);
extern void cBoundingBox__dtor(cBox *box, int flags);
extern void func_00150048(cModel *self, int flags);
extern void func_001B6FB8(cOmSized *self);
extern void cOmDoor_setObjCollisionCenterOnly(cOmSized *self);
extern void SetFlagBit_1BD698(cOmSized *self);
extern void *cCamera_getScreenPos(cVec *out, void *camera, cVec *world);
extern void CustomIDWork_SetLocalPosXY(void *work, int x, int y);
extern cScenario *D_003C2F84;
extern void KeyStop(void);
extern int cScenario_taskExec(cScenario *sc, void *fn, void *arg, int attr);
extern void func_001BF8C8(void);
extern unsigned int D_00747A84;
extern void func_002FA350(float *frame);

/* Destructor body of the model: installs its vtable, frees the packet block, drops meshes and parts, then runs the base destructor. */
__attribute__((section(".text.cModel_destroy")))
void cModel_destroy(cModel *self, int flags) {
    self->vtable = (void *)D_0041EA90;
    if (self->alloc != 0) {
        cHeap_free(((int *)self->alloc)[-8], self->alloc);
    }
    cModel_removeMesh(self);
    func_00149E60(self);
    cBoundingBox__dtor(&self->box, 2);
    func_00150048(self, flags);
}

extern void func_001BDD88(cOmSized *self, float f);

/* Init: base setup, extent 1.5 x 2.4 x 0.1, then the shared setters; returns 1. */
__attribute__((section(".text.cOmSized_start")))
int cOmSized_start(cOmSized *self) {
    cVec ext;

    func_001B6FB8(self);
    ext.x = 1.5f;
    ext.y = 2.4f;
    ext.z = 0.1f;
    ext.w = 1.0f;
    cVec_copy3(&self->extent, &ext);
    cOmDoor_setObjCollisionCenterOnly(self);
    SetFlagBit_1BD698(self);
    func_001BDD88(self, 2.5f);
    COMSIZED_SCRFLAGS(self) |= COMSIZED_SCR_READY;
    return 1;
}

/* Init: base setup, extent 3.2 x 3.1 x 0.2, then the shared setters (the first extent value is also the setter's argument); returns 1. */
__attribute__((section(".text.cOmSized_startLarge")))
int cOmSized_startLarge(cOmSized *self) {
    cVec ext;
    float size = 3.2f;

    func_001B6FB8(self);
    ext.x = size;
    ext.y = 3.1f;
    ext.z = 0.2f;
    ext.w = 1.0f;
    cVec_copy3(&self->extent, &ext);
    cOmDoor_setObjCollisionCenterOnly(self);
    SetFlagBit_1BD698(self);
    func_001BDD88(self, size);
    COMSIZED_SCRFLAGS(self) |= COMSIZED_SCR_READY;
    return 1;
}

extern void *D_005CAFF0;                /* the camera */


extern void func_001ED700(void *self, int n, int f);

#define MARKER_WORK_OFFSET  0x2CC       /* the marker's CustomIDWork */

/* Moves the marker to the screen position of a world point, then runs its step 5. */
__attribute__((section(".text.ScreenMarker_moveToWorldPos")))
void ScreenMarker_moveToWorldPos(char *self, cVec *world, int arg) {
    struct {
        cVec pos;
        cVec tmp;                       /* 0x10 */
    } f;

    void *camera = D_005CAFF0;

    if (camera != 0) {
        VU0_SQC2_VF0(&f, 0x0);
        cCamera_getScreenPos(&f.tmp, camera, world);
        cVec_copy3(&f.pos, &f.tmp);
        CustomIDWork_SetLocalPosXY(self + MARKER_WORK_OFFSET, (int)f.pos.x, (int)f.pos.y);
        func_001ED700(self, 5, arg);
    }
}

/* The system flag words from D_00747A78 on: the third one is at +8. */
typedef struct SysFlagWords {
    unsigned int f78;                   /* 0x747A78 */
    unsigned int f7C;
    unsigned int f80;                   /* 0x747A80 */
} SysFlagWords;

extern SysFlagWords D_00747A78;





/* Enter the cut: next phase, freeze the game flags and the pad, run the cut task for this object and mark both the task and the scenario as soft events. */
__attribute__((section(".text.cOmBase_startCutTask")))
void cOmBase_startCutTask(cOmBase *self) {
    int no;
    unsigned int flags;
    char *works;

    self->phase = self->phase + 1;
    flags = D_00747A78.f78;
    flags |= 0x80000000; flags |= 0x40000000; flags |= 0x20000000; flags |= 0x10000000; flags |= 0x8000000;
    flags |= 0x4000000; flags |= 0x800000; flags |= 0x400000; flags |= 0x100000;
    D_00747A78.f78 = flags;
    D_00747A78.f80 = D_00747A78.f80 | 0x100000;
    KeyStop();
    no = cScenario_taskExec(D_003C2F84, (void *)func_001BF8C8, self, 1);
    works = D_003C2F84->task.works;     /* dead store: the unused read changes retail's register choice */
    if (no >= 0) {
        cTaskWork *e = (cTaskWork *)(no * TASKMGR_WORK_SIZE + (int)D_003C2F84->task.works);
        e->attr = e->attr | SCENARIO_TASK_SOFT_EVENT;
    }
    D_003C2F84->task.flags = D_003C2F84->task.flags | SCENARIO_F_SOFT_EVENT;
}

/* An effect that steps through indexed frames; a different record from EspAnim (espSys.h), with the frame counter at 0x240. */
typedef struct EspAnim2 {
    char unk000[0x110];
    EspData *data;                      /* 0x110 */
    char unk114[0x11C - 0x114];
    unsigned int flags;                 /* 0x11C */
    char unk120[0x23F - 0x120];
    signed char frameNum;               /* 0x23F */
    float frame;                        /* 0x240 */
    unsigned char loopNo;               /* 0x244 */
    char unk245[0x2A0 - 0x245];
    signed char loopNum;                /* 0x2A0 */
} EspAnim2;

#define ESP_F_RUN        0x04000000     /* flags: the effect is running */
#define ESP_F_CLOCK      0x100          /* flags: advance through the clock function */
#define ESP_F_REPEAT     0x02000000     /* flags: wrap the loop number */




/* Advances a running effect by one tick; when the frame count is reached, restarts the frame and moves to the next loop, wrapping (or holding the last loop) when the loops run out. */
__attribute__((section(".text.EspAnim2_stepLoop")))
void EspAnim2_stepLoop(EspAnim2 *self) {
    int index;
    unsigned char loop;

    if ((self->flags & ESP_F_RUN) == 0) {
        return;
    }
    if ((self->data->flags & ESP_DATA_PAUSE) == 0 && (self->flags & ESP_F_CLOCK) != 0) {
        func_002FA350(&self->frame);
    } else if ((D_00747A84 & SYSFLAG_SLOWMO) != 0) {
        func_002FA350(&self->frame);
    } else {
        self->frame = self->frame + 1.0f;
    }
    index = (int)self->frame;
    if ((signed char)index < self->frameNum) {
        return;
    }
    loop = self->loopNo;
    self->frame = 0;
    self->loopNo = loop + 1;
    if ((signed char)self->loopNo < self->loopNum) {
        return;
    }
    if ((self->flags & ESP_F_REPEAT) != 0) {
        self->loopNo = 0;
        return;
    }
    self->loopNo = loop;
}
