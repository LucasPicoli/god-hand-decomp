/* sn-2.95.3-136: count the shake timer down; while it runs, set the position from the model
 * position with the rest z jittered by fRand1_1 (2 degrees), and on the last tick without it. */
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

/* A model whose z is shaken for a while, then put back. */
typedef struct cOmShakeZ {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x986 - 0x5E0];
    short timer;                        /* 0x986 frames of shake left */
    float restZ;                        /* 0x988 value the z returns to */
} cOmShakeZ;

__attribute__((section(".text.func_001AEF40")))
void func_001AEF40(cOmShakeZ *self)
{
    float v[4];

    if (self->timer <= 0)
        return;
    if (--self->timer != 0) {
        cVtEnt *set = &self->base.vtable[15];
        char *obj = (char *)self + set->delta;
        cVtEnt *get = &self->base.vtable[17];
        float *a = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        float *b;

        get = &self->base.vtable[17];
        b = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        setVec4(v, a[0], b[1], self->restZ + fRand1_1() * 0.034906585f);
        ((void (*)(char *, float *))set->pfn)(obj, v);
    } else {
        cVtEnt *set = &self->base.vtable[15];
        char *obj = (char *)self + set->delta;
        cVtEnt *get = &self->base.vtable[17];
        float *a = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        float *b;

        get = &self->base.vtable[17];
        b = ((float *(*)(char *))get->pfn)((char *)self + get->delta);
        setVec4(v, a[0], b[1], self->restZ);
        ((void (*)(char *, float *))set->pfn)(obj, v);
    }
}
