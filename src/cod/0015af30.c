/* sn-2.95.3-136: func_0015AF30, build a matrix that turns the z axis onto dir, rolls it by roll
 * and places it at pos. */
#include "godhand/sceVu0.h"
typedef float Mtx44[4][4];
typedef float Vec4[4];

extern float D_003C3C40[4][4];
extern float capVu0Atan2(float y, float x);
extern void func_0030A650(void *dst, void *src, float rx);
extern void func_0030A7B8(void *dst, void *src, float ry);
extern void func_0030A700(void *dst, void *src, float rz);
extern void func_0030A2E0(void *dst, void *a, void *b);
extern void sceVu0TransposeMatrix(void *dst, void *src);
extern void sceVu0SubVector(void *v0, void *v1, void *v2);

static inline void setTrans(float (*out)[4], float *pos)
{
    Vec4 v;

    sceVu0ApplyMatrix(v, out, pos);
    sceVu0SubVector(out[3], pos, v);
}

__attribute__((section(".text.func_0015AF30")))
void func_0015AF30(Mtx44 out, float *dir, float *pos, float roll)
{
    Mtx44 m;
    Mtx44 inv;
    float a;

    if (dir[0] == 0.0f && dir[2] == 0.0f) {
        a = -capVu0Atan2(dir[1], 0.0f);
        func_0030A650(m, D_003C3C40, a);
    } else {
        a = capVu0Atan2(dir[2], dir[0]);
        func_0030A7B8(m, D_003C3C40, a);
        a = -capVu0Atan2(dir[1], __builtin_sqrtf(dir[0] * dir[0] + dir[2] * dir[2]));
        func_0030A650(m, m, a);
    }
    sceVu0TransposeMatrix(inv, m);
    func_0030A700(m, m, roll);
    func_0030A2E0(out, inv, m);
    setTrans(out, pos);
    out[3][3] = 1.0f;
}
