/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
typedef struct cEmActor cEmActor;
typedef struct cEmManage cEmManage;
extern char D_005864F0[];
extern cEmActor *func_002948C8(cEmManage *self, unsigned int no);
extern unsigned char cOmbb_ckFire(void *actor);
extern void MtxInverse(void *dst, void *src);
extern cVec *func_001B8720(void *actor);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void cOmbb__clearFire(void *actor);

/* Clear the first burning actor inside the object's local bounds. */
__attribute__((section(".text.func_0012A3C0")))
void func_0012A3C0(cOmBase *self)
{
    struct {
        cVec position;
        float inverse[16];
        cVec copied;
        cVec transformed;
    } local __attribute__((aligned(16)));
    cEmActor *actor;
    unsigned int index = 0;
    float lowerX = -32.0f;
    float lowerZ = -3.0f;
    float lowerY = -0.5f;
    float upperY = 0.5f;
    do {
        actor = func_002948C8((cEmManage *)D_005864F0, index);
        if (actor && cOmbb_ckFire(actor)) {
            VU0_SQC2_VF0(&local, 0);
            MtxInverse(local.inverse, self->mtx);
            VU0_LQC2(4, func_001B8720(actor), 0);
            VU0_SQC2(4, &local, 0x60);
            sceVu0ApplyMatrix(&local.transformed, local.inverse, &local.transformed);
            VU0_LQC2(4, &local.transformed, 0);
            VU0_SQC2(4, &local, 0x50);
            cVec_copy3(&local.position, &local.copied);
            if (!(local.position.x < lowerX) && !(local.position.x > 3.0f) &&
                !(local.position.z < lowerZ) && !(local.position.z > 3.0f) &&
                !(local.position.y < lowerY) && !(local.position.y > upperY)) {
                cOmbb__clearFire(actor);
                return;
            }
        }
        index++;
    } while (index < 2);
}
