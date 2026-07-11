extern int D_00448CA0;
extern int D_005864F0;
extern int D_00448E20;
extern int D_00754C80;

__attribute__((section(".text.ResetStateVtable_284A90")))
void ResetStateVtable_284A90(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00448CA0;
    func_002A84A8();
    if (*(int *)((char *)a0 + 0x15C4) != 0) {
        SetField_630_1C2370(*(int *)((char *)a0 + 0x15C4));
        *(int *)((char *)a0 + 0x15C4) = 0;
    }
    func_00285678(a0);
    func_0028EB88(a0, a1);
}

__attribute__((section(".text.IsAnyActorActive_289418")))
int IsAnyActorActive_289418(void) {
    unsigned int i;
    int r;
    for (i = 0; i < 2; i++) {
        r = func_002948C8(&D_005864F0, i);
        if (r != 0) {
            if (GetField_600_1B8640(r) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

__attribute__((section(".text.ResetAltStateVtable_289788")))
void ResetAltStateVtable_289788(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)&D_00448E20;
    func_002A84A8();
    if (*(int *)((char *)a0 + 0x15B0) != 0) {
        SetField_630_1C2370(*(int *)((char *)a0 + 0x15B0));
        *(int *)((char *)a0 + 0x15B0) = 0;
    }
    cCollisionSolidManage_ReleaseUnit_289E10(a0);
    func_0028EB88(a0, a1);
}

__attribute__((section(".text.BuildGifPacket_2A5930")))
void BuildGifPacket_2A5930(int a0) {
    int *t0;
    t0 = func_002A4F30(a0, 0x10);
    if (t0 != 0) {
        *(long *)((char *)t0 + 0x0) = 0x70000000;
        *(int *)((char *)t0 + 0x8) = 0x11000000;
        *(int *)((char *)t0 + 0xC) = 0;
        func_0031A650(&D_00754C80, *(int *)((char *)a0 + 0x2A060),
                      *(int *)((char *)a0 + 0x2A064), *(int *)((char *)a0 + 0x2A050), t0);
    }
}

__attribute__((section(".text.InitControllerState_2ACC70")))
void InitControllerState_2ACC70(int a0, int a1) {
    func_003A52F0(a0 + 0x100, 0, 0x640);
    *(int *)((char *)a0 + 0x1B544) = 0;
    *(int *)((char *)a0 + 0x740) = 0;
    func_002ACCD8(a0);
    cIDManager_setIDData(a0, 1, a1);
}
