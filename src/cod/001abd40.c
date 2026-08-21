/* sn-2.95.3-136 matched TU. */

extern int func_0();
extern char *InitFields_1B6E90(void *);
extern int D_00427E60;
extern char D_003BE0D8[];
extern char D_003BE168[];

__attribute__((section(".text.cEvent_isEndCreateWork")))
int cEvent_isEndCreateWork(void) {
    return func_0(func_0);
}

__attribute__((section(".text.cEvent_startReleaseObj")))
int cEvent_startReleaseObj(void) {
    return func_0(func_0);
}

#include "godhand/vu0.h"

__attribute__((section(".text.func_001ABD40")))
void *func_001ABD40(char *a0) {
    char *p;
    char *q;
    unsigned int i;

    InitFields_1B6E90(a0);
    p = a0 + 0x630;
    *(int **)(a0 + 0x214) = &D_00427E60;
    VU0_SQC2_VF0(a0, 0x680);
    VU0_SQC2_VF0(a0, 0x690);
    VU0_SQC2_VF0(a0, 0x6A0);
    VU0_SQC2_VF0(a0, 0x6B0);
    VU0_SQC2_VF0(a0, 0x6C0);
    VU0_SQC2_VF0(a0, 0x6D0);
    VU0_SQC2_VF0(a0, 0x6E0);
    VU0_SQC2_VF0(a0, 0x6F0);
    VU0_SQC2_VF0(a0, 0x700);
    VU0_SQC2_VF0(a0, 0x710);
    VU0_SQC2_VF0(a0, 0x720);
    VU0_SQC2_VF0(a0, 0x730);
    VU0_SQC2_VF0(a0, 0x740);
    VU0_SQC2_VF0(a0, 0x750);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    *(int *)(p + 0x130) = 0;
    *(int *)(p + 0x134) = 0;
    *(int *)(p + 0x138) = 0;
    *(int *)(p + 0x13C) = 0;
    i = 0;
    q = p + 0xC;
    for (; i < 8; i++) {
        *(int *)q = 0;
        q += 4;
    }
    return a0;
}

__attribute__((section(".text.func_001E1CD0")))
void func_001E1CD0(int a0) {
    int i = *(int *)(a0 + 0x8);
    short off = *(short *)(D_003BE0D8 + i * 8);
    void (*fn)() = *(void (**)())(D_003BE0D8 + i * 8 + 4);
    fn(a0 + off);
}

__attribute__((section(".text.func_001E58B8")))
void func_001E58B8(int a0) {
    int i = *(int *)(a0 + 0x8);
    short off = *(short *)(D_003BE168 + i * 8);
    void (*fn)() = *(void (**)())(D_003BE168 + i * 8 + 4);
    fn(a0 + off);
}

__attribute__((section(".text.func_001FC548")))
void func_001FC548(int **a0) {
    unsigned int i;
    if (*a0 != 0) {
        i = 0;
        do {
            short *p = (short *)((char *)*a0 + i * 2);
            i++;
            p[0x5D6] = 0;
        } while (i < 5);
    }
}

__attribute__((section(".text.func_00297AA8")))
int func_00297AA8(void *a0) {
    return func_0(func_0) != 0;
}

__attribute__((section(".text.func_00297B20")))
int func_00297B20(void) {
    return func_0(func_0);
}

__attribute__((section(".text.func_00297B40")))
int func_00297B40(void) {
    return func_0(func_0);
}

__attribute__((section(".text.func_00297B60")))
int func_00297B60(void) {
    return func_0(func_0);
}

__attribute__((section(".text.func_00297BA8")))
int func_00297BA8(void) {
    return func_0(func_0);
}

__attribute__((section(".text.func_002999D0")))
void func_002999D0(char *a0, long a1, long a2) {
    char *base = a0 + 0x10000;
    *(long*)(*(long**)(base + 0x4080)) = a2;
    *(long*)((char*)*(long**)(base + 0x4080) + 8) = a1;
    *(int*)(base + 0x4080) = *(int*)(base + 0x4080) + 0x10;
    *(int*)(base + 0x4090) = *(int*)(base + 0x4090) + 1;
}

__attribute__((section(".text.func_00373B30")))
int func_00373B30(int *a0) {
    if (!func_00373A50(a0)) return 0;
    return a0[22];
}
