/* cygnus-2.96 matched TU. */

extern int Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920(int a0);

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.func_00348498")))
void func_00348498(char *a0) {
    void *x, *obj;
    void (*f)(void *);
    if (func_00348968(a0) != 1) return;
    x = *(void **)(a0 + 0x1C);
    obj = *(void **)(a0 + 0x8);
    if (x == 0) return;
    if (obj == 0) return;
    f = *(void (**)(void *))((char *)obj + 0x18);
    if (f == 0) return;
    f(x);
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.func_00348440")))
void func_00348440(char *a0) {
    void *obj, *arg0;
    int arg1;
    void (*f)(void *, int);
    if (func_00348968(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg0 = *(void **)(a0 + 0x1C);
    arg1 = *(int *)(a0 + 0x14);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x14);
    if (f == 0) return;
    f(arg0, arg1);
}

/* MATCH via cygnus-2.96 +drop-freorder. */


__attribute__((section(".text.func_00348258")))
void func_00348258(int a0) {
    char *ptr1 = (char *)Obj0000_Get_Ptr_D_003EE088_Scaled_8_348920(a0);
    char *ptr2 = (char *)func_00348938(a0);
    void (*method)(void);
    if (ptr2 == 0) return;
    if (*(int *)(ptr1 + 0x4) != 0) return;
    method = *(void (**)(void))(ptr2 + 0x0);
    if (method != 0) {
        method();
    }
    *(int *)(ptr1 + 0x4) = *(int *)(ptr1 + 0x4) + 1;
}
