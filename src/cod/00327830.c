/* cygnus-2.96 matched TU. */

extern int Obj33C8_GetField_2C_OrZeroIfNull(int);
extern void Obj3270_SetField_9C(int, int);
extern void func_003BA058(int);

__attribute__((section(".text.func_00327830")))
int func_00327830(int a0) {
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

__attribute__((section(".text.func_0035B678")))
int func_0035B678(int a0, int a1) {
    if (a1 == 0) return 0;
    return func_0035B6B0(a0, *(int *)((char *)a1 + 0x14), *(int *)((char *)a1 + 0x18));
}

__attribute__((section(".text.func_003B9BB8")))
void func_003B9BB8(int a0) {
    int v;
    v = *(int *)(*(int *)(*(int *)((char *)a0 + 0x4) + 0x4) + 0xC0);
    if (v != 0) {
        func_003BA058(v);
    }
}
