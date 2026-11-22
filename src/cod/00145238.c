/* sn-2.95.3-136 matched TU. */
#include "godhand/cIDBaseScreen.h"
#include "godhand/globals.h"

extern void func_00145410(void *a0);
extern void func_00145460(void *a0);
extern void func_00145810(void *a0);
extern void func_00145FC8(void *a0);
extern void func_00146190(void *a0);

/* sn-2.95.3-136 matched TU. */











__attribute__((section(".text.func_00145238")))
void func_00145238(cIDBaseScreen *self)
{
    cIDBaseObj *w;
    cIDBaseEnt *p;
    cIDBaseObj *x;
    unsigned short i;
    float a;
    float b;
    int n;

    switch (self->phase) {
    case 0:
        func_00145410(self);
        break;
    case 1:
        func_00145460(self);
        break;
    case 2:
        func_00145810(self);
        break;
    case 3:
        func_00145FC8(self);
        break;
    case 4:
        func_00146190(self);
        break;
    }
    for (i = 0; i < SCR_ROW_NUM; i++) {
        cIDBase_move(&self->row[i].id);
    }
    if (self->phase != 2) return;
    n = self->timer - 1;
    self->timer = n;
    if ((short)n < 0) {
        self->timer = 0;
    }
    w = &self->extraA.id;
    x = &self->extraB.id;
    p = cIDBase_getIDWork(w, 0);
    a = D_0041E898[0];
    p->posX = a;
    p = cIDBase_getIDWork(w, 0);
    b = D_0041E898[1];
    p->posY = b;
    cIDBase_getIDWork(w, 1)->rotSpeed = (float)(short)self->timer * 6.28f / (float)D_003BD70C;
    cIDBase_getIDWork(w, 2)->msg = 0x30F2;
    cIDBase_getIDWork(x, 0)->posX = a;
    cIDBase_getIDWork(x, 0)->posY = b;
    cIDBase_move(w);
    cIDBase_move(x);
}
