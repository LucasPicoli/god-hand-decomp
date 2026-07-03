/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_0031A0B8")))
void func_0031A0B8(void *a0, unsigned int a1) {
    unsigned int idx = a1 >> 5;
    unsigned int bit = a1 & 0x1F;
    int *arr = (int*)((char*)a0 + 0x350);
    arr[idx] &= ~(0x80000000U >> bit);
}

__attribute__((section(".text.func_0031AF40")))
int func_0031AF40(void *a0, int a1) {
    switch (a1) {
    case 1: return *(int*)((char*)a0+0x154) != 0;
    case 2: return *(int*)((char*)a0+0x4AC) != 0;
    }
    return 0;
}
