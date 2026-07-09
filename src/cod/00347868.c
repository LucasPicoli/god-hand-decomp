/* cygnus-2.96 matched TU. */

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error();
extern char D_00458F10[];
extern void func_00347E58(void *a0, int a1);
extern void Forward345D58_345D40(void *a0, int a1);
extern void func_00346100(void *a0);
extern void func_003358B8(int a0);
extern void func_00342FF8(void *a0);
extern void func_00327FA8(void *a0);
extern void func_00327E18(void *a0, int a1, int a2, int a3, int a4);
extern void func_00328448(void *a0, void *a1);
extern void func_0035EA30(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0035F5F0(void *a0, int a1, int a2, void *a3, int a4);

__attribute__((section(".text.func_00347868")))
void func_00347868(char *a0) {
    void *obj;
    void *vtable;
    void (*method)(void *);
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458F10);
        return;
    }
    func_00347E58(a0, 1);
    Forward345D58_345D40(a0, *(int *)(a0 + 0x1C0));
    func_00346100(a0);
    func_003358B8(*(int *)(a0 + 0x48));
    obj = *(void **)(a0 + 0x1BC);
    if (obj != 0) {
        vtable = *(void **)obj;
        method = *(void (**)(void *))((char *)vtable + 0x14);
        method(obj);
    }
    func_00342FF8(a0);
    *(int *)(a0 + 0x2D4) = 0;
}

__attribute__((section(".text.func_00349AD0")))
void func_00349AD0(void *a0, int a1, int a2, int a3, void *a4) {
    func_00327FA8(a0);
    func_00327E18(a0, a1, a2, a3, (int)a4);
    func_00328448(a0, a4);
}

__attribute__((section(".text.func_0035F578")))
int func_0035F578(void *a0, int a1, int a2, int *a3, int a4, int a5, int a6, int a7) {
    func_0035EA30(a0, a1, a4, a5, a6, a7);
    func_0035F5F0(a0, a1, a2, a3, 0);
    *a3 = 1;
    return 1;
}
