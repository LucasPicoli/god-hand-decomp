/* sn-2.95.3-136 matched TU. */

extern char D_005F3970[];
extern void func_003A52F0(void *, int, int);
extern void func_001F2708(void *);
extern void func_002A7338(void *);
extern int D_0044A660;
extern int D_0044A630;

__attribute__((section(".text.func_00134650")))
void *func_00134650(void *this) {
    int *p;
    unsigned int i;

    *(int *)((char *)this + 0x0) = 0;
    p = (int *)((char *)this + 0x8);
    for (i = 0; i < 32; i++) {
        p[i] = 0;
    }
    *(int *)((char *)this + 0x88) = 0;
    return this;
}

__attribute__((section(".text.cCoreSave_setClearStage")))
void cCoreSave_setClearStage(void *this, unsigned short stage) {
    void *obj;
    unsigned int mask;
    unsigned int i;

    obj = *(void **)this;
    if (obj != 0) {
        mask = 0;
        for (i = 0; i <= stage; i++) {
            mask |= 1 << i;
        }
        *(unsigned int *)((char *)obj + 0xA4) = mask;
    }
}

#include "godhand/vu0.h"



__attribute__((section(".text.func_002C0A28")))
void func_002C0A28(int a0, int a1) {
    char *base;
    unsigned char *p;
    int i;

    if (a1 != 0xFFFF) {
        return;
    }
    if (a0 == 0) {
        return;
    }
    base = D_005F3970;
    VU0_SQC2_VF0(base, 0x190);
    p = (unsigned char *)(base + 0x28A);
    for (i = 0x7F; i != -1; i--) {
        p[4] = 0;
        p += 0x10;
    }
    *(int *)(base + 0xB8C) = 0;
}

#include "godhand/vu0.h"




__attribute__((section(".text.ColiseumBattle__ctor")))
void *ColiseumBattle__ctor(void *this) {
    unsigned char *p;
    int i;

    func_003A52F0(this, 0, 0x54);
    *(int *)((char *)this + 0x54) = 0;
    func_001F2708((char *)this + 0x60);
    *(int *)((char *)this + 0xBAC) = 0;
    p = (unsigned char *)this + 0xBD0;
    for (i = 8; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    }
    return this;
}

#include "godhand/vu0.h"





__attribute__((section(".text.func_0028EB00")))
void *func_0028EB00(void *a0) {
    char *p;
    int i;

    func_002A7338(a0);
    *(int **)((char *)a0 + 0x214) = &D_0044A660;
    p = (char *)a0 + 0x5C0;
    for (i = 1; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x0);
        p += 0x10;
    }
    *(int *)((char *)a0 + 0x610) = 0;
    VU0_SQC2_VF0(a0, 0x650);
    *(int **)((char *)a0 + 0x4AC) = &D_0044A630;
    *(short *)((char *)a0 + 0x2AE) = 0x258;
    *(int *)((char *)a0 + 0x610) = 0;
    *(short *)((char *)a0 + 0x62E) = 0;
    *(int *)((char *)a0 + 0x644) = 0;
    return a0;
}
