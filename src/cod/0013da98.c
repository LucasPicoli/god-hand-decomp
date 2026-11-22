/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot2.h"
#include "godhand/globals.h"

extern void MtxInitRotY(void *a0);
extern void Tramp_func_0030A2B0_001508D8(int, void *, int);
extern void cIDBase_move(void *p);
extern void displayScrollLayer(int id, int on);
extern void func_001EC088(void *self);
extern void cTaskWork_exit(void *work);

struct buf_00150888 { char b[0x40]; };

/* Build a Y-axis rotation matrix from the angle and hand it to the matrix trampoline. */
__attribute__((section(".text.VecRotY")))
void VecRotY(int a0, int angle)
{
    struct buf_00150888 buf;
    MtxInitRotY(&buf);
    Tramp_func_0030A2B0_001508D8(a0, &buf, angle);
}

#define ICONSCREEN_SUB_FLAG_DONE 0x400  /* the child object finished its animation */

typedef struct IconScreenSub {
    char unk00[0x2C];
    unsigned int flags;                 /* 0x2C */
} IconScreenSub;

typedef struct IconScreen {
    char unk00[0x92];
    unsigned short step;                /* 0x92 */
    IconScreenSub *child;               /* 0x94 */
} IconScreen;

/* Advance to the next step once the child object has finished animating. */
__attribute__((section(".text.IconScreen_waitChildDone")))
void IconScreen_waitChildDone(IconScreen *self)
{
    if (self->child->flags & ICONSCREEN_SUB_FLAG_DONE) {
        cIDBase_move(self);
        self->step++;
    }
}

#define SLOT2_OFFSET_LAYER_IDS  0x3A0   /* scroll layer ids, not named in Slot2.h */
#define SLOT2_LAYER_ID_NUM      12

/* Hide every scroll layer of the machine's layer id table. */
__attribute__((section(".text.Slot2_hideLayerIds")))
void Slot2_hideLayerIds(Slot2 *self)
{
    int *id = (int *)((char *)self + SLOT2_OFFSET_LAYER_IDS);
    int i;

    for (i = SLOT2_LAYER_ID_NUM - 1; i >= 0; i--) {
        displayScrollLayer(*id++, 0);
    }
}

typedef struct StepObj {
    int unk00;
    int step;                           /* 0x04 index into the handler table */
} StepObj;

/* Call the handler for the current step (8 byte entries: short delta, handler at +4), then run the shared update. */
__attribute__((section(".text.Slot2_dispatchStep")))
void Slot2_dispatchStep(StepObj *self)
{
    int i = self->step;
    short off = *(short *)(D_003BE528 + i * 8);
    void (*fn)() = *(void (**)())(D_003BE528 + i * 8 + 4);
    fn((int)self + off);
    func_001EC088(self);
}

#define TASKFN_ARG1  1      /* call the function with the argument word */

/* The work record of a task that just runs one function and ends. */
typedef struct TaskFnWork {
    char unk00[0x14];
    void (*fn)();                       /* 0x14 */
    int arg;                            /* 0x18 */
    char unk1C[2];
    unsigned short kind;                /* 0x1E TASKFN_ARG1, anything else: no argument */
} TaskFnWork;



/* Task body: call the stored function (with its argument when kind is 1), then end the task. */
__attribute__((section(".text.TaskFnWork_runAndExit")))
void TaskFnWork_runAndExit(TaskFnWork *self)
{
    switch (self->kind) {
    default:
    case 0:
        self->fn();
        break;
    case TASKFN_ARG1:
        self->fn(self->arg);
        break;
    }
    cTaskWork_exit(self);
}
