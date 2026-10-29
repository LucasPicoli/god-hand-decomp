/* sn-2.95.3-136 */
#include "include_asm.h"

#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define HOLD_FACE_TARGET  0
#define HOLD_FACE_HOLDER  1

extern float Turn_dest(void *from, void *to, float cur, float max);
extern void MtxInitRotY(void *mtx, float angle);

/* dst = m * v, through a work copy. */
static __inline__ void cVec_transform(cVec *dst, cVec *v, float *m)
{
    cVec work;

    VU0_LQC2(4, v, 0);
    VU0_SQC2_MEM(4, &work, 0);
    sceVu0ApplyMatrix(&work, m, &work);
    VU0_LQC2(4, &work, 0);
    VU0_SQC2_MEM(4, dst, 0);
}

/* Puts the holder at an offset in front of the held object and faces them toward each
 * other, then stops both. With HOLD_FACE_HOLDER only the held object turns. */
__attribute__((section(".text.func_001299F0")))
void func_001299F0(cGameObj *self, cGameObj *held, cVec *offset, int how, float turn)
{
    float mtx[16] __attribute__((aligned(16)));
    cVec at;
    cVec out;

    if (held == 0) {
        return;
    }
    switch (how) {
    default:
    case HOLD_FACE_TARGET:
        self->rot.y += Turn_dest(self->pos, held->pos, self->rot.y, 3.1415927f);
        self->rot.y = Adjust_theta(self->rot.y);
        held->rot.y = self->rot.y + 3.1415927f;
        held->rot.y = Adjust_theta(held->rot.y);
        self->rot.y += turn;
        self->rot.y = Adjust_theta(self->rot.y);
        break;
    case HOLD_FACE_HOLDER:
        held->rot.y = self->rot.y + 3.1415927f;
        held->rot.y = Adjust_theta(held->rot.y);
        break;
    }
    VU0_SQC2_VF0_MEM(&at, 0);
    MtxInitRotY(mtx, held->rot.y);
    at.x = offset->x * held->scale.x;
    at.y = 0.0f;
    at.z = offset->z * held->scale.z;
    cVec_transform(&out, &at, mtx);
    cVec_copy3(&at, &out);
    VU0_VADD_XYZ_IP(&at, 0, held->pos);
    self->pos->x = at.x;
    self->pos->z = at.z;
    held->vel.x = 0.0f;
    held->vel.y = 0.0f;
    held->vel.z = 0.0f;
    self->vel.x = 0.0f;
    self->vel.y = 0.0f;
    self->vel.z = 0.0f;
}
