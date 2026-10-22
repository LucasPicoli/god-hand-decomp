/* sn-2.95.3-136: Quaternion_GetEulerXYZ, convert a unit quaternion (x, y, z, w) to XYZ Euler angles; at the
 * +-pi/2 pitch singularity the roll is folded into x and z is zero. */
#include "godhand/cObjSimple.h"
#include "godhand/cOmBase.h"
extern float func_003A1B78(float s);
extern float capVu0Atan2(float y, float x);

#define HALF_PI 1.5707964f

__attribute__((section(".text.Quaternion_GetEulerXYZ")))
void Quaternion_GetEulerXYZ(cVec *q, cObjSimpleVec3 *e)
{
    float y2;
    float z2;
    float x2;
    float s;
    float ey;
    float xy2;
    float wz2;
    float zz2;
    float xx2;
    float yy2;

    y2 = q->y + q->y;
    z2 = q->z + q->z;
    x2 = q->x + q->x;
    s = -(q->x * z2 - q->w * y2);
    if (s >= 1.0f)
        s = 1.0f;
    else if (s <= -1.0f)
        s = -1.0f;
    ey = func_003A1B78(s);
    e->y = ey;
    wz2 = q->w * z2;
    zz2 = q->z * z2;
    xx2 = q->x * x2;
    xy2 = q->x * y2;
    if (ey < HALF_PI) {
        if (-HALF_PI < ey) {
            yy2 = q->y * y2;
            e->x = capVu0Atan2(q->y * z2 + q->w * x2, 1.0f - (xx2 + yy2));
            e->z = capVu0Atan2(xy2 + wz2, 1.0f - (yy2 + zz2));
        } else {
            e->x = -capVu0Atan2(xy2 - wz2, 1.0f - (xx2 + zz2));
            e->z = 0.0f;
        }
    } else {
        e->x = capVu0Atan2(xy2 - wz2, 1.0f - (xx2 + zz2));
        e->z = 0.0f;
    }
}
