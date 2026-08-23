/* sn-2.95.3-136 matched TU. */

extern int D_00747A78;
extern int D_00755800;
extern int D_00755804;
extern char *D_00755840;
extern char D_00747A50[];
extern char D_005864F0[];

/* compiler: sn-2.95.3-136 ; extra keys: none */





__attribute__((section(".text.func_0031BDC8")))
void func_0031BDC8(char *a0) {
    int i;
    char *d;
    long t;
    t = D_00747A78;
    if (!(((unsigned long)t >> 5) & 1)) {
        return;
    }
    d = a0 + 0x100;
    for (i = 0; i < 0x20; i++) {
        *(char *)(d + i) = *(unsigned char *)((D_00755800 << 5) + (int)D_00755840 + i);
    }
    D_00755800 = D_00755800 + 1;
    if (D_00755800 < D_00755804) {
        return;
    }
    D_00747A78 = D_00747A78 & ~0x20;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */



__attribute__((section(".text.func_00274F50")))
int func_00274F50(char *a0) {
    char *g;
    char *p;
    if ((*(int *)(a0 + 0x564) ^ 0x21C) != 0) {
        return 0;
    }
    if (*(unsigned short *)D_00747A50 != 0x403) {
        return 0;
    }
    if (0.0f < *(float *)(a0 + 0x1748)) {
        return 0;
    }
    g = D_005864F0;
    p = *(char **)(g + 0x56C);
    if (p == 0) {
        return 0;
    }
    if (*(short *)(p + 0x54A) <= 0) {
        return 0;
    }
    p = *(char **)(g + 0x568);
    if (p == 0) {
        return 0;
    }
    if (*(short *)(p + 0x54A) <= 0) {
        return 0;
    }
    *(char *)(a0 + 0x2F7) = 0;
    *(char *)(a0 + 0x2F4) = 0;
    *(char *)(a0 + 0x2F6) = 0;
    *(char *)(a0 + 0x2F5) = 0x7A;
    return 1;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00133408")))
int func_00133408(void *unused, float *a1, float *a2, float *a3, float *t0) {
    if (a2[0] < a3[0]) goto ret0;
    if (!(a1[0] > t0[0])) goto cont;
ret0:
    return 0;
cont:
    if (a2[2] < a3[2]) goto ret0;
    if (a1[2] > t0[2]) goto ret0;
    if (a2[1] < a3[1]) goto ret0;
    if (a1[1] > t0[1]) goto ret0;
    return 1;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00135250")))
int func_00135250(void *unused, float *a1, float *a2, float *a3, float *t0) {
    if (a2[0] < a3[0]) goto ret0;
    if (!(a1[0] > t0[0])) goto cont;
ret0:
    return 0;
cont:
    if (a2[2] < a3[2]) goto ret0;
    if (a1[2] > t0[2]) goto ret0;
    if (a2[1] < a3[1]) goto ret0;
    if (a1[1] > t0[1]) goto ret0;
    return 1;
}
