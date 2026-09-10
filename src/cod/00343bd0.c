/* cygnus-2.96 matched TU. */

extern void func_00345750(int e);
extern void MWSFSVM_Error(char *s);
extern char D_004573B8[];

__attribute__((section(".text.MWSFCRE_DestroySfd")))
void MWSFCRE_DestroySfd(void)
{
    if (func_003587E8() == 0) return;
    func_00345750(-0x132);
    MWSFSVM_Error(D_004573B8);
}
