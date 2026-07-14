/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.Slot1_SetSlotLayer")))
void Slot1_SetSlotLayer(int *dst, int *src) {
    int i;

    dst += 0x100;
    for (i = 34; i >= 0; i--) {
        *dst++ = *src++;
    }
}

__attribute__((section(".text.func_001E8E88")))
void func_001E8E88(int *p) {
    int i;
    int v;

    v = 9;
    for (i = 20; i >= 0; i--) {
        p[i + 21] = v;
    }
}

__attribute__((section(".text.func_002B5E90")))
void *func_002B5E90(void *obj, int n) {
    void *p;

    p = *(void **)((char *)obj + 0x8);
    while (n-- != 0) {
        p = *(void **)((char *)p + 0x10);
    }
    return p;
}
