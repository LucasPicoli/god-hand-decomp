#include "godhand/cObjBase.h"

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned int D_00747A84;
extern void VecRotVec(float *out, float *in, cVec *rot, int order);
extern void Adjust_theta_vec(cVec *v);
extern void SetNodeListFlag_134608(void *a0, int a1);
extern float D_007479FC;
extern float Turn_dest(int a0, float f12, float f13);
extern float Adjust_theta(float f12);

#include "godhand/vu0.h"




/* Move the model by its null-part speed, scaled by its own scale and by
 * scale, and turned by its rotation. Does nothing while the game is frozen. */
__attribute__((section(".text.cObjBase_addNullSpeed")))
void cObjBase_addNullSpeed(cObjBase *self, float scale) {
    float v[4];
    if (!(D_00747A84 & 0x20000000)) {
        VU0_SQC2_VF0(v, 0);
        v[0] = self->nullSpeed.x * self->scale.x * scale;
        v[1] = self->nullSpeed.y * self->scale.y * scale;
        v[2] = self->nullSpeed.z * self->scale.z * scale;
        VecRotVec(v, v, &self->rot, 0);
        self->pos->x += v[0];
        self->pos->y += v[1];
        self->pos->z += v[2];
    }
}

/* Turn the model by its null-part rotation speed, scaled by scale, and wrap
 * the angles. Does nothing while the game is frozen. */
__attribute__((section(".text.cObjBase_addNullSpeed_Rotation")))
void cObjBase_addNullSpeed_Rotation(cObjBase *self, float scale) {
    if (!(D_00747A84 & 0x20000000)) {
        self->rot.x += self->nullRotSpeed.x * scale;
        self->rot.y += self->nullRotSpeed.y * scale;
        self->rot.z += self->nullRotSpeed.z * scale;
        Adjust_theta_vec(&self->rot);
    }
}

__attribute__((section(".text.cCollisionSolidManage_SetActive")))
void cCollisionSolidManage_SetActive(int a0, int a1, int a2) {
    void *v0 = func_001346C8(a0, a1);
    if (v0 != 0) {
        SetNodeListFlag_134608(v0, a2);
    }
}

__attribute__((section(".text.cGameObj_SetTgtTurn")))
void cGameObj_SetTgtTurn(int a0, float f12) {
    int s0 = a0;
    float r = Turn_dest(*(int*)(s0 + 0xF0), *(float*)(s0 + 0x104), f12 * D_007479FC);
    *(float*)(s0 + 0x104) = Adjust_theta(*(float*)(s0 + 0x104) + r);
}
