/* TU: cMc - recovered C++ class. */
extern void *D_003C23A4;
extern void ObjTrans(void);
extern void func_002AF028(void *);
#include "godhand/cMc.h"

extern void *D_005CAFF0;
extern void *D_003BD6E8;
extern cMcObjList *D_00754C58;
extern void cCamera_move(void *cam);
extern void MoveEffect(void);
extern void cMessage_updateAll(void *p);
extern void func_00140E58(void *p);

/* One frame of the loading screen: move the camera, the effects and two
 * managers, then call the move method of every listed object that is not
 * suspended and not flagged skip. The two flag tests stay two nested ifs: written
 * with && they merge into one mask test. */
__attribute__((section(".text.cMc_Move")))
void cMc_Move(cMc *self) {
    cMcObj **p;
    cMcObj *obj;
    cCamera_move(D_005CAFF0);
    MoveEffect();
    cMessage_updateAll(D_003C23A4);
    func_00140E58(D_003BD6E8);
    for (p = D_00754C58->begin; p != D_00754C58->end; p++) {
        obj = *p;
        if ((obj->objFlags & MCOBJ_FLAG_SUSPEND) == 0) {
            if ((obj->objFlags & MCOBJ_FLAG_SKIP) == 0) {
                obj->vt->move((char *)obj + obj->vt->moveDelta);
            }
        }
    }
}

__attribute__((section(".text.cMc_Trans")))
void cMc_Trans(void) {
    ObjTrans();
    func_002AF028(D_003C23A4);
}
