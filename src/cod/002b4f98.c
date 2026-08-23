/* sn-2.95.3-136 matched TU. */

extern int D_003E0710;
extern int D_003E0708;
extern int D_003E0738;

__attribute__((section(".text.func_002B4F98")))
int func_002B4F98(void *a0, int key) {
    char *p = (char *)a0;
    int i;
    if (key == 0) return 0;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + 4 + i * 4) == key) return *(int *)p + i * 0xAC;
    }
    return 0;
}

__attribute__((section(".text.func_002C30C8")))
unsigned int func_002C30C8(void *a0, void *a1) {
    unsigned int x = *(unsigned int *)a1;
    while (x != 0xFFFFFFFF) {
        unsigned int y = x & 0x7FFFFFFF;
        if ((x & 0x80000000) != 0) return y;
        x = *(unsigned int *)y;
    }
    return 0;
}

__attribute__((section(".text.func_002C97C8")))
int func_002C97C8(void *a0, int x) {
    switch (x) {
    case 0x1A:
    case 0x20:
    case 0x5C:
    case 0x5D:
        return 1;
    }
    return 0;
}

__attribute__((section(".text.func_002D05D8")))
int func_002D05D8(void *a0, int idx, void *out) {
    char *p = (char *)a0;
    char *e;
    if (*(char **)(p + 0x30) == 0) return 0;
    e = *(char **)(*(char **)(p + 0x30));
    e += idx * 8;
    if (*(int *)(e + 4) == 0) return 0;
    *(int *)out = *(int *)(e + 4);
    return *(int *)(*(char **)(p + 0x30) + 8) + *(int *)e * 0xC;
}

__attribute__((section(".text.func_00337B30")))
void func_00337B30(void *a0, int v) {
    char *p = (char *)a0;
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    if (*(signed char *)(p + 0x54) == v) return;
    if (D_003E0738 != 0 || v != 1) *(signed char *)(p + 0x54) = v;
}

__attribute__((section(".text.cScrArray_move")))
void cScrArray_move(void *a0) {
    char *p = (char *)a0;
    int n = *(int *)(p + 0x8);
    int i;
    if (n <= 0) return;
    if (*(unsigned char *)(p + 0x4) != 0) {
        i = *(int *)(p + 0xC) + 1;
        *(int *)(p + 0xC) = i;
        if (i < n) return;
        *(int *)(p + 0xC) = 0;
    } else {
        i = *(int *)(p + 0xC) - 1;
        *(int *)(p + 0xC) = i;
        if (i >= 0) return;
        *(int *)(p + 0xC) = 0;
    }
    *(int *)(p + 0x8) = 0;
}
