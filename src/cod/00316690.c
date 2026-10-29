extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardInitObject_316690")))
int ForwardInitObject_316690(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x600, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x600);
    return func_001BBAC8(s0);
}

__attribute__((section(".text.ForwardInitObject_316700")))
int ForwardInitObject_316700(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitFieldsWithMode5_1C8F80(s0);
}

__attribute__((section(".text.ForwardInitObject_316770")))
int ForwardInitObject_316770(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x910, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x910);
    return func_001BDE50(s0);
}

__attribute__((section(".text.ForwardInitObject_3167E0")))
int ForwardInitObject_3167E0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitActorWithVtableAndTimer_1BE8B0(s0);
}

__attribute__((section(".text.ForwardInitObject_316850")))
int ForwardInitObject_316850(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return func_001BF478(s0);
}

__attribute__((section(".text.ForwardInitObject_3168C0")))
int ForwardInitObject_3168C0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return func_0016F3B0(s0);
}

__attribute__((section(".text.ForwardInitObject_316930")))
int ForwardInitObject_316930(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x980, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x980);
    return func_0016F698(s0);
}

__attribute__((section(".text.ForwardInitObject_3169A0")))
int ForwardInitObject_3169A0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x980, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x980);
    return func_0016F988(s0);
}

__attribute__((section(".text.ForwardInitObject_316A10")))
int ForwardInitObject_316A10(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjVU0Fields_16FC80(s0);
}

__attribute__((section(".text.AllocZeroedAndForward_316A80")))
int AllocZeroedAndForward_316A80(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x920, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x920);
    return Obj16FF_Setup_Field_620_16FF68(s0);
}
