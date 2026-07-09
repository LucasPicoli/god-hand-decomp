/* cygnus-2.96 matched TU. */

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern char D_00458038[];
extern void func_003497F8(int a0);
extern void func_00345DF0(void *a0);
extern void func_00345BE0(void *a0);
extern void func_00342FF8(void *a0);
extern char D_00458110[];
extern void Forward345D58_345D40(void *a0, int a1);
extern void func_00346228(void *a0, int a1, int a2);
extern char D_00458628[];
extern void func_0036CA38(void *a0, int a1);
extern void func_003485B0(void *a0, int a1);

/* MATCH via cygnus-2.96. */







__attribute__((section(".text.func_00345D58")))
void func_00345D58(char *a0, int a1) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458038);
        return;
    }
    func_003497F8(1);
    func_00345DF0(a0);
    *(int *)(a0 + 0x1BC) = a1;
    *(int *)(a0 + 0x1D4) = 0;
    *(int *)(a0 + 0x1D0) = 2;
    *(int *)(a0 + 0x1D8) = 0;
    *(int *)(a0 + 0x1DC) = 0;
    func_00345BE0(a0);
    func_003497F8(0);
    func_00342FF8(a0);
}

/* MATCH via cygnus-2.96. */






__attribute__((section(".text.func_00346078")))
void func_00346078(int a0, int a1, int a2) {
    if (GetField0OrZero_346828((void *)a0) != 1) {
        MWSFSVM_Error(D_00458110);
        return;
    }
    Forward345D58_345D40((void *)a0, func_00346AE8((void *)a0));
    func_00346228((void *)a0, a1, a2);
}

/* MATCH via cygnus-2.96. */





__attribute__((section(".text.func_00346A48")))
void func_00346A48(char *a0, int a1) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458628);
        return;
    }
    func_0036CA38(a0, a1);
    func_003485B0(a0 + 0x284, a1);
    func_003485B0(a0 + 0x2A4, a1);
}
