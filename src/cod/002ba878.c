/* sn-2.95.3-136 matched TU. */

extern float capVu0LengthSq(void *a0);
extern float sqrtf(float x);
extern void func_002BCF28(void *a0, float f12, float f13, void *a1, float f14, float f15);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002BA878")))
void func_002BA878(void *a0) {
    *(float *)((char *)a0 + 0xE4) =
        __builtin_sqrtf(capVu0LengthSq((char *)a0 + 0x110));
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002BA998")))
void func_002BA998(void *a0) {
    char *s2 = (char *)a0;
    float max = 0.0f;
    unsigned int i;

    for (i = 0; i < 8; i++) {
        float d = __builtin_sqrtf(capVu0LengthSq(s2 + 0x110 + i * 0x10));

        if (max < d) {
            max = d;
        }
    }
    *(float *)(s2 + 0xE4) = max;
}

/* sn-2.95.3-136 matched TU. */




typedef void (*vfn)(void *, void *);

__attribute__((section(".text.func_002BAB30")))
void func_002BAB30(void *a0) {
    char *s0 = (char *)a0;
    char buf[16] __attribute__((aligned(16)));
    char *vt = *(char **)(s0 + 0x100);

    (*(vfn *)(vt + 0x34))(buf, s0 + *(short *)(vt + 0x30));

    *(float *)(buf + 0x0) *= 0.5f;
    *(float *)(buf + 0x4) *= 0.5f;
    *(float *)(buf + 0x8) *= 0.5f;

    *(float *)(s0 + 0xE4) = __builtin_sqrtf(capVu0LengthSq(buf));
}

/* sn-2.95.3-136 matched TU. */



extern int func_002BBDB8(void *a0, float f0, float f1, void *a1, float f2,
                         float f3);

__attribute__((section(".text.func_002BCCC0")))
int func_002BCCC0(void *a0, void *a1, void *a2, float f0, float f1) {
    float t = __builtin_sqrtf(capVu0LengthSq(a2));

    return func_002BBDB8(a0, f0, f1, a1, 0.0f, t);
}

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_002BD340")))
void func_002BD340(void *a0, void *a1, void *a2, float f12, float f13) {
    float d = __builtin_sqrtf(capVu0LengthSq(a2));

    func_002BCF28(a0, f12, f13, a1, 0.0f, d);
}
