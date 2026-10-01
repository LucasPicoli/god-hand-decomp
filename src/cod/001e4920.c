/* sn-2.95.3-136 matched TU. */

#include "godhand/Slot2.h"
#include "godhand/cMessDrawFont.h"

extern int ResetEntityStateById_2C29F8(int a0, int a1);
extern void cScenario_taskExec(void *a0, void *a1, void *a2, int a3);
extern char D_005FEA60[];
extern char *D_003C2F84;
extern void func_001E4970(void);
extern char *D_003BD6E8;
extern void func_00143A90(char *a0);
extern void *cMessage_getMessageAddr(void *mgr, int id);
extern void *cMessage_getRubyAddr(void *mgr, int id);
extern void cMessDrawFont_setBodyData(cMessDrawFont *a0, void *a1, void *a2, void *a3);
extern void cMessDrawFont_setRubyData(cMessDrawFont *a0, void *a1, void *a2);
extern void cMessDrawFont_setDrawCounter(cMessDrawFont *a0, int a1, int a2);
extern void *D_003C23A4;
extern void func_001E6BE8(Slot2 *a0);
extern void func_001E6CD8(Slot2 *a0);
extern void func_001E6DA0(Slot2 *a0);
extern void func_001E6E68(Slot2 *a0);
extern void func_001E6FE8(Slot2 *a0);
extern void func_001E79E8(void *a0);
extern void func_001E8830(void *a0);
extern int cCoreSave_getGold(void *a0);
extern void CustomIDWork_SetNumber(void *a0, int a1);
extern void func_001E73C0(void *a0);
extern void func_001E7440(void *a0);
extern void func_001E6938(Slot2 *a0);
extern char D_00569B70[];
extern int D_00747A2C;

/* Slot2 action-button handler: reset the slot's entity state, then run the
 * slot's per-frame task with this object. */








__attribute__((section(".text.Slot2_actBtnHandler")))
void Slot2_actBtnHandler(Slot2 *self) {
    ResetEntityStateById_2C29F8((int)D_005FEA60, self->slotId);
    cScenario_taskExec(D_003C2F84, (void *)&func_001E4970, self, -1);
}

/* Slot2 end-of-game stage: on the first call run the end hook, then flag the
 * game as over. */





__attribute__((section(".text.Slot2_endGameStep")))
void Slot2_endGameStep(Slot2 *self) {
    switch (self->step) {
    case 0:
        func_00143A90(D_003BD6E8 + 0x1AE0);
        self->step++;
        /* fallthrough */
    case 1:
        self->endFlag |= 1;
        break;
    }
}

/* Start drawing a message: look up its text and ruby by id and reset the
 * draw counter. */









__attribute__((section(".text.cMessDrawFont_setMessage")))
void cMessDrawFont_setMessage(cMessDrawFont *self, int id) {
    void *msg;
    void *ruby;

    id = id & 0xFFFF;
    msg = cMessage_getMessageAddr(D_003C23A4, id);
    ruby = cMessage_getRubyAddr(D_003C23A4, id);
    cMessDrawFont_setBodyData(self, msg, msg, 0);
    cMessDrawFont_setRubyData(self, ruby, ruby);
    cMessDrawFont_setDrawCounter(self, 0, MESSDRAWFONT_COUNT_NONE);
}

/* Slot2 per-frame update: dispatch the current screen through the state
 * table, tick the sub-objects, and refresh the clock and the layer. */


typedef struct Slot2VtEnt { short delta; short pad; void *pfn; } Slot2VtEnt;

typedef struct { Slot2VtEnt e[1]; } Slot2VtTbl;
extern Slot2VtTbl D_003BE140;















__attribute__((section(".text.Slot2_update")))
void Slot2_update(Slot2 *self) {
    Slot2VtTbl *vt = &D_003BE140;
    void *layer = self->layer;
    int t;

    ((void (*)(void *))vt->e[self->state].pfn)((char *)self + vt->e[self->state].delta);
    func_001E6BE8(self);
    func_001E6CD8(self);
    func_001E6DA0(self);
    func_001E6E68(self);
    func_001E6FE8(self);
    func_001E79E8(&self->panel);
    func_001E8830(&self->reel[0]);
    func_001E8830(&self->reel[1]);
    func_001E8830(&self->reel[2]);
    t = cCoreSave_getGold(D_00569B70);
    CustomIDWork_SetNumber(self->customId, t);
    func_001E73C0(layer);
    func_001E7440(layer);
    if (D_00747A2C & 0x200) {
        func_001E6938(self);
    }
}
