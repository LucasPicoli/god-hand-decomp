/* sn-2.95.3-136 matched TU. */

extern void func_001DEE40(void *p, int a1);
extern void func_001DF528(void *p, int a1, int a2);
extern void func_001DF758(void *p, int a1);
extern void func_001DF7D0(void *p, int a1);
extern void func_001DF820(void *p, int a1);
extern void cCoreSave_addGold(void *p, int a1, int a2);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern char D_00569B70[];
extern char D_005681C0[];
extern char D_005FEE00[];
extern long D_007474A0[];
extern long D_00747640;

/* sn-2.95.3-136 candidate. */















static __inline__ unsigned char TickDown(int *p)
{
    int v;

    v = *p;
    if (v == 0) {
        return 1;
    }
    *p = v - 1;
    return 0;
}

__attribute__((section(".text.func_001DB558")))
void func_001DB558(void *arg)
{
    char *s1 = (char *)arg;
    unsigned char f;
    long m;
    float d;

    switch (*(unsigned char *)(s1 + 0x3025)) {
    case 0:
        *(int *)(s1 + 0x3028) = 0x1E;
        *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        break;
    case 1:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            func_001DF528(s1 + 0x25B0, 2, 4);
            *(int *)(s1 + 0x3028) = 0x1E;
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 2:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            char *p = s1 + 0x25B0;

            *(int *)(s1 + 0x3040) = 0;
            func_001DF758(p, 1);
            func_001DF7D0(p, 1);
            func_001DF820(p, 1);
            *(int *)(s1 + 0x3028) = 0x14;
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 3:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 4:
        if ((D_007474A0[54] & 0xCC0000C000000L) != 0) {
            if (*(int *)(s1 + 0x3040) == 0) {
                *(int *)(s1 + 0x3040) = 1;
                func_001DF7D0(s1 + 0x25B0, 0);
            } else {
                *(int *)(s1 + 0x3040) = 0;
                func_001DF7D0(s1 + 0x25B0, 1);
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else {
            m = D_007474A0[52];
            if ((m & 0x20000000) != 0) {
                *(int *)(s1 + 0x3040) = 1;
                func_001DF7D0(s1 + 0x25B0, 0);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            } else if ((m & 0x10000000) != 0) {
                char *p;

                if (*(int *)(s1 + 0x3040) == 0) {
                    p = s1 + 0x25B0;
                    func_001DF528(p, 2, 3);
                    *(int *)(s1 + 0x3028) = 0x1E;
                    *(unsigned char *)(s1 + 0x3025) =
                        *(unsigned char *)(s1 + 0x3025) + 1;
                } else {
                    int g = *(int *)(s1 + 0x3034);
                    int q;

                    p = s1 + 0x25B0;
                    *(int *)(s1 + 0x3038) = g;
                    q = g / 10;
                    *(unsigned char *)(s1 + 0x3025) =
                        *(unsigned char *)(s1 + 0x3025) + 3;
                    *(int *)(s1 + 0x302C) = q;
                }
                func_001DF758(p, 0);
                func_001DF820(p, 0);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
            }
        }
        break;
    case 5:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0,
                               **(int **)(s1 + 0x3004), 0, 0, 0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0,
                               **(int **)(s1 + 0x3008), 0, 0, 0, 0);
            *(int *)(s1 + 0x302C) = 0xF;
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 6:
        d = -((15.0f - (float)*(int *)(s1 + 0x302C)) / 15.0f);
        **(float **)(*(char **)*(char **)(s1 + 0x3004) + 0xF0) =
            d + *(float *)D_005681C0;
        **(float **)(*(char **)*(char **)(s1 + 0x3008) + 0xF0) =
            d + *(float *)(D_005681C0 + 0x10);
        if (*(int *)(s1 + 0x302C) == 0) {
            *(unsigned char *)(s1 + 0x3025) = 0;
            *(unsigned char *)(s1 + 0x3024) = 0xD;
        } else {
            *(int *)(s1 + 0x302C) = *(int *)(s1 + 0x302C) - 1;
        }
        break;
    case 7:
        if ((D_00747640 & 0x30000000) != 0 || *(int *)(s1 + 0x302C) == 0) {
            char *p = s1 + 0x25B0;

            cCoreSave_addGold(D_00569B70, *(int *)(s1 + 0x302C) * 10, 0);
            *(int *)(s1 + 0x3034) = 0;
            func_001DEE40(p, 0);
            func_001DF528(p, 2, 3);
            *(int *)(s1 + 0x3028) = 0x1E;
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        } else {
            *(int *)(s1 + 0x302C) = *(int *)(s1 + 0x302C) - 1;
            cCoreSave_addGold(D_00569B70, 10, 0);
            *(int *)(s1 + 0x3034) = *(int *)(s1 + 0x3034) - 10;
            func_001DEE40(s1 + 0x25B0, *(int *)(s1 + 0x3034));
        }
        break;
    case 8:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            *(unsigned char *)(s1 + 0x3025) = 0;
            *(unsigned char *)(s1 + 0x3024) = 0x14;
        }
        break;
    }
}
