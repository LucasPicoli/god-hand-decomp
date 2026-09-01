#include "godhand/mmi.h"

/* sceVu0TransMatrix -- copy three quadwords (0x0/0x10/0x20) from a1 to a0 via MMI
 * lq/sq, and store a0.0x30 = a1.0x30 + a2 (vadd.xyz).  Single hardware-
 * intrinsic block; see godhand/mmi.h. */

__attribute__((section(".text.sceVu0TransMatrix")))
void sceVu0TransMatrix(void *a0, void *a1, void *a2) {
    MMI_COPY3Q_VADD(a0, a1, a2);
}
