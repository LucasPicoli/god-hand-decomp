/* sn-2.95.3-136: draw the object's ID base, then redraw the second one once per active slot (0x143998). */
#include "godhand/cIDBase.h"

/* A cIDBase display with a second one at 0xB0 that is drawn once per active slot. */
typedef struct IDSlotScreen {
    char unk000[0xB0];
    cIDBaseObj base2;           /* 0xB0 */
    char unkF8[0x100 - 0xF8];
    float posYOfs[16];          /* 0x100 */
    unsigned int seed[16];      /* 0x140 */
    char unk180[0x20];
    unsigned char alpha[16];    /* 0x1A0 */
    unsigned char on[16];       /* 0x1B0 */
} IDSlotScreen;

extern void cIDBase_trans(void *self);
extern cIDBaseEnt *cIDBase_getIDWork(void *self, int idx);

__attribute__((section(".text.func_00143998")))
void func_00143998(IDSlotScreen *obj)
{
    unsigned short i;
    cIDBaseEnt *w;

    cIDBase_trans(obj);
    i = 0;
    w = cIDBase_getIDWork(&obj->base2, 0);
    for (; i < 16; i++) {
        if (obj->on[i] == 1) {
            w->posY = w->src->posY + obj->posYOfs[i];
            w->colorBase.c[3] = obj->alpha[i];
            w->seed = obj->seed[i];
            cIDBase_move(&obj->base2);
            cIDBase_trans(&obj->base2);
        }
    }
}
