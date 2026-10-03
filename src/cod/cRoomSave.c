/* TU: cRoomSave - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cRoomSave.h"

extern cRoomSaveEm *cRoomSave_getEm(cRoomSave *self, unsigned int idx);
extern unsigned int func_002BEDD8(cRoomSave *self);

/* Mark the enemy record with this id alive again. 1 when found. */
__attribute__((section(".text.cRoomSave_clearEmDeadFlag")))
int cRoomSave_clearEmDeadFlag(cRoomSave *self, int id) {
    int i;
    cRoomSaveEm *em;
    for (i = 0; (unsigned int)i < func_002BEDD8(self); i++) {
        em = cRoomSave_getEm(self, i);
        if (em != 0 && em->id == id) {
            em->dead = 0;
            return 1;
        }
    }
    return 0;
}
