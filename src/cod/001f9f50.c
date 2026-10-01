/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"

extern char D_00583EC0[];

extern void SetField_1C_2009B0(void *, cCoreSaveSpawnArg *);

/* Hand the saved respawn point to the player-spawn setup. */
__attribute__((section(".text.cCoreSave_loadSpawn")))
void cCoreSave_loadSpawn(cCoreSave *self)
{
    cCoreSaveData *data = self->data;
    cCoreSaveSpawnArg spawn;

    if (data != 0) {
        spawn.angle = data->spawn.angle;
        spawn.pos[0] = data->spawn.pos[0];
        spawn.pos[1] = data->spawn.pos[1];
        spawn.pos[2] = data->spawn.pos[2];
        spawn.pos[3] = data->spawn.pos[3];
        spawn.kind = data->spawn.kind;
        spawn.sub = data->spawn.sub;
        spawn.param = data->spawn.param;
        SetField_1C_2009B0(D_00583EC0, &spawn);
    }
}
