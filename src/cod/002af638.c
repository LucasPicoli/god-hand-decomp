/* cygnus-2.96 matched TU. */
#include "godhand/cSnd.h"

__attribute__((section(".text.cMessDrawFont_setRubyData")))
void cMessDrawFont_setRubyData(int *a0, int a1, int a2) {
    a0[2] = a1;
    a0[5] = a2;
}

__attribute__((section(".text.cMessDrawFont_setDrawCounter")))
void cMessDrawFont_setDrawCounter(int *a0, int a1, int a2) {
    a0[6] = a1;
    a0[7] = a2;
}

__attribute__((section(".text.func_002AF6A8")))
void func_002AF6A8(int *a0, int a1, int a2) {
    a0[0x13] = a1;
    a0[0x14] = a2;
}

__attribute__((section(".text.func_002AF710")))
void func_002AF710(int *a0, int a1, int a2) {
    a0[0x16] = a1;
    a0[0x17] = a2;
}

__attribute__((section(".text.func_002B5AE8")))
void func_002B5AE8(int *a0) {
    a0[0] = 0;
    a0[1] = 0;
}

__attribute__((section(".text.func_002B6510")))
int func_002B6510(char *a0) {
    return *(int*)(a0 + 0x90) != 0;
}

__attribute__((section(".text.func_002BAC88")))
void func_002BAC88(void *a0) {
    *(int*)((char*)a0+0) = 0;
    *(int*)((char*)a0+4) = 0;
}

__attribute__((section(".text.func_002BE980")))
void *func_002BE980(void *a0, int a1) {
    *(int*)((char*)a0+0) = a1;
    return a0;
}

__attribute__((section(".text.func_002BEDC8")))
void func_002BEDC8(void *a0, int a1) {
    char *p = *(char**)a0;
    *(char*)(p+8) = (char)a1;
}

__attribute__((section(".text.func_002BEDD8")))
unsigned char func_002BEDD8(void *a0) {
    char *p = *(char**)a0;
    return *(unsigned char*)(p+8);
}

__attribute__((section(".text.func_002C0E68")))
int func_002C0E68(void *a0) {
    return *(unsigned char*)((char*)a0+0x34) & 1;
}

__attribute__((section(".text.func_002C4DD0")))
void func_002C4DD0(void *a0, int a1, int a2) {
    *(int*)((char*)a0+0xF4) = a1;
    *(int*)((char*)a0+0xF8) = a2;
}

/* True while the node is in use. */
__attribute__((section(".text.func_002CC568")))
int func_002CC568(cSndBgmNode *node) {
    return node->state != 0;
}

__attribute__((section(".text.func_002D3210")))
int func_002D3210(void *a0) {
    return *(int*)a0 & 1;
}

__attribute__((section(".text.func_0030A298")))
int func_0030A298(int a0) {
    return (a0 << 2) + 0x1C00;
}

__attribute__((section(".text.func_00328438")))
void func_00328438(void *a0, int a1, int a2) {
    *(int*)((char*)a0+0x38) = a1;
    *(int*)((char*)a0+0x3C) = a2;
}

__attribute__((section(".text.func_00328D30")))
int func_00328D30(void *a0, int a1) {
    *(int*)((char*)a0+0x2C) = a1;
    return 1;
}

__attribute__((section(".text.func_00330910")))
void func_00330910(void *a0) {
    *(int*)((char*)a0+4) = 0;
    *(int*)a0 = 0;
}
