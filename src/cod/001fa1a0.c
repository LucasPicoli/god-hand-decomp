/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int D_00569B70;
extern unsigned int D_00568240;
extern int Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(void *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void cCoreSave_setGameLevel(void *a0, int level);

__attribute__((section(".text.func_001FA1A0")))
/* Drop the level points to the start of the level below the current one.
 * Skipped on difficulty 2, and when the 0x4000000 record flag is set
 * without the 0x2 cheat bit. */
void func_001FA1A0(cCoreSave *self)
{
    int byte;
    cCoreSaveData *global;
    long v;
    int level;

    if (self->data == 0) {
        return;
    }
    byte = Obj0000_Get_Byte_1F_If_Ptr_NonNull_1FA678(self);
    if (byte == 2) {
        return;
    }
    global = ((cCoreSave *)&D_00569B70)->data;
    if ((global->flags & 0x4000000) != 0) {
        v = *(unsigned int *)&D_00568240;
        if (((v >> 1) & 1) == 0) {
            return;
        }
    }
    level = cCoreSave_getGameLevel(self);
    switch (level - 1) {
    default:
    case 0:
        self->data->levelPoint = 0;
        return;
    case 1:
        cCoreSave_setGameLevel(self, 1);
        return;
    case 2:
    case 3:
        cCoreSave_setGameLevel(self, 2);
        return;
    case 4:
        cCoreSave_setGameLevel(self, 3);
        return;
    }
}
