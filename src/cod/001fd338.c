/* sn-2.95.3-136 matched TU. */

#include "godhand/cDamageGive.h"
#include "godhand/vu0.h"

extern void MtxInitRotVec(void *mtx, cVec *dir, int roll);
extern void sceVu0ApplyMatrix(cVec *out, void *mtx, cVec *in);

/* Rotate the unit Z axis by the facing `dir` and store the result as the hit vector. */
__attribute__((section(".text.cDamageGive_SetDmgGiveHitVecDir")))
void cDamageGive_SetDmgGiveHitVecDir(cDamageGive *self, cVec *dir) {
    struct {
        float mtx[16];                  /* 0x00 */
        cVec axis;                      /* 0x40 */
    } f;
    VU0_SQC2_VF0(&f, 0x40);
    f.axis.x = 0.0f;
    f.axis.y = 0.0f;
    f.axis.z = 1.0f;
    MtxInitRotVec(f.mtx, dir, 0);
    sceVu0ApplyMatrix(&f.axis, f.mtx, &f.axis);
    cVec_copy3(&self->hitVec, &f.axis);
}
