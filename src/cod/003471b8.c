/* cygnus-2.96 matched TU. */

extern void SetField_1_35FC58(int, int);
extern void SFTRN_CallTrSetup(int, int);

__attribute__((section(".text.MWSFSFX_SetCompoMode")))
void MWSFSFX_SetCompoMode(int a0, int a1) {
    int r = func_00346C48(a0, a1);
    SetField_1_35FC58(r, a1);
}

__attribute__((section(".text.sfply_TrDestroy")))
void sfply_TrDestroy(int a0) {
    *(int *)(a0 + 0x48) = 0;
    *(int *)(a0 + 0x4C) = 0;
    SFTRN_CallTrSetup(a0, 4);
}
