/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0015FD68")))
int func_0015FD68(void *a0) {
    char *p = (char*)a0 + 4;
    int i;
    for (i = 0; i < 9; i++) {
        if (*(int*)p == 0) return i;
        p += 8;
    }
    return -1;
}

__attribute__((section(".text.func_001FC198")))
int func_001FC198(void *a0, int a1) {
    void *p = *(void**)a0;
    unsigned char v1;
    if (p == 0) {
        return 0x1F;
    }
    v1 = a1 & 0xFF;
    if (v1 >= 0xA) {
        return 0x1F;
    }
    return *(unsigned char*)((char*)p + v1 + 0x98);
}

__attribute__((section(".text.func_001FD8D8")))
int func_001FD8D8(void *a0, int a1) {
    void *v1 = *(void**)((char*)a0 + 0x3C);
    while (v1 != 0) {
        short v0 = *(short*)((char*)v1 + 0x2C);
        if (v0 == a1) {
            return *(int*)((char*)v1 + 0x28);
        }
        v1 = *(void**)((char*)v1 + 0x24);
    }
    return 0;
}
