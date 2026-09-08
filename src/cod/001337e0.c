extern unsigned char D_0041D5A8[];

__attribute__((section(".text.InitVtableField5C_1337E0")))
void InitVtableField5C_1337E0(int *a0, int a1) {
    *(int *)((char *)a0 + 0x5C) = (int)D_0041D5A8;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}
