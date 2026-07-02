/* sn-2.95.3-136 matched TU. */

extern int D_003F2160;
extern int D_005FEA60;

__attribute__((section(".text.func_00374AE0")))
int func_00374AE0(int index) {
    int offset = ((index << 16) >> 14);
    int *table = (int *)&D_003F2160;
    int *ptr = (int *)((char *)table + offset);
    return *ptr;
}

__attribute__((section(".text.func_002C23F8")))
int func_002C23F8(void *base) {
    int *obj = (int *)&D_005FEA60;
    int ptr1 = (int)((char *)base + 0x5C);
    int ptr2 = (int)((char *)base + 0x7C);
    *(int *)((char *)obj + 0x6C) = ptr2;
    *(int *)((char *)obj + 0x68) = ptr1;
    return 0;
}
