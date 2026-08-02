/* cygnus-2.96 matched TU. */

extern void func_00326568(int a0);
extern void (*D_003EADB8)(void *, void *);
extern void *D_003EADBC;
extern char D_003EADC0[];

/* clone */


__attribute__((section(".text.func_00326830")))
void func_00326830(void *a0) {
    func_00326568(a0);
    *(char *)((char *)a0 + 0x1) = 1;
}

/* clone */





__attribute__((section(".text.func_0033F0F0")))
void func_0033F0F0(void) {
    func_003A52F0(D_003EADC0, 0, 0x100);
    D_003EADB8 = 0;
    D_003EADBC = 0;
}
