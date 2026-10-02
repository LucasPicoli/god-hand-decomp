/* sn-2.95.3-136 matched TU. */
#include "godhand/cWorldLight.h"

extern void func_003A52F0(void *dst, int val, int len);
extern void cHeap_free(void *list, int node);
extern char D_00754220[];

/* Clears every light and frees the lights each preset still owns. The far
 * fields are reached through one 0x10000 base, as retail does. */
__attribute__((section(".text.func_002D73E0")))
void func_002D73E0(cWorldLight *self)
{
    char *far;
    int *slot;
    int i;
    int node;

    func_003A52F0(self->light, 0, sizeof(self->light));

    for (i = 255; i >= 0; i--) {
        self->light[i].state = WORLDLIGHT_LIGHT_FREE;
    }

    self->lightNum = 0;

    slot = (int *)self->slot;
    far = (char *)self + WORLDLIGHT_FAR_BASE;
    for (i = 0; i < WORLDLIGHT_PRESET_NUM; i++) {
        node = *(int *)(far + (WORLDLIGHT_OFFSET(preset[0].lights) - WORLDLIGHT_FAR_BASE));
        if (node != 0) {
            cHeap_free(D_00754220, node);
            *(int *)(far + (WORLDLIGHT_OFFSET(preset[0].lights) - WORLDLIGHT_FAR_BASE)) = 0;
        }
        *slot = 0;
        far += sizeof(cWorldLightPreset);
        slot++;
    }

    self->tbl = 0;
    self->areaTbl = 0;
}
