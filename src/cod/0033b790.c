/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern struct cb_0033b790 D_007588B0;
extern char D_003EADC0[];
extern void PrintfErrorReport(char *fmt, ...);
extern void (*D_003EADB8)(void *arg, char *p);
extern int strncat(char *dst, int src, int n);
extern void func_003B9DE0(void *a0);

struct cb_0033b790 { void (*fn)(void *arg, void *p); void *arg; };




__attribute__((section(".text.SVM_CallErr1")))
void SVM_CallErr1(int a0) {
    if (a0 == 0) {
        D_007588B0.fn(D_007588B0.arg, 0);
        return;
    }
    func_003A5DA0(D_003E9990, a0, 0x7F);
    if (D_007588B0.fn != 0)
        D_007588B0.fn(D_007588B0.arg, D_003E9990);
}

__attribute__((section(".text.func_0033F1A8")))
void func_0033F1A8(int a0, int a1) {
    if (a0 == 0 || a1 == 0) {
        PrintfErrorReport(D_00456930);
        return;
    }
    func_003A5DA0(D_003EADC0, a0, 0xFF);
    strncat(D_003EADC0, a1, 0xFF);
    if (D_003EADB8 != 0)
        D_003EADB8(D_003EADBC, D_003EADC0);
    PrintfErrorReport(D_003EADC0);
}

__attribute__((section(".text.AC3CNV_Stop")))
void AC3CNV_Stop(int a0) {
    if (a0 == 0) {
        func_003B9DE0(D_00460900);
        return;
    }
    *(int*)((char*)a0 + 4) = 0;
}
