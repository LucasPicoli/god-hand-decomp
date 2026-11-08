extern void func_00378C48(void *);
extern void func_0037B0E0(void *);
extern void DebugPage_printRecordRows(void *);
extern void func_00379BC0(void *);

__attribute__((section(".text.func_00378BF8")))
void func_00378BF8(char *self)
{
    func_00378C48(self);
    func_0037B0E0(self);
    if (self[6] == 0)
        DebugPage_printRecordRows(self);
    else
        func_00379BC0(self);
}
