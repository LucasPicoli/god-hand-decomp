#include "godhand/vu0.h"

/* capVu0AddVectorXYZ — VU0 vector add: *a0.xyz = *a1.xyz + *a2.xyz.
 * Compiled with sn-2.95.3-136 (the VU0/sq family compiler). */

__attribute__((section(".text.capVu0AddVectorXYZ")))
void capVu0AddVectorXYZ(void *a0, void *a1, void *a2) {
    VU0_VADD_XYZ_PTR(a0, a1, a2);
}
