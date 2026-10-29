extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardInit1A9688_315DD0")))
int ForwardInit1A9688_315DD0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x600, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x600);
    return func_001A9688(s0);
}

__attribute__((section(".text.ForwardInit1A9858_315E40")))
int ForwardInit1A9858_315E40(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xA00, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xA00);
    return func_001A9858(s0);
}

__attribute__((section(".text.ForwardInit1ABD40_315EB0")))
int ForwardInit1ABD40_315EB0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x7A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x7A0);
    return func_001ABD40(s0);
}

__attribute__((section(".text.ForwardInit1ADB88_315F20")))
int ForwardInit1ADB88_315F20(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x630, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x630);
    return func_001ADB88(s0);
}

__attribute__((section(".text.ForwardInit1AE798_315F90")))
int ForwardInit1AE798_315F90(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xB00, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xB00);
    return func_001AE798(s0);
}

__attribute__((section(".text.ForwardInit1B0290_316000")))
int ForwardInit1B0290_316000(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x630, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x630);
    return func_001B0290(s0);
}

__attribute__((section(".text.ForwardInit1B0B70_316070")))
int ForwardInit1B0B70_316070(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x780, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x780);
    return InitPilotVtable_1B0B70(s0);
}

__attribute__((section(".text.ForwardInit1B0CE8_3160E0")))
int ForwardInit1B0CE8_3160E0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x680, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x680);
    return cObj_initVuFields610(s0);
}

__attribute__((section(".text.ForwardInit1C9140_316150")))
int ForwardInit1C9140_316150(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x790, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x790);
    return func_001C9140(s0);
}

__attribute__((section(".text.ForwardInitObject_3161C0")))
int ForwardInitObject_3161C0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitFieldsAndVtable600_1B1B38(s0);
}
