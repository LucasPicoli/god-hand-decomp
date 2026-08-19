/* sn-2.95.3-136 matched TU. */

extern float sqrtf(float x);
extern int D_0041EE48[];

/* sn-2.95.3-136 matched TU. */




/* m is a 4x4 float matrix: row stride 0x10, element stride 4. */
#define M(r, c) (*(float *)((char *)m + ((r) * 16 + (c) * 4)))

__attribute__((section(".text.func_0015A190")))
void func_0015A190(float *q, void *m) {
    float tr;

    tr = M(0, 0) + M(1, 1) + M(2, 2);
    if (tr > 0.0f) {
        float s;
        float w;

        s = __builtin_sqrtf(tr + 1.0f);
        q[3] = s * 0.5f;
        w = 0.5f / s;
        q[0] = (M(1, 2) - M(2, 1)) * w;
        q[1] = (M(2, 0) - M(0, 2)) * w;
        q[2] = (M(0, 1) - M(1, 0)) * w;
    } else {
        float s;
        float w;
        int i;
        int j;
        int k;

        i = 0;
        if (M(0, 0) < M(1, 1)) {
            i = 1;
        }
        if (M(i, i) < M(2, 2)) {
            i = 2;
        }
        j = D_0041EE48[i];
        k = D_0041EE48[j];
        s = __builtin_sqrtf(M(i, i) - M(j, j) - M(k, k) + 1.0f);
        {
            float *p = q + i;

            *p = s * 0.5f;
        }
        w = 0.5f / s;
        q[3] = (M(j, k) - M(k, j)) * w;
        {
            float *p = q + j;

            *p = (M(i, j) + M(j, i)) * w;
        }
        {
            float *p = q + k;

            *p = (M(i, k) + M(k, i)) * w;
        }
    }
}
