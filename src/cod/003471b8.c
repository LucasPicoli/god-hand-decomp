/* cygnus-2.96 matched TU. */

extern void func_0035FC58(int, int);
extern void func_0035C238(int, int);

__attribute__((section(".text.func_003471B8")))
void func_003471B8(int a0, int a1) {
    int r = func_00346C48(a0, a1);
    func_0035FC58(r, a1);
}

__attribute__((section(".text.func_00358888")))
void func_00358888(int a0) {
    *(int *)(a0 + 0x48) = 0;
    *(int *)(a0 + 0x4C) = 0;
    func_0035C238(a0, 4);
}
