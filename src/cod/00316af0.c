extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.AllocZeroedAndForward_316AF0")))
int AllocZeroedAndForward_316AF0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x920, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x920);
    return InitObjVU0Fields8Slots_170250(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316B60")))
int AllocZeroedAndForward_316B60(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitObjSetVtable4205E0_170538(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316BD0")))
int AllocZeroedAndForward_316BD0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitObjSetVtable4206B0_1707C8(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316C40")))
int AllocZeroedAndForward_316C40(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitActorSetVtable_170A58(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316CB0")))
int AllocZeroedAndForward_316CB0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitActorSetVtable2_170CE8(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316D20")))
int AllocZeroedAndForward_316D20(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x780, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x780);
    return InitActorBD580Vtable_170F00(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316D90")))
int AllocZeroedAndForward_316D90(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x2B10, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x2B10);
    return func_00171070(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316E00")))
int AllocZeroedAndForward_316E00(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x780, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x780);
    return func_00171B10(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316E70")))
int AllocZeroedAndForward_316E70(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xDB0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xDB0);
    return func_00171C90(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316EE0")))
int AllocZeroedAndForward_316EE0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8A0);
    return func_001739F0(s0);
}
