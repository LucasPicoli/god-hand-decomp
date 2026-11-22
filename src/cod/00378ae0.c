/* sn-2.95.3-136: func_00378AE0, actor update step when the actor is idle. */
extern int func_00378B58(void *self);
extern int IsActorActiveOrReady_379EC0(void *self);
extern void func_0037A1F0(void *self);
extern int func_0037A4C8(void *self);
extern int SdeTblTestParaMove(void *self);
extern int SdeTblTestParaChange(void *self);
extern void func_0037A298(void *self);

__attribute__((section(".text.func_00378AE0")))
void func_00378AE0(void *self)
{
    if (func_00378B58(self) != 0 || IsActorActiveOrReady_379EC0(self) != 0)
        return;
    func_0037A1F0(self);
    if (func_0037A4C8(self) == 0 && SdeTblTestParaMove(self) == 0)
        SdeTblTestParaChange(self);
    func_0037A298(self);
}
