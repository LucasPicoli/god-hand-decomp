#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

/* A cIDBase display with 11 entries and a second display at 0xD0 driven by five CustomIDWorks. */
typedef struct IDPanelScreen {
    cIDBaseObj base;            /* 0x000 */
    char unk48[0x90 - 0x48];
    unsigned char on;           /* 0x090 */
    char unk91;
    short unk92;                /* 0x092 */
    cIDBaseEnt *ent[11];        /* 0x094 */
    char unkC0[0x10];
    cIDBaseObj base2;           /* 0x0D0 */
    char unk118[0x120 - 0x118];
    CustomIDWork cw[5];         /* 0x120 */
    char unk38C;                /* 0x38C */
} IDPanelScreen;

extern void cIDBase_initIDWork(void *self, int idx);
extern cIDBaseEnt *cIDBase_getIDWork(void *self, int idx);
extern void cIDBase_restartAnim(void *self);
extern void func_002AC9B8(void *self, cIDBaseEnt *w, int a2);
extern void CustomIDWork_Initialize(CustomIDWork *cw, cIDBaseEnt *w);
extern void CustomIDWork_SetDisp(CustomIDWork *cw, int on);
extern void CustomIDWork_Main(CustomIDWork *cw);

__attribute__((section(".text.func_0013D400")))
void func_0013D400(IDPanelScreen *obj)
{
    unsigned short i;
    int j, k;

    obj->unk92 = 0;
    for (i = 0; i < 11; i++) {
        cIDBase_initIDWork(obj, i);
        obj->ent[i] = cIDBase_getIDWork(obj, i);
        func_002AC9B8(obj, obj->ent[i], 0);
    }
    cIDBase_restartAnim(obj);
    obj->on = 1;
    obj->ent[4]->f70[2] = 0.0f;
    obj->ent[4]->sclX = 0.0f;
    cIDBase_move(&obj->base);
    cIDBase_restartAnim(&obj->base2);
    for (j = 0; j < 5; j++) {
        CustomIDWork_Initialize(&obj->cw[j], cIDBase_getIDWork(&obj->base2, j));
        CustomIDWork_SetDisp(&obj->cw[j], 0);
    }
    for (k = 0; k < 5; k++)
        CustomIDWork_Main(&obj->cw[k]);
    cIDBase_move(&obj->base2);
    obj->unk38C = 0;
}
