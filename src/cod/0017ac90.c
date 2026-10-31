/* sn-2.95.3-136: func_0017AC90, setup with a radius 1 damage-take sphere 2.28 above the first child, a 120-frame
 * timer pair, and the first child's rot.x kept at 0x608. */
#include "godhand/cOmBase.h"
#include "godhand/cOmHitVolumeSetup.h"

#define OBJ_FLAG_SPHERE_TAKE  0x10000   /* objFlags bit this setup sets */

/* The object this sets up: two cleared state bytes, the child's rot.x and the damage-take unit. */
typedef struct cOmSphereTake {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    unsigned char unk600;               /* 0x600 cleared at setup */
    char unk601;
    unsigned char unk602;               /* 0x602 cleared at setup */
    char unk603[5];
    float childPrevX;                   /* 0x608 the first child's rot.x */
    void *take;                         /* 0x60C damage-take unit, 0 when none */
} cOmSphereTake;

extern void func_0017B5E0(unsigned char *p);
extern char D_00574380[];

static inline cOmBase *GetChild(cOmSphereTake *self)
{
    int frame[3];

    return cOmBase_childAt(&self->base, frame, 0);
}

__attribute__((section(".text.func_0017AC90")))
int func_0017AC90(cOmSphereTake *self)
{
    int bits;

    func_001B6FB8((cOmHitVolume *)self);
    {
        float ofs[4];
        void *slot;

        ofs[2] = 2.28f;
        ofs[3] = 1.0f;
        ofs[0] = 0.0f;
        ofs[1] = 0.0f;
        slot = cDamageManage_CreateDamageTake(D_00574380, self, 2);
        self->take = slot;
        if (slot != 0 && GetChild(self) != 0) {
            cDamageUnit_AddDamageCollSphere(self->take, GetChild(self)->mtx, ofs, 1.0f);
            *(int *)self->take |= 1;
        }
    }
    bits = self->base.objFlags | OBJ_FLAG_SPHERE_TAKE;
    self->unk602 = 0;
    self->base.flags2 |= 8;
    self->unk600 = 0;
    self->base.hpMax = 0x78;
    self->base.hp = 0x78;
    self->base.objFlags = bits;
    func_0017B5E0((unsigned char *)self);
    if (GetChild(self) != 0)
        self->childPrevX = GetChild(self)->rot.x;
    return 1;
}
