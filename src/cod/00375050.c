/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00375050")))
int func_00375050(int arg0, short arg1) {
    char *p;
    char one;

    p = func_0037D170();
    if (p == 0) {
        return -1;
    }
    one = 1;
    *(short *)(p + 0x0) = one;
    *(int *)(p + 0x4) = arg0;
    *(int *)(p + 0x8) = 0;
    p[0xC] = 0x10;
    p[0xD] = one;
    *(short *)(p + 0xE) = 0;
    *(short *)(p + 0x10) = arg1;
    *(short *)(p + 0x12) = -1;
    *(short *)(p + 0x14) = 0;
    *(short *)(p + 0x16) = 0;
    *(short *)(p + 0x18) = 0;
    *(short *)(p + 0x1A) = 0;
    *(short *)(p + 0x1C) = 0;
    *(short *)(p + 0x1E) = 0;
    return 0;
}
