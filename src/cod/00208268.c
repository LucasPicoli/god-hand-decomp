/* sn-2.95.3-136 matched TU. */

extern int GetEm00CharIndex(int a, int b);
extern void *SearchData(void *a, void *b, int c);
extern int cModel_setTextureExchange(void *self, void *tex, void *tbl, int n);
extern int cModel_setupModel(void *a, void *b, void *c, int d, int e);
extern char D_0042FD50[];
extern char D_0042FD58[];

/* sn-2.95.3-136 matched TU. */








__attribute__((section(".text.func_00208268")))
int func_00208268(void *a0)
{
    char *s1 = (char *)a0;
    void *m1;
    void *m2;
    int idx;

    idx = GetEm00CharIndex(*(unsigned short *)(s1 + 0x2FE), *(int *)(s1 + 0x564));
    m1 = SearchData(*(void **)(s1 + 0x304), &D_0042FD50, idx);
    m2 = SearchData(*(void **)(s1 + 0x304), &D_0042FD58, idx);

    switch (*(int *)(s1 + 0x564)) {
    case 0x200:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x44) + b), 0);
            *(int *)(s1 + 0x564) = 0x227;
        }
        break;
    case 0x201:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x48) + b), 0);
            *(int *)(s1 + 0x564) = 0x228;
        }
        break;
    case 0x202:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x4C) + b), 0);
            *(int *)(s1 + 0x564) = 0x229;
        }
        break;
    case 0x203:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x50) + b), 0);
            *(int *)(s1 + 0x564) = 0x22A;
        }
        break;
    case 0x204:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x54) + b), 0);
            *(int *)(s1 + 0x564) = 0x22B;
        }
        break;
    case 0x240:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x64) + b), 0);
            *(int *)(s1 + 0x564) = 0x24A;
        }
        break;
    case 0x21A:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x58) + b), 0);
            *(int *)(s1 + 0x564) = 0x22C;
        }
        break;
    case 0x21D:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x70) + b), 0);
            *(int *)(s1 + 0x564) = 0x22E;
        }
        break;
    case 0x21E:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x68) + b), 0);
            *(int *)(s1 + 0x564) = 0x22F;
        }
        break;
    case 0x248:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x74) + b), 0);
            *(int *)(s1 + 0x564) = 0x24C;
        }
        break;
    case 0x249:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x88) + b), 0);
            *(int *)(s1 + 0x564) = 0x24E;
        }
        break;
    case 0x216:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x6C) + b), 0);
            *(int *)(s1 + 0x564) = 0x24B;
        }
        break;
    case 0x21B:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x78) + b), 0);
            *(int *)(s1 + 0x564) = 0x22D;
        }
        break;
    case 0x225:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x7C) + b), 0);
            *(int *)(s1 + 0x564) = 0x24D;
        }
        break;
    case 0x242:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x80) + b), 0);
            *(int *)(s1 + 0x564) = 0x243;
        }
        break;
    case 0x270: case 0x271: case 0x272: case 0x273: case 0x274:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x5C) + b), 0);
            *(int *)(s1 + 0x564) = 0x271;
        }
        if (*(int *)(s1 + 0x164C) & 2) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x5C) + b), 1);
            *(int *)(s1 + 0x564) = 0x272;
        }
        if (*(int *)(s1 + 0x164C) & 4) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x5C) + b), 2);
            *(int *)(s1 + 0x564) = 0x273;
        }
        break;
    case 0x25A:
        if (*(int *)(s1 + 0x164C) & 1) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x94) + b), 0);
        }
        if (*(int *)(s1 + 0x164C) & 2) {
            int b = *(int *)(s1 + 0x304);
            *(int *)(s1 + 0x254) = *(int *)(s1 + 0x254) | 0x10000000;
            cModel_setTextureExchange(s1, m2, (void *)(*(int *)(b + 0x94) + b), 1);
        }
        break;
    }

    if (m2 != 0) {
        return cModel_setupModel(s1, m1, m2, 0, 0);
    }
    return 0;
}
