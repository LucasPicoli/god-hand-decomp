#include "godhand/cCollisionSolid.h"
#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern void Spawner_spawnChild(void *a0);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);

#include "godhand/vu0.h"
#include "godhand/cCoreSave.h"
#include "godhand/cObjBase.h"














typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;


/* Phase machine on the step byte, 7 case labels. Calls VU0_SQC2_VF0,
 * cCollisionSolidManage_SetActive, func_002A8578, cCoreSave_getGameLevel, Spawner_spawnChild,
 * cSnd_SeCall_2CBA48 and 4 more. */
__attribute__((section(".text.func_00242880"))) void func_00242880(cEm00 *self)
{
    cEffectParam fr;
    cEffectParam *e = &fr;

    e->color.x = 1.0f;
    e->color.y = 1.0f;
    e->color.z = 1.0f;
    e->color.w = 1.0f;
    VU0_SQC2_VF0(&fr, 0x10);
    VU0_SQC2_VF0(&fr, 0x20);
    {
        float *q = &e->scale.x;
        q[0] = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    e->size = 1.0f;
    fr.unk44 = 0;
    fr.flags = 0;
    e->unk4C = -1;
    fr.unk4D = 0;
    fr.unk4E = 0;
    e->unk4F = 0xFF;
    fr.unk50 = 0;
    VU0_SQC2_VF0(&fr, 0x60);
    e->size = self->scale.y;
    self->hitFlash = 3.0f;
    fr.unk70 = 0;
    fr.unk72 = 0;
    fr.unk74 = 0;
    fr.unk78 = 0;
    cCollisionSolidManage_SetActive(&D_00462FC0, (cGameObj *)self, 0);

    self->emFlags |= 0x10000;
    switch (self->step) {
        case 0: {
            int w = EM_RES(self);
            func_002A8578(self, EM_RES_REC(w, 0x245C), EM_RES_REC(w, 0x2460), 3, 0.0f, 0, 0);
            self->timer = 45.0f;
            self->timer2 = 0.053333335f;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                default:
                case 1:
                    *(float *)((char *)self + 0x172C) = 450.0f;
                    break;
                case 2:
                    *(float *)((char *)self + 0x172C) = 600.0f;
                    break;
                case 3:
                    *(float *)((char *)self + 0x172C) = 750.0f;
                    break;
                case 4:
                    *(float *)((char *)self + 0x172C) = 750.0f;
                    break;
                case 5:
                    *(float *)((char *)self + 0x172C) = 900.0f;
                    break;
            }
            Spawner_spawnChild(self);
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x107, (cObj *)self, 0, 0, 0, 0);
            SetEffect(0x69, 1, (cObj *)self, &fr, 1, EFFECT_FOLLOW_OWNER);
            self->emFlags2 |= 0x20;
            self->step++;
        }
        /* fallthrough */
        case 1: {
            float t = self->timer;
            float *p;
            if (0.0f < t) {
                self->timer = t - self->speedRate;
            } else {
                self->timer2 = self->timer2 * (1.0f - self->speedRate * 0.1f);
            }
            p = (float *)((int)self->pos + 4);
            *p = *p + self->timer2 * self->speedRate;
            if (moveMotion(self)) {
                float fv = *(float *)((int)self->pos + 4);
                self->phase = 0x7F;
                *(float *)((char *)self + 0x1738) = fv;
                self->mode = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            cObjBase_addNullSpeed_Rotation(self, 1.0f);
            cObjBase_addNullSpeed(self, 1.0f);
            break;
        }
        default:
            break;
    }
}
