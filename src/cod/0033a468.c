/* cygnus-2.96 matched TU. */

extern void func_0033A048(void *a0, void *a1);
extern int D_00455C48;
extern int D_00455BD8;
extern int D_00455C58;
extern int D_00455C08;

__attribute__((section(".text.func_0033A468")))
void func_0033A468(char *a0, int a1, int a2)
{
    if (a0 == 0) {
        func_0033A048(&D_00455C48, &D_00455BD8);
        return;
    }
    if (a0[4] == 0) {
        func_0033A048(&D_00455C58, &D_00455C08);
        return;
    }
    *(int *)(a0 + 0x28) = a1;
    *(int *)(a0 + 0x2C) = a2;
}
