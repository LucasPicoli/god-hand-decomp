/* cygnus-2.96 matched TU. */

extern void func_003282D0(void *a0);
extern void func_0033F590(void);
extern void func_00335950(void);
extern void func_003A52F0(void *a0, int a1, int a2);
extern int GetField0OrZero_346828(int a0);
extern int MWSFSVM_Error(char *a0, int a1);
extern char D_00459008[];
extern void func_0034DD70(int a0, unsigned int a1);
extern void Thunk_func_0033B658(void *a0);
extern void Thunk_func_0033B670(void *a0);

__attribute__((section(".text.func_00322C18")))
int func_00322C18(int a0, int a1, int a2, int a3, int t0, int t1) {
    return func_00322C68(a0, 0, 0, a1, a2, 0, 0xFFFFF, a3, t0, t1, 1);
}

__attribute__((section(".text.func_00328398")))
void func_00328398(void *a0) {
    func_003282D0(a0);
    do {
        func_0033F590();
    } while (*(char *)((char *)a0 + 1) != 1 || *(int *)((char *)a0 + 0x24) != 0);
}

__attribute__((section(".text.func_00335530")))
void func_00335530(void *a0) {
    if (a0 != 0) {
        func_00335950();
        *(char *)a0 = 0;
        func_003A52F0(a0, 0, 0x238);
    }
}

__attribute__((section(".text.func_00347AA8")))
int func_00347AA8(int a0) {
    if (GetField0OrZero_346828(a0) == 1) {
        return func_00347E58(a0, 0);
    }
    return MWSFSVM_Error(D_00459008, 0);
}

__attribute__((section(".text.func_0034FE90")))
void func_0034FE90(int a0) {
    if (Tramp_MPS_Destroy_34FEE0(**(int**)((char*)a0+0x1F7C))) {
        func_0034DD70(a0, 0xFF000D0A);
    }
}

__attribute__((section(".text.func_0035B568")))
void func_0035B568(char *a0) {
    char local[0x10];
    int *s0 = (int*)(a0 + 0xD30);
    int s1 = func_0036C920(s0[0x2E0/4]);
    Thunk_func_0033B658(local);
    s0[0x2DC/4] = s0[0x2DC/4] + s1;
    Thunk_func_0033B670(local);
}
