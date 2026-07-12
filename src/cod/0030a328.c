#include "godhand/vu0.h"

/* sceVu0OuterProduct — VU0 cross product: *a0 = (*a1) x (*a2) (with w cleared),
 * via the outer-product multiply/subtract ops. */

__attribute__((section(".text.sceVu0OuterProduct")))
void sceVu0OuterProduct(void *a0, void *a1, void *a2) {
    VU0_LQC2(4, a1, 0);
    VU0_LQC2(5, a2, 0);
    VU0_VOPMULA_XYZ(4, 5);
    VU0_VOPMSUB_XYZ(6, 5, 4);
    VU0_VSUB_W(6, 6, 6);
    VU0_SQC2(6, a0, 0);
}
