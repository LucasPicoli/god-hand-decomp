/* cygnus-2.96 matched TU. */

extern const char D_004551B8[];
extern const char D_004551D0[];
extern const char D_00455130[];
extern void func_00336980(void);
extern void Forward3A52F0_336588(void *hn);
extern void Forward33B658_3362E8(void);
extern void Forward33B670_336300(void);
extern const char D_00455110[];

__attribute__((section(".text.func_003369D0")))
int func_003369D0(signed char *hn)
{
    if (hn == 0) {
        func_00336330(hn, D_004551B8);
        return 0;
    }
    return hn[1];
}

__attribute__((section(".text.func_00336A08")))
int func_00336A08(int *hn)
{
    if (hn == 0) {
        func_00336330(hn, D_004551D0);
        return 0;
    }
    return hn[1];
}

__attribute__((section(".text.func_00336AC0")))
int func_00336AC0(int *hn)
{
    if (hn == 0) {
        func_00336330(hn, D_004551B8);
        return 0;
    }
    return hn[5];
}

__attribute__((section(".text.func_003367C0")))
int func_003367C0(int *hn)
{
    if (hn == 0) {
        func_00336330(hn, D_00455130);
        return 0;
    }
    return hn[4];
}

__attribute__((section(".text.mfCiClose")))
void mfCiClose(signed char *hn)
{
    if (hn == 0) return;
    func_00336980();
    if (hn[0] == 1) {
        hn[0] = 0;
        Forward3A52F0_336588(hn);
    }
}

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






__attribute__((section(".text.mfCiSeek")))
int mfCiSeek(MFH *hn, int off, int whence)
{
    int pos, len;
    if (hn == 0) {
        func_00336330(hn, D_00455110);
        return 0;
    }
    Forward33B658_3362E8();
    if (whence == 0) hn->f10 = off;
    else if (whence == 2) hn->f10 = hn->fC + off;
    else if (whence == 1) hn->f10 = hn->f10 + off;
    len = hn->fC;
    pos = hn->f10;
    if (pos >= len) pos = len;
    if (pos < 0) pos = 0;
    hn->f10 = pos;
    Forward33B670_336300();
    return hn->f10;
}
