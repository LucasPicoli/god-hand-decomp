#include "godhand/cObjBase.h"

/* sn-2.95.3-136 matched TU. */

extern void cObjBase_runPhase1(cObjBase *self);
extern void func_0014EB90(cObjBase *self);
extern void func_0014EC88(cObjBase *self);
extern void func_0014ED60(cObjBase *self);
extern void cObjBase_runPhase5(cObjBase *self);

/* Run the handler for the actor's current phase. */
__attribute__((section(".text.cObjBase_R0_scenario")))
void cObjBase_R0_scenario(cObjBase *self) {
    switch (self->phase) {
    case 1:
        cObjBase_runPhase1(self);
        break;
    case 2:
        func_0014EB90(self);
        break;
    case 3:
        func_0014EC88(self);
        break;
    case 4:
        func_0014ED60(self);
        break;
    case 5:
        cObjBase_runPhase5(self);
        break;
    case 0:
    case 0xF:
    default:
        break;
    }
}
