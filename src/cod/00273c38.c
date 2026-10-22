/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define EYE_HEIGHT      0.5f
#define EYE_REACH       -6.0f
#define EM_NO_BLIND_LO  0x220
#define EM_NO_BLIND_HI  0x223

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* Nonzero when nothing blocks the line from the enemy's eye to a point ahead of it. */
__attribute__((section(".text.func_00273C38")))
int func_00273C38(cGameObj *self)
{
    cVec eye;
    cVec ahead;

    VU0_SQC2_VF0_MEM(&eye, 0);
    VU0_SQC2_VF0_MEM(&ahead, 0);
    if (self->emNo < EM_NO_BLIND_HI) {
        if (self->emNo >= EM_NO_BLIND_LO) {
            return 0;
        }
    }
    eye.x = 0;
    eye.y = EYE_HEIGHT;
    eye.z = 0;
    cVec_applyMatrix(&eye, self->mtx);
    ahead.x = 0;
    ahead.y = EYE_HEIGHT;
    ahead.z = EYE_REACH;
    cVec_applyMatrix(&ahead, self->mtx);
    if (ChkLine(&eye, &ahead, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
        return 0;
    }
    return 1;
}
