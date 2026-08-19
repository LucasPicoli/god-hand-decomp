/* sn-2.95.3-136 matched TU. */

/* func_002C0CB0 — return 0 when the distance from the point at a1 to the
 * reference at a0 is greater than the radius a0[2], else return 1. */

__attribute__((section(".text.func_002C0CB0")))
int func_002C0CB0(float *a0, float *a1) {
    float dx = a1[0] - a0[0];
    float dy = a1[1] - a0[8];
    float dz = a1[2] - a0[1];
    if (a0[2] < __builtin_sqrtf(dx * dx + dy * dy + dz * dz))
        return 0;
    return 1;
}
