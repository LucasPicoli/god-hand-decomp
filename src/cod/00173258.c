/* sn-2.95.3-136: count the shake timer down; while it runs, set the position from the
 * model position with the rest height jittered by fRand1_1, and on the last tick without it. */
#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
extern float fRand1_1(void);

static inline void setVec4(float *v, float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 1.0f;
}

/* A model whose y is shaken for a while, then put back. */
typedef struct cOmShakeY {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0xDA0 - 0x5E0];
    short timer;                        /* 0xDA0 frames of shake left */
    char unkDA2[0xDA4 - 0xDA2];
    float restY;                        /* 0xDA4 value the y returns to */
} cOmShakeY;

__attribute__((section(".text.func_00173258")))
void func_00173258(cOmShakeY *self)
{
    float v[4];

    if (self->timer <= 0)
        return;
    if (--self->timer != 0) {
        cVtEnt *set = &self->base.vtable[14];
        char *obj = (char *)self + set->delta;
        cVtEnt *get = &self->base.vtable[16];
        float *a = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        float y = self->restY + fRand1_1() * 0.02617994f;
        float *b;

        get = &self->base.vtable[16];
        b = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        setVec4(v, a[0], y, b[2]);
        ((void (*)(char *, float *))set->pfn)(obj, v);
    } else {
        cVtEnt *set = &self->base.vtable[14];
        char *obj = (char *)self + set->delta;
        cVtEnt *get = &self->base.vtable[16];
        float *a = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        float *b;

        get = &self->base.vtable[16];
        b = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        setVec4(v, a[0], self->restY, b[2]);
        ((void (*)(char *, float *))set->pfn)(obj, v);
    }
}
