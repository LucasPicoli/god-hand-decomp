/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"
#include "godhand/cWorldLight.h"

extern cSndMemHeap D_00602F80, D_00603310, D_006036A0;
extern void cSndMemHeap_Close(cSndMemHeap *heap);
extern cSndMemHeap D_00602F80;
extern void cSndMemHeap_OpenRoot(cSndMemHeap *heap, int a1, int a2);

/* On the all-heaps id (0xFFFF), shuts all three heaps down when the first argument is set. */
__attribute__((section(".text.cSndMemHeap_CloseAll")))
void cSndMemHeap_CloseAll(int on, int id)
{
    if (id == 0xFFFF && on != 0) {
        cSndMemHeap_Close(&D_00602F80);
        cSndMemHeap_Close(&D_00603310);
        cSndMemHeap_Close(&D_006036A0);
    }
}

/* Sets up the first heap with its two size values. */
__attribute__((section(".text.cSndMemHeap_OpenMain")))
void cSndMemHeap_OpenMain(void)
{
    cSndMemHeap_OpenRoot(&D_00602F80, 0x5080, 0xFAF80);
}

/* Returns extra record idx, clamping idx to the last record. */
__attribute__((section(".text.cWorldLight_getExtra")))
cWorldLightExtra *cWorldLight_getExtra(cWorldLight *self, int idx)
{
    if (idx >= WORLDLIGHT_EXTRA_NUM) {
        idx = WORLDLIGHT_EXTRA_NUM - 1;
    }
    return &self->extra[idx];
}

/* Finds the light with this owner key and id; NULL if there is none. */
__attribute__((section(".text.cWorldLight_Get_LightData2")))
cWorldLightRec *cWorldLight_Get_LightData2(cWorldLight *self, unsigned short id, int key)
{
    int i;
    cWorldLightRec *rec = 0;

    for (i = 0; i < self->lightNum; i++) {
        rec = &self->light[i];
        if (rec->key == key && rec->id == id) {
            break;
        }
    }
    return (i != self->lightNum) ? rec : 0;
}
