/* cygnus-2.96 matched TU. */

__attribute__((section(".text.func_002B3B40")))
int func_002B3B40(void *a0) {
    void *obj = *(void**)((char*)a0 + 0x8C);
    short cur = *(short*)((char*)a0 + 0x96);
    short newVal = (short)(*(unsigned short*)((char*)obj + 0x2) + 1);
    if (cur < newVal) {
        *(short*)((char*)a0 + 0x96) = newVal;
    }
    return 0;
}
