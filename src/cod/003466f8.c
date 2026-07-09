/* cygnus-2.96 matched TU. */

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern char D_00458238[];
extern char D_00458758[];
extern void func_00349840(int a0);
extern int Forward349480_349468(int a0);

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.func_003466F8")))
int func_003466F8(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458238);
        return 0;
    }
    return *(int *)(a0 + 0x3C);
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.func_00346AE8")))
int func_00346AE8(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458758);
        return 0;
    }
    return *(int *)(a0 + 0x1C0);
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.func_00349250")))
int func_00349250(int a0) {
    int r;
    int c;
    func_00349840(a0);
    c = func_003492E8();
    r = 0;
    if (c == 1) {
        r = Forward349480_349468(a0);
    }
    return r;
}
