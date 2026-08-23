/* sn-2.95.3-136 matched TU. */

extern int D_00747A84;

__attribute__((section(".text.func_002CB198")))
int func_002CB198(void)
{
    char *base;
    unsigned long v;
    unsigned long w;

    base = (char *)&D_00747A84;
    v = *(int *)base;
    if (v & 0x800) goto ret1;
    if (v & 0x20000000) goto ret1;
    if (((v >> 7) & 1) == 0) goto rest;
ret1:
    return 1;
rest:
    w = *(int *)(base - 0x60);
    if (((w >> 3) & 1) == 1) return 1;
    if (*(unsigned int *)(base - 0x58) & 0x1000000) return 1;
    return 0;
}
