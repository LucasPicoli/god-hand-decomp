/* TU: cWorldLight [gfx] - recovered C++ class. */
#include "godhand/cWorldLight.h"
#include "include_asm.h"

/* cWorldLight_Set_LightData — sn-2.95.3-136.
 * EE gcc: `long long` is a 128-bit (quadword) type, so a 0x70-byte light
 * record is long long[7]. */
typedef struct { long long qw[7]; } LightData;    /* 0x70-byte light record */
extern void cWorldLight_Light_curent_set2(void *a0, int a1);
extern unsigned int D_00747A84;

INCLUDE_ASM("nonmatching", cWorldLight_Light_curent_set);

/* Appends a copy of light src to the live lights and refreshes the preset.
 * Returns 0 if src is unused (id 0) or all 256 slots are taken. */
__attribute__((section(".text.cWorldLight_Set_LightData")))
int cWorldLight_Set_LightData(cWorldLight *self, cWorldLightRec *src)
{
    int idx;

    if (src->id == 0)
        return 0;
    idx = self->lightNum;
    if (idx >= WORLDLIGHT_LIGHT_NUM)
        return 0;

    self->light[idx] = *src;

    WORLDLIGHT_RAW(self, int, lightNum) = WORLDLIGHT_RAW(self, int, lightNum) + 1;

    if ((D_00747A84 & 0x8000000) == 0)
        cWorldLight_Light_curent_set2(self, self->unk16288);
    return 1;
}
