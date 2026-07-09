/* sn-2.95.3-136 matched TU. */

extern char *CreateObj(int a0, int a1);

__attribute__((section(".text.func_0026AA30")))
char *func_0026AA30(char *a0, int a1) {
    char *s1 = a0;
    switch (a1) {
    case 0x361: case 0x362: case 0x363: case 0x365: case 0x366: case 0x367:
    case 0x368: case 0x369: case 0x36A: case 0x36B: case 0x36C: case 0x36D:
    case 0x36E: case 0x36F: case 0x370: case 0x372: case 0x373: case 0x374:
    case 0x375: case 0x377: case 0x378: case 0x379: case 0x37A: case 0x37D:
    case 0x37E: case 0x37F: case 0x380: case 0x3B7:
    {
        char *s0 = CreateObj(a1, 0xFFFF);
        if (s0 == 0) {
            return 0;
        }
        {
            char *v1 = *(char **)(s0 + 0x214);
            int (*fn)(char *) = *(int (**)(char *))(v1 + 0x44);
            short off = *(short *)(v1 + 0x40);
            if (fn(s0 + off) == 0) {
                return 0;
            }
        }
        {
            float *src = *(float **)(s1 + 0xF0);
            float *dst = *(float **)(s0 + 0xF0);
            float *p490 = (float *)(s0 + 0x490);
            int *p100;
            if (dst != src) {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                dst = *(float **)(s0 + 0xF0);
            }
            if (p490 != dst) {
                p490[0] = dst[0];
                p490[1] = dst[1];
                p490[2] = dst[2];
            }
            p100 = (int *)(s0 + 0x100);
            p100[0] = 0;
            p100[1] = 0;
            p100[2] = 0;
            return s0;
        }
    }
    default:
        return 0;
    }
}
