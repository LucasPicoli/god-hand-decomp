/* sn-2.95.3-136: draw the object's ID base, then redraw the second one once per active slot (0x143998). */
#include "godhand/cCockPrintData.h"

extern void cIDBase_trans(void *self);

__attribute__((section(".text.func_00143998")))
void func_00143998(cCockPrintData *obj)
{
    unsigned short i;
    cIDBaseEnt *w;

    cIDBase_trans(obj);
    i = 0;
    w = cIDBase_getIDWork(&obj->base2, 0);
    for (; i < COCKPRINT_SLOT_NUM; i++) {
        if (obj->on[i] == 1) {
            w->posY = w->src->posY + obj->posYOfs[i];
            w->colorBase.c[3] = obj->alpha[i];
            w->number = obj->number[i];
            cIDBase_move(&obj->base2);
            cIDBase_trans(&obj->base2);
        }
    }
}
