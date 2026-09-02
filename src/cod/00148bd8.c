/* sn-2.95.3-136 matched TU. */

extern long D_00747650;
extern char D_0042BAC0[];
extern char D_0042BAE0[];
extern void func_002E0D60(int a, int b, int c, int d, int e, int f, char *g, int h);
extern void func_001D5690(void *a0, int a1);
extern void SetBlendField820_1D5B90(void *a0, int a1);
extern void CustomIDWork_SetNumber_1D5760(void *a0, int a1);
extern void cCoreSave_subGold(char *a0, int a1);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, short a2, short a3, short a4, int a5, int a6);
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_007474A0;
extern int D_004664A0;
extern int D_007476B0;

/* sn-2.95.3-136, as=sn */



__attribute__((section(".text.func_002A52E8")))
void func_002A52E8(int a0, unsigned int col)
{
    char *p;
    float f;
    int q;
    long v;

    p = func_002A4F30(a0, 0x30);
    if (p != 0) {
        f = 1.0f;
        q = *(int *)&f;
        v = (long)(col & 0xFF)
          | ((long)((col >> 8) & 0xFF) << 8)
          | ((long)((col >> 16) & 0xFF) << 16)
          | ((long)((col >> 24) & 0xFF) << 24)
          | ((long)q << 32);
        *(long *)(p + 0x0) = 0x10000002;
        *(int *)(p + 0x8) = 0x11000000;
        *(int *)(p + 0xC) = 0x50000002;
        *(long *)(p + 0x10) = 0x1000000000008001L;
        *(long *)(p + 0x18) = 0xE;
        *(long *)(p + 0x20) = v;
        *(long *)(p + 0x28) = 1;
    }
}

/* sn-2.95.3-136, as=sn */






typedef struct { char b[0x20]; } T32;

__attribute__((section(".text.func_001E6938")))
void func_001E6938(char *a0)
{
    int tbl[8];

    if (D_00747650 & 0x0004400008000000L) {
        int dn = *(unsigned short *)(a0 + 0xA80) - 1;
        *(short *)(a0 + 0xA80) = dn;
        if ((short)dn < 0) {
            *(short *)(a0 + 0xA80) = 7;
        }
    } else if (D_00747650 & 0x0008800004000000L) {
        int up = *(unsigned short *)(a0 + 0xA80) + 1;
        *(short *)(a0 + 0xA80) = up;
        if ((short)up >= 8) {
            *(short *)(a0 + 0xA80) = 0;
        }
    }
    *(T32 *)tbl = *(T32 *)D_0042BAC0;
    func_002E0D60(8, 0x10, 0x20, 0x20, 0, 0, D_0042BAE0,
                  tbl[*(short *)(a0 + 0xA80)]);
}

/* sn-2.95.3-136, as=sn */










__attribute__((section(".text.func_001D2BB0")))
void func_001D2BB0(void *a0)
{
    char *s0 = (char *)a0;

    switch (*(int *)(s0 + 0x1808)) {
    case 0:
        func_001D5690(s0, 0);
        SetBlendField820_1D5B90(s0, 1);
        *(int *)(s0 + 0x1808) += 1;
        /* fallthrough */
    case 1: {
        char *g = (char *)&D_007474A0;
        long f = *(long *)(g + 0x1B0);

        if ((f & 0x3300003000000L) != 0) {
            func_001D5690(s0, 1);
            SetBlendField820_1D5B90(s0, 0);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
            *(int *)(s0 + 0x1808) = 0;
            *(int *)(s0 + 0x1804) = 6;
            return;
        }
        {
            long h = *(long *)(g + 0x1A0);

            if ((h & 0x10000000L) != 0) {
                int v;

                cCoreSave_subGold(D_00569B70, *(int *)(s0 + 0x1814));
                v = *(int *)(s0 + 0x1814) * 2;
                *(int *)(s0 + 0x1814) = v;
                CustomIDWork_SetNumber_1D5760(s0, v);
                SetBlendField820_1D5B90(s0, 0);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                *(int *)(s0 + 0x1808) = 0;
                *(int *)(s0 + 0x1804) = 0xB;
            }
        }
        break;
    }
    }
}

/* sn-2.95.3-136, as=sn */






__attribute__((section(".text.func_00148BD8")))
void func_00148BD8(char *a0, int a1, int a2, int a3)
{
    char *s3 = a0;
    char *L[2];
    int n;
    int h;
    int i;
    int flag;

    L[0] = *(char **)(s3 + 0x388);
    n = *(unsigned short *)(L[0] + 0xA);
    h = func_00151398((int)&D_004664A0, a2, a1);
    flag = D_007476B0 & 1;
    for (i = 0; i < n; i++) {
        int idx = i * 4;
        L[1] = (char *)(*(int *)((int)L[0] + idx + 0x20) + (int)L[0]);
        if (*(unsigned char *)(L[1] + 0x16) != 0xFF) {
            char *o = *(char **)((flag << 6) + (int)(s3 + 0x300) + i * 4);
            unsigned long q;
            unsigned long t;

            q = func_00151368((int)&D_004664A0, h);
            *(long *)(o + 0x20) = q;
            t = q >> 37;
            t &= 0x3FFF;
            q &= 0xFFF8001FFFFFFFFFUL;
            t += *(char *)(s3 + 0x387);
            t &= 0x3FFF;
            t <<= 37;
            q |= t;
            q &= 0xFFFFFFE7FFFFFFFFUL;
            q |= ((long)(a3 & 3) << 35);
            *(long *)(o + 0x20) = q;
        }
    }
}
