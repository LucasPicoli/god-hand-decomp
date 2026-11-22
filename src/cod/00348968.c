/* cygnus-2.96 matched TU. */

__attribute__((section(".text.MWSST_IsEnable")))
int MWSST_IsEnable(int *a0) {
    if (func_00348938(a0[1]) == 0) {
        return 0;
    }
    if (a0[0] != 1) {
        return 0;
    }
    return *(int*)((char*)a0 + 0x1C) != 0;
}
