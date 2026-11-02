/* cygnus-2.96 matched TU. */
#include "godhand/heapArena.h"

__attribute__((section(".text.func_00297FB8")))
void func_00297FB8(int a0, int a1, int a2) {
    *(int*)(a0 + 0x10) = a1;
    *(int*)(a0 + 0x14) = a2;
}

__attribute__((section(".text.func_002A7308")))
void func_002A7308(int a0) {
    *(int*)(a0 + 0x0) = 0;
    *(int*)(a0 + 0x4) = 0;
}

__attribute__((section(".text.func_002A9528")))
void func_002A9528(HeapArena *self) {
    self->unk[0] = 0;
    self->unk[1] = 0;
}

__attribute__((section(".text.func_00332378")))
void func_00332378(int a0, int a1, int a2) {
    *(int*)(a0 + 0x20) = a1;
    *(int*)(a0 + 0x24) = a2;
}

__attribute__((section(".text.func_00332388")))
void func_00332388(int a0, int a1, int a2) {
    *(int*)(a0 + 0x28) = a1;
    *(int*)(a0 + 0x2C) = a2;
}

__attribute__((section(".text.func_00339788")))
void func_00339788(int a0, int a1, int a2) {
    *(int*)(a0 + 0x38) = a1;
    *(int*)(a0 + 0x3C) = a2;
}

__attribute__((section(".text.func_00345D10")))
void func_00345D10(void *a0) {
    *(int*)((char*)a0+0x7C) = 0;
    *(int*)((char*)a0+0x80) = 0;
}

__attribute__((section(".text.func_00346FA0")))
int func_00346FA0(void *a0, void *a1) {
    int v = *(int*)((char*)a0+0x34);
    *(int*)((char*)a1+0x4C) = v;
    return v;
}

__attribute__((section(".text.func_0034C1F8")))
void func_0034C1F8(void *a0) {
    *(int*)((char*)a0+0x0) = 0;
    *(int*)((char*)a0+0x4) = 0;
}

__attribute__((section(".text.func_00350138")))
int func_00350138(void *a0) {
    int *p = *(int**)((char*)a0+0x1F7C);
    return *(int*)((char*)p+0x20);
}

__attribute__((section(".text.func_003554E8")))
int func_003554E8(void *a0) {
    int *p = *(int**)((char*)a0+0x1FC0);
    return *(int*)((char*)p+0x7C);
}

__attribute__((section(".text.func_003554F8")))
void func_003554F8(void *a0, int a1) {
    void *p = *(void**)((char*)a0+0x1FC0);
    *(int*)((char*)p+0x80) = a1;
}

__attribute__((section(".text.func_003565D0")))
int func_003565D0(void *a0) {
    int *v1 = *(int **)((char*)a0 + 0x1FC0);
    return *(int*)((char*)v1 + 0x11FC);
}

__attribute__((section(".text.func_00356C58")))
int func_00356C58(void *a0) {
    int *v1 = *(int **)((char*)a0 + 0x1FC0);
    return *(int*)((char*)v1 + 0x1158);
}

__attribute__((section(".text.func_0035AA40")))
void func_0035AA40(void *a0, int a1, int a2) {
    *(int*)((char*)a0 + 0x144) = a1;
    *(int*)((char*)a0 + 0x148) = a2;
}

__attribute__((section(".text.func_0035FB78")))
int func_0035FB78(int a0) {
    return a0 >= 0x181F;
}

__attribute__((section(".text.func_0035FC60")))
void func_0035FC60(void *a0, int a1, int a2) {
    *(int*)((char*)a0 + 0x8) = a1;
    *(int*)((char*)a0 + 0xC) = a2;
}

__attribute__((section(".text.func_00360940")))
int func_00360940(int a0) {
    return a0 ? 0x23 : 0;
}
