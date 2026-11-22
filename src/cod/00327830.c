/* cygnus-2.96 matched TU. */

extern int Obj33C8_GetField_2C_OrZeroIfNull(int);
extern void Obj3270_SetField_9C(int, int);
extern void AC3CNV_Stop(int);

__attribute__((section(".text.ADXSJD_GetLpStartOfst")))
int ADXSJD_GetLpStartOfst(int a0) {
    if (a0 == 0) return 0;
    return Obj33C8_GetField_2C_OrZeroIfNull(*(int *)((char *)a0 + 0x4));
}

__attribute__((section(".text.func_0032B6A0")))
void func_0032B6A0(int a0, int a1) {
    int v;
    *(unsigned char *)((char *)a0 + 0x98) = a1;
    v = *(int *)((char *)a0 + 0x4);
    if (v != 0) {
        Obj3270_SetField_9C(v, a1);
    }
}

__attribute__((section(".text.SFTIM_IsGetFrmTime")))
int SFTIM_IsGetFrmTime(int a0, int a1) {
    if (a1 == 0) return 0;
    return SFTIM_IsGetFrmTimeTunit(a0, *(int *)((char *)a1 + 0x14), *(int *)((char *)a1 + 0x18));
}

__attribute__((section(".text.AC3LINK_StopAc3")))
void AC3LINK_StopAc3(int a0) {
    int v;
    v = *(int *)(*(int *)(*(int *)((char *)a0 + 0x4) + 0x4) + 0xC0);
    if (v != 0) {
        AC3CNV_Stop(v);
    }
}
