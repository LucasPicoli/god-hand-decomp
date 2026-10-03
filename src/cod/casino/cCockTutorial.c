/* TU: cCockTutorial [casino] - recovered C++ class. */
#include "godhand/cCockTutorial.h"

extern void *D_003C2388;
extern void *D_003C2384;
extern char D_0041E970[];
extern char D_00583F20[];
extern char D_00754220[];
extern void cIDManager_getLocalFileName(void *mgr, char *out, char *fmt, int n);
extern int cDvd_ReadAlloc(void *dvd, char *name, void **out, void *heap, int a, int b, int c, int d);
extern void cDvd_CheckWait(void *dvd, int id);
extern void cIDManager_setIDData(void *mgr, int pack, void *data);
extern void cIDBase_initialize(cCockTutorial *self, int pack, int a);
extern void cIDBase_setPackedMessData(cCockTutorial *self, int pack, int a);
extern void cIDBase_restartAnim(cCockTutorial *self);
extern cIDBaseEnt *cIDBase_getIDWork(cCockTutorial *self, int id);

/* Prepare the tutorial display for the room: load the message pack once,
 * initialise the display and look the seven entries up by id. */
__attribute__((section(".text.cCockTutorial_roomInit")))
void cCockTutorial_roomInit(cCockTutorial *self) {
    char name[0x40];
    unsigned int i;
    if (self->data == 0) {
        cIDManager_getLocalFileName(D_003C2388, name, D_0041E970, -1);
        self->readId = cDvd_ReadAlloc(D_00583F20, name, &self->data, D_00754220, 0, 0, 0, 0);
        cDvd_CheckWait(D_00583F20, self->readId);
        cIDManager_setIDData(*(void **)D_003C2384, COCKTUT_MSG_PACK, self->data);
        cIDBase_initialize(self, COCKTUT_MSG_PACK, 0);
        cIDBase_setPackedMessData(self, COCKTUT_MSG_PACK, 1);
    }
    cIDBase_restartAnim(self);
    self->base.playing = 1;
    for (i = 0; i < COCKTUT_ENT_NUM; i++) {
        self->ent[i] = cIDBase_getIDWork(self, i);
    }
    self->ent[0]->sclX = 0;
    self->ent[0]->sclY = 0;
    self->ent[1]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[2]->flags |= IDENT_FLAG_NO_DRAW;
    self->ent[3]->msg = 0x200C;
    self->ent[4]->msg = 0x200C;
    self->curMsg = COCKTUT_MSG_NONE;
    self->unkB8 = 0;
}
