/* sn-2.95.3-136 matched TU. */

extern void Adjust_theta_vec(float *p);
extern void capVu0AddVectorXYZ(void *a0, void *a1, void *a2);
extern void func_002B6230(void *a0, void *a1);

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.func_00302E48")))
void func_00302E48(char *s)
{
    float v[4];
    float w[4];
    float t;
    char *p;
    float *q;
    int n;

    func_002B62F8(v, s);
    p = *(char **)(s + 0x100);
    n = *(int *)(p + 0x1A0);
    if (n != 0) {
        t = (*(float *)(s + 0x180) - (float)*(short *)(s + 0x186)) / (float)n;
    } else {
        t = 0.0f;
    }
    p = *(char **)(s + 0x100);
    if (*(float *)(p + 0x1C0) <= t) {
        *(float *)(s + 0x128) = *(float *)(s + 0x128) * *(float *)(p + 0x1C4);
        *(float *)(s + 0x12C) = *(float *)(s + 0x12C) * *(float *)(p + 0x1C8);
        *(float *)(s + 0x130) = *(float *)(s + 0x130) * *(float *)(p + 0x1CC);
        Adjust_theta_vec(v);
    }
    p = *(char **)(s + 0x100);
    if (*(float *)(p + 0x1B0) <= t) {
        q = w;
        w[0] = *(float *)(s + 0x128);
        w[1] = *(float *)(s + 0x12C);
        w[2] = *(float *)(s + 0x130);
        q[3] = 1.0f;
        capVu0AddVectorXYZ(v, v, q);
        Adjust_theta_vec(v);
    }
    func_002B6230(s, v);
}
