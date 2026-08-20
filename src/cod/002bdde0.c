/* sn-2.95.3-136 matched TU. */

extern void *func_002BDEE8(void *a0, void *a1, void *a2, float f);
extern void *func_002BDF30(void *a0, void *a1, void *a2, float f);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_002BDDE0")))
int func_002BDDE0(void *a0, void *a1, void *a2, float t) {
    char *p;
    char *q;
    int y0;
    int y1;
    float d;

    p = (char *)func_002BDEE8(a0, a1, a2, t);
    q = (char *)func_002BDF30(a0, a1, a2, t);
    if (p == 0 || q == 0) {
        return 0;
    }
    if (p == q) {
        return *(unsigned char *)p;
    }
    y0 = *(unsigned short *)(p + 2);
    y1 = *(unsigned short *)(q + 2);
    d = (t - (float)y0) / (float)(y1 - y0);
    return (int)((float)*(unsigned char *)p * (1.0f - d)
                 + (float)*(unsigned char *)q * d);
}
