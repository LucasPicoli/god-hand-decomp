/* sn-2.95.3-136 matched TU. */

extern void func_002A84A8(int a0, int a1, int a2, int a3, float f12);
extern int setMotionInfo(int a0, int a1, int a2, int a3, float f12, float f13, int t0);
extern void func_002B6400(int a0);
extern void *func_001346C8(int a0, int a1, int a2, int a3, float f);
extern void func_00134520(void *p, int a2, int a3, float f);
extern void CustomIDWork_SetNumber(void *p);
extern int D_00429DD8;
extern int SetField214PtrThenInit_1B6F38(void *obj);
extern char *InitFields_1B6E90(char *a0);
extern void func_00305908(void);
extern void LookupSlotPopulateFieldsAndDispatch_1F7858(void *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern char D_00568288;
extern void MtxInitRotVec(void *a0, int a1, int a2);
extern void Tramp_func_0030A2E0_00147548(int a0, int a1, void *a2);

__attribute__((section(".text.func_002A8578")))
int func_002A8578(int a0, int a1, int a2, int a3, int t0, int t1, float f12) {
    int m = t0 & 0xFFFF;
    if ((t1 & 0xFFFF) == 0) {
        func_002A84A8(a0, a1, a2, a3, f12);
    }
    return setMotionInfo(a0, a1, a2, a3,
                         *(float*)((char*)a0 + 0x5A8), f12, m);
}

__attribute__((section(".text.cNode_setLocalTranslation")))
void cNode_setLocalTranslation(int a0, int a1)
{
    char *d;
    func_002B6400(a0);
    d = (char*)a0 + 0x40;
    if (d != (char*)a1) {
        *(float*)((char*)a0 + 0x40) = *(float*)((char*)a1 + 0x0);
        *(float*)(d + 0x4) = *(float*)((char*)a1 + 0x4);
        *(float*)(d + 0x8) = *(float*)((char*)a1 + 0x8);
    }
}

__attribute__((section(".text.cCollisionSolidManage_CreateSphere")))
void cCollisionSolidManage_CreateSphere(int a0, int a1, int a2, int a3, float f) {
    void *r = func_001346C8(a0, a1, a2, a3, f);
    if (r) {
        func_00134520(r, a2, a3, f);
    }
}

__attribute__((section(".text.CustomIDWork_SetNumber_1D5760")))
void CustomIDWork_SetNumber_1D5760(char *a0) {
    CustomIDWork_SetNumber(a0 + 0x158);
}

__attribute__((section(".text.func_002998D8")))
void func_002998D8(int a0, int a1, long a2) {
    int *p = (int *)(a0 + 0x10000);
    int v1 = p[0];
    *(short *)((char *)p + 0x14) = (short)(a1 & 0xFF);
    p[1] = v1;
    p[0] = v1 + 0x10;
    *(long *)((char *)p + 8) = a2;
    *(int *)((char *)p + 0x10) = 0;
}

__attribute__((section(".text.func_00299908")))
void func_00299908(int a0) {
    char *base = (char *)(a0 + 0x10000);
    unsigned long v1 = *(unsigned short *)(base + 0x14);
    unsigned long v0 = *(unsigned int *)(base + 0x10);
    long *p = *(long **)(base + 4);
    v0 = v0 | (v1 << 15);
    v0 = v0 | ((unsigned long)0x8000 << 45);
    *p = v0;
    *(long *)((char *)(*(long **)(base + 4)) + 8) = *(long *)(base + 8);
}

__attribute__((section(".text.cNode_setLocalScale")))
void cNode_setLocalScale(int a0, int a1)
{
    char *d;
    func_002B6400(a0);
    d = (char*)a0 + 0x20;
    if (d != (char*)a1) {
        *(float*)((char*)a0 + 0x20) = *(float*)((char*)a1 + 0x0);
        *(float*)(d + 0x4) = *(float*)((char*)a1 + 0x4);
        *(float*)(d + 0x8) = *(float*)((char*)a1 + 0x8);
    }
}

__attribute__((section(".text.func_001C7DE0")))
int func_001C7DE0(void *a0) {
    *(int **)((char *)a0 + 0x214) = &D_00429DD8;
    return SetField214PtrThenInit_1B6F38(a0);
}

#include "godhand/vu0.h"




__attribute__((section(".text.func_001C7D98")))
char *func_001C7D98(char *a0) {
    InitFields_1B6E90(a0);
    *(int*)(a0 + 0x214) = (int)&D_00429DD8;
    VU0_SQC2_VF0(a0, 0x610);
    VU0_SQC2_VF0(a0, 0x630);
    *(int*)(a0 + 0x5B0) |= 0x8;
    return a0;
}

__attribute__((section(".text.espSys_effDataRegist")))
void espSys_effDataRegist(void)
{
    func_00305908();
}

__attribute__((section(".text.func_002DB770")))
void func_002DB770(void)
{
    LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 0xB, 0x13, 0x10, 0, 0, 0);
}

struct buf_00147B60 { char b[0x40]; };

__attribute__((section(".text.MtxMulRotVec")))
void MtxMulRotVec(int a0, int a1, int a2, int a3)
{
    struct buf_00147B60 buf;
    MtxInitRotVec(&buf, a2, a3 & 0xFF);
    Tramp_func_0030A2E0_00147548(a0, a1, &buf);
}
