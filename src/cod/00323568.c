/* cygnus-2.96 matched TU. */

extern void Tramp_003302B0_003302E0(void *a0);
extern void func_00330910(void *a0);
extern char D_004532D8[];
extern char D_004532F8[];
extern void func_00327F00(int a0, int a1, int a2, int a3, int t0);
extern void func_00328018(int a0);
extern void func_0033F130(int a0);
extern char D_00451658[];
extern char D_00452060[];
extern int D_003D1420;
extern void func_00326860(int *a0);
extern void func_00327FA8(int a0);
extern void func_00335950(int a0);
extern void func_00329E08(void *a0);
extern char D_004531C8[];
extern char D_004531F0[];
extern unsigned int strlen(const char *a0);
extern void toUpperStr(char *a0);
extern int isExistDev(char *a0, int a1);
extern char D_00756080[];
extern void func_003A5148(char *a0, char *a1, int a2);

__attribute__((section(".text.func_00330AD0")))
void func_00330AD0(void *a0) {
    void (*fn)(int);
    if (a0 == 0) {
        Tramp_003302B0_003302E0(D_004532D8);
        return;
    }
    fn = (void (*)(int))(*(int **)a0)[5];
    if (fn != 0) {
        fn(*(int *)((char *)a0 + 4));
        func_00330910(a0);
        return;
    }
    Tramp_003302B0_003302E0(D_004532F8);
}

__attribute__((section(".text.func_00323700")))
int func_00323700(void *a0, int a1, int a2, int a3, int t0) {
    *(int *)((char *)a0 + 0x34) = a2;
    *(int *)((char *)a0 + 0x30) = a3;
    *(int *)((char *)a0 + 0x38) = a1;
    *(int *)((char *)a0 + 0x3C) = a3;
    *(int *)((char *)a0 + 0x40) = t0;
    *(int *)((char *)a0 + 0x14) = 0;
    func_00327F00(*(int *)((char *)a0 + 4), a1, a2, a3, t0);
    if (func_00328098(*(int *)((char *)a0 + 4)) == 4) {
        func_00328018(*(int *)((char *)a0 + 4));
        return -1;
    }
    *(int *)((char *)a0 + 0xC) = t0;
    *(int *)((char *)a0 + 0x10) = t0 << 11;
    return 0;
}

__attribute__((section(".text.func_00323568")))
int func_00323568(void *a0, int a1, int a2) {
    if (a1 == 0) {
        func_0033F130((int)D_00451658);
        return -1;
    }
    *(int *)((char *)a0 + 0x34) = a2;
    *(int *)((char *)a0 + 0x38) = a1;
    *(int *)((char *)a0 + 0x14) = 0;
    func_00327F00(*(int *)((char *)a0 + 4), a1, a2, 0, 0xFFFFF);
    if (func_00328098(*(int *)((char *)a0 + 4)) == 4) {
        func_00328018(*(int *)((char *)a0 + 4));
        return -1;
    }
    {
        int d40 = func_00328D40(*(int *)((char *)a0 + 4));
        int d80;
        *(int *)((char *)a0 + 0x10) = d40;
        d80 = func_00328D80(*(int *)((char *)a0 + 4));
        *(int *)((char *)a0 + 0x3C) = 0;
        *(int *)((char *)a0 + 0xC) = d80;
        *(int *)((char *)a0 + 0x40) = d80;
        return 0;
    }
}

__attribute__((section(".text.func_00329ED8")))
void func_00329ED8(void *a0) {
    if (a0 == 0) {
        func_0033F130((int)D_00452060);
        return;
    }
    if (D_003D1420 != 0) {
        func_00326860(*(int **)((char *)a0 + 4));
        (*(void (*)(void *))D_003D1420)(a0);
    }
    if (*(int *)((char *)a0 + 8) != 0)
        func_00327FA8(*(int *)((char *)a0 + 8));
    if (*(signed char *)((char *)a0 + 2) == 4) {
        func_00335950(*(int *)((char *)a0 + 0x94));
        {
            void *o = *(void **)((char *)a0 + 0x14);
            if (o != 0)
                (*(void (**)(void *))(*(char **)o + 0x14))(o);
        }
    }
    func_00329E08(a0);
}

__attribute__((section(".text.func_00330580")))
void func_00330580(char *a0) {
    int len;
    if (a0 == 0) {
        Tramp_003302B0_003302E0(D_004531C8);
        return;
    }
    len = strlen(a0);
    if (len == 0) {
        D_00756080[0] = 0;
        return;
    }
    toUpperStr(a0);
    if (isExistDev(a0, len) == 1) {
        func_003A5148(D_00756080, a0, len + 1);
        return;
    }
    Tramp_003302B0_003302E0(D_004531F0);
}
