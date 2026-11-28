/* sn-2.95.3-136 matched TU. */
extern "C" {

#include "godhand/cVec.h"
#include "godhand/sceVu0.h"
#include "godhand/mtx.h"

/* *r = a x b, with w = 1. A file-local inline: no header has a cross product helper. */
static __inline__ void cVec_cross(cVec *r, cVec *a, cVec *b)
{
    r->x = a->y * b->z - a->z * b->y;
    r->y = a->z * b->x - a->x * b->z;
    r->z = a->x * b->y - a->y * b->x;
    r->w = 1.0f;
}

/* Quaternion::SetCoordinateRotationZ(const cVec &z, const cVec &up): q = the rotation of
 * the frame whose z axis is z, x = unit(up x z) and y = unit(z x x). */
__attribute__((section(".text.Quaternion_SetCoordinateRotationZ")))
void Quaternion_SetCoordinateRotationZ(cVec *q, cVec *dirZ, cVec *up)
{
    cVec z;

    CVEC_COPY(z, dirZ);
    cVec x;
    {   /* C++ scope: the next block reuses t and u's slots (as C: frame 0xF0 not 0xD0, 92 off) */
        cVec t;
        cVec u;

        cVec_cross(&t, up, &z);
        cVec_unitOf(&u, &t);
        CVEC_COPY(x, &u);
    }
    cVec y;
    {   /* the slots of the block above */
        cVec t;
        cVec u;

        cVec_cross(&t, &z, &x);
        cVec_unitOf(&u, &t);
        CVEC_COPY(y, &u);
    }
    float m[4][4];

    sceVu0UnitMatrix(m);
    m[0][0] = x.x;
    m[0][1] = x.y;
    m[0][2] = x.z;
    m[1][0] = y.x;
    m[1][1] = y.y;
    m[1][2] = y.z;
    m[2][0] = z.x;
    m[2][1] = z.y;
    m[2][2] = z.z;
    func_0015A190(&q->x, m);
}

/* q = the rotation of the frame whose z axis is z, y = unit(z x xdir) and x = unit(y x z). */
__attribute__((section(".text.func_0015ABA0")))
void func_0015ABA0(cVec *q, cVec *xdir, cVec *dirZ)
{
    cVec z;

    CVEC_COPY(z, dirZ);
    cVec y;
    {   /* C++ scope: the next block reuses t and u's slots (as C: frame 0xF0 not 0xD0, 94 off) */
        cVec t;
        cVec u;

        cVec_cross(&t, &z, xdir);
        cVec_unitOf(&u, &t);
        CVEC_COPY(y, &u);
    }
    cVec x;
    {   /* the slots of the block above */
        cVec t;
        cVec u;

        cVec_cross(&t, &y, &z);
        cVec_unitOf(&u, &t);
        CVEC_COPY(x, &u);
    }
    float m[4][4];

    sceVu0UnitMatrix(m);
    m[0][0] = x.x;
    m[0][1] = x.y;
    m[0][2] = x.z;
    m[1][0] = y.x;
    m[1][1] = y.y;
    m[1][2] = y.z;
    m[2][0] = z.x;
    m[2][1] = z.y;
    m[2][2] = z.z;
    func_0015A190(&q->x, m);
}

}
