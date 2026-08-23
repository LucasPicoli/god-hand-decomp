/* sn-2.95.3-136 matched TU. */

extern char D_00583EC0[];
extern char *D_00754C38;
extern int D_00773250[];

/* compiler: TBD ; extra keys: TBD */


__attribute__((section(".text.func_001F9ED0")))
void func_001F9ED0(char **a0) {
    char *base;
    char *s;
    if (*a0 != 0) {
        base = D_00583EC0;
        s = base + 0x1C;
        *(unsigned short *)(*a0 + 0x15A) = *(unsigned short *)(s + 0x10);
        *(float *)(*a0 + 0x15C) = *(float *)(base + 0x1C);
        *(float *)(*a0 + 0x160) = *(float *)(s + 0x4);
        *(float *)(*a0 + 0x164) = *(float *)(s + 0x8);
        *(float *)(*a0 + 0x168) = *(float *)(s + 0xC);
        *(unsigned char *)(*a0 + 0x158) = *(unsigned char *)(s + 0x12);
        *(unsigned char *)(*a0 + 0x159) = *(unsigned char *)(s + 0x13);
        *(int *)(*a0 + 0x16C) = *(int *)(s + 0x14);
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.GetViewScrollIdAll")))
void GetViewScrollIdAll(unsigned int *a0) {
    char **a1;
    char *obj;
    unsigned int id;
    a1 = *(char ***)((char *)D_00754C38 + 4);
    if (a1 != *(char ***)((char *)D_00754C38 + 8)) {
        do {
            obj = *a1;
            id = *(unsigned char *)(obj + 0x2FD);
            if (id < 0x100) {
                if (*(int *)(obj + 0x250) & 2) {
                    a0[id >> 5] |= 0x80000000 >> (id & 0x1F);
                }
            }
            a1++;
        } while (a1 != *(char ***)((char *)D_00754C38 + 8));
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002D5610")))
int func_002D5610(char **a0, int a1) {
    int cnt;
    char *p;
    if (a1 < 0) {
        cnt = *(unsigned short *)((char *)a0 + 0xC);
        if (cnt != 0) {
            a1 = 0;
            p = *a0 + 0xC;
            do {
                if (*(unsigned short *)p == 0) {
                    return a1;
                }
                a1++;
                p += 0x58;
            } while (a1 < cnt);
        }
        return -1;
    }
    if (a1 < *(unsigned short *)((char *)a0 + 0xC)) {
        return *(unsigned short *)(a1 * 0x58 + (int)*a0 + 0xC) == 0 ? a1 : -1;
    }
    return -1;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_001F6AF8")))
void func_001F6AF8(char *a0) {
    int i;
    int j;
    int *p;
    i = *(int *)(a0 + 0xC) + 1;
    if (i < 4) {
        p = (int *)(i * 4 + (0x10 + (int)a0));
        do {
            if (*p != 0) {
                *(int *)(a0 + 0xC) = i;
                return;
            }
            i++;
            p++;
        } while (i < 4);
    }
    for (j = 0; j < *(int *)(a0 + 0xC); j++) {
        if (*(int *)(a0 + 0x10 + j * 4) != 0) {
            *(int *)(a0 + 0xC) = j;
            return;
        }
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00305FB0")))
char *func_00305FB0(char *a0, int a1) {
    char *h;
    char *sec;
    char *nam;
    char *e;
    unsigned int i;
    h = *(char **)(a0 + 0x400);
    if (h == 0) {
        return 0;
    }
    sec = h + (*(int *)(h + 0x10) + 0x10);
    nam = h + (*(int *)(h + 0x14) + 0x10);
    for (i = 0; i < *(unsigned int *)(sec + 4); i++) {
        if (*(unsigned short *)(*(int *)(sec + 0x10 + i * 4) + (int)sec + 0x10) == a1) {
            e = nam + i * 4;
            return nam + (*(int *)(e + 0x10) + 0x10);
        }
    }
    return 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */


__attribute__((section(".text.func_0037C6A0")))
void func_0037C6A0(char *a0) {
    char *m;
    char *e;
    char *d;
    m = *(char **)(a0 + 0x8);
    d = (char *)D_00773250[*(short *)(m + 0x1A)];
    if (d != 0) {
        e = *(char **)(d + 4) + (*(unsigned short *)(m + 0x6) << 5);
        *(short *)(a0 + 0x38) = *(unsigned char *)(e + 0xC) * *(short *)(a0 + 0x38) / 127;
        *(short *)(a0 + 0x3A) = *(unsigned char *)(e + 0xC) * *(short *)(a0 + 0x3A) / 127;
    }
}
