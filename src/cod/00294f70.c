/* sn-2.95.3-136: func_00294F70, load the SE bank for this object: fixed for types 0x209 / 0x220 / 0x223, otherwise
 * picked from the current stage id (stages past area 4 use 0x223 one time in four at game level 3 and up). Nothing is
 * loaded on stage 0x506. */
#include "godhand/cCoreSave.h"
#include "godhand/heapArena.h"
#include "godhand/cDataManager.h"
#include "godhand/gameWork.h"
extern int cDataManager_loadWait(cDataManager *mgr, int id, void *buf, int wait);
extern void cDataManager_loadSeWait(cDataManager *mgr, int id, int se, int wait);
extern int Rnd(void);

/* Retail keeps the D_007474A0 base in a register; naming D_007474A0.room directly rebuilds it with lui on each read. */
static inline GameWork *game(void)
{
    return &D_007474A0;
}

static inline void load_se(int id)
{
    cDataManager_loadWait(&D_005864E0, id, &D_00754220, 1);
    cDataManager_loadSeWait(&D_005864E0, id, id, 0);
}

__attribute__((section(".text.func_00294F70")))
void func_00294F70(char *p)
{
    if (game()->room == 0x506)
        return;
    switch (*(int *)(p + 4)) {
    case 0x209:
        load_se(0x209);
        return;
    case 0x220:
        load_se(0x220);
        return;
    case 0x223:
        load_se(0x223);
        return;
    }
    switch (game()->room) {
    case 0x801:
        load_se(0x220);
        break;
    case 0x600:
    case 0x604:
    case 0x702:
        load_se(0x209);
        break;
    case 0x409:
    case 0x802:
        load_se(0x223);
        break;
    default:
        if (((unsigned char *)&game()->room)[1] >= 5 && (Rnd() & 3) == 0 && cCoreSave_getGameLevel(&D_00569B70) >= 3)
            load_se(0x223);
        else
            load_se(0x220);
        break;
    }
}
