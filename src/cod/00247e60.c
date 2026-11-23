/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/globals.h"
#include "godhand/cObjBase.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int moveMotion(void *a0);
extern void ReleaseObj(void *a0);
extern void func_00275DA8(void *a0);

extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);


/* Phase machine on the step byte, 2 case labels. Calls Obj0000_Get_Byte_17C3_NZ_2_276468,
 * func_002A8578, ReleaseObj, func_00275DA8, VU0_SQC2_VF0, SetEffect and 4 more. */
__attribute__((section(".text.func_00247E60"))) void func_00247E60(cEm00 *self)
{
    cEffectParam s;
    char *v;
    int t0, b, p1, p2;
    float one;

    self->objFlags = self->objFlags | 0x40000;
    switch (self->step) {
        case 0:
            self->unk1864 = 0;
            t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
            b = EM_RES(self);
            p1 = EM_RES_REC(b, 0x38C0);
            p2 = EM_RES_REC(b, 0x38C4);
            self->emFlags2 = self->emFlags2 | 0x20000000;
            *(char *)((char *)self + 0x186C) = 2;
            func_002A8578(self, p1, p2, 10, 0.0f, t0, 0);
            self->unk1768 = 600.0f;
            if ((void *)self->unk744 != 0) {
                ReleaseObj((void *)self->unk744);
                self->unk744 = 0;
                func_00275DA8(self);
            }
            s.color.x = 1.0f;
            s.color.y = 1.0f;
            s.color.z = 1.0f;
            s.color.w = 1.0f;
            VU0_SQC2_VF0(&s, 0x10);
            VU0_SQC2_VF0(&s, 0x20);
            {
                float *q = &s.scale.x;
                s.scale.x = 1.0f;
                q[1] = 1.0f;
                q[2] = 1.0f;
                q[3] = 1.0f;
            }
            s.size = 1.0f;
            s.unk4C = -1;
            s.unk4F = 0xFF;
            s.unk44 = 0;
            s.flags = 0;
            s.unk4D = 0;
            s.unk4E = 0;
            s.unk50 = 0;
            VU0_SQC2_VF0(&s, 0x60);
            s.unk70 = 0;
            s.size = self->scale.y;
            s.unk72 = 0;
            s.unk74 = 0;
            s.unk78 = 0;
            SetEffect(0xBD, 0x19, (cObj *)self, &s, 1, EFFECT_FOLLOW_OWNER);
            v = cModel_getMeshPtr_14B730(self, &D_0042CAD0);
            if (v != 0) {
                *(int *)(v + 0x380) = *(int *)(v + 0x380) & 0xFFFFFFFE;
            }
            self->step++;
        case 1:
            self->emFlags = self->emFlags | 0x800000;
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0x9C;
                self->step = 0;
                self->stepArg = 0;
            }
            one = 1.0f;
            cObjBase_addNullSpeed_Rotation(self, one);
            cObjBase_addNullSpeed(self, one);
            break;
    }
}
