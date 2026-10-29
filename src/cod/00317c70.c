extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.AllocInitObj1835A0_317C70")))
int AllocInitObj1835A0_317C70(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x680, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x680);
    return func_001835A0(s0);
}

__attribute__((section(".text.AllocInitObj183848_317CE0")))
int AllocInitObj183848_317CE0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x1CC0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x1CC0);
    return func_00183848(s0);
}

__attribute__((section(".text.AllocInitObj3184E0_317F00")))
int AllocInitObj3184E0_317F00(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x4E0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x4E0);
    return func_003184E0(s0);
}
