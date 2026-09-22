/* sn-2.95.3-136 matched TU. */

extern void *cMessage_getMessageAddr(void *a, int b);
extern void *D_003C23A4;
extern void *D_003C2380;

/* sn-2.95.3-136 candidate. */







__attribute__((section(".text.func_002B0D68")))
float func_002B0D68(char *obj, int val, float *scale)
{
    unsigned int n;
    unsigned int i;
    int p;
    int d;
    int r;
    unsigned short w;
    float acc;

    acc = 0.0f;
    n = func_002AF348(val);
    p = 1;
    for (i = 1; i < n; i++) p *= 10;
    while (p != 0) {
        d = val / p;
        w = ((unsigned short *)cMessage_getMessageAddr(D_003C23A4, 4))[d];
        r = func_002A4B20(D_003C2380, w);
        acc += (float)r * (*scale * *(float *)(obj + 0x3C) * *(float *)(obj + 0x44))
               + *(float *)(obj + 0x2C) * *(float *)(obj + 0x44);
        val -= d * p;
        p /= 10;
    }
    return acc - *(float *)(obj + 0x2C) * *(float *)(obj + 0x44);
}

/* sn-2.95.3-136 candidate. */







__attribute__((section(".text.func_002B0F20")))
float func_002B0F20(char *obj, int val, float *scale)
{
    unsigned int n;
    unsigned int i;
    int p;
    int d;
    int r;
    unsigned short w;
    float acc;
    float t;

    acc = 0.0f;
    n = func_002AF348(val);
    p = 1;
    for (i = 1; i < n; i++) p *= 10;
    while (p != 0) {
        d = val / p;
        w = ((unsigned short *)cMessage_getMessageAddr(D_003C23A4, 4))[d];
        r = func_002A4B88(D_003C2380, w);
        t = (float)r * (*scale * *(float *)(obj + 0x40) * *(float *)(obj + 0x48));
        if (acc < t) acc = t;
        val -= d * p;
        p /= 10;
    }
    if ((*(int *)obj & 1) != 0) {
        acc += (*(float *)(obj + 0x38) + 12.0f) * *(float *)(obj + 0x48);
    }
    return acc;
}
