/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cScenario.h"

extern char D_00754C58[];
extern int D_00747A78;
extern void func_00319520(int);
extern void *cObjBaseArray_SearchOM(char *arr, long mask);

__attribute__((section(".text.cScenario_runExitFunc")))
/* Run exitFunc(exitArg) once. */
void cScenario_runExitFunc(cScenario *self) {
    void (*fp)(void *) = self->exitFunc;
    if (fp != 0) {
        fp(self->exitArg);
        self->exitFunc = 0;
    }
}

__attribute__((section(".text.cScenario_isOmBreak_2C51E8")))
/* isOmBreak for the object with this packed name. */
int cScenario_isOmBreak_2C51E8(cScenario *self, long name) {
    return cScenario_isOmBreak(self, cObjBaseArray_SearchOM(D_00754C58, name));
}

__attribute__((section(".text.ForwardListEntries_2C5470")))
void ForwardListEntries_2C5470(int **a0) {
    int *s0;
    if (D_00747A78 & 0x08000000) return;
    for (s0 = (int *)(*a0)[1]; s0 < (int *)(*a0)[2]; s0++) {
        func_00319520(*s0);
    }
}
