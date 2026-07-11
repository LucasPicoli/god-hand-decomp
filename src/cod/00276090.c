/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00276090")))
void func_00276090(int *a0, int a1) {
    if (a1) {
        *(int*)((char*)a0+0x16D4) |= 0x200000;
    } else {
        *(int*)((char*)a0+0x16D4) &= ~0x200000;
    }
}

__attribute__((section(".text.func_00290958")))
int func_00290958(char *a0) {
    unsigned int i;
    for (i = 0; i < 0x40; i++) {
        if (*(unsigned char*)(a0+0x10) == 0) {
            return i;
        }
        a0 += 0x14;
    }
    return -1;
}

__attribute__((section(".text.func_00294898")))
void func_00294898(char *a0, int a1) {
    unsigned int i;
    a0 += 0x5AC;
    for (i = 0; i < 2; i++) {
        if (*(int*)a0 == 0) {
            *(int*)a0 = a1;
            return;
        }
        a0 += 4;
    }
}

__attribute__((section(".text.func_002AED40")))
void *func_002AED40(void *a0, int a1) {
    void *v1 = *(void**)((char*)a0 + 0x10);
    unsigned short w = (unsigned short)(a1 & 0xFFFF);
    while (v1 != 0) {
        if (*(unsigned short*)((char*)v1 + 0x64) == w) return v1;
        v1 = *(void**)((char*)v1 + 8);
    }
    return 0;
}

typedef struct Node_00276090 {
    int pad0;
    struct Node_00276090 *prev;
    struct Node_00276090 *next;
} Node_00276090;

__attribute__((section(".text.func_002B2318")))
Node_00276090 *func_002B2318(Node_00276090 *a0) {
    Node_00276090 *prev;
    Node_00276090 *next;
    prev = a0->prev;
    if (prev != 0) {
        prev->next = a0->next;
    }
    next = a0->next;
    if (next != 0) {
        next->prev = a0->prev;
    }
    return a0->next;
}
