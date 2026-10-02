/* sn-2.95.3-136 matched TU. */
#include "godhand/cScenario.h"

extern int D_00747A78;
extern int D_00747A84;
extern char D_00747B20[];
extern char D_005864F0[];
extern void HideModelMgr_ResetHiddenModels(void *a0);
extern void HideModelMgr_ClearHiddenModelList(void *a0);
extern void KeyStop(void);
extern void *Getplayer(void);
extern void func_00126770(void *a0);
extern void func_002948E8(void *a0, int a1);
extern void func_002FA470(int a0);

__attribute__((section(".text.cScenario_startSoftEvent")))
/* Enter a soft event of the given type: the first call freezes play the
 * way the type asks, nested calls only count. */
void cScenario_startSoftEvent(cScenario *self, int type)
{
    int t;
    int v;

    t = (unsigned short)self->softEventDepth + 1;
    self->softEventDepth = t;
    if ((short)t >= 2) return;

    self->softEventType = type;
    if (type == 5) {
        HideModelMgr_ResetHiddenModels(D_00747B20);
        HideModelMgr_ClearHiddenModelList(D_00747B20);
    } else {
        char *g = (char *)&D_00747A84;
        D_00747A84 = D_00747A84 | 0x40000040;
        KeyStop();
        *(int *)(g - 0xC) = *(int *)(g - 0xC) | 0x00400000;
        *(int *)(g - 0x4) = *(int *)(g - 0x4) | 0x00100000;
        *(int *)(g - 0xC) = *(int *)(g - 0xC) | 0x00100000;
        *(int *)(g - 0x4) = *(int *)(g - 0x4) | 0x02000000;
        func_00126770(Getplayer());

        switch (self->softEventType) {
        case 0:
        case 1:
        case 3:
            {
                char *g2 = (char *)&D_00747A78;
                char *p;
                char *vt;
                D_00747A78 = D_00747A78 | 0x00040000;
                *(int *)(g2 + 0xC) = *(int *)(g2 + 0xC) | 0x00010000;
                *(int *)(g2 + 0xC) = *(int *)(g2 + 0xC) | 0x04000000;
                HideModelMgr_ResetHiddenModels(D_00747B20);
                HideModelMgr_ClearHiddenModelList(D_00747B20);
                func_002948E8(D_005864F0, 1);
                cScenario_setOmSuspend(self, 1);
                func_002FA470(1);
                p = (char *)Getplayer();
                vt = *(char **)(p + 0x214);
                (*(void (**)(char *, int))(vt + 0x64))(p + *(short *)(vt + 0x60), 1);
                *(int *)(g2 + 0xC) = *(int *)(g2 + 0xC) | 0x01000000;
            }
            break;
        case 2:
            D_00747A78 = D_00747A78 | 0x00040000;
            D_00747A78 = D_00747A78 | 0x80000000;
            D_00747A78 = D_00747A78 | 0x40000000;
            D_00747A78 = D_00747A78 | 0x20000000;
            D_00747A78 = D_00747A78 | 0x10000000;
            D_00747A78 = D_00747A78 | 0x08000000;
            D_00747A78 = D_00747A78 | 0x04000000;
            D_00747A78 = D_00747A78 | 0x00800000;
            break;
        case 4:
            {
                char *g3 = (char *)&D_00747A84;
                D_00747A84 = D_00747A84 | 0x00080000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x40000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x80000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x20000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x10000000;
                *(int *)(g3 - 0xC) = *(int *)(g3 - 0xC) | 0x04000000;
            }
            break;
        case 5:
            break;
        }
    }
    v = self->task.curNo;
    if (v >= 0) {
        cTaskWork *e = (cTaskWork *)(v * TASKMGR_WORK_SIZE + (int)self->task.works);
        e->attr = e->attr | SCENARIO_TASK_SOFT_EVENT;
    }
    self->task.flags = self->task.flags | SCENARIO_F_SOFT_EVENT;
}
