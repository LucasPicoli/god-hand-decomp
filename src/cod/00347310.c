/* cygnus-2.96 matched TU. */

extern int MWSFSVM_Error(char *a0);
extern void Forward3443E0_3443C8(void *a0);
extern char D_00458C68[];

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.func_0034E460")))
int func_0034E460(int a0, int a1) {
    int r = func_0034C390(a0, *(int *)((char *)a0 + 0x1F84), a1);
    if (r == 0) {
        *(int *)((char *)a0 + 0x37A8) += a1;
    }
    return r;
}

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.func_00347310")))
int func_00347310(char *a0) {
    int y;
    if (func_003472E8(a0 + 8) != 1)
        return 0;
    y = func_003395A0(*(int *)(a0 + 0x180), *(int *)(a0 + 0x184), 0);
    if (y != 0)
        return y;
    MWSFSVM_Error(D_00458C68);
    Forward3443E0_3443C8(a0);
    return 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.func_00348550")))
void func_00348550(char *a0, int a1) {
    void *obj, *arg;
    void (*f)(void *, int);
    if (func_00348968(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg = *(void **)(a0 + 0x1C);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x24);
    if (f == 0) return;
    f(arg, a1);
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.func_003485B0")))
void func_003485B0(char *a0, int a1) {
    void *obj, *arg;
    void (*f)(void *, int);
    if (func_00348968(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg = *(void **)(a0 + 0x1C);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x28);
    if (f == 0) return;
    f(arg, a1);
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.func_00348610")))
void func_00348610(char *a0, int a1) {
    void *obj, *arg;
    void (*f)(void *, int);
    if (func_00348968(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg = *(void **)(a0 + 0x1C);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x30);
    if (f == 0) return;
    f(arg, a1);
}
