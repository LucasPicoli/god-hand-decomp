#include "godhand/cCoreSave.h"
#include "godhand/gameWork.h"
#include "godhand/player.h"

extern char D_0061A990[];
extern void cWorldTime_setGlobalTime(void *wt, unsigned int t);
extern void func_002D9D48(void *wt, int t);

static inline void setHpClamped(cGameObj *p, int hp)
{
    if (hp >= p->hpMax)
        p->hp = p->hpMax;
    else
        p->hp = hp;
}

__attribute__((section(".text.cCoreSave_loadStageState")))
void cCoreSave_loadStageState(cCoreSave *self, int flag)
{
    cGameObj *pl;

    if (flag == 0)
        return;
    D_007474A0.nextRoom = self->data->saveStageA;
    D_007474A0.unk5B6 = self->data->saveStageB;
    cCoreSave_loadSpawn(self);
    cWorldTime_setGlobalTime(D_0061A990, self->data->worldTime);
    func_002D9D48(D_0061A990, self->data->worldTimeB);
    pl = Getplayer();
    pl->hpMax = cCoreSave_getVitalMax(self);
    if (cCoreSave_getVital(self) > 0)
        setHpClamped(Getplayer(), cCoreSave_getVital(self));
    else
        setHpClamped(Getplayer(), 1);
    cCoreSave_loadWorldActive(self);
    cCoreSave_loadSoundOutMode(self);
    cCoreSave_loadGlobalToggle(self);
}
