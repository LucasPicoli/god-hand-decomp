extern unsigned char D_0041D808[];

__attribute__((section(".text.InitVtableField30_1339C0")))
void InitVtableField30_1339C0(int *a0, int a1) {
    *(int *)((char *)a0 + 0x30) = (int)D_0041D808;
    if (a1 & 1) {
        __builtin_delete(a0);
    }
}
