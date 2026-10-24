/* sn-2.95.3-136: func_0013EE58, scroll two UV channels by 0.03 a frame (wrapping) into ID works 0 and 1,
 * ramp the fade and slide values from channel 0 into ID work 2, and show ID work 3 with the message in msg. */
#include "godhand/cIDBase.h"

/* One UV channel: x, y scroll; z, w are copied through. */
typedef struct UvCh {
    float x, y, z, w;
} UvCh;

typedef struct UvScrollObj {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x90 - 0x48];
    UvCh ch[2];                         /* 0x90 */
    float slide;                        /* 0xB0 0..256 over the second half of channel 0's cycle */
    float baseX;                        /* 0xB4 ID work 2's x before the slide */
    float fade;                         /* 0xB8 0..256 over the first half of the cycle */
    short unkBC;
    unsigned short msg;                 /* 0xBE message ID work 3 shows, 0xFFFF hides it */
} UvScrollObj;

extern void *cIDBase_getIDWork(void *self, int idx);
extern void cIDBase_move(cIDBaseObj *self);

__attribute__((section(".text.func_0013EE58")))
void func_0013EE58(UvScrollObj *self)
{
    cIDBaseEnt *w[3];                   /* works 0, 1 and 3: a separate pointer for work 3 moves the frame */
    cIDBaseEnt *w2;
    unsigned short i;
    float f;

    w[0] = cIDBase_getIDWork(self, 0);
    w[1] = cIDBase_getIDWork(self, 1);
    w2 = cIDBase_getIDWork(self, 2);
    w[2] = cIDBase_getIDWork(self, 3);
    for (i = 0; i < 2; i++) {
        self->ch[i].y += 0.03f;
        self->ch[i].x += 0.03f;
        if (self->ch[i].y >= 2.0f) {
            self->ch[i].y = 0.0f;
            self->fade = 0.0f;
            self->slide = 0.0f;
        }
        if (self->ch[i].x >= 3.0f)
            self->ch[i].x = 1.0f;
        w[i]->f70[0] = self->ch[i].x;
        w[i]->f70[2] = self->ch[i].y;
        w[i]->f70[1] = self->ch[i].z;
        w[i]->f70[3] = self->ch[i].w;
    }
    f = self->ch[0].y;
    if (f < 1.0f)
        self->fade = f * 256.0f;
    else if (1.0f < f)
        self->slide = (f - 1.0f) * 256.0f;
    w2->posX = self->baseX + self->slide;
    w2->f68 = self->fade;
    if ((short)self->msg != -1) {
        w[2]->flags &= ~IDENT_FLAG_NO_DRAW;
        w[2]->msg = self->msg;
    } else {
        w[2]->flags |= IDENT_FLAG_NO_DRAW;
        w[2]->msg = 0xFFFF;
    }
    cIDBase_move(&self->base);
}
