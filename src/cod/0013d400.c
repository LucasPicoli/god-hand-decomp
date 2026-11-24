#include "godhand/cCockGameOver.h"

extern void cIDBase_initIDWork(void *self, int idx);
extern void cIDBase_restartAnim(void *self);
extern void func_002AC9B8(void *self, cIDBaseEnt *w, int a2);
extern void CustomIDWork_Initialize(CustomIDWork *cw, cIDBaseEnt *w);
extern void CustomIDWork_SetDisp(CustomIDWork *cw, int on);
extern void CustomIDWork_Main(CustomIDWork *cw);

__attribute__((section(".text.func_0013D400")))
void func_0013D400(cCockGameOver *obj)
{
    unsigned short i;
    int j, k;

    obj->unk92 = 0;
    for (i = 0; i < COCKGAMEOVER_ENT_NUM; i++) {
        cIDBase_initIDWork(obj, i);
        obj->ent[i] = cIDBase_getIDWork(&obj->base, i);
        func_002AC9B8(obj, obj->ent[i], 0);
    }
    cIDBase_restartAnim(obj);
    obj->on = 1;
    obj->ent[4]->f70[2] = 0.0f;
    obj->ent[4]->sclX = 0.0f;
    cIDBase_move(&obj->base);
    cIDBase_restartAnim(&obj->base2);
    for (j = 0; j < COCKGAMEOVER_CW_NUM; j++) {
        CustomIDWork_Initialize(&obj->cw[j], cIDBase_getIDWork(&obj->base2, j));
        CustomIDWork_SetDisp(&obj->cw[j], 0);
    }
    for (k = 0; k < COCKGAMEOVER_CW_NUM; k++)
        CustomIDWork_Main(&obj->cw[k]);
    cIDBase_move(&obj->base2);
    obj->unk38C = 0;
}
