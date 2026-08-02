/* sn-2.95.3-136 matched TU. */

extern int D_00747A80;
extern int cGameObj_isClip();
extern void func_00297CA0();
extern void func_00297CE8();

__attribute__((section(".text.func_0028ABF0")))
int func_0028ABF0(void *a0) {
    char *s0 = (char *)&D_00747A80;
    int v;
    if (D_00747A80 & 0x40000000) return 1;
    if (cGameObj_isClip(a0) != 0) return 1;
    v = *(int *)(s0 - 0x54) & 0x400000;
    return v != 0;
}

__attribute__((section(".text.func_0028C398")))
int func_0028C398(void *a0) {
    char *s0 = (char *)&D_00747A80;
    int v;
    if (D_00747A80 & 0x40000000) return 1;
    if (cGameObj_isClip(a0) != 0) return 1;
    v = *(int *)(s0 - 0x54) & 0x400000;
    return v != 0;
}

__attribute__((section(".text.func_0028E9D0")))
int func_0028E9D0(void *a0) {
    char *s0 = (char *)&D_00747A80;
    int v;
    if (D_00747A80 & 0x40000000) return 1;
    if (cGameObj_isClip(a0) != 0) return 1;
    v = *(int *)(s0 - 0x54) & 0x400000;
    return v != 0;
}

__attribute__((section(".text.func_00297CB0")))
void func_00297CB0(void *a0, char *a1) {
    if (a1) {
        func_00297CA0(a0, a1 + 0x10, *(int *)(a1 + 4));
    } else {
        func_00297CA0(a0, 0, 0);
    }
}

__attribute__((section(".text.func_00297CF8")))
void func_00297CF8(void *a0, char *a1) {
    if (a1) {
        func_00297CE8(a0, a1 + 0x10, *(int *)(a1 + 4));
    } else {
        func_00297CE8(a0, 0, 0);
    }
}
