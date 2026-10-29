extern char D_00569B70[];
extern char D_005E85F8;
extern void cCoreSave_clearStateBit0(void *);
extern void SdeSystemOutModeSet(int);

__attribute__((section(".text.func_00167EB0")))
void func_00167EB0(void)
{
    cCoreSave_clearStateBit0(D_00569B70);
    SdeSystemOutModeSet(1);
    D_005E85F8 = 1;
}
