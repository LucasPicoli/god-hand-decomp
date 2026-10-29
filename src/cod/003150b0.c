extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.ForwardSetObjVtableBuffer_3150B0")))
int ForwardSetObjVtableBuffer_3150B0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x610, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x610);
    return SetObjVtable_19D7B0(s0);
}

__attribute__((section(".text.ForwardInitObjVu0Block_315120")))
int ForwardInitObjVu0Block_315120(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return InitObjVu0Block_19D9C0(s0);
}

__attribute__((section(".text.ForwardInitVu0ObjBlock_315190")))
int ForwardInitVu0ObjBlock_315190(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitVu0ObjBlock_19DC48(s0);
}

__attribute__((section(".text.ForwardInitVu0ObjData_315200")))
int ForwardInitVu0ObjData_315200(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitVu0ObjData_19DED0(s0);
}

__attribute__((section(".text.ForwardInitObjVu0Array_315270")))
int ForwardInitObjVu0Array_315270(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x7A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x7A0);
    return InitObjVu0Array_19E1C0(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlots_3152E0")))
int AllocZeroedAndInitObjSlots_3152E0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x9E0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x9E0);
    return InitObjSlots_19E448(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlots_315350")))
int AllocZeroedAndInitObjSlots_315350(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjSlots_19E6C0(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlots_3153C0")))
int AllocZeroedAndInitObjSlots_3153C0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjSlots_19E938(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlots_315430")))
int AllocZeroedAndInitObjSlots_315430(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x7A0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x7A0);
    return InitObjSlots_19EBB8(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlots_3154A0")))
int AllocZeroedAndInitObjSlots_3154A0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjSlots_19EE30(s0);
}
