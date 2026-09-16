/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void func_001DD6D8(void *a0, int a1);
extern void func_001DE5F8(void *a0, int a1, int a2);
extern void func_001DD910(void *a0, int a1);
extern void func_001DF758(void *p, int a1);
extern void func_001DF7D0(void *p, int a1);
extern void func_001DF820(void *p, int a1);
extern void CustomIDWork_SetNumber_1DD218(void *a0, int a1);
extern void cCoreSave_addGold(void *p, int a1, int a2);
extern void cSnd_SetBgmState(void *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_0042B2F0[];
extern long D_007474A0[];
extern long D_00747640;

typedef struct {
    int w[8];
} Blob32;

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

__attribute__((section(".text.func_001D9D28")))
void func_001D9D28(void *arg)
{
    char *s1 = (char *)arg;
    unsigned char f;
    long m;

    switch (*(unsigned char *)(s1 + 0x3025)) {
    case 0: {
        int buf[8];

        *(Blob32 *)buf = *(Blob32 *)D_0042B2F0;
        *(int *)(s1 + 0x3028) = 0x3C;
        *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        *(int *)(s1 + 0x3038) =
            buf[*(int *)(s1 + 0x3048)] * *(int *)(s1 + 0x3034);
        break;
    }
    case 1:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            func_001DD6D8(s1, *(int *)(s1 + 0x3038));
            func_001DE5F8(s1, *(unsigned char *)(s1 + 0x3048), 2);
            *(int *)(s1 + 0x3028) = 0x14;
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 2:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 3:
        *(int *)(s1 + 0x3028) = 0x1E;
        *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        /* fallthrough */
    case 4:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            char *s0 = s1 + 0x25B0;

            *(int *)(s1 + 0x3040) = 0;
            func_001DF758(s0, 1);
            func_001DF7D0(s0, 1);
            func_001DF820(s0, 1);
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 5:
        if (D_007474A0[0x1B0 / 8] & 0xCC0000C000000L) {
            if (*(int *)(s1 + 0x3040) == 0) {
                *(int *)(s1 + 0x3040) = 1;
                func_001DF7D0(s1 + 0x25B0, 0);
            } else {
                *(int *)(s1 + 0x3040) = 0;
                func_001DF7D0(s1 + 0x25B0, 1);
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            return;
        }
        m = D_007474A0[0x1A0 / 8];
        if (m & 0x20000000L) {
            *(int *)(s1 + 0x3040) = 1;
            func_001DF7D0(s1 + 0x25B0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            return;
        }
        if (m & 0x10000000L) {
            char *s0;

            func_001DD910(s1, 1);
            s0 = s1 + 0x25B0;
            func_001DF758(s0, 0);
            func_001DF7D0(s0, 0);
            func_001DF820(s0, 0);
            func_001DE5F8(s1, *(unsigned char *)(s1 + 0x3048), 3);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
            *(int *)(s1 + 0x3028) = 0x14;
            *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        }
        break;
    case 6:
        f = TickDown((int *)(s1 + 0x3028));
        if (f) {
            if (*(int *)(s1 + 0x3040) == 0) {
                *(unsigned char *)(s1 + 0x3025) =
                    *(unsigned char *)(s1 + 0x3025) + 1;
            } else {
                *(unsigned char *)(s1 + 0x3025) =
                    *(unsigned char *)(s1 + 0x3025) + 2;
            }
        }
        break;
    case 7:
        *(int *)(s1 + 0x3020) = *(int *)(s1 + 0x3020) | 4;
        *(unsigned char *)(s1 + 0x3024) = 0xB;
        *(unsigned char *)(s1 + 0x3025) = 0;
        break;
    case 8:
        *(int *)(s1 + 0x3020) = *(int *)(s1 + 0x3020) & -5;
        *(int *)(s1 + 0x302C) = *(int *)(s1 + 0x3038) / 0xA;
        *(unsigned char *)(s1 + 0x3025) = *(unsigned char *)(s1 + 0x3025) + 1;
        /* fallthrough */
    case 9:
        if ((D_00747640 & 0x30000000L) != 0 || *(int *)(s1 + 0x302C) == 0) {
            cCoreSave_addGold(D_00569B70, *(int *)(s1 + 0x302C) * 0xA, 0);
            *(int *)(s1 + 0x3034) = 0;
            CustomIDWork_SetNumber_1DD218(s1, 0);
            cSnd_SetBgmState(D_005FEE00, 0);
            *(unsigned char *)(s1 + 0x3025) = 0;
            *(unsigned char *)(s1 + 0x3024) = 0xB;
        } else {
            *(int *)(s1 + 0x302C) = *(int *)(s1 + 0x302C) - 1;
            cCoreSave_addGold(D_00569B70, 0xA, 0);
        }
        break;
    }
}
