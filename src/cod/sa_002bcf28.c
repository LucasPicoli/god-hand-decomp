/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"
extern void ForwardVec3At30_147C60(void *a0, float *a1);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern int func_002BC0F8(cVec *, cVec *, float, float, cVec *, cVec *, float, float);
/* Transform the two endpoints before checking their swept volumes. */
__attribute__((section(".text.func_002BCF28")))
int func_002BCF28(float *matrix1, float radius1, float height1, float *matrix2, float radius2, float height2)
{
    struct { cVec start1, end1, start2, end2, result, work; } v __attribute__((aligned(16)));
    cVec *work;
    VU0_SQC2_VF0(&v, 0);
    VU0_SQC2_VF0(&v, 16);
    VU0_SQC2_VF0(&v, 32);
    VU0_SQC2_VF0(&v, 48);
    ForwardVec3At30_147C60(&v.start1, matrix1);
    work = &v.work;
    v.end1.y = height1;
    VU0_LQC2(4, &v.end1, 0);
    VU0_SQC2(4, &v, 80);
    sceVu0ApplyMatrix(work, matrix1, work);
    VU0_LQC2(4, work, 0);
    VU0_SQC2(4, &v, 64);
    cVec_copy3(&v.end1, &v.result);
    ForwardVec3At30_147C60(&v.start2, matrix2);
    v.end2.y = height2;
    VU0_LQC2(4, &v.end2, 0);
    VU0_SQC2(4, &v, 80);
    sceVu0ApplyMatrix(work, matrix2, work);
    VU0_LQC2(4, work, 0);
    VU0_SQC2(4, &v, 64);
    cVec_copy3(&v.end2, &v.result);
    return func_002BC0F8(&v.start1, &v.end1, radius1, height1, &v.start2, &v.end2, radius2, height2);
}
