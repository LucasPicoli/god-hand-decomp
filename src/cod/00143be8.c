#include "godhand/cIDScreen3.h"

extern void *Getplayer(void);
extern void cIDBase_restartAnim(void *self);
extern cIDBaseEnt *cIDBase_getIDWork(void *self, int idx);

/* cIDScreen3 setup: restart every display, keep the first entries of each part, reset the colour. */
__attribute__((section(".text.func_00143BE8")))
void func_00143BE8(cIDScreen3 *obj)
{
    cIDScreen3Part *a = &obj->partA;
    cIDScreen3Part *b = &obj->partB;
    cIDScreen3Part *c = &obj->partC;
    unsigned short i = 0;

    obj->f90 = 0;
    obj->player = Getplayer();
    obj->pulse = IDSCREEN3_PULSE;
    cIDBase_restartAnim(obj);
    obj->base.playing = 1;
    cIDBase_restartAnim(a);
    a->base.playing = 1;
    cIDBase_move(&a->base);
    cIDBase_restartAnim(b);
    b->base.playing = 1;
    cIDBase_move(&b->base);
    cIDBase_restartAnim(c);
    c->base.playing = 1;
    for (; i < IDSCREEN3_ENT_NUM; i++)
        obj->ent[i] = cIDBase_getIDWork(obj, i);
    obj->entA = cIDBase_getIDWork(&obj->partA, 0);
    obj->entB = cIDBase_getIDWork(&obj->partB, 0);
    obj->entC = cIDBase_getIDWork(&obj->partC, 0);
    obj->flag5DD = 0;
    obj->color = IDSCREEN3_COLOR_GREY;
    obj->flag5DC = 0;
}
