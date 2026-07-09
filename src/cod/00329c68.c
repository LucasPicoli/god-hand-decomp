/* cygnus-2.96 matched TU. */

extern void NoOp_33E6A8(void);
extern void NoOp_33E6B0(void);
extern void func_0032AC48(void *o, float f, int a1, int a2);
extern void func_00328448(void *a0, void *a1);
extern void func_00329B60(void *a0, void *a1);
extern void *D_003D1404;
extern void func_00349738(int a0, int a1);
extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern char D_00458FD8[];
extern void func_00347908(void *a0, int a1);
extern void func_00347AA8(void *a0);

__attribute__((section(".text.func_0032ABE8")))
void func_0032ABE8(void *o, float f, int a1, int a2) {
    NoOp_33E6A8();
    func_0032AC48(o, f, a1, a2);
    NoOp_33E6B0();
}

__attribute__((section(".text.func_00329C68")))
void func_00329C68(void *o, int a1, int a2, int a3, int a4) {
    func_00328C80(*(int *)((char *)o + 8), *(short *)((char *)o + 0x3E) << 11, *(short *)((char *)o + 0x3C) << 11);
    func_00328448((void *)*(int *)((char *)o + 8), D_003D1404);
    func_003283E8(*(int *)((char *)o + 8), 0, 0);
    func_003280D8(*(int *)((char *)o + 8), 0);
    func_003282D0(*(int *)((char *)o + 8));
    func_00327FA8(*(int *)((char *)o + 8));
    func_00327E18(*(int *)((char *)o + 8), a1, a2, a3, a4);
    func_003281C8(*(int *)((char *)o + 8));
    func_00329B60(o, *(void **)((char *)o + 0x10));
}

__attribute__((section(".text.func_00348CE0")))
void func_00348CE0(int a0) {
    int i;
    for (i = 0; i < 10; i++) {
        func_00349738(a0, 1);
        func_00325F20();
        func_00349738(a0, 0);
        if (*(int *)(a0 + 0x60) != 1) break;
    }
}

__attribute__((section(".text.func_00347A40")))
void func_00347A40(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458FD8);
        return;
    }
    func_00347908(a0, 0);
    func_00347AA8(a0);
    *(int *)(a0 + 0x2E8) = 4;
}
