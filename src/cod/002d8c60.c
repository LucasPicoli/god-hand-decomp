/* sn-2.95.3-136 */
#include "godhand/cWorldLight.h"

extern cWorldLight D_00604700;

/* Moves the world light a step `t` (0..1) of the way to preset `slot`: the
 * three light vectors and the sky colour. self is not read; the fade works
 * on the one world light object. */
__attribute__((section(".text.func_002D8C60")))
void func_002D8C60(cWorldLight *self, int slot, float t)
{
    cWorldLightPreset *to;

    to = &D_00604700.preset[slot];
    D_00604700.v30[0] += (to->v30[0] - D_00604700.v30[0]) * t;
    D_00604700.v30[1] += (to->v30[1] - D_00604700.v30[1]) * t;
    D_00604700.v30[2] += (to->v30[2] - D_00604700.v30[2]) * t;
    D_00604700.ambient[0] += (to->ambient[0] - D_00604700.ambient[0]) * t;
    D_00604700.ambient[1] += (to->ambient[1] - D_00604700.ambient[1]) * t;
    D_00604700.ambient[2] += (to->ambient[2] - D_00604700.ambient[2]) * t;
    D_00604700.v50[0] += (to->v50[0] - D_00604700.v50[0]) * t;
    D_00604700.v50[1] += (to->v50[1] - D_00604700.v50[1]) * t;
    D_00604700.v50[2] += (to->v50[2] - D_00604700.v50[2]) * t;
    D_00604700.head.b[0] += (int)((to->head.b[0] - D_00604700.head.b[0]) * t);
    D_00604700.head.b[1] += (int)((to->head.b[1] - D_00604700.head.b[1]) * t);
    D_00604700.head.b[2] += (int)((to->head.b[2] - D_00604700.head.b[2]) * t);
}
