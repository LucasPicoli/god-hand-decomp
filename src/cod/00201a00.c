/* sn-2.95.3-136 matched TU. */
#include "godhand/messPanel.h"

extern unsigned int D_00747A84[];
extern char D_00752C00;
extern void cMc_loadRunRelease(void);
extern void cTaskManager_execute(void *, void *, int);
extern int func_003999A8(void);
extern void func_00323A70(void *);
extern char D_0042C780;
extern void func_002BF708(void *);
extern void SysFlags_saveAndFreeze(void *);
extern void func_002C0A08(void *);
extern void *D_003C264C;
extern float Adjust_theta(float f12);
extern void cTaskWork_kill(void *work);

/* Start the memory card load/run/release task: set the pending flag
 * (bit 31) in the system flags, then register the task with the caller's arg. */





__attribute__((section(".text.cMc_startLoadRunRelease")))
void cMc_startLoadRunRelease(int mode) {
    D_00747A84[1] |= 0x80000000;
    cTaskManager_execute(&D_00752C00, (void *)&cMc_loadRunRelease, mode);
}

/* If func_003999A8 reports 0x14 and the entry for D_0042C780 exists, release it.
 * Returns 1 unless an entry was released. */





__attribute__((section(".text.Entry_releaseIfReady")))
int Entry_releaseIfReady(void) {
    if (func_003999A8() == 0x14) {
        void *e = func_00323618(&D_0042C780, 0);
        if (e != 0) {
            func_00323A70(e);
            return 0;
        }
    }
    return 1;
}

/* Re-initialise a scenario cursor: run the two reset steps, tell the manager,
 * then set its four state bytes (0x1 = 1, 0x0 = old 0x0 value, rest 0). */





__attribute__((section(".text.cScenarioCursor_reinit")))
void cScenarioCursor_reinit(char *self) {
    func_002BF708(self);
    SysFlags_saveAndFreeze(self);
    func_002C0A08(D_003C264C);
    {
        char old = self[0];
        self[1] = 1;
        self[0] = old;
        self[2] = 0;
        self[3] = 0;
    }
}

/* Blend two angles: wrap b, wrap the wrapped difference a - b, scale it by
 * the factor c and add it back onto b, wrapping each step. */


__attribute__((section(".text.Ang_blendLate")))
float Ang_blendLate(float a, float b, float c) {
    float base = Adjust_theta(b);
    float diff = Adjust_theta(Adjust_theta(a) - base);
    return Adjust_theta(base + diff * c);
}

/* Kill every task record of a pool: works array at +0, count at +0xC. */
#define POOL_WORK_SIZE 0x58

typedef struct TaskPool {
    char *works;                        /* 0x00 */
    char unk04[8];
    unsigned short count;               /* 0x0C */
} TaskPool;



__attribute__((section(".text.cTaskPool_killAll")))
void cTaskPool_killAll(TaskPool *self) {
    int i;
    for (i = 0; i < self->count; i++)
        cTaskWork_kill(self->works + i * POOL_WORK_SIZE);
}

/* Reset a panel to its start pose: copy the saved position to the current one, set the text
 * scale to 1.0 and the text offset to (1, -20), then draw the text and the frame. */
__attribute__((section(".text.Panel_resetToStartPose")))
void Panel_resetToStartPose(Panel *self) {
    self->curX = self->savedX;
    self->curY = self->savedY;
    self->scaleA = 1.0f;
    self->scaleB = 1.0f;
    self->ofsX = 1;
    self->ofsY = -20;
    func_002B1C80(self);
    func_002B1890(self);
}
