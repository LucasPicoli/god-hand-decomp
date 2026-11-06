/* sn-2.95.3-136 */
#include "godhand/capVu0.h"
#include "godhand/fpu.h"

/* Arc cosine through the arc tangent: acos(x) = atan2(sqrt(1 - x * x), x). The root is
 * FPU_SQRT_S: with __builtin_sqrtf cc1 keeps x in $f12 and copies it, where retail keeps x in
 * $f13 from entry and builds 1 - x * x in $f12. */
__attribute__((section(".text.capVu0Acos")))
float capVu0Acos(float x)
{
    float s;

    FPU_SQRT_S(s, 1.0f - x * x);
    return capVu0Atan2(s, x);
}
