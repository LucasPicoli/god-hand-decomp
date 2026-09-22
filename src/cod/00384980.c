/* sn-2.95.3-136 matched TU. */

extern void func_003849F8(void *a0, char *a1, int a2);

__attribute__((section(".text.func_00384980")))
void func_00384980(void *a0, char *a1) {
    unsigned char b = *(unsigned char *)(a1 + 3);
    if ((b & 1) != 0) {
        if (*(int *)(a1 + 0xC4) != 0) {
            func_003849F8(a0, a1, *(unsigned char *)(a1 + 4));
            return;
        }
    } else {
        if (*(int *)(a1 + 0x64) != 0) {
            func_003849F8(a0, a1, 0);
            return;
        }
    }
    if ((*(unsigned char *)(a1 + 3) & 2) != 0) {
        func_003849F8(a0, a1, *(unsigned char *)(a1 + 4));
        return;
    }
    func_003849F8(a0, a1, 0);
}
