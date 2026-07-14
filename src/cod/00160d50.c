/* sn-2.95.3-136 matched TU. */

extern void *Gp_draw_poly4(void *v, int b, int c, void *d, int e, int f);
extern void cScrSpriteDraw_drawInit(void *p);
extern char *D_003C2FB0;

#include "godhand/vu0.h"

typedef struct Vtx {
    float x;
    float y;
    float z;
    float w;
} Vtx;





__attribute__((section(".text.func_00160D50")))
void func_00160D50(void *arg) {
    char ctx[0x50];
    Vtx vt[4];
    char *self = (char *)arg;
    char *q;
    Vtx *p0;
    Vtx *p1;
    Vtx *p2;
    Vtx *p3;
    char *r;
    int i;

    *(int *)ctx = 1;

    q = (char *)vt;
    i = 3;
    for (; i != -1; i--) {
        VU0_SQC2_VF0(q, 0x0);
        q += 0x10;
    }

    p0 = &vt[0];
    p1 = &vt[1];
    p2 = &vt[2];
    p3 = &vt[3];

    vt[0].x = -1.0f;
    p0->y = -1.0f;
    vt[0].z = 0.0f;
    p0->w = 1.0f;
    vt[1].x = 513.0f;
    p1->y = -1.0f;
    vt[1].z = 0.0f;
    p1->w = 1.0f;
    vt[2].x = -1.0f;
    p2->y = 449.0f;
    vt[2].z = 0.0f;
    p2->w = 1.0f;
    vt[3].x = 513.0f;
    p3->y = 449.0f;
    vt[3].z = 0.0f;
    p3->w = 1.0f;

    r = (char *)Gp_draw_poly4(vt, *(int *)(self + 0xED0), 1, ctx, 6, 5);
    if (r != 0) {
        *(long *)(r + 0x40) = 0x3001D;
    }

    cScrSpriteDraw_drawInit(D_003C2FB0);
    *(int *)(D_003C2FB0 + 0x28) = 7;
    *(int *)(D_003C2FB0 + 0x2C) = 1;
}
