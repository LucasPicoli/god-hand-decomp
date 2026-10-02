extern void MtxMultiply(int a, int b, void *buf);
extern void Obj0000_Set_D_007474A0_Fields_5D8_5E0(int a);
extern char **D_003C2384;

__attribute__((section(".text.BuildMatrixAndForward_147BB0")))
void BuildMatrixAndForward_147BB0(int a0, int a1, int a2) {
    int buf[16];
    MtxInitRotQuaternion(buf, a2);
    MtxMultiply(a0, a1, buf);
}

__attribute__((section(".text.MtxMulScaleVec")))
void MtxMulScaleVec(int a0, int a1, int a2) {
    int buf[16];
    MtxInitScaleVec(buf, a2);
    MtxMultiply(a0, a1, buf);
}

__attribute__((section(".text.ResetObjFields4C48_161780")))
void ResetObjFields4C48_161780(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0x4C) = 0;
    *(int *)(p + 0x48) = 0;
    func_00161590(a0);
}

__attribute__((section(".text.ResetObjFields3430_161CC0")))
void ResetObjFields3430_161CC0(int a0) {
    char *p;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0);
    p = *D_003C2384;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x30) = 0;
    func_00161590(a0);
}

__attribute__((section(".text.ResetObjFields9820_1632A0")))
void ResetObjFields9820_1632A0(int a0) {
    int *v1;
    Obj0000_Set_D_007474A0_Fields_5D8_5E0(a0);
    cIDBase_release(a0);
    v1 = *D_003C2384;
    v1[9] = 0;
    v1[8] = 0;
    func_00161590(a0);
}
