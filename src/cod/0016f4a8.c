/* sn-2.95.3-136: func_0016F4A8, enemy setup with a 1.6 x 1.0 x 1.2 damage-take volume, the enemy work defaults,
 * and effect data 600 registered from the object's texture resource. */
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"

extern void espSys_effDataRegist(void *sys, int id, void *data);
extern char D_007419A0[];

__attribute__((section(".text.func_0016F4A8")))
int func_0016F4A8(cOmHitVolume *self)
{
    cVec v[4];
    cVec *m;
    cVec *nv;
    cVec *t;
    void *slot;

    func_001B6FB8(self);
    t = &v[1];
    m = &v[2];
    v[0].x = 1.6f;
    v[1].x = 1.6f;
    v[0].y = 1.0f;
    v[0].z = 1.2f;
    v[1].z = 1.2f;
    v[0].w = 1.0f;
    v[1].y = 1.0f;
    t->w = 1.0f;
    v[2].x = 0.0f;
    v[2].y = 0.0f;
    v[2].z = 0.0f;
    m->w = 1.0f;
    slot = cDamageManage_CreateDamageTake(D_00574380, self, 2);
    self->damageTake = slot;
    if (slot != 0) {
        nv = &v[3];
        v[3].x = 0.0f;
        v[3].y = 0.0f;
        v[3].z = 0.0f;
        nv->w = 1.0f;
        func_001FD9D8(slot, self->base.mtx, m, nv, t);
    }
    cOmHitVolume_initWork(self, 1, self->tableData, 6, 1, 600);
    func_001C28A0(self);
    {
        int h = self->base.texKey;
        espSys_effDataRegist(D_007419A0, 600, (void *)(*(int *)(h + 0xC) + h));
    }
    return 1;
}
