/* sn-2.95.3-136 matched TU. */

extern void func_002B62F8(float *v, void *s);
extern float Adjust_theta(float a);
extern void Adjust_theta_vec(float *p);
extern void capVu0AddVectorXYZ(void *a0, void *a1, void *a2);
extern void func_002B6230(void *a0, void *a1);

/* Scale the object's rotation by its param record's damping factor, add the drift step per axis, wrap each angle, then store the rotation back. */
__attribute__((section(".text.func_00304830")))
void func_00304830(char *s)
{
    float v[4];
    float w[4];
    float *q;
    char *p;

    func_002B62F8(v, s);
    p = *(char **)(s + 0x100);
    *(float *)(s + 0x128) = *(float *)(s + 0x128) * *(float *)(p + 0x1C0);
    *(float *)(s + 0x12C) = *(float *)(s + 0x12C) * *(float *)(p + 0x1C0);
    *(float *)(s + 0x130) = *(float *)(s + 0x130) * *(float *)(p + 0x1C0);
    *(float *)(s + 0x128) = Adjust_theta(*(float *)(s + 0x128) + *(float *)(p + 0x1C4) * 0.001f);
    p = *(char **)(s + 0x100);
    *(float *)(s + 0x12C) = Adjust_theta(*(float *)(s + 0x12C) + *(float *)(p + 0x1C8) * 0.001f);
    p = *(char **)(s + 0x100);
    *(float *)(s + 0x130) = Adjust_theta(*(float *)(s + 0x130) + *(float *)(p + 0x1CC) * 0.001f);
    q = w;
    w[0] = *(float *)(s + 0x128);
    w[1] = *(float *)(s + 0x12C);
    w[2] = *(float *)(s + 0x130);
    q[3] = 1.0f;
    capVu0AddVectorXYZ(v, v, q);
    Adjust_theta_vec(v);
    func_002B6230(s, v);
}
