/* sn-2.95.3-136 matched TU. */

extern void func_001DBEB0(void *a0);
extern void func_001DBE18(void *a0, void *a1);
extern void func_001D6EC8(void *a0, int a1);
extern void func_001D6DD0(void *a0, int a1);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void SetField_56_1DEBE8(void *a0, int a1);
extern float D_00568160[];
extern float D_005681C0[];
extern int D_005FEE00;

/* sn-2.95.3-136 matched TU. */











static __inline__ unsigned char TickDown(int *p) {
    if (*p == 0) {
        return 1;
    }
    *p = *p - 1;
    return 0;
}

__attribute__((section(".text.func_001DA670")))
void func_001DA670(char *s0) {
    unsigned char ok;

    switch (*(unsigned char *)(s0 + 0x3025)) {
    case 0:
        *(int *)(s0 + 0x3038) = *(int *)(s0 + 0x3038) * 2;
        func_001DBEB0(s0);
        *(int *)(s0 + 0x3028) = 30;
        *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        break;
    case 1:
        ok = TickDown((int *)(s0 + 0x3028));
        if (ok) {
            char *g1;
            char *ob;
            char *vt;
            void (*fp)();
            *(int *)(s0 + 0x3020) = *(int *)(s0 + 0x3020) & ~0x10;
            func_001DBE18(s0, s0 + 0x3004);
            func_001D6EC8(*(char **)(s0 + 0x3004), 0);
            g1 = *(char **)*(char **)(s0 + 0x3004);
            *(int *)(g1 + 0x250) = *(int *)(g1 + 0x250) | 2;
            ob = *(char **)*(char **)(s0 + 0x3004);
            vt = *(char **)(ob + 0x214);
            fp = *(void (**)())(vt + 0x74);
            fp(ob + *(short *)(vt + 0x70), D_00568160);
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        break;
    case 2:
        {
        char *g2 = *(char **)*(char **)(s0 + 0x3004);
        *(int *)(g2 + 0x250) = *(int *)(g2 + 0x250) & 0xFFFFFFFDU;
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0, *(char **)*(char **)(s0 + 0x3004), 0, 0, 0, 0);
        SetField_56_1DEBE8(s0, 0);
        *(int *)(s0 + 0x302C) = 10;
        *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        break;
    case 3:
        {
        float t = (10.0f - (float)*(int *)(s0 + 0x302C)) / 10.0f;
        float r0;
        float r1;
        char *d1;
        int n;
        r0 = t * (D_005681C0[0] - D_00568160[0]) + D_00568160[0];
        r1 = t * (D_005681C0[1] - D_00568160[1]) + D_00568160[1];
        d1 = *(char **)(*(char **)*(char **)(s0 + 0x3004) + 0xF0);
        *(float *)d1 = r0;
        {
        char *d2 = *(char **)(*(char **)*(char **)(s0 + 0x3004) + 0xF0);
        *(float *)(d2 + 4) = r1;
        }
        n = *(int *)(s0 + 0x302C);
        if (n == 0) {
            *(int *)(s0 + 0x3028) = 30;
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        } else {
            *(int *)(s0 + 0x302C) = n - 1;
        }
        }
        break;
    case 4:
        ok = TickDown((int *)(s0 + 0x3028));
        if (ok) {
            func_001D6DD0(*(char **)(s0 + 0x3004), 1);
            cSnd_SeCall_2CBA48(&D_005FEE00, 2, 1, *(char **)*(char **)(s0 + 0x3004), 0, 0, 0, 0);
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        break;
    case 5:
        {
        long f = *(unsigned int *)(*(char **)(s0 + 0x3004) + 4);
        if (((f >> 3) & 1) == 1) {
            *(unsigned char *)(s0 + 0x3025) = *(unsigned char *)(s0 + 0x3025) + 1;
        }
        }
        break;
    case 6:
        *(unsigned char *)(s0 + 0x3025) = 0;
        *(unsigned char *)(s0 + 0x3024) = 14;
        break;
    }
}
