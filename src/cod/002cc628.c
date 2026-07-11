/* sn-2.95.3-136 matched TU. */

extern void SetSequenceBlendWeight_3739A0(void *a0, int a1, float f);
extern void func_002CCBF8(void *a0);
extern void func_002CCD80(void *a0);
extern void func_002CD1D0(void *a0);
extern void func_002CD310(void *a0);
extern void func_00372CB0(void *a0);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */












__attribute__((section(".text.func_002CC628")))
void func_002CC628(void *a0) {
    char *s0 = (char *)a0;
    int i;
    if (func_002CC568(a0) != 0) {
        if (func_00373A50(s0) == 1) {
            char *p = (char *)&D_005FEE00;
            for (i = 0; i < func_00373B30(s0); i++)
                SetSequenceBlendWeight_3739A0(s0, 0, *(float *)(p + 0x6C));
        }
        switch (*(int *)(s0 + 0x94)) {
        case 3:
            func_002CCBF8(s0);
            break;
        case 2:
            func_002CCD80(s0);
            break;
        case 1:
        case 5:
            func_002CD1D0(s0);
            break;
        case 4:
            func_002CD310(s0);
            break;
        case 0:
        default:
            break;
        }
        *(int *)(s0 + 0x98) = *(int *)(s0 + 0x98) & 0xFFFFFFFB;
        func_00372CB0(s0);
    }
}
