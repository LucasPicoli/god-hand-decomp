/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern float func_002AC650(void *a0, int a1, int a2, int a3);

__attribute__((section(".text.func_002AC378")))
void func_002AC378(void *a0, void *a1)
{
    char *s0 = (char *)a1;
    char *s1;
    int flags;
    int m;
    int n;
    int lim;
    char *rec;
    float t;
    float u;
    unsigned long bits;

    s1 = *(char **)(s0 + 0x1C);
    flags = *(int *)(s1 + 4);
    if ((flags & 0x200000) == 0) {
        return;
    }
    m = *(int *)(s0 + 0x2C);
    if (m & 0x400) {
        return;
    }
    if (*(char *)(s1 + 0x64) != 0) {
        return;
    }
    n = *(short *)(s1 + 0x278);
    rec = s1 + (n - 1) * 0xC;
    lim = *(short *)(rec + 0x284);
    if ((flags & 0x10000) != 0) {
        if (lim < *(unsigned short *)(s0 + 0xA8)) {
            *(short *)(s0 + 0xA8) = 0;
        }
    } else {
        if (lim < *(unsigned short *)(s0 + 0xA8)) {
            *(int *)(s0 + 0x2C) = m | 0x400;
            return;
        }
    }
    t = func_002AC650(a0, *(short *)(s0 + 0xA8), n, *(int *)(s0 + 0x10));
    u = 1.0f - t;
    bits = *(int *)(s0 + 0x2C);
    *(char *)(s0 + 0x4C) = (int)((float)*(unsigned char *)(s1 + 0x50) * u
                                 + (float)*(unsigned char *)(s1 + 0x2DC) * t);
    *(char *)(s0 + 0x4D) = (int)((float)*(unsigned char *)(s1 + 0x51) * u
                                 + (float)*(unsigned char *)(s1 + 0x2DD) * t);
    *(char *)(s0 + 0x4E) = (int)((float)*(unsigned char *)(s1 + 0x52) * u
                                 + (float)*(unsigned char *)(s1 + 0x2DE) * t);
    *(char *)(s0 + 0x4F) = (int)((float)*(unsigned char *)(s1 + 0x53) * u
                                 + (float)*(unsigned char *)(s1 + 0x2DF) * t);
    if (((bits >> 5) & 1) == 0) {
        *(unsigned short *)(s0 + 0xA8) = *(unsigned short *)(s0 + 0xA8) + 1;
    }
}
