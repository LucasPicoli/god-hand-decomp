/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"
#include "godhand/cObj.h"

__attribute__((section(".text.func_00102728")))
void func_00102728(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 8) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BC770 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BC770 + i8 + 4);
    }
    f0 = *(short *)(D_003BC770 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_0010B6B0")))
void func_0010B6B0(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 71) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BD0F0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BD0F0 + i8 + 4);
    }
    f0 = *(short *)(D_003BD0F0 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_002777A8")))
void func_002777A8(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 5) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BFAD8 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFAD8 + i8 + 4);
    }
    f0 = *(short *)(D_003BFAD8 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_002785E0")))
void func_002785E0(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 6) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BFB18 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFB18 + i8 + 4);
    }
    f0 = *(short *)(D_003BFB18 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_0027BEF8")))
void func_0027BEF8(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 11) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BFE18 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFE18 + i8 + 4);
    }
    f0 = *(short *)(D_003BFE18 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_0027E348")))
void func_0027E348(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 2) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BFE88 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFE88 + i8 + 4);
    }
    f0 = *(short *)(D_003BFE88 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_0027F4C0")))
void func_0027F4C0(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 18) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BFEB0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFEB0 + i8 + 4);
    }
    f0 = *(short *)(D_003BFEB0 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}

__attribute__((section(".text.func_00281C60")))
void func_00281C60(void *a0) {
    cObj *s0 = a0;
    char *e;
    int i8;
    int f0;
    int type; int arg; int (*fp)(int); long entry;
    if (s0->phase >= 15) s0->phase = 0;
    i8 = s0->phase * 8;
    e = D_003BFF58 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)((char *)s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))(D_003BFF58 + i8 + 4);
    }
    f0 = *(short *)(D_003BFF58 + s0->phase * 8);
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)((char *)s0 + arg));
}
