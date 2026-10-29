extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardInitBuffer_314C50")))
int ForwardInitBuffer_314C50(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8C0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8C0);
    return func_0019A998(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314CC0")))
int ForwardInitBuffer_314CC0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8C0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8C0);
    return func_0019AC18(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314D30")))
int ForwardInitBuffer_314D30(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xAA0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xAA0);
    return func_0019AE98(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314DA0")))
int ForwardInitBuffer_314DA0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xAA0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xAA0);
    return func_0019BBB8(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314E10")))
int ForwardInitBuffer_314E10(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x920, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x920);
    return func_0019BE28(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314E80")))
int ForwardInitBuffer_314E80(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return func_0019C118(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314EF0")))
int ForwardInitBuffer_314EF0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8F0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8F0);
    return func_0019C320(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314F60")))
int ForwardInitBuffer_314F60(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8A0);
    return func_0019C588(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314FD0")))
int ForwardInitBuffer_314FD0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8F0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8F0);
    return InitObjVu0Fields_19D340(s0);
}

__attribute__((section(".text.ForwardInitObjVtableBuffer_315040")))
int ForwardInitObjVtableBuffer_315040(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitObjVtable_19D5A8(s0);
}
