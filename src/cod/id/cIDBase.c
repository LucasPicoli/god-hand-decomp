/* TU: cIDBase [id] - recovered C++ class. */
#include "godhand/vu0.h"
extern int *D_003C2384;
extern void func_002A9DF8(int a0);
extern void cIDBase_resetAnim(int a0);

__attribute__((section(".text.cIDBase_initialize")))
int cIDBase_initialize(int a0, int a1, int a2)
{
    int r;
    func_002A9DF8(a0);
    *(int*)(a0 + 0x10) = a2;
    *(char*)(a0 + 0x46) = 6;
    *(int*)(a0 + 0x14) = a1;
    r = func_002ACD78(*D_003C2384, a1, a2 + 1);
    if (r == 0)
        return 0;
    if (cIDBase_setWorkFromData(a0, r) != 0)
        cIDBase_resetAnim(a0);
    return 1;
}

__attribute__((section(".text.cIDBase_restartAnim")))
void cIDBase_restartAnim(void *a0) {
    cIDBase_resetAnim(a0);
    *(char *)((char *)a0 + 0x1C) = 1;
}
#include "include_asm.h"

extern unsigned char *D_003C23A4;
extern void func_002AA6E0(void);
extern void func_002ABDC0(void *a0, void *a1);
extern void func_002AC048(void *a0, void *a1);
extern void func_002AC1C0(void *a0, void *a1);
extern void func_002AC298(void *a0, void *a1);
extern void func_002AC378(void *a0, void *a1);
extern int cMessage_create(int a0, int a1, int a2, int a3, int t0);

__attribute__((section(".text.cIDBase")))
void *cIDBase(void *a0) {
    VU0_SQC2_VF0(a0, 0x20);
    VU0_SQC2_VF0(a0, 0x30);
    func_002A9DF8(a0);
    return a0;
}

__attribute__((section(".text.cIDBase_setDispFamily")))
void cIDBase_setDispFamily(int a0, int a1, int a2) {
    int w = cIDBase_getIDWork(a0);
    func_002AA598(a0, w, a2);
    func_002AA5F0(a0, w, a2);
}


__attribute__((section(".text.cIDBase_move")))
void cIDBase_move(void *a0)
{
    char *s1 = (char *)a0;
    int i;
    int v;
    unsigned long t;
    if (*(unsigned char *)(s1 + 0x18) != 0) return;
    if (*(int *)(s1 + 0x4) == 0) return;
    func_002AA6E0();
    if (*(unsigned char *)(s1 + 0x1C) == 0) return;
    v = *(unsigned short *)(s1 + 0x1A) + 1;
    *(short *)(s1 + 0x1A) = (short)v;
    if ((short)v >= 0x2710) *(short *)(s1 + 0x1A) = 0;
    i = 0;
    while (i < *(int *)(s1 + 0xC)) {
        char *s0 = *(char **)(s1 + 0x4) + i * 0xAC;
        if (s0 != 0) {
            func_002ABDC0(s1, s0);
            func_002AC048(s1, s0);
            func_002AC1C0(s1, s0);
            func_002AC298(s1, s0);
            func_002AC378(s1, s0);
            if (*(unsigned char *)(s0 + 0x88) == 4) {
                t = *(int *)(s0 + 0x2C);
                if (((t >> 1) & 1) == 0) {
                    if (*(unsigned short *)(s0 + 0x90) != 0xFFFF) {
                        cMessage_create((int)D_003C23A4, *(unsigned short *)(s0 + 0x90), 0, 0, 0);
                        *(int *)(s0 + 0x2C) = *(int *)(s0 + 0x2C) | 0x2;
                    }
                }
            }
        }
        i++;
    }
}

INCLUDE_ASM("nonmatching", cIDBase_trans);
