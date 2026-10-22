/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/pathRec.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

extern const float D_003BD880[4];
extern void sceVu0UnitMatrix(void *m);
extern void sceVu0RotMatrix(void *dst, void *src, float *ang);
extern float sceVu0InnerProduct(void *a0, void *a1);
extern float capVu0Acos(float x);

static __inline__ void RotMatrixOf(float m[4][4], float *ang)
{
    sceVu0UnitMatrix(m);
    sceVu0RotMatrix(m, m, ang);
}

/* How far dir lies inside the path's cone around the turned z axis: 1 on the axis, 0 at the cone edge or outside. */
__attribute__((section(".text.func_00137E70")))
float func_00137E70(PathHost *self, cVec *dir, cVec *rot)
{
    cVec axis;
    float mtx[4][4];
    PathRec *rec = self->rec;
    float ang;

    VU0_SQC2_VF0_MEM(&axis, 0);
    axis.x = D_003BD880[0];
    axis.y = D_003BD880[1];
    axis.z = 1.0f;
    RotMatrixOf(mtx, &rot->x);
    sceVu0ApplyMatrix(&axis, mtx, &axis);
    ang = capVu0Acos(sceVu0InnerProduct(dir, &axis));
    if (rec->coneAngle < ang) {
        return 0.0f;
    }
    return (rec->coneAngle - ang) / rec->coneAngle;
}
