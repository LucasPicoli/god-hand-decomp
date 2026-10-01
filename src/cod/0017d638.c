extern char D_00421F20[];
extern char D_00428778[];
extern char D_00429420[];
extern char D_00429EC8[];

__attribute__((section(".text.InitField214AndSubfields_17D638")))
void InitField214AndSubfields_17D638(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_00421F20;
    cOl21_releaseShapes(a0);
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.SetFlagsAndClearState_17E1E8")))
int SetFlagsAndClearState_17E1E8(int a0) {
    func_001B6FB8(a0);
    *(int *)((char *)a0 + 0x250) = *(int *)((char *)a0 + 0x250) | 0x10000;
    *(char *)((char *)a0 + 0x600) = 0;
    *(int *)((char *)a0 + 0x5B8) = *(int *)((char *)a0 + 0x5B8) | 0x8;
    return 1;
}

__attribute__((section(".text.InitField214WithPtr428778_1B3A70")))
void InitField214WithPtr428778_1B3A70(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_00428778;
    func_001B55A0(a0);
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.InitField214WithPtr429420_1BD650")))
void InitField214WithPtr429420_1BD650(int a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_00429420;
    func_001BDBB8(a0);
    SetField214PtrThenInit_1B6F38(a0, a1);
}

__attribute__((section(".text.InitFieldsWithMode5_1C8F80")))
int InitFieldsWithMode5_1C8F80(int a0) {
    int v0 = a0;
    InitFields_1B6E90(a0);
    *(int *)((char *)a0 + 0x214) = (int)D_00429EC8;
    *(int *)((char *)a0 + 0x600) = 5;
    *(int *)((char *)a0 + 0x604) = 0xE;
    *(int *)((char *)a0 + 0x608) = 0;
    return v0;
}
