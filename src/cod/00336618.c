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



extern void func_003A57C4(char *dst, const char *src);
extern void func_003365A8(MFH *hn);
extern const char D_00455090[];
extern const char D_004550B8[];
extern const char D_004550E0[];

__attribute__((section(".text.mfCiOpen")))
MFH *mfCiOpen(const char *fname, int a1, int a2)
{
    MFH *hn;
    if (fname == 0) {
        func_00336330((void *)fname, D_00455090);
        return 0;
    }
    if (a2 != 0) {
        func_00336330(0, D_004550B8);
        return 0;
    }
    hn = func_00336530();
    if (hn == 0) {
        func_00336330(0, D_004550E0);
        return 0;
    }
    func_003A57C4(hn->f1C, fname);
    func_003365A8(hn);
    return hn;
}
