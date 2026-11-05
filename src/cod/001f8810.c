/* sn-2.95.3-136 */
#include "godhand/cArea.h"
#include "godhand/fpu.h"

/* 1 when pt, its height scaled by scale, lies inside the circle area: inside the height band, then
 * within radius of the scaled centre in XZ. The root is FPU_SQRT_S: with __builtin_sqrtf cc1 loads
 * the radius before it, where retail loads it after. */
__attribute__((section(".text.func_001F8810")))
int func_001F8810(cArea *self, float *pt, float scale)
{
    float py;
    float top;
    float dx;
    float dz;
    float d;

    py = pt[1] * scale;
    top = self->y + self->height;
    if (py < self->y)
        return 0;
    if (top < py)
        return 0;
    dx = pt[0] - self->corner[0].x * scale;
    dz = pt[2] - self->corner[0].z * scale;
    FPU_SQRT_S(d, dx * dx + dz * dz);
    if (d < self->radius)
        return 1;
    return 0;
}
