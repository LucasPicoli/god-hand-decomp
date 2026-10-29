extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardInitBuffer_313D70")))
int ForwardInitBuffer_313D70(void)
{
    void *s0;

    if (D_00747A34 & 0x10000)
        return 0;
    s0 = _MemoryAlloc(0xCE0, 0x10, D_00754C10);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0xCE0);
    return func_00188F80(s0);
}

__attribute__((section(".text.ForwardInitBuffer_313DE0")))
int ForwardInitBuffer_313DE0(void)
{
    void *s0;

    if (D_00747A34 & 0x10000)
        return 0;
    s0 = _MemoryAlloc(0x910, 0x10, D_00754C10);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0x910);
    return func_0018A598(s0);
}

__attribute__((section(".text.ForwardInitBuffer_313EC0")))
int ForwardInitBuffer_313EC0(void)
{
    void *s0;

    if (D_00747A34 & 0x10000)
        return 0;
    s0 = _MemoryAlloc(0x9C0, 0x10, D_00754C10);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0x9C0);
    return func_0018C098(s0);
}
