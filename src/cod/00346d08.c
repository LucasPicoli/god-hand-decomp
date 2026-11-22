/* cygnus-2.96 matched TU. */

extern void SetField_1_35FC58(int a0, int a1);

__attribute__((section(".text.mwsfsfx_DecideCompoMode")))
void mwsfsfx_DecideCompoMode(int *a0, int *a1) {
    int s1;
    if (a0[0x13] == 0) {
        int r = MWSFD_GetFxType(a0, a1[0xC]);
        if (r != -1)
            a0[0x14] = r;
        else
            a0[0x14] = 0x11;
        s1 = a0[0x14];
    } else {
        s1 = a0[0x13];
    }
    SetField_1_35FC58(func_00346C48(a0), s1);
}
