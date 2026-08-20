/* sn-2.95.3-136 matched TU. */

extern void func_001DE858(void *a0, int a1);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_001DD770(void *a0, int a1);
extern void func_001DD840(void *a0, int a1);
extern void func_001DD910(void *a0, int a1);
extern void func_001DD9E0(void *a0, int a1);
extern unsigned char D_005FEE00[];
extern float D_00568170[];

/* sn-2.95.3-136 matched TU. */










static inline unsigned char DecCount(int *p)
{
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DA2A8")))
void func_001DA2A8(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(unsigned char *)(s0 + 0x3025)) {
    case 0:
        func_001DE858(s0, 0xFF);
        *(int *)(s0 + 0x3028) = 1;
        *(unsigned char *)(s0 + 0x3025) += 1;
        break;
    case 1: {
        char **p;
        int i;
        if (DecCount((int *)(s0 + 0x3028)) == 0) {
            break;
        }
        p = (char **)(s0 + 0x3004);
        for (i = 0; i < 5; i++) {
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, *(void **)(p[i]), 0, 0, 0, 0);
        }
        *(int *)(s0 + 0x302C) = 0xF;
        *(unsigned char *)(s0 + 0x3025) += 1;
        break;
    }
    case 2: {
        char **p;
        float *q;
        int i;
        p = (char **)(s0 + 0x3004);
        q = D_00568170;
        for (i = 4; i >= 0; i--) {
            *(float *)(*(int *)(*(int *)(*p) + 0xF0)) =
                -((15.0f - (float)*(int *)(s0 + 0x302C)) / 15.0f) + *q;
            p++;
            q += 4;
        }
        if (*(int *)(s0 + 0x302C) == 0) {
            *(unsigned char *)(s0 + 0x3025) += 1;
        } else {
            *(int *)(s0 + 0x302C) -= 1;
        }
        break;
    }
    case 3: {
        char **p;
        long fl;
        int i;
        p = (char **)(s0 + 0x3004);
        for (i = 4; i >= 0; i--) {
            *(int *)(*(int *)(*p) + 0x250) |= 2;
            p++;
        }
        fl = *(unsigned int *)(s0 + 0x3020);
        if (((fl >> 2) & 1) == 1) {
            *(unsigned char *)(s0 + 0x3024) = 0xC;
            *(int *)(s0 + 0x3020) &= -5;
            *(unsigned char *)(s0 + 0x3025) = 0;
        } else {
            func_001DD770(s0, 2);
            func_001DD840(s0, 2);
            func_001DD910(s0, 2);
            func_001DD9E0(s0, 2);
            *(int *)(s0 + 0x3028) = 0x1E;
            *(unsigned char *)(s0 + 0x3025) += 1;
        }
        break;
    }
    case 4: {
        if (DecCount((int *)(s0 + 0x3028)) != 0) {
            *(unsigned char *)(s0 + 0x3024) = 0;
            *(unsigned char *)(s0 + 0x3025) = 0;
        }
        break;
    }
    }
}
