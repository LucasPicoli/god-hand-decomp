/* sn-2.95.3-136 matched TU. */

extern char D_003BC770[];
extern char D_003BD0F0[];
extern char D_003BFAD8[];
extern char D_003BFB18[];
extern char D_003BFE18[];
extern char D_003BFE88[];
extern char D_003BFEB0[];
extern char D_003BFF58[];

__attribute__((section(".text.func_00102728")))
void func_00102728(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 8) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BC770 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BC770 + i8 + 4);
    }
    f0 = *(short *)(D_003BC770 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_0010B6B0")))
void func_0010B6B0(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 71) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BD0F0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BD0F0 + i8 + 4);
    }
    f0 = *(short *)(D_003BD0F0 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_002777A8")))
void func_002777A8(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 5) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BFAD8 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFAD8 + i8 + 4);
    }
    f0 = *(short *)(D_003BFAD8 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_002785E0")))
void func_002785E0(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 6) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BFB18 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFB18 + i8 + 4);
    }
    f0 = *(short *)(D_003BFB18 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_0027BEF8")))
void func_0027BEF8(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 11) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BFE18 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFE18 + i8 + 4);
    }
    f0 = *(short *)(D_003BFE18 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_0027E348")))
void func_0027E348(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 2) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BFE88 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFE88 + i8 + 4);
    }
    f0 = *(short *)(D_003BFE88 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_0027F4C0")))
void func_0027F4C0(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 18) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BFEB0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFEB0 + i8 + 4);
    }
    f0 = *(short *)(D_003BFEB0 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}

__attribute__((section(".text.func_00281C60")))
void func_00281C60(void *a0) {
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (*(unsigned char *)(s0 + 0x2F5) >= 15) *(unsigned char *)(s0 + 0x2F5) = 0;
    i8 = *(unsigned char *)(s0 + 0x2F5) * 8;
    e = D_003BFF58 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFF58 + i8 + 4);
    }
    f0 = *(short *)(D_003BFF58 + *(unsigned char *)(s0 + 0x2F5) * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
}
