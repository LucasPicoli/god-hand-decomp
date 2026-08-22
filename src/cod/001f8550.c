/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU.
 * compile_units: {"path": "src/cod/001f8550.c", "compiler": "sn-2.95.3-136",
 *                 "c_flags_add": ["-f=-ffast-math"], "fp_hazard_rules": "sqrt"} */

/* func_001F8550 — XZ-cylinder containment test. Return 1 when the point at a1
 * lies inside the cylinder at a0: the height band a0[1]..a0[1]+a0[2], and the
 * XZ radius a0[3] about the centre (a0[4], a0[5]). Return 0 otherwise. */

__attribute__((section(".text.func_001F8550")))
int func_001F8550(float *a0, float *a1) {
    float y = a0[1];
    float py = a1[1];
    float h = a0[2];
    float t, dx, dz, d;
    int r;
    t = y + h;
    if (py < y) goto zero;
    r = 0;
    if (t < py) goto ret;
    dx = a1[0] - a0[4];
    dz = a1[2] - a0[5];
    d = __builtin_sqrtf(dx * dx + dz * dz);
    do { } while (0);
    r = 1;
    if (d < a0[3]) goto ret;
zero:
    return 0;
ret:
    return r;
}

/* sn-2.95.3-136 matched TU.
 * compile_units: {"path": "src/cod/002abc30.c", "compiler": "sn-2.95.3-136",
 *                 "c_flags_add": ["-f=-ffast-math"], "fp_hazard_rules": "sqrt"} */

/* func_002ABC30 — clear the 0xA2 counter, set or clear flag 0x2000 from the
 * two 0x6C/0x6E counts, then sum the 2D leg lengths of the point list at
 * p[0x0] into the float at p[0x9C].
 *
 * The three do{}while(0) barriers are LOAD-BEARING. Each one holds one
 * instruction of the loop tail in retail's order. Do not flatten them. */

__attribute__((section(".text.func_002ABC30")))
void func_002ABC30(int unused, char *p) {
    char *q = *(char **)(p + 0x1C);
    int n0 = *(short *)(q + 0x6C);
    int n2 = *(short *)(q + 0x6E);
    int cnt;
    float *v;
    *(short *)(p + 0xA2) = 0;
    if (*(signed char *)(q + 0x5D) == 0) {
        int ok = (n0 >= 2 && n2 >= 2);
        int bad = ok ^ 1;
        if (bad)
            *(int *)(p + 0x2C) = *(int *)(p + 0x2C) | 0x2000;
        else
            *(int *)(p + 0x2C) = *(int *)(p + 0x2C) & ~0x2000;
    }
    cnt = n2 - 3;
    *(float *)(p + 0x9C) = 0.0f;
    if (cnt > 0) {
        v = *(float **)p;
        do {
            float dx = __builtin_fabsf(v[2] - v[4]);
            float dy = __builtin_fabsf(v[3] - v[5]);
            float t;
            float s = __builtin_sqrtf(dx * dx + dy * dy);
            do { } while (0);
            t = *(float *)(p + 0x9C);
            do { } while (0);
            v += 2;
            cnt--;
            do { } while (0);
            *(float *)(p + 0x9C) = t + s;
        } while (cnt != 0);
    }
}
