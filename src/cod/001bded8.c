/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"

extern int D_00586AF0;
extern void func_00297B20(void *a, void *b);
extern void func_00297B40(void *a, void *b);
extern void ScrollLayer_hideAtEnd(void);
extern void func_00298460(void);
extern char D_00462FC0[];
extern void cCollisionSolidManage_ReleaseUnit(void *manager, void *unit);
extern void cOmBase_dieCommon(void *obj);
extern int D_004294F0;
extern char D_007419A0[];
extern void espSys_effDataRelease(void *sys, int effNo);
extern void SetField214PtrThenInit_1B6F38(cGameObj *self, int flag);

/* Register the pair of hook callbacks at D_00586AF0. */






__attribute__((section(".text.RegisterCostumeHookPair")))
void RegisterCostumeHookPair(void)
{
    func_00297B20(&D_00586AF0, (void *)&ScrollLayer_hideAtEnd);
    func_00297B40(&D_00586AF0, (void *)&func_00298460);
}

/* Destroy hook: release the collision unit, then the owned child object. */
typedef struct ChildOwner {
    char unk000[0x15EC];
    void *child;                        /* 0x15EC owned object, dies with its owner */
} ChildOwner;

__attribute__((section(".text.ChildOwner_releaseChild")))
void ChildOwner_releaseChild(ChildOwner *self)
{
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, self);
    if (self->child != 0) {
        cOmBase_dieCommon(self->child);
        self->child = 0;
    }
}

/* State 5 of the screen-corner panel: set three screen points, then rebuild the layout. */
typedef struct CornerPanel {
    char unk00[0xA4];
    unsigned char state;                /* 0xA4 switch index of the panel update */
    char unkA5;
    short x0;                           /* 0xA6 */
    short y0;                           /* 0xA8 */
    short x1;                           /* 0xAA */
    short y1;                           /* 0xAC */
    short x2;                           /* 0xAE */
    short y2;                           /* 0xB0 */
} CornerPanel;

extern void func_002B1C80(CornerPanel *self);

__attribute__((section(".text.CornerPanel_setPointsState5")))
void CornerPanel_setPointsState5(CornerPanel *self)
{
    self->x0 = 0x100;
    self->y0 = 0x144;
    self->x1 = 0x1E0;
    self->y1 = 0x78;
    self->x2 = 0x100;
    self->y2 = 0x144;
    func_002B1C80(self);
}

/* Run the step for the current state byte at 0x02: state 0 or state 1. */
typedef struct StateObj {
    char unk00[2];
    unsigned char state;                /* 0x02 */
} StateObj;

extern void func_00385078(StateObj *self);
extern void func_00385138(StateObj *self);

__attribute__((section(".text.StateObj_runStep")))
void StateObj_runStep(StateObj *self)
{
    switch (self->state) {
    case 0:
        func_00385078(self);
        break;
    case 1:
        func_00385138(self);
        break;
    }
}

/* sn-2.95.3-136 */







/* Destructor of a game object subclass: set its method table, release effect data 0x241, run the base destructor. */
__attribute__((section(".text.cGameObj_destructSubclassB")))
void cGameObj_destructSubclassB(cGameObj *self, int flag) {
    self->vtable = (cVtEnt *)&D_004294F0;
    espSys_effDataRelease(D_007419A0, 0x241);
    SetField214PtrThenInit_1B6F38(self, flag);
}
