/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char D_00754C58[];
extern int D_00747A78;
extern void func_00319520(int);
extern void *cObjBaseArray_SearchOM(char *arr, long mask);
extern int cScenario_isOmBreak(int a0, void *om);

__attribute__((section(".text.ForwardStoredCallback_2C4DE0")))
void ForwardStoredCallback_2C4DE0(void *a0) {
    void (*fp)(int) = *(void(**)(int))((char*)a0 + 0xF4);
    if (fp != 0) {
        fp(*(int*)((char*)a0 + 0xF8));
        *(int*)((char*)a0 + 0xF4) = 0;
    }
}

__attribute__((section(".text.Forward2C5110_2C51E8")))
int Forward2C5110_2C51E8(int a0, long mask) {
    return cScenario_isOmBreak(a0, cObjBaseArray_SearchOM(D_00754C58, mask));
}

__attribute__((section(".text.ForwardListEntries_2C5470")))
void ForwardListEntries_2C5470(int **a0) {
    int *s0;
    if (D_00747A78 & 0x08000000) return;
    for (s0 = (int *)(*a0)[1]; s0 < (int *)(*a0)[2]; s0++) {
        func_00319520(*s0);
    }
}
