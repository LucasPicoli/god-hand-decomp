extern int D_00747A34;
extern char D_00754C10[];

__attribute__((section(".text.AllocZeroedAndInitObjSlots_315510")))
int AllocZeroedAndInitObjSlots_315510(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xB40, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xB40);
    return InitObjSlots_19F0A8(s0);
}

__attribute__((section(".text.AllocZeroedAndSetupFields214And620_315580")))
int AllocZeroedAndSetupFields214And620_315580(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return Setup_Field_214_Field_620_19FEA8(s0);
}

__attribute__((section(".text.AllocZeroedAndInitVu0SlotArray4_3155F0")))
int AllocZeroedAndInitVu0SlotArray4_3155F0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return InitVu0SlotArray4_1A0120(s0);
}

__attribute__((section(".text.AllocZeroedAndInitVu0SlotArray5_315660")))
int AllocZeroedAndInitVu0SlotArray5_315660(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitVu0SlotArray5_1A0390(s0);
}

__attribute__((section(".text.AllocZeroedAndInitVu0SlotArray5B_3156D0")))
int AllocZeroedAndInitVu0SlotArray5B_3156D0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitVu0SlotArray5B_1A0608(s0);
}

__attribute__((section(".text.AllocZeroedAndInitVu0SlotArray4B_315740")))
int AllocZeroedAndInitVu0SlotArray4B_315740(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x800, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x800);
    return InitVu0SlotArray4B_1A0880(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlots_3157B0")))
int AllocZeroedAndInitObjSlots_3157B0(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0x860, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0x860);
    return InitObjSlots_1A0AF0(s0);
}

__attribute__((section(".text.AllocZeroedAndInitObjSlotsB_315820")))
int AllocZeroedAndInitObjSlotsB_315820(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xDA0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xDA0);
    return InitObjSlots_1A0D68(s0);
}

__attribute__((section(".text.AllocZeroedAndForwardInit1A25A0_315890")))
int AllocZeroedAndForwardInit1A25A0_315890(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xDA0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xDA0);
    return func_001A25A0(s0);
}

__attribute__((section(".text.ForwardInit1A3A98_315900")))
int ForwardInit1A3A98_315900(void){
    void *s0;
    if (D_00747A34 & 0x10000) return 0;
    s0 = _MemoryAlloc(0xDA0, 0x10, D_00754C10);
    if (s0 == 0) return 0;
    func_003A52F0(s0, 0, 0xDA0);
    return func_001A3A98(s0);
}
