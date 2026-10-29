extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardInitBuffer_314390")))
int ForwardInitBuffer_314390(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x600, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x600);
    return InitFields_1B6E90(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314400")))
int ForwardInitBuffer_314400(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return Obj1929_Setup_1929B0(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314470")))
int ForwardInitBuffer_314470(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjSlots_192C38(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3144E0")))
int ForwardInitBuffer_3144E0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return InitObjSlots_192F68(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314550")))
int ForwardInitBuffer_314550(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x7A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x7A0);
    return Obj1930_Setup_1931F0(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3145C0")))
int ForwardInitBuffer_3145C0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return Setup_Ptr_214_VU0Array_620_193468(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314630")))
int ForwardInitBuffer_314630(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return Setup_Field_214_Obj0000Array_620_193718(s0);
}

__attribute__((section(".text.ForwardInitBuffer_3146A0")))
int ForwardInitBuffer_3146A0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return InitSlotVu0Data_193998(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314710")))
int ForwardInitBuffer_314710(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x7A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x7A0);
    return InitSlotVu0DataC_193C20(s0);
}

__attribute__((section(".text.ForwardInitBuffer_314780")))
int ForwardInitBuffer_314780(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xB30, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xB30);
    return func_00193EA8(s0);
}
