extern int D_0076A7A4;
extern void MtxMultiply(int a, int b, void *buf);

__attribute__((section(".text.SetGlobalToggle_375700")))
void SetGlobalToggle_375700(int a0) {
    if (a0 == 0) {
        func_0032BA30(1);
    } else {
        func_0032BA30(0);
    }
    D_0076A7A4 = a0;
}

__attribute__((section(".text.InitObjectFull_3806D8")))
void InitObjectFull_3806D8(char *a0) {
    func_00380E10(a0);
    func_00381D38(a0, a0 + 0x348, a0 + 0x318);
    UpdateChildAndFreeSoundHandle(a0);
    func_00385A20(a0);
}

__attribute__((section(".text.InitStructDefaults_137AA0")))
void InitStructDefaults_137AA0(char *a0) {
    *(int *)(a0 + 0x0) = 0;
    *(int *)(a0 + 0x30) = 0;
    func_003A52F0(a0 + 0x4, 0, 0x2C);
    *(float *)(a0 + 0x1C) = 1.06f;
}

__attribute__((section(".text.MtxMulTransVec")))
void MtxMulTransVec(int a0, int a1, int a2) {
    int buf[16];
    MtxInitTransVec(buf, a2);
    MtxMultiply(a0, a1, buf);
}
