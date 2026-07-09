/* ee-2.9-991111 matched TU. */

extern int _IO_default_setbuf(int a0, int a1, int a2);

__attribute__((section(".text.func_00392A30")))
int func_00392A30(int a0, int a1, int a2) {
    int v1;
    if (_IO_default_setbuf(a0, a1, a2) == 0) return 0;
    v1 = *(int *)(a0 + 0x1C);
    *(int *)(a0 + 0x18) = v1;
    *(int *)(a0 + 0x14) = v1;
    *(int *)(a0 + 0x10) = v1;
    *(int *)(a0 + 0xC) = v1;
    *(int *)(a0 + 0x4) = v1;
    *(int *)(a0 + 0x8) = v1;
    return a0;
}
