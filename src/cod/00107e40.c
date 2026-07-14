/* sn-2.95.3-136 matched TU. */

extern int D_00460D18;
extern int D_006046C0;
extern int D_0042C320;
extern int InitFields_1B6E90(void *obj);
extern int D_00421F20;
extern void func_002B46F0(void *obj, int a1, int a2, int a3);
extern int InitObjectVtables_100280(void *obj);
extern int D_0041D220;
extern int D_0041B800;

__attribute__((section(".text.func_00134690")))
void func_00134690(int *p) {
    unsigned int i;

    p[0] = 0;
    p[1] = 0;
    D_00460D18 = 0;
    for (i = 0; i < 0x20; i++) {
        p[i + 2] = 0;
    }
    p[34] = 0;
}

#include "godhand/vu0.h"



__attribute__((section(".text.func_002D4FC0")))
void func_002D4FC0(void *obj, int id) {
    char *p;
    int i;

    if (id != 0xFFFF) {
        return;
    }
    if (obj == 0) {
        return;
    }
    p = (char *)&D_006046C0;
    i = 4;
    while (i-- != 0) {
        VU0_SQC2_VF0(p, 0);
        p += 0x10;
    }
}

__attribute__((section(".text.func_002BAC98")))
void func_002BAC98(void *obj) {
    char *this = (char *)obj;
    char *base;
    char *p;

    base = this + 0x14;
    if (base != 0) {
        p = this + 0x34;
        if (base != p) {
            do {
                p -= 8;
            } while (base != p);
        }
    }
    *(int **)(this + 0x8) = &D_0042C320;
    *(unsigned int *)(this + 0x0) &= 0xFFFFF9FC;
}

#include "godhand/vu0.h"




__attribute__((section(".text.func_0017D5D0")))
void *func_0017D5D0(void *obj) {
    int *p;
    int i;

    InitFields_1B6E90(obj);
    *(int **)((char *)obj + 0x214) = &D_00421F20;
    VU0_SQC2_VF0(obj, 0x610);
    VU0_SQC2_VF0(obj, 0x620);
    VU0_SQC2_VF0(obj, 0x630);
    VU0_SQC2_VF0(obj, 0x640);
    p = (int *)((char *)obj + 0x654);
    for (i = 7; i >= 0; i--) {
        p[i] = 0;
    }
    *(int *)((char *)obj + 0x674) = 0;
    return obj;
}

__attribute__((section(".text.func_002B3460")))
void func_002B3460(void *obj) {
    char *this = (char *)obj;
    unsigned short *p;
    unsigned int i;
    int x;
    int y;
    int z;

    z = 0;
    x = *(int *)(this + 0x20);
    y = 0;
    if (*(unsigned char *)(this + 0x70) == 0) {
        y = *(int *)(this + 0x18);
    }
    func_002B46F0(this, x, 0, y);
    p = (unsigned short *)(this + 0x24);
    for (i = 0; i < 2; i++) {
        p[i] = p[i + 1];
    }
    *(int *)(this + 0x14) &= ~2;
    *(short *)(this + 0x28) = z;
}

#include "godhand/vu0.h"





__attribute__((section(".text.func_00107E40")))
void *func_00107E40(void *obj) {
    char *p;
    int i;

    InitObjectVtables_100280(obj);
    *(int **)((char *)obj + 0x214) = &D_0041D220;
    VU0_SQC2_VF0(obj, 0x630);
    VU0_SQC2_VF0(obj, 0x650);
    VU0_SQC2_VF0(obj, 0x660);
    p = (char *)obj + 0x1580;
    i = 2;
    while (i-- != 0) {
        VU0_SQC2_VF0(p, 0);
        p += 0x10;
    }
    VU0_SQC2_VF0(obj, 0x15E0);
    *(int *)((char *)obj + 0x698) = 0;
    *(int **)((char *)obj + 0x4AC) = &D_0041B800;
    *(int *)((char *)obj + 0x6A0) = 0;
    *(int *)((char *)obj + 0x69C) = 0;
    *(int *)((char *)obj + 0x6A4) = 0;
    *(int *)((char *)obj + 0x6A8) = 0;
    return obj;
}
