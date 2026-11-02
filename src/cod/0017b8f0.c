/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmBase.h"
#include "godhand/ScenarioCursor.h"
#include "godhand/Slot2.h"
#include "godhand/cGameObj.h"

extern unsigned int D_00747A84[];
extern char D_00752C00;
extern void cMc_loadRunReleaseB(void);
extern void cTaskManager_execute(void *, void *, int);
extern void cScenarioCursor_reinit(ScenarioCursor *self);
extern void func_002BF420(ScenarioCursor *self);
extern void displayScrollLayer(int id, int on);
extern int D_00427A58;
extern void func_002AD288(void *sub, int mode);
extern void SetField214PtrThenInit_1B6F38(cGameObj *self, int flags);
extern int D_00421BB8;

/* Start the second memory card load/run/release task: set the pending flag
 * (bit 31) in the system flags, then register the task with the caller's arg. */
__attribute__((section(".text.cMc_startLoadRunReleaseB")))
void cMc_startLoadRunReleaseB(int mode) {
    D_00747A84[1] |= 0x80000000;
    cTaskManager_execute(&D_00752C00, (void *)&cMc_loadRunReleaseB, mode);
}

/* A cOmBase object whose damage record sits after the base at 0x654. */
typedef struct cOmHit654 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x74];
    int hitRecord;                      /* 0x654 damage record for cOmBase_checkDamage */
} cOmHit654;

extern int cOmBase_checkDamage(cOmHit654 *self, int record);

/* On a plain hit (result 1) restart the four state bytes at mode 1. */
__attribute__((section(".text.cOmHit_onDamageHit")))
void cOmHit_onDamageHit(cOmHit654 *self) {
    int r = cOmBase_checkDamage(self, self->hitRecord);
    if (r == 1) {
        self->base.mode = r;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* Run the step for the current step byte: step 0 reinitialises, step 1 runs. */
__attribute__((section(".text.ScenarioCursor_runStep")))
void ScenarioCursor_runStep(ScenarioCursor *self)
{
    switch (self->step) {
    case SCENARIOCURSOR_STEP_REINIT:
        cScenarioCursor_reinit(self);
        break;
    case SCENARIOCURSOR_STEP_RUN:
        func_002BF420(self);
        break;
    }
}

#define SLOT2_OFFSET_BANK_LAYER_IDS  0x400   /* second scroll layer id table, not named in Slot2.h */
#define SLOT2_BANK_LAYER_ID_NUM      35

/* Hide every scroll layer of the machine's second layer id table. */
__attribute__((section(".text.Slot2_hideBankLayerIds")))
void Slot2_hideBankLayerIds(Slot2 *self)
{
    int *id = (int *)((char *)self + SLOT2_OFFSET_BANK_LAYER_IDS);
    int i;

    for (i = SLOT2_BANK_LAYER_ID_NUM - 1; i >= 0; i--) {
        displayScrollLayer(*id++, 0);
    }
}

#define SUBOBJ_OFFSET  0xE40   /* sub-object this class owns, not named in cGameObj.h */

/* Destructor of a game object subclass: set its method table, shut the sub-object, run the base destructor. */
__attribute__((section(".text.cGameObj_destructWithSubE40")))
void cGameObj_destructWithSubE40(cGameObj *self, int flags) {
    self->vtable = (cVtEnt *)&D_00427A58;
    func_002AD288((char *)self + SUBOBJ_OFFSET, 2);
    SetField214PtrThenInit_1B6F38(self, flags);
}

#define SUBOBJ_OFFSET  0xD80   /* sub-object this class owns, not named in cGameObj.h */

/* Destructor of a game object subclass: set its method table, shut the sub-object, run the base destructor. */
__attribute__((section(".text.cGameObj_destructWithSubD80")))
void cGameObj_destructWithSubD80(cGameObj *self, int flags) {
    self->vtable = (cVtEnt *)&D_00421BB8;
    func_002AD288((char *)self + SUBOBJ_OFFSET, 2);
    SetField214PtrThenInit_1B6F38(self, flags);
}
