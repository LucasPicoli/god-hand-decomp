#include "godhand/cCockBossBar.h"
#include "godhand/globals.h"

extern void *D_003C2388;
extern void *D_003C2384;
extern char D_00583F20[];
extern char D_00754220[];
extern void cIDManager_getLocalFileName(void *mgr, char *out, char *fmt, int n);
extern int cDvd_ReadAlloc(void *dvd, char *name, void **out, void *heap, int a, int b, int c, int d);
extern void cDvd_CheckWait(void *dvd, int id);
extern void cIDManager_setIDData(void *mgr, int pack, void *data);
extern void cIDBase_initialize(cCockBossBar *self, int pack, int a);
extern void cIDBase_restartAnim(cCockBossBar *self);
extern cIDBaseEnt *cIDBase_getIDWork(cCockBossBar *self, int id);

/* Prepare the boss bar for the room: load the message pack once, initialise the display and look the five entries up by id. */
__attribute__((section(".text.cCockBossBar_roomInit")))
void cCockBossBar_roomInit(cCockBossBar *self)
{
    char name[0x40];
    unsigned short i;
    if (self->data == 0) {
        cIDManager_getLocalFileName(D_003C2388, name, D_0041DD20, -1);
        self->readId = cDvd_ReadAlloc(D_00583F20, name, &self->data, D_00754220, 0, 0, 0, 0);
        cDvd_CheckWait(D_00583F20, self->readId);
        cIDManager_setIDData(*(void **)D_003C2384, COCKBOSSBAR_MSG_PACK, self->data);
        cIDBase_initialize(self, COCKBOSSBAR_MSG_PACK, 0);
    }
    cIDBase_restartAnim(self);
    self->unkA0 = 0x20000000;
    self->unkA4 = 1.0f;
    self->unkB4 = 0;
    self->unkB8 = 0;
    for (i = 0; i < COCKBOSSBAR_ENT_NUM; i++) {
        self->ent[i] = cIDBase_getIDWork(self, i);
    }
}
