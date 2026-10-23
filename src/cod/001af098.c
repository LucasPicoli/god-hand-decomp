/* sn-2.95.3-136: func_001AF098, enemy damage-phase update: sync motion speed, run the current phase handler, and on a confirmed hit either kill (guard at zero) or stagger with two hit sounds. */
#include "godhand/cEmManage.h"
extern void SetMotionStep(void *a0, float f12);
extern int cOmBase_checkDamage(cOmBase *self, cDamageTake *hit);
extern void func_001B7EE0(void *a0, float fp12);
extern void func_001AEEA8(void *self, int a1);
extern void func_001B0078(char *self);
extern void func_001AEF40(char *self);
extern int cSnd_SeCall_2CBA48(void *snd, int a1, int id, void *owner, int t0, int t1, int t2, int t3);
extern char D_005FEE00[];

#include "godhand/cModel.h"
#include "godhand/emPhaseTable.h"

extern EmPhaseTable D_003BDC80;

/* A gimmick that takes hits: it staggers on a hit and dies once its hp is gone.
 * func_001AEF40 shakes its z rotation. */
typedef struct cOmHitStagger {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    cDamageTake *take;                  /* 0x600 */
    char unk604[0xAF0 - 0x604];
    unsigned char unkAF0;               /* 0xAF0 1 runs func_001B7EE0 every frame */
} cOmHitStagger;

__attribute__((section(".text.func_001AF098")))
void func_001AF098(cOmHitStagger *self)
{
    float rate;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    self->base.speedRate = rate;
    SetMotionStep(self, rate);
    EM_PHASE_RUN(&D_003BDC80, self, self->base.phase);

    if (cOmBase_checkDamage(&self->base, self->take) == 1) {
        if (self->base.hp <= 0) {
            self->base.mode = 1;
            self->base.flags0 |= 1;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        } else {
            func_001AEEA8(self, 8);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x55, self, 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 10, self, 0, 0, 0, 0);
        }
    }
    func_001B0078((char *)self);
    if (self->unkAF0 == 1)
        func_001B7EE0(self, 2.0f);
    func_001AEF40((char *)self);
}
