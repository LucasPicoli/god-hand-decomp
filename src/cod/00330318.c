/* cygnus-2.96 matched TU. */

extern void Tramp_003302B0_003302E0(const char *msg);
extern void func_003302B0(void);
extern volatile int D_003D8400;
extern const char D_00453128[], D_00453150[], D_00453178[];
extern void func_00330920(char *path, char *dev, char *fname);
extern void func_00330910(int *hn);
extern char *variousProc(char *path, char *dev, char *fname);
extern const char D_00453218[], D_00453238[], D_00453280[];
extern const char D_004532A0[], D_004532B8[];
extern void func_00334008(void *hn, const char *msg);
extern void *SRD_Create(void);
extern void htci_zero_padding(void *hn);
extern int SRD_ReqRdHst(void *srd, int a, int b, long long n, void *buf);
extern void func_00331BF0(void);
extern void func_00331AD8(void);
extern void func_00331070(void *srd);
extern int D_003DA390;
extern const char D_00454960[], D_00454978[], D_00454998[];

typedef void (*CVFS_INITFN)(void (*)(void), int);

__attribute__((section(".text.func_00330318")))
void func_00330318(char *name, void *openfn)
{
    int *dev;
    CVFS_INITFN initfn;
    int unused = D_003D8400;

    if (name == 0) {
        Tramp_003302B0_003302E0(D_00453128);
        return;
    }
    if (openfn == 0) {
        Tramp_003302B0_003302E0(D_00453150);
        return;
    }
    dev = func_003303A8(name, openfn);
    if (dev == 0) {
        Tramp_003302B0_003302E0(D_00453178);
        return;
    }
    initfn = (CVFS_INITFN)dev[1];
    if (initfn != 0) {
        initfn(func_003302B0, 0);
    }
}

__attribute__((section(".text.func_00330780")))
int *func_00330780(char *fname, int mode, int arg)
{
    char path[304];
    char dev[304];
    int *hn;
    int *dv;
    int (*openfn)(char *, int, int);

    if (fname == 0) {
        Tramp_003302B0_003302E0(D_00453218);
        return 0;
    }
    func_00330920(path, dev, fname);
    if (dev[0] == 0) {
        Tramp_003302B0_003302E0(D_00453218);
        return 0;
    }
    hn = func_003308A8();
    if (hn == 0) {
        Tramp_003302B0_003302E0(D_00453238);
        return 0;
    }
    dv = (int *)variousProc(path, dev, fname);
    hn[0] = (int)dv;
    if (dv == 0) {
        func_00330910(hn);
        Tramp_003302B0_003302E0(D_00453280);
        return 0;
    }
    openfn = (int (*)(char *, int, int))dv[4];
    if (openfn != 0) {
        hn[1] = openfn(dev, mode, arg);
    } else {
        func_00330910(hn);
        Tramp_003302B0_003302E0(D_004532A0);
        return 0;
    }
    if (hn[1] == 0) {
        func_00330910(hn);
        Tramp_003302B0_003302E0(D_004532B8);
        return 0;
    }
    return hn;
}

struct HTCI_RD {
    char pad0[2];
    signed char stat;
    char pad3[5];
    long long fsize;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    void *f2C;
};

__attribute__((section(".text.func_00334808")))
int func_00334808(struct HTCI_RD *hn, int nsct, void *buf)
{
    long long lim;
    int n;
    int d;
    int mode;

    if (hn == 0) { func_00334008(hn, D_00454960); return 0; }
    if (nsct < 0) { func_00334008(hn, D_00454978); return 0; }
    if (buf == 0) { func_00334008(hn, D_00454998); return 0; }
    if (func_00334038(hn) == 1) return 0;
    if (hn->stat == 2) return 0;
    if (nsct == 0) {
        hn->stat = 1;
        return 0;
    }
    hn->f2C = SRD_Create();
    if (hn->f2C == 0) return 0;
    hn->f20 = (int)buf;
    d = hn->f10 - hn->f1C;
    n = (nsct < d) ? nsct : d;
    hn->f24 = n;
    lim = (long long)(nsct << 11);
    if ((unsigned long long)hn->fsize < (unsigned long long)lim) lim = hn->fsize;
    htci_zero_padding(hn);
    if (SRD_ReqRdHst(hn->f2C, hn->f18, hn->f1C, lim, buf) == 0) return 0;
    mode = D_003DA390;
    if (mode == 1) {
        func_00331BF0();
        func_00331AD8();
        hn->f1C = hn->f1C + hn->f24;
        func_00331070(hn->f2C);
        hn->f2C = 0;
        hn->stat = mode;
        hn->f28 = hn->f24;
    } else {
        hn->stat = 2;
        hn->f28 = 0;
    }
    hn->f14 = 0;
    return hn->f24;
}
