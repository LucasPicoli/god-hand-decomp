/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern unsigned int D_00747A78;

#include "godhand/vu0.h"




typedef struct {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct {
    char pad0[0xF0];
    Vec4 *pos;
} Obj;

__attribute__((section(".text.func_002C1CC8")))
int func_002C1CC8(void) {
    Vec4 v[2];
    Obj *obj;
    Vec4 *src;
    char *p;
    int i;

    obj = (Obj *)Obj0000_Get_D_00747A94_2DB6B0();

    p = (char *)v;
    for (i = 1; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    }

    if ((D_00747A78 & 0x2000000) != 0) {
        return 0;
    }

    src = obj->pos;
    if (&v[0] != src) {
        v[0].x = src->x;
        v[0].y = src->y;
        v[0].z = src->z;
    }
    v[0].y = v[0].y + 1.0f;
    return 1;
}
