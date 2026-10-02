/* sn-2.95.3-136 matched TU. */
#include "godhand/cScenario.h"

extern int D_00747A78;
extern int D_00747A80;
extern int D_00747A84;
extern char D_005864F0[];
extern void *Getplayer(void);
extern void pl00_reset(void *a0);
extern void func_002948E8(void *a0, int a1);
extern void func_002FA470(int a0);

__attribute__((section(".text.cScenario__endSoftEvent")))
/* Leave a soft event; the last nested call undoes what startSoftEvent did. */
void cScenario__endSoftEvent(cScenario *self)
{
    int t;
    int c;
    int v;

    c = (unsigned short)self->softEventDepth;
    if (self->softEventDepth <= 0) return;
    t = c - 1;
    self->softEventDepth = t;
    if ((short)t > 0) return;

    {
        char *g = (char *)&D_00747A84;

        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x02000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00400000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00100000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00040000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & 0x7FFFFFFF;
        D_00747A84 = D_00747A84 & ~0x40000000;
        D_00747A84 = D_00747A84 & ~0x40;
        D_00747A84 = D_00747A84 & ~0x00010000;
        D_00747A84 = D_00747A84 & ~0x04000000;
        D_00747A84 = D_00747A84 & ~0x01000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x40000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x20000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x10000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x08000000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x04000000;
        *(int *)(g - 0x4) = *(int *)(g - 0x4) & ~0x00100000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) & ~0x00800000;

        /* An int view: through the struct type this load is scheduled
         * above the flag stores just before it. */
        switch (*(int *)&self->softEventType) {
        case 0:
        case 1:
        case 3:
            D_00747A80 = D_00747A80 & ~0x02000000;
            func_002FA470(0);
            cScenario_resetCam(self);
            break;
        case 2:
            D_00747A80 = D_00747A80 & ~0x02000000;
            func_002FA470(0);
            break;
        case 4:
            D_00747A84 = D_00747A84 & ~0x00080000;
            pl00_reset(Getplayer());
            cScenario_resetCam(self);
            break;
        case 5:
            cScenario_resetCam(self);
            break;
        }
    }
    func_002948E8(D_005864F0, 0);
    cScenario_setOmSuspend(self, 0);
    {
        char *p = (char *)Getplayer();
        char *vt = *(char **)(p + 0x214);
        (*(void (**)(char *, int))(vt + 0x64))(p + *(short *)(vt + 0x60), 0);
    }
    v = self->task.curNo;
    if (v >= 0) {
        cTaskWork *e = (cTaskWork *)(v * TASKMGR_WORK_SIZE + (int)self->task.works);
        e->attr = e->attr & ~SCENARIO_TASK_SOFT_EVENT;
    }
    self->task.flags = self->task.flags & ~SCENARIO_F_SOFT_EVENT;
}
