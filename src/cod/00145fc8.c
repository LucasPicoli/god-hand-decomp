/* sn-2.95.3-136: func_00145FC8, pop-in animation of a five-part HUD effect: shrink the scale each frame,
 * fade in colour 0 on every part, then colour 1 on the second part's third entry, then stop. */
#include "godhand/cIDBase.h"

typedef struct EffPartSlot {
    cIDBaseEnt *a;            /* 0x00 */
    int pad04;
    cIDBaseEnt *b;            /* 0x08 */
    cIDBaseEnt *c;            /* 0x0C */
    int pad10;
} EffPartSlot;

typedef struct EffPartObj {
    char pad000[0x90];
    unsigned int flags;         /* 0x090 */
    EffPartSlot slot[5];       /* 0x094 */
    char pad0F8[0x338 - 0xF8];
    float scale;                /* 0x338 */
    char pad33C[0x364 - 0x33C];
    unsigned int col0;          /* 0x364 */
    unsigned int col1;          /* 0x368 */
    char pad36C[0x41E - 0x36C];
    short f41E;                 /* 0x41E */
    short step;                 /* 0x420 */
} EffPartObj;

extern float D_0041E880[];
extern float D_0041E884;

__attribute__((section(".text.func_00145FC8")))
void func_00145FC8(EffPartObj *self)
{
    unsigned short i;
    float t;
    float u;

    self->scale *= 0.7f;
    switch (self->step) {
    case 0:
        self->step++;
    case 1:
        self->col0 += 0xE0000000;
        if (self->col0 == 0x808080) {
            self->scale = 1.0f;
            self->step++;
        }
        for (i = 0; i < 5; i++) {
            self->slot[i].b->sclX = (t = D_0041E880[i]) * (1.0f - self->scale + 1.0f);
            t *= self->scale;
            self->slot[i].b->sclY = t;
            if (i != 1)
                self->slot[i].a->colorBase.word = self->col0;
        }
        self->slot[1].b->colorBase.word = self->col0;
        break;
    case 2:
        self->col1 += 0xF0000000;
        if (self->col1 == 0x808080)
            self->step++;
        self->slot[1].c->colorBase.word = self->col1;
        u = D_0041E884;
        self->slot[1].c->sclX = u * (1.0f - self->scale + 1.0f);
        u *= self->scale;
        self->slot[1].c->sclY = u;
        break;
    case 3:
        self->flags &= ~0x40000000;
        self->flags &= ~0x20000000;
        self->f41E = 0;
        self->step = 0;
        break;
    }
}
