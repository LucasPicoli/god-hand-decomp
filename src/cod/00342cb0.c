/* cygnus-2.96 matched TU. */

struct S_mwsf { int f0, f4, f8, fC; };

__attribute__((section(".text.mwsfcre_CalcFrmRes")))
void mwsfcre_CalcFrmRes(struct S_mwsf *a0, int *a1, int *a2, int *a3, int *t0) {
    int t2 = a0->f8;
    int t3 = a0->fC;
    int v1 = t2 / 2;
    *a3 = ((v1 + 31) / 32) * 32;
    *t0 = t3 / 2;
    *a1 = t2;
    *a2 = t3;
}
