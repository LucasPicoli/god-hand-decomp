/* sn-2.95.3-136 matched TU. */

#include "godhand/cIDScreen4.h"
#include "godhand/cCoreSave.h"

extern void cIDBase_initialize(void *p, int a, int b);
extern void cIDBase_initIDWork(void *p, int i);
extern cIDBaseEnt *cIDBase_getIDWork(void *p, int i);
extern void cIDBase_restartAnim(void *p);

/* Set up the screen: build the four displays, collect the entry pointers of the first three,
 * restart the animation of the main one and of the last, mark four entries and store the game level. */
__attribute__((section(".text.cIDScreen4_initialize")))
void cIDScreen4_initialize(cIDScreen4 *self)
{
    unsigned short i;
    cIDBaseObj *pc;

    cIDBase_initialize(self, 1, 0);
    cIDBase_initialize(&self->partA, 1, 0xC);
    cIDBase_initialize(&self->partB, 1, 1);
    cIDBase_initialize(&self->partC, 1, 0x14);
    for (i = 0; i < IDSCREEN4_MAIN_ENT_NUM; i++) {
        cIDBase_initIDWork(self, i);
        self->mainEnt[i] = cIDBase_getIDWork(self, i);
    }
    for (i = 0; i < IDSCREEN4_A_ENT_NUM; i++) {
        cIDBase_initIDWork(&self->partA, i);
        self->aEnt[i] = cIDBase_getIDWork(&self->partA, i);
    }
    for (i = 0; i < IDSCREEN4_B_ENT_NUM; i++) {
        cIDBase_initIDWork(&self->partB, i);
        self->bEnt[i] = cIDBase_getIDWork(&self->partB, i);
    }
    cIDBase_restartAnim(self);
    self->base.playing = 1;
    pc = &self->partC;
    cIDBase_restartAnim(pc);
    pc->playing = 1;
    self->mainEnt[12]->flags |= IDSCREEN4_ENT_F_PULSE;
    self->mainEnt[13]->flags |= IDSCREEN4_ENT_F_PULSE;
    self->mainEnt[14]->flags |= IDSCREEN4_ENT_F_PULSE;
    self->mainEnt[15]->flags |= IDSCREEN4_ENT_F_PULSE;
    self->level = cCoreSave_getGameLevel(&D_00569B70);
    self->unk26D = 1;
    self->unk26C = 0;
}
