extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardInitBuffer_3147F0")))
int ForwardInitBuffer_3147F0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return InitSlotVu0DataB_195C20(s0);
}

__attribute__((section(".text.AllocZeroAndInit_9E0_314860")))
int AllocZeroAndInit_9E0_314860(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x9E0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x9E0);
    return InitObjSlotArray_196058(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3148D0")))
int ForwardInitBuffer_3148D0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x9E0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x9E0);
    return InitObjSlotArrayB_197680(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314940")))
int ForwardInitBuffer_314940(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitObjVtableC_198CA8(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3149B0")))
int ForwardInitBuffer_3149B0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x9C0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x9C0);
    return InitObjSlotArrayD_198FB8(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314A20")))
int ForwardInitBuffer_314A20(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return InitObjVtableE_199DC0(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314A90")))
int ForwardInitBuffer_314A90(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8C0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8C0);
    return func_00199FD0(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314B00")))
int ForwardInitBuffer_314B00(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8C0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8C0);
    return func_0019A240(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314B70")))
int ForwardInitBuffer_314B70(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x8C0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x8C0);
    return func_0019A4A8(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314BE0")))
int ForwardInitBuffer_314BE0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return func_0019A720(s0);
}
