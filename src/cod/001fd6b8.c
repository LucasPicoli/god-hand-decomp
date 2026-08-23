/* sn-2.95.3-136 matched TU. */

extern unsigned int D_007476B0;

__attribute__((section(".text.func_001FD6B8")))
void func_001FD6B8(char *o, int id, int f, short val) {
    char *n = *(char **)(o + 0x3C);
    unsigned int *q;
    while (n != 0) {
        if (*(short *)(n + 0x2C) == id) {
            q = *(unsigned int **)(n + 0x28);
            if (f == 1) *q = *q | 2;
            else *q = *q & 0xFFFFFFFDU;
            *(short *)(n + 0x30) = val;
            return;
        }
        n = *(char **)(n + 0x24);
    }
}

__attribute__((section(".text.func_002E12D8")))
int func_002E12D8(signed char c) {
    switch (c) {
    case 1: return 0x7D;
    case 2: return 0x60;
    case 3: return 0x7C;
    case 4: return 0x7B;
    }
    return c;
}

__attribute__((section(".text.func_002A4F30")))
unsigned int func_002A4F30(char *o, unsigned int amt) {
    char *b = o + 0x28000;
    unsigned int cur = *(unsigned int *)(b + 0x2054);
    unsigned int lim = *(unsigned int *)(b + 0x2058);
    unsigned int nw = cur + amt;
    unsigned int t;
    if (nw >= lim) {
        *(unsigned int *)(b + 0x2054) = lim;
        return 0;
    }
    *(unsigned int *)(b + 0x2054) = nw;
    t = nw - (unsigned int)(o + ((D_007476B0 & 1) * 0x15000 + 0x50));
    if (*(unsigned int *)(b + 0x208C) < t) *(unsigned int *)(b + 0x208C) = t;
    return cur;
}
