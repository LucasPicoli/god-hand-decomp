/* sn-2.95.3-136 matched TU. */

extern char *CreateObj(int a0, int a1);

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001F0498")))
char *func_001F0498(char *a0, int a1, float *a2, float a3) {
    float f20 = a3;
    float *s1 = a2;
    char *s0 = CreateObj(a1, 0xFFFF);

    if (s0 != 0) {
        {
            char *v1 = *(char **)(s0 + 0x214);
            int (*fn)(char *) = *(int (**)(char *))(v1 + 0x44);
            short off = *(short *)(v1 + 0x40);
            fn(s0 + off);
        }
        {
            float *dst = *(float **)(s0 + 0xF0);
            if (dst != s1) {
                dst[0] = s1[0];
                dst[1] = s1[1];
                dst[2] = s1[2];
            }
            *(float *)(s0 + 0x104) = f20;
        }
    }
    return s0;
}
