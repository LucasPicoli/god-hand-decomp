/* sn-2.95.3-136 matched TU. */

extern float sqrtf(float x);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.Quaternion_SetVectorRotation")))
void Quaternion_SetVectorRotation(float *q, float *a, float *b) {
    float c[5];
    float d;
    float e;
    float t;
    float u;
    float s;
    float r;

    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
    d = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
    c[3] = 1.0f;
    c[4] = 1.0f;
    e = (d < -1.0f) ? -1.0f : d;
    t = (e < 1.0f) ? e : 1.0f;
    u = t + 1.0f;
    s = __builtin_sqrtf(u + u);
    r = 1.0f / s;
    q[0] = c[0] * r;
    q[1] = c[1] * r;
    q[2] = c[2] * r;
    q[3] = s * 0.5f;
}
