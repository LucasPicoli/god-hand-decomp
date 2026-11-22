/* SN ProDG ee-gcc 2.95.3: func_00378C48, idle actor step: toggles the blink bit when flag 4 is set, otherwise
 * runs the think/move sequence. */
extern int IsActorActiveOrReady_379EC0(char *a);
extern void func_0037A1F0(char *a);
extern int func_0037A4C8(char *a);
extern int SdeTblTestParaMove(char *a);
extern int SdeTblTestParaChange(char *a);
extern void func_0037A298(char *a);

__attribute__((section(".text.func_00378C48")))
void func_00378C48(char *a)
{
    int r;

    if (IsActorActiveOrReady_379EC0(a) != 0)
        return;
    if (*(int *)(a + 0x34) & 4) {
        a[6] ^= 1;
        return;
    }
    func_0037A1F0(a);
    r = func_0037A4C8(a);
    if (*(signed char *)(a + 6) == 0 && r == 0 && SdeTblTestParaMove(a) == 0)
        SdeTblTestParaChange(a);
    func_0037A298(a);
}
