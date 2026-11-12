/* sn-2.95.3-136 matched TU. */

#include "godhand/cVecType.h"

/* Hamilton product o = a * b of two quaternions (x, y, z vector part, w scalar part). */
static __inline__ void Quat_mul(cVec *o, cVec *a, cVec *b)
{
    o->x = a->y * b->z - a->z * b->y + a->x * b->w + a->w * b->x;
    o->y = a->z * b->x - a->x * b->z + a->y * b->w + a->w * b->y;
    o->z = a->x * b->y - a->y * b->x + a->z * b->w + a->w * b->z;
    o->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
}

/* Rotate the point v by the unit quaternion q: dst = q * (v, 0) * conj(q), dst->w = 1. Returns dst. */
__attribute__((section(".text.func_0015ADA0")))
cVec *func_0015ADA0(cVec *dst, cVec *q, cVec *v)
{
    cVec rot, half, pure, conj, rq;

    pure.x = v->x;
    pure.y = v->y;
    pure.z = v->z;
    pure.w = 0.0f;
    {
        /* the reads are bound in this order and the copies stored in field order, as retail schedules them */
        float y = q->y, z = q->z, x = q->x, w = q->w;

        rq.x = x;
        rq.y = y;
        rq.z = z;
        rq.w = w;
    }
    Quat_mul(&half, &rq, &pure);
    conj.x = -rq.x;
    conj.y = -rq.y;
    conj.z = -rq.z;
    conj.w = rq.w;
    Quat_mul(&rot, &half, &conj);
    dst->x = rot.x;
    dst->y = rot.y;
    dst->z = rot.z;
    dst->w = 1.0f;
    return dst;
}
