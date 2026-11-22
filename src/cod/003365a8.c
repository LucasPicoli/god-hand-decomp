/* cygnus-2.96 matched TU. */

typedef struct {
    signed char f0;
    signed char f1;
    char pad2[2];
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    char f1C[4];
} MFH;



__attribute__((section(".text.mfci_reset_hn")))
void mfci_reset_hn(MFH *hn)
{
    int n;
    hn->f4 = 0x800;
    n = func_00336510(hn->f1C);
    hn->f8 = n;
    hn->fC = (n + hn->f4 - 1) / hn->f4;
    hn->f0 = 1;
    hn->f18 = 0;
    hn->f14 = 0;
    hn->f1 = 0;
    hn->f10 = 0;
}
