/* sn-2.95.3-136 matched TU. */

extern int cCoreSave_getCostumeNo(void *a0);
extern void cModel_setTextureExchange(void *a0, int a1, int a2, int a3);
extern int D_00569B70;

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_001236E8")))
void func_001236E8(void *arg)
{
    char *s0 = (char *)arg;
    unsigned int i;
    char **pa;
    char **pb;

    if ((*(int *)(s0 + 0x15F4) & 0x20) == 0) {
        char *t0;
        char *p;
        *(int *)(s0 + 0x254) |= 0x10000000;
        t0 = *(char **)(s0 + 0x304);
        cModel_setTextureExchange(s0, *(int *)(s0 + 0x284), *(int *)(t0 + 0xC) + (int)t0, 0);
        p = *(char **)(s0 + 0x1550);
        if (p != 0) {
            *(int *)(p + 0x380) |= 1;
        }
    } else {
        switch (cCoreSave_getCostumeNo(&D_00569B70)) {
        case 0: case 1: case 2: case 4: case 6: default: {
            char *p;
            *(int *)(s0 + 0x254) &= 0xEFFFFFFF;
            p = *(char **)(s0 + 0x1550);
            if (p != 0) {
                *(int *)(p + 0x380) &= 0xFFFFFFFE;
            }
            break;
        }
        case 3: case 5: case 7: {
            char *t0;
            char *p;
            *(int *)(s0 + 0x254) |= 0x10000000;
            t0 = *(char **)(s0 + 0x304);
            cModel_setTextureExchange(s0, *(int *)(s0 + 0x284), *(int *)(t0 + 0xC) + (int)t0, 1);
            p = *(char **)(s0 + 0x1550);
            if (p != 0) {
                *(int *)(p + 0x380) |= 1;
            }
            break;
        }
        }
    }

    i = 0;
    pb = (char **)(s0 + 0x1564);
    pa = (char **)(s0 + 0x1554);
    do {
        if (*pa != 0) {
            *(int *)(*pa + 0x380) |= 1;
        }
        if (*pb != 0) {
            *(int *)(*pb + 0x380) |= 1;
        }
        i++;
        pb++;
        pa++;
    } while (i < 4);

    {
        int q;
        unsigned short w;
        w = *(unsigned short *)(s0 + 0x3AC);
        q = 0;
        if (w & 0x4000) {
            q = 1;
        }
        if (w & 0x1000) {
            q |= 2;
        }
        if (q == 1) goto a1A;
        if (q == 0) goto a0A;
        if (q == 2) goto a2A;
        if (q == 3) goto a3A;
    a0A: q = *(int *)(s0 + 0x1554); goto gotA;
    a2A: q = *(int *)(s0 + 0x155C); goto gotA;
    a1A: q = *(int *)(s0 + 0x1558); goto gotA;
    a3A: q = *(int *)(s0 + 0x1560);
    gotA:
        if (q != 0) {
            *(int *)(q + 0x380) &= 0xFFFFFFFE;
        }
    }
    {
        int q;
        unsigned short w;
        w = *(unsigned short *)(s0 + 0x3AC);
        q = 0;
        if (w & 0x8000) {
            q = 1;
        }
        if (w & 0x2000) {
            q |= 2;
        }
        if (q == 1) goto a1B;
        if (q == 0) goto a0B;
        if (q == 2) goto a2B;
        if (q == 3) goto a3B;
    a0B: q = *(int *)(s0 + 0x1564); goto gotB;
    a2B: q = *(int *)(s0 + 0x156C); goto gotB;
    a1B: q = *(int *)(s0 + 0x1568); goto gotB;
    a3B: q = *(int *)(s0 + 0x1570);
    gotB:
        if (q != 0) {
            *(int *)(q + 0x380) &= 0xFFFFFFFE;
        }
    }
}
