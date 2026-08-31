/* sn-2.95.3-136 matched TU. */

extern void *SearchData(void *a, void *b, int c);
extern void cModel_setTextureExchange(void *self, void *tex, int tbl, int n);
extern char D_0044B4A8[];
extern char D_0044B4B0[];

/* sn-2.95.3-136 matched TU. */






__attribute__((section(".text.cObjSimple__SetTexChange")))
void cObjSimple__SetTexChange(void *a0, int a1) {
    char *s0 = (char *)a0;
    int s1 = a1;
    void *m;
    int val;

    if (*(unsigned char *)(s0 + 0x4D0) == 0) {
        m = SearchData(*(void **)(s0 + 0x304), &D_0044B4A8, 0);
        if (m == 0) {
            m = SearchData(*(void **)(s0 + 0x304), &D_0044B4B0, 0);
        }
    } else {
        m = SearchData(*(void **)(s0 + 0x304), &D_0044B4A8, *(int *)(s0 + 0x4D4));
        if (m == 0) {
            m = SearchData(*(void **)(s0 + 0x304), &D_0044B4B0, *(int *)(s0 + 0x4D4));
        }
    }
    switch (*(unsigned short *)(s0 + 0x2FE)) {
    case 0x227: {
        char *p0 = *(char **)(s0 + 0x304);
        int f0 = *(int *)(p0 + 0x44);
        val = f0 + (int)p0;
        break;
    }
    case 0x228: {
        char *p1 = *(char **)(s0 + 0x304);
        int f1 = *(int *)(p1 + 0x48);
        val = f1 + (int)p1;
        break;
    }
    case 0x229: {
        char *p2 = *(char **)(s0 + 0x304);
        int f2 = *(int *)(p2 + 0x4C);
        val = f2 + (int)p2;
        break;
    }
    case 0x22A: {
        char *p3 = *(char **)(s0 + 0x304);
        int f3 = *(int *)(p3 + 0x50);
        val = f3 + (int)p3;
        break;
    }
    case 0x22B: {
        char *p4 = *(char **)(s0 + 0x304);
        int f4 = *(int *)(p4 + 0x54);
        val = f4 + (int)p4;
        break;
    }
    case 0x22C: {
        char *p5 = *(char **)(s0 + 0x304);
        int f5 = *(int *)(p5 + 0x58);
        val = f5 + (int)p5;
        break;
    }
    case 0x22D: {
        char *p6 = *(char **)(s0 + 0x304);
        int f6 = *(int *)(p6 + 0x78);
        val = f6 + (int)p6;
        break;
    }
    case 0x22E: {
        char *p7 = *(char **)(s0 + 0x304);
        int f7 = *(int *)(p7 + 0x70);
        val = f7 + (int)p7;
        break;
    }
    case 0x243: {
        char *p8 = *(char **)(s0 + 0x304);
        int f8 = *(int *)(p8 + 0x80);
        val = f8 + (int)p8;
        break;
    }
    case 0x24A: {
        char *p9 = *(char **)(s0 + 0x304);
        int f9 = *(int *)(p9 + 0x64);
        val = f9 + (int)p9;
        break;
    }
    case 0x24B: {
        char *p10 = *(char **)(s0 + 0x304);
        int f10 = *(int *)(p10 + 0x6C);
        val = f10 + (int)p10;
        break;
    }
    case 0x24C: {
        char *p11 = *(char **)(s0 + 0x304);
        int f11 = *(int *)(p11 + 0x74);
        val = f11 + (int)p11;
        break;
    }
    case 0x24D: {
        char *p12 = *(char **)(s0 + 0x304);
        int f12 = *(int *)(p12 + 0x7C);
        val = f12 + (int)p12;
        break;
    }
    case 0x24E: {
        char *p13 = *(char **)(s0 + 0x304);
        int f13 = *(int *)(p13 + 0x88);
        val = f13 + (int)p13;
        break;
    }
    case 0x271:
    case 0x272:
    case 0x273: {
        char *p14 = *(char **)(s0 + 0x304);
        int f14 = *(int *)(p14 + 0x5C);
        val = f14 + (int)p14;
        break;
    }
    default:
        val = 0;
        break;
    }
    if (m != 0) {
        if (val != 0) {
            *(int *)(s0 + 0x254) = *(int *)(s0 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s0, m, val, s1);
        }
    }
}
