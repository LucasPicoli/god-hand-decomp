/* cygnus-2.96 matched TU. */

extern float func_003A18F0(float);

__attribute__((section(".text.func_0033E6B8")))
void func_0033E6B8(int a0, int a1, short *a2, short *a3) {
    float s = __builtin_sqrtf(2.0f);
    float c = func_003A18F0((float)a0 * 6.2831850051879883f / (float)a1);
    float u = s - c;
    float d = __builtin_sqrtf(2.0f) - 1.0f;
    float w = __builtin_sqrtf((u + d) * (u - d));
    float r = (u - w) / d;
    *a2 = (short)(int)((r + r) * 4096.0f);
    *a3 = (short)(int)(-r * r * 4096.0f);
}
