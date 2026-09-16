/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

typedef struct { char b[0x28]; } T28;

extern void func_001F4428(void *a0, int a1);
extern void func_001F44E0(void *a0);
extern void func_001F4068(void *a0, unsigned short a1, void *a2, int a3);
extern void func_001F4248(void *a0, int a1);
extern void func_001F52A0(void *a0, int a1, int a2);
extern void func_001F55C0(void *a0, int a1, int a2, int a3);

extern void func_001FC518(void *a0, int a1);
extern void func_001F53A8(void *a0, int a1);
extern void func_001F4700(void *a0);
extern void func_001F4758(void *a0);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int t0, int t1,
                              int t2);
extern unsigned char D_005FEE00[];
extern int D_00569B70;
extern int D_007474A0;
extern unsigned char D_0074748C;
extern unsigned char D_00586AA4;
extern char D_003BE8B0[];

__attribute__((section(".text.func_001F3930")))
void func_001F3930(void *a0)
{
    char *s1 = (char *)a0;

    switch (*(int *)(s1 + 8)) {
    case 0:
        func_001F4428(s1, 0);
        *(int *)(s1 + 8) = *(int *)(s1 + 8) + 1;
        break;
    case 1:
        if ((D_0074748C >> 2) & 1) {
            func_001F44E0(s1);
            *(int *)(s1 + 8) = *(int *)(s1 + 8) + 1;
        }
        break;
    case 2: {
        char *g = (char *)&D_007474A0;
        long pad = *(long *)(g + 0x1B0);

        if (pad & 0x3300003000000L) {
            int i;

            if (pad & 0x1100001000000L) {
                int t = *(unsigned short *)(s1 + 0x37D0) - 1;

                *(short *)(s1 + 0x37D0) = t;
                if ((short)t < 0)
                    *(short *)(s1 + 0x37D0) =
                        *(unsigned short *)(s1 + 0x37D6) - 1;
                if (*(short *)(s1 + 0x37D0) !=
                    *(short *)(s1 + 0x37D6) - 1) {
                    int u = *(unsigned short *)(s1 + 0x37D2) - 1;

                    *(short *)(s1 + 0x37D2) = u;
                    if ((short)u < 0) {
                        *(short *)(s1 + 0x37D4) =
                            *(unsigned short *)(s1 + 0x37D0);
                        *(short *)(s1 + 0x37D2) = 0;
                    }
                } else {
                    *(short *)(s1 + 0x37D2) = 6;
                    *(short *)(s1 + 0x37D4) =
                        *(unsigned short *)(s1 + 0x37D6) - 7;
                }
            } else if (pad & 0x2200002000000L) {
                int t = *(unsigned short *)(s1 + 0x37D0) + 1;

                *(short *)(s1 + 0x37D0) = t;
                if ((short)t >= *(short *)(s1 + 0x37D6))
                    *(short *)(s1 + 0x37D0) = 0;
                if (*(short *)(s1 + 0x37D0) != 0) {
                    int u = *(unsigned short *)(s1 + 0x37D2) + 1;

                    *(short *)(s1 + 0x37D2) = u;
                    if ((short)u >= 7) {
                        *(short *)(s1 + 0x37D2) = 6;
                        *(short *)(s1 + 0x37D4) =
                            *(unsigned short *)(s1 + 0x37D0) - 6;
                    }
                } else {
                    *(short *)(s1 + 0x37D2) = 0;
                    *(short *)(s1 + 0x37D4) = 0;
                }
            }
            for (i = 0; i < 7; i++)
                func_001F4068(s1, i,
                              &D_003BE8B0[(*(short *)(s1 + 0x37D4) + i) * 0x28],
                              1);
            *(T28 *)(s1 + 0x37A8) =
                *(T28 *)&D_003BE8B0[*(short *)(s1 + 0x37D0) * 0x28];
            func_001F4248(s1, 1);
            func_001F52A0(s1 + 0x60, *(unsigned short *)(s1 + 0x37D2), 1);
            func_001F55C0(s1 + 0x60, *(short *)(s1 + 0x37D6), 7,
                          *(short *)(s1 + 0x37D4));
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1A0) & 0x20000000) {
            func_001F4428(s1, 1);
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
            *(int *)(s1 + 8) = *(int *)(s1 + 8) + 1;
        } else if (*(long *)(g + 0x1A0) & 0x10000000) {
            if (func_001F4530(s1, *(short *)(s1 + 0x37A8),
                              *(unsigned short *)(s1 + 0x37AC)) != 0) {
                func_001FC518(&D_00569B70, *(short *)(s1 + 0x37D0));
                D_00586AA4 = *(unsigned char *)(s1 + 0x37AE);
                func_001F53A8(s1 + 0x60, 0);
                func_001F4428(s1, 1);
                cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
                *(int *)(s1 + 8) = *(int *)(s1 + 8) + 2;
            }
        }
        break;
    }
    case 3:
        if ((D_0074748C >> 2) & 1) {
            *(int *)(s1 + 8) = 0;
            *(int *)(s1 + 4) = 1;
            *(int *)(s1 + 0xC) = 0;
        }
        break;
    case 4:
        if ((D_0074748C >> 2) & 1) {
            *(int *)(s1 + 8) = 0;
            *(int *)(s1 + 4) = 2;
            *(int *)(s1 + 0xC) = 0;
        }
        break;
    }
    func_001F4700(s1 + 0x60);
    func_001F4758(s1 + 0x60);
}
