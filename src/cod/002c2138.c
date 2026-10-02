/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cSceAtManager.h"
#include "godhand/cScenario.h"
#define SCEAT_TYPE_HIT     0xB          /* units with the enable flag that FindNodeByHit looks at */

extern char *D_003C23A4;
extern void cTaskWork_exit(cTaskWork *work);
extern void func_002D56A8(void *a0);
extern char D_007474A0[];
extern char D_0061A990[];
extern void func_002D9BD0(void *a0);
extern void func_002D9BD8(void *a0);

__attribute__((section(".text.SetNodeCallback_2C2138")))
int SetNodeCallback_2C2138(char *a0, int a1) {
    int t;
    if (*(int*)(a0+0x3C) == 0) {
        return 0;
    }
    t = cScenario_taskExec_2C38D8(D_003C2F84, *(void **)(a0+0x3C), *(void **)(a0+0x40), *(char*)(a0+0x44));
    D_003C2F84->taskData[t].owner = a1;
    return 1;
}

__attribute__((section(".text.ForwardEntityAndExit_2C2368")))
void ForwardEntityAndExit_2C2368(char *a0) {
    char *s1 = a0 + 0x5C;
    int v1 = *(unsigned short*)(s1 + 2);
    if ((unsigned int)v1 < 0x1000) {
        v1 = func_002AEB50(D_003C23A4, *(unsigned short*)(a0 + 0x5C), v1);
    }
    cScenario_execUpCutData(D_003C2F84, v1, *(int*)(s1 + 0xC), 0, 0, 1);
    cTaskWork_exit(D_003C2F84->task.cur);
}

extern cSceAtUnit *cSceAtManager_getUnitList(cSceAtManager *self);
extern cSceAtUnit *cSceAtManager_getNextUnit(cSceAtManager *self, cSceAtUnit *e);
extern void func_002C1D68(cSceAtManager *self, int *out, cSceAtUnit *e);
extern int cArea_HitCheck_1F83E8(int *hit, void *shape);
extern void cSceAtUnit_getCenterPos(cSceAtUnit *unit, void *out);
extern cSceAtUnit *cSceAtManager_getUnit(cSceAtManager *self, int id);
extern int cSceAtManager_SetDisable(cSceAtManager *self, cSceAtUnit *unit);
/* First enabled unit of type 0xB that the shape hits. Copies its position to out. */
__attribute__((section(".text.FindNodeByHit_2C2490")))
int FindNodeByHit_2C2490(cSceAtManager *self, void *shape, float *out) {
    cSceAtUnit *e;
    int hit[12];
    e = cSceAtManager_getUnitList(self);
    while ((e = cSceAtManager_getNextUnit(self, e)) != 0) {
        /* flags (0x34) and type (0x35) are read as one word to test both */
        if ((*(int *)&e->flags & 0xFF01) == ((SCEAT_TYPE_HIT << 8) | SCEAT_FLAG_ENABLED)) {
            func_002C1D68(self, hit, e);
            if (cArea_HitCheck_1F83E8(hit, shape) == 1) {
                if (out != 0) {
                    out[0] = e->pos[0];
                    out[1] = e->pos[1];
                    out[2] = e->pos[2];
                }
                return 1;
            }
        }
    }
    return 0;
}

/* First unit of type 0xD that the shape hits. Copies its position to out. */
__attribute__((section(".text.FindNodeByType_2C2568")))
int FindNodeByType_2C2568(cSceAtManager *self, void *shape, float *out) {
    cSceAtUnit *e;
    int hit[12];
    e = cSceAtManager_getUnitList(self);
    while ((e = cSceAtManager_getNextUnit(self, e)) != 0) {
        if (e->type == 0xD) {
            func_002C1D68(self, hit, e);
            if (cArea_HitCheck_1F83E8(hit, shape) == 1) {
                if (out != 0) {
                    out[0] = e->pos[0];
                    out[1] = e->pos[1];
                    out[2] = e->pos[2];
                }
                return 1;
            }
        }
    }
    return 0;
}

