/* sn-2.95.3-136 matched TU. */

extern int *D_003FA62C;

__attribute__((section(".text.func_003A6A20")))
int func_003A6A20(char *fmt, ...) {
    char *ap = (char *)__builtin_next_arg(fmt) - 0x38;
    int *r = D_003FA62C;
    int stream = *(int *)((char *)r + 0x8);
    *(int **)((char *)stream + 0x54) = r;
    return func_003A9D88(*(int *)((char *)D_003FA62C + 0x8), fmt, ap);
}
