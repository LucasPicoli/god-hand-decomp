/* sn-2.95.3-136 matched TU. */

extern int D_003FA62C;

__attribute__((section(".text.func_003A6C58")))
void func_003A6C58(void *a0, void *a1, ...) {
    char buf[0x58];
    char *p;
    *(void **)(buf + 0x0) = a0;
    *(int *)(buf + 0x8) = 0x7FFFFFFF;
    *(short *)(buf + 0xC) = 0x208;
    *(void **)(buf + 0x10) = a0;
    *(int *)(buf + 0x14) = 0x7FFFFFFF;
    *(int *)(buf + 0x54) = D_003FA62C;
    func_003A9D88(buf, a1, (char *)__builtin_next_arg(a1) - 0x30);
    p = *(char **)(buf + 0x0);
    *p = 0;
}
