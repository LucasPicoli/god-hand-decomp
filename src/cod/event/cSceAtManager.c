/* TU: cSceAtManager [event] - the attack/hit-box manager. */
#include "godhand/cSceAtManager.h"

extern cSceAtTypeEnt D_003C2650[];
extern int func_002C0E68(cSceAtUnit *unit);
extern void cSceAtUnit_SetEnable(cSceAtUnit *unit, int arg);
extern void cSceAtUnit_SetDisable(cSceAtUnit *unit, int arg);
extern void cSceAtUnit_getCenterPos(cSceAtUnit *unit, int out);
extern void *func_002C0ED0(cSceAtUnit *unit, void *arg);
extern cSceAtUnit *cSceAtManager_getUnitList(cSceAtManager *self);
extern cSceAtUnit *cSceAtManager_getNextUnit(cSceAtManager *self, cSceAtUnit *e);
extern void func_002C3058(cSceAtManager *self, unsigned int *list, cSceAtUnit *unit);
extern cSceAtUnit *cSceAtManager_getUnit(cSceAtManager *self, int id);
extern int cSceAtManager_SetEnable_2C28F8(cSceAtManager *self, cSceAtUnit *unit);
extern void cSceAtManager_AtDataSetExec(cSceAtManager *self, cSceAtUnit *unit, int a2, int a3, int a4, int a5);

/* Turn one unit on, unless it already is. Returns 0 if the manager is off. */
__attribute__((section(".text.cSceAtManager_SetEnable_2C28F8")))
int cSceAtManager_SetEnable_2C28F8(cSceAtManager *self, cSceAtUnit *unit) {
    if (self->enabled == 0) return 0;
    if (unit == 0) return 0;
    if (func_002C0E68(unit) != 0) return 1;
    cSceAtUnit_SetEnable(unit, 0);
    return 1;
}

/* Turn on the unit with the given id. */
__attribute__((section(".text.cSceAtManager_SetEnable_2C2950")))
int cSceAtManager_SetEnable_2C2950(cSceAtManager *self, unsigned short id) {
    cSceAtUnit *unit;
    if (self->enabled == 0) return 0;
    unit = cSceAtManager_getUnit(self, id);
    if (unit == 0) return 0;
    return cSceAtManager_SetEnable_2C28F8(self, unit);
}

/* Turn one unit off if it is on. Returns 0 if the manager is off. */
__attribute__((section(".text.cSceAtManager_SetDisable")))
int cSceAtManager_SetDisable(cSceAtManager *self, cSceAtUnit *unit) {
    if (self->enabled == 0) return 0;
    if (unit == 0) return 0;
    if (func_002C0E68(unit) != 0) {
        cSceAtUnit_SetDisable(unit, 0);
    }
    return 1;
}

/* Write the centre of the unit with the given id to out. */
__attribute__((section(".text.cSceAtManager_getCenterPos")))
void cSceAtManager_getCenterPos(cSceAtManager *self, unsigned short id, int out) {
    cSceAtUnit *unit;
    if (self->enabled) {
        unit = cSceAtManager_getUnit(self, id);
        if (unit) {
            cSceAtUnit_getCenterPos(unit, out);
        }
    }
}

/* Ask the unit with the given id whether it is hit. */
__attribute__((section(".text.cSceAtManager_isHit")))
void *cSceAtManager_isHit(cSceAtManager *self, int id, void *arg) {
    cSceAtUnit *unit = cSceAtManager_getUnit(self, id);
    if (unit == 0) return 0;
    return func_002C0ED0(unit, arg);
}

/* Find the unit with the given id in the manager's list, or 0. */
__attribute__((section(".text.cSceAtManager_getUnit")))
cSceAtUnit *cSceAtManager_getUnit(cSceAtManager *self, int id) {
    cSceAtUnit *e;
    if (id == SCEAT_ID_NONE) return 0;
    e = cSceAtManager_getUnitList(self);
    while ((e = cSceAtManager_getNextUnit(self, e)) != 0) {
        if (e->id == id) return e;
    }
    return 0;
}

/* Set the hit kind and data of the unit with the given id. */
__attribute__((section(".text.cSceAtManager_AtDataSet_exec")))
void cSceAtManager_AtDataSet_exec(cSceAtManager *self, unsigned short id, int a2, int a3, int a4, int a5) {
    cSceAtUnit *unit = cSceAtManager_getUnit(self, id);
    if (unit) {
        cSceAtManager_AtDataSetExec(self, unit, a2, a3, a4, a5);
    }
}

/* Take one unit out of the manager's unit list. */
/* cSceAtManager_AtExecuteUnit: run the type handler of one unit with the full-strength argument. */

__attribute__((section(".text.cSceAtManager_AtExecuteUnit")))
void cSceAtManager_AtExecuteUnit(cSceAtManager *self, cSceAtUnit *unit) {
    if (unit != 0) {
        D_003C2650[unit->type].handler(unit, SCEAT_ON_RESET);
    }
}

/* cSceAtManager_AtExecuteById: look a unit up by id and run its type handler. */

__attribute__((section(".text.cSceAtManager_AtExecuteById")))
void cSceAtManager_AtExecuteById(cSceAtManager *self, unsigned short id) {
    cSceAtUnit *unit = cSceAtManager_getUnit(self, id);
    if (unit != 0) {
        D_003C2650[unit->type].handler(unit, SCEAT_ON_RESET);
    }
}

/* Take one unit out of the manager's unit list. */
__attribute__((section(".text.cSceAtManager_delUnitData")))
void cSceAtManager_delUnitData(cSceAtManager *self, cSceAtUnit *unit) {
    if (unit) {
        func_002C3058(self, &self->unitList, unit);
    }
}
