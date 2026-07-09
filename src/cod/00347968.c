/* cygnus-2.96 matched TU. */

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error();
extern char D_00459110[];
extern void func_003461B0(void *a0, int a1);
extern void func_00335950(int a0);
extern void func_00347C80(void *a0, int a1, int a2, int a3);
extern void func_00347908(void *a0, int a1);
extern void func_00347868(void *a0);
extern char D_00458F78[];
extern char D_00458FA8[];
extern void func_003477A8(void *a0, int a1);
extern char D_004590A8[];
extern void func_00347AF8(void *a0, int a1, int a2);

__attribute__((section(".text.func_00347D08")))
void func_00347D08(char *a0, int a1, int a2, int a3) {
    int r = GetField0OrZero_346828(a0);
    if (r != 1) {
        MWSFSVM_Error(D_00459110);
        return;
    }
    func_003461B0(a0, a1);
    func_00335950(*(int *)(a0 + 0x48));
    func_00347C80(a0, a1, a2, a3);
    func_00347908(a0, 1);
    func_00347868(a0);
    *(int *)(a0 + 0x2E4) = 3;
    *(int *)(a0 + 0x2F4) = a2;
    *(int *)(a0 + 0x2F8) = a3;
    *(int *)(a0 + 0x2DC) = r;
    if (*(int *)(a0 + 0x2E0) == 0) {
        *(int *)(a0 + 0x2E8) = r;
    }
}

__attribute__((section(".text.func_00347968")))
void func_00347968(char *a0, int a1) {
    int r = GetField0OrZero_346828(a0);
    if (r != 1) {
        MWSFSVM_Error(D_00458F78);
        return;
    }
    if (a1 == 0) {
        MWSFSVM_Error(D_00458FA8);
        return;
    }
    func_003461B0(a0, a1);
    func_00335950(*(int *)(a0 + 0x48));
    func_003477A8(a0, *(int *)(a0 + 0x1A4));
    func_00347908(a0, 1);
    func_00347868(a0);
    *(int *)(a0 + 0x2E4) = r;
    *(int *)(a0 + 0x2DC) = r;
    if (*(int *)(a0 + 0x2E0) == 0) {
        *(int *)(a0 + 0x2E8) = r;
    }
}

__attribute__((section(".text.func_00347BC0")))
void func_00347BC0(char *a0, int a1, int a2) {
    int r = GetField0OrZero_346828(a0);
    if (r != 1) {
        MWSFSVM_Error(D_004590A8);
        return;
    }
    func_00335950(*(int *)(a0 + 0x48));
    func_00347AF8(a0, a1, a2);
    func_00347908(a0, 1);
    func_00347868(a0);
    *(int *)(a0 + 0x2E4) = 2;
    *(int *)(a0 + 0x2EC) = a1;
    *(int *)(a0 + 0x2F0) = a2;
    *(int *)(a0 + 0x2DC) = r;
    if (*(int *)(a0 + 0x2E0) == 0) {
        *(int *)(a0 + 0x2E8) = r;
    }
}
