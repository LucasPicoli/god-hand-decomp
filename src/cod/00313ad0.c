extern int D_00747A34;
extern unsigned char D_00754C10[];

__attribute__((section(".text.ForwardInitBuffer_313AD0")))
void *ForwardInitBuffer_313AD0(void) {
    void *s0;
    if (!(D_00747A34 & 0x10000)) {
        s0 = _MemoryAlloc(0x8A0, 0x10, D_00754C10);
        if (s0 != 0) {
            func_003A52F0(s0, 0, 0x8A0);
            return func_00186998(s0);
        }
    }
    return 0;
}

__attribute__((section(".text.ForwardInitBuffer_313B40")))
void *ForwardInitBuffer_313B40(void) {
    void *s0;
    if (!(D_00747A34 & 0x10000)) {
        s0 = _MemoryAlloc(0x920, 0x10, D_00754C10);
        if (s0 != 0) {
            func_003A52F0(s0, 0, 0x920);
            return func_00187750(s0);
        }
    }
    return 0;
}

__attribute__((section(".text.ForwardInitBuffer_313BB0")))
void *ForwardInitBuffer_313BB0(void) {
    void *s0;
    if (!(D_00747A34 & 0x10000)) {
        s0 = _MemoryAlloc(0x9E0, 0x10, D_00754C10);
        if (s0 != 0) {
            func_003A52F0(s0, 0, 0x9E0);
            return func_001879C8(s0);
        }
    }
    return 0;
}

__attribute__((section(".text.ForwardInitBuffer_313C20")))
int ForwardInitBuffer_313C20(void)
{
    void *s0;

    if (D_00747A34 & 0x10000)
        return 0;
    s0 = _MemoryAlloc(0x850, 0x10, D_00754C10);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0x850);
    return func_00187C88(s0);
}

__attribute__((section(".text.ForwardInitBuffer_313C90")))
int ForwardInitBuffer_313C90(void)
{
    void *s0;

    if (D_00747A34 & 0x10000)
        return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0x860);
    return func_00188A68(s0);
}

__attribute__((section(".text.ForwardInitBuffer_313D00")))
int ForwardInitBuffer_313D00(void)
{
    void *s0;

    if (D_00747A34 & 0x10000)
        return 0;
    s0 = _MemoryAlloc(0x920, 0x10, D_00754C10);
    if (s0 == 0)
        return 0;
    func_003A52F0(s0, 0, 0x920);
    return func_00188CF8(s0);
}
