/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void (*D_003EADB8)(void *, void *);
extern char D_003EADC0;
extern void PrintfErrorReport(char *fmt, ...);

__attribute__((section(".text.func_0033F130")))
void func_0033F130(void *a0) {
    if (a0 == 0) {
        PrintfErrorReport(D_00456930);
        return;
    }
    func_003A5DA0(&D_003EADC0, a0, 0xFF);
    if (D_003EADB8 != 0) D_003EADB8(D_003EADBC, &D_003EADC0);
    PrintfErrorReport(&D_003EADC0);
}
