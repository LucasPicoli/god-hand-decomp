/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_00343AD0")))
void func_00343AD0(void *a0, int a1, int a2, int a3) {
    int *v0 = (int *)((char *)a0 + 0x160);
    *(int *)((char *)a0 + 0x178) = (int)v0;
    v0[1] = a2;
    v0[2] = a3;
    v0[0] = a1;
}

__attribute__((section(".text.func_0037C618")))
void func_0037C618(void *a0, void *a1) {
    *(short *)((char *)a0 + 0x48) = *(short *)((char *)a1 + 0x3c);
    *(short *)((char *)a0 + 0x06) = (unsigned short)(*(unsigned short *)((char *)a0 + 0x06) | 0x4);
}