/* First enabled unit of type 0xC that the shape hits. Gives its centre and extent. */
__attribute__((section(".text.FindEntityAtPosition_2C2638")))
int FindEntityAtPosition_2C2638(cSceAtManager *self, void *shape, void *centerOut, float *extentOut) {
    cSceAtUnit *e;
    int hit[12];
    e = cSceAtManager_getUnitList(self);
    while ((e = cSceAtManager_getNextUnit(self, e)) != 0) {
        if (((e->flags ^ SCEAT_FLAG_ENABLED) & SCEAT_FLAG_ENABLED) != 0) continue;
        if (e->type != 0xC) continue;
        func_002C1D68(self, hit, e);
        if (cArea_HitCheck_1F83E8(hit, shape) != 1) continue;
        if (centerOut != 0) cSceAtUnit_getCenterPos(e, centerOut);
        if (extentOut != 0) *extentOut = e->extent;
        return 1;
    }
    return 0;
}

/* Turn off the unit with the given id. */
__attribute__((section(".text.cSceAtManager_SetDisableById")))
int cSceAtManager_SetDisableById(cSceAtManager *self, int id) {
    cSceAtUnit *unit;
    if (self->enabled == 0) return 0;
    unit = cSceAtManager_getUnit(self, id & 0xFFFF);
    if (unit == 0) return 0;
    return cSceAtManager_SetDisable(self, unit);
}

/* First placed unit (type 1) whose spawn index is idx. */
__attribute__((section(".text.cSceAtManager_getUnitBySpawnIdx")))
cSceAtUnit *cSceAtManager_getUnitBySpawnIdx(cSceAtManager *self, int idx) {
    cSceAtUnit *e;
    e = cSceAtManager_getUnitList(self);
    while ((e = cSceAtManager_getNextUnit(self, e)) != 0) {
        if (e->type == SCEAT_UNIT_TYPE_MARK) {
            if (e->spawnIdx == idx) return e;
        }
    }
    return 0;
}

__attribute__((section(".text.ClearActorList_2C32C0")))
void ClearActorList_2C32C0(void *a0) {
    func_002D56A8((char*)a0 + 0x1C);
    *(char*)((char*)a0 + 0x14) = 0;
}

__attribute__((section(".text.ResetActorState_2C3440")))
void ResetActorState_2C3440(void *a0) {
    int v0;
    char *b = D_007474A0;
    *(unsigned short*)((char*)a0 + 0x112) = 0xFFFF;
    *(int*)((char*)a0 + 0x104) = 0;
    *(int*)((char*)a0 + 0xEC) = 0;
    *(int*)((char*)a0 + 0xF0) = 0;
    *(int*)((char*)a0 + 0xF4) = 0;
    *(int*)((char*)a0 + 0xF8) = 0;
    *(int*)((char*)a0 + 0xFC) = 0;
    *(int*)((char*)a0 + 0x100) = 0;
    *(char*)((char*)a0 + 0x108) = 0;
    *(short*)((char*)a0 + 0xE8) = 0;
    *(int*)(b + 0x610) = 0xFFFFu;
    v0 = *(int*)((char*)a0 + 0x48);
    v0 &= -2;
    v0 &= -3;
    *(int*)((char*)a0 + 0x48) = v0;
    if ((*(int*)(b + 0x590) & 1) == 0) {
        void (*f)(void);
        func_002D9BD0(D_0061A990);
        f = *(void (**)(void))(*(char**)((char*)a0 + 0xD4) + 8);
        if (f != 0) f();
        func_002D9BD8(D_0061A990);
    }
}

__attribute__((section(".text.cScenario_runRoomExitFunc")))
/* Run roomExitFunc(roomExitArg) once. */
void cScenario_runRoomExitFunc(cScenario *self) {
    void (*f)(void *) = self->roomExitFunc;
    if (f != 0) {
        f(self->roomExitArg);
        self->roomExitFunc = 0;
    }
}
