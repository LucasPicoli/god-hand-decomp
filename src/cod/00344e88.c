/* cygnus-2.96 matched TU. */

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern char D_00457918[];
extern void func_003448B0(int a0, int a1);

/* MATCH via cygnus-2.96. */






__attribute__((section(".text.func_00344E88")))
int func_00344E88(int a0, int a1) {
    if (GetField0OrZero_346828(a0) != 1) {
        return MWSFSVM_Error(D_00457918);
    }
    func_003448B0(a0, 2);
    return func_00359168(func_003466F8(a0), a1);
}
