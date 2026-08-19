/* sn-2.95.3-136 matched TU. */

extern float sqrtf(float x);
extern float capVu0Atan2(float y, float x);
extern float func_003A19F8(float x);

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_0015A6A0")))
void func_0015A6A0(float *out, float *a, float *b, float t) {
    float sign = 1.0f;
    float dot;
    float w0;
    float w1;

    dot = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
    if (dot < 0.0f) {
        sign = -1.0f;
    }
    dot = dot * sign;
    if (dot < 0.99999f) {
        float s = __builtin_sqrtf(1.0f - dot * dot);
        float th = capVu0Atan2(s, dot);
        float inv = 1.0f / s;
        w1 = func_003A19F8(t * th) * inv;
        w0 = func_003A19F8((1.0f - t) * th) * inv;
    } else {
        w1 = t;
        w0 = 1.0f - w1;
    }
    w1 = w1 * sign;
    out[0] = a[0] * w0 + b[0] * w1;
    out[1] = a[1] * w0 + b[1] * w1;
    out[2] = a[2] * w0 + b[2] * w1;
    out[3] = a[3] * w0 + b[3] * w1;
}
