/* sn-2.95.3-136 matched TU. */

extern int D_005FEE00;
extern void cSnd_SeCall_2CBA48(int *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int Forward30F348_31CFE0(void);
extern void cDamageUnit_SetDamageCollFlashActive(void *a0, int a1, short a2);

/* sn-2.95.3-136 matched TU. */






#define PART(K, OFF)                                        \
    b = *(unsigned char *)(s0 + 0x2B4);                     \
    spill[0] = b;                                           \
    lim = (K);                                              \
    if (lim < b)                                            \
        obj = *(int *)(*(int *)(s0 + 0x278) + (OFF));       \
    else                                                    \
        obj = 0;

__attribute__((section(".text.func_001ACB78")))
void func_001ACB78(void *a0)
{
    char *s0 = (char *)a0;
    int obj;
    int b, lim;
    int spill[2];
    int r;
    int n;
    int p;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(float *)(s0 + 0x794) = 0.0f;
        r = Forward30F348_31CFE0();
        *(char *)(s0 + 0x2F6) = 1;
        *(short *)(s0 + 0x61E) = (r & 0xF) + 0xF;
        *(char *)(s0 + 0x620) = 0;
        *(char *)(s0 + 0x2F7) = 0;
        /* fall through */
    case 1:
        n = *(unsigned short *)(s0 + 0x61E) - 1;
        *(short *)(s0 + 0x61E) = n;
        if ((short)n > 0)
            break;
        *(short *)(s0 + 0x61E) = 8;
        *(char *)(s0 + 0x2F6) = 2;
        *(char *)(s0 + 0x620) = *(unsigned char *)(s0 + 0x620) + 1;
        *(char *)(s0 + 0x2F7) = 0;
        break;
    case 2:
        *(float *)(s0 + 0x794) = *(float *)(s0 + 0x794) + 0.0872664601f;
        PART(1, 4)
        if (obj != 0) {
            PART(1, 4)
            *(float *)(obj + 0x104) = -*(float *)(s0 + 0x794);
        }
        PART(2, 8)
        if (obj != 0) {
            PART(2, 8)
            *(float *)(obj + 0x104) = *(float *)(s0 + 0x794);
        }
        *(char *)(s0 + 0x2F7) = 0;
        *(char *)(s0 + 0x2F6) = 3;
        break;
    case 3:
        *(float *)(s0 + 0x794) = *(float *)(s0 + 0x794) - 0.0872664601f;
        PART(1, 4)
        if (obj != 0) {
            PART(1, 4)
            *(float *)(obj + 0x104) = -*(float *)(s0 + 0x794);
        }
        PART(2, 8)
        if (obj != 0) {
            PART(2, 8)
            *(float *)(obj + 0x104) = *(float *)(s0 + 0x794);
        }
        n = *(unsigned short *)(s0 + 0x61E) - 1;
        *(short *)(s0 + 0x61E) = n;
        if ((short)n > 0) {
            *(char *)(s0 + 0x2F7) = 0;
            *(char *)(s0 + 0x2F6) = 2;
            break;
        }
        *(char *)(s0 + 0x2F7) = 0;
        *(char *)(s0 + 0x2F6) = 4;
        break;
    case 4:
        *(float *)(s0 + 0x794) = *(float *)(s0 + 0x794) + 0.34906584f;
        PART(1, 4)
        if (obj != 0) {
            PART(1, 4)
            *(float *)(obj + 0x104) = -*(float *)(s0 + 0x794);
        }
        PART(2, 8)
        if (obj != 0) {
            PART(2, 8)
            *(float *)(obj + 0x104) = *(float *)(s0 + 0x794);
        }
        if (1.57079637f <= *(float *)(s0 + 0x794)) {
            p = *(int *)(s0 + 0x628);
            if (p != 0) {
                cDamageUnit_SetDamageCollFlashActive((void *)p, 1, 2);
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x111, s0, 0, 0, 0, 0);
            }
            *(char *)(s0 + 0x2F7) = 0;
            *(char *)(s0 + 0x2F6) = 5;
            break;
        }
        break;
    case 5:
        *(float *)(s0 + 0x794) = *(float *)(s0 + 0x794) - 0.0872664601f;
        PART(1, 4)
        if (obj != 0) {
            PART(1, 4)
            *(float *)(obj + 0x104) = -*(float *)(s0 + 0x794);
        }
        PART(2, 8)
        if (obj != 0) {
            PART(2, 8)
            *(float *)(obj + 0x104) = *(float *)(s0 + 0x794);
        }
        if (*(float *)(s0 + 0x794) <= 0.0f) {
            PART(1, 4)
            if (obj != 0) {
                PART(1, 4)
                *(int *)(obj + 0x104) = 0;
            }
            PART(2, 8)
            if (obj != 0) {
                PART(2, 8)
                *(int *)(obj + 0x104) = 0;
            }
            if ((Forward30F348_31CFE0() & 1) != 0) {
                *(char *)(s0 + 0x2F7) = 0;
                *(char *)(s0 + 0x2F6) = 6;
                break;
            }
            if (*(char *)(s0 + 0x620) >= 2) {
                *(char *)(s0 + 0x2F7) = 0;
                *(char *)(s0 + 0x2F6) = 6;
                break;
            }
            *(short *)(s0 + 0x61E) = 4;
            *(char *)(s0 + 0x2F6) = 1;
            *(float *)(s0 + 0x794) = 0.0f;
            *(char *)(s0 + 0x2F7) = 0;
            break;
        }
        break;
    case 6:
        *(char *)(s0 + 0x2F5) = 0;
        *(char *)(s0 + 0x2F6) = 0;
        *(char *)(s0 + 0x2F7) = 0;
        *(int *)(s0 + 0x618) = 0;
        break;
    }
}
