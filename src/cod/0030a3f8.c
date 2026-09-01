#include "godhand/mmi.h"

/* sceVu0InversMatrix -- invert a rigid-body matrix at a1 into a0: transpose the
 * upper-left 3x3 basis (MMI shuffle) and inverse-rotate the negated
 * translation through VU0.  Single hardware-intrinsic block; see godhand/mmi.h. */

__attribute__((section(".text.sceVu0InversMatrix")))
void sceVu0InversMatrix(void *a0, void *a1) {
    MMI_INVERSE_RT_MATRIX(a0, a1);
}
