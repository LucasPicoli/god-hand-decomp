/* sn-2.95.3-136 matched TU. */

extern char D_0041EBE8[];
extern char D_0041EB80[];
extern void func_003A52F0(void *a0, int a1, int a2);
extern int D_007854F8;
extern int D_0041EC58;
extern int D_007856E8;
extern void func_0014E8D8(void);
extern void SetField_0_4_8_31EEA8(void *a0, void *a1, void *a2);
extern int D_00754230;
extern void func_002A94F0(void *a0);
extern int D_004292F0;
extern void *InitFields_1B6E90(void *a0);
extern int D_007859B8;
extern int D_004293A0;
extern int D_00785878;
extern void GetOrInitGlobal785878_1B8058(void);
extern int D_007854D8;
extern int D_0044AEC8;
extern void *cIDBase_getIDWork(void *a0);
extern void cIDBase_initEntry(void *a0, int a1, void *a2);
extern void func_002B64C0(int a0);
extern char D_0045C470[];
extern char D_0045C4A0[];
extern char D_005FEE00[];
extern int cCoreSave_getGold(int a0);
extern int D_00569B70;
extern void SetCustomIDDispOneOrAll_1DD258(int a0, int a1, int a2);
extern void func_002D5250(int a0);
extern int cDvd_Check(int a0, int a1);
extern int D_0044A660;
extern int D_00574380;
extern int D_00462FC0;
extern void func_001FE370(int *a0, int a1);
extern void cCollisionSolidManage_ReleaseUnit(int *a0, int a1);
extern void func_002A73C8(int a0, int a1);
extern void *D_005CAFF0;
extern void func_00138CA8(void *a0, void *a1, void *a2, int a3);

__attribute__((section(".text.func_001D6D20")))
void func_001D6D20(int a0, int a1) {
    if (a1 != 0) {
        *(char*)(*(int*)(a0 + 0xE0) + 0x2B) = 3;
        *(char*)(*(int*)(a0 + 0x15C) + 0x2B) = 4;
    } else {
        int v1 = a0 + 0xDC;
        int a5 = a0 + 0x158;
        *(char*)(*(int*)(v1 + 0x4) + 0x2B) = *(unsigned char*)(v1 + 0x78);
        *(char*)(*(int*)(a5 + 0x4) + 0x2B) = *(unsigned char*)(a5 + 0x78);
    }
}

__attribute__((section(".text.func_002D5080")))
void func_002D5080(long long *a0, int *a1, int *a2) {
    int one = 1;
    *a1 = one << ((int)((*(unsigned long*)a0 >> 26) & 0xF));
    *a2 = one << ((int)((*(unsigned long*)a0 >> 30) & 0xF));
}

#include "godhand/vu0.h"




__attribute__((section(".text.func_0014E990")))
void *func_0014E990(void *a0) {
    func_0014E598(a0);
    *(int*)((char*)a0 + 0x214) = (int)D_0041EBE8;
    VU0_SQC2_VF0(a0, 0x310);
    VU0_SQC2_VF0(a0, 0x320);
    VU0_SQC2_VF0(a0, 0x330);
    VU0_SQC2_VF0(a0, 0x360);
    VU0_SQC2_VF0(a0, 0x370);
    VU0_SQC2_VF0(a0, 0x380);
    VU0_SQC2_VF0(a0, 0x390);
    VU0_SQC2_VF0(a0, 0x460);
    VU0_SQC2_VF0(a0, 0x480);
    VU0_SQC2_VF0(a0, 0x490);
    VU0_SQC2_VF0(a0, 0x4C0);
    *(int*)((char*)a0 + 0x4AC) = (int)D_0041EB80;
    func_003A52F0((char*)a0 + 0x4A8, 0, 4);
    *(int*)((char*)a0 + 0x4A0) = -1;
    *(int*)((char*)a0 + 0x4B4) = 0;
    *(int*)((char*)a0 + 0x4B0) = 0;
    *(int*)((char*)a0 + 0x4A4) = 0;
    *(int*)((char*)a0 + 0x44C) = 0;
    *(char*)((char*)a0 + 0x420) = 0;
    return a0;
}

__attribute__((section(".text.func_0014FD20")))
void *func_0014FD20(void)
{
    if (D_007854F8 == 0) {
        func_0014E8D8();
        SetField_0_4_8_31EEA8(&D_007854F8, &D_0041EC58, &D_007856E8);
    }
    return &D_007854F8;
}

__attribute__((section(".text.func_00161590")))
void func_00161590(char *a0)
{
    func_002A94F0(&D_00754230);
    *(char*)(a0 + 0x64) = 0;
    *(int*)(a0 + 0x60) = -1;
    *(int*)(a0 + 0x50) = 0;
}

#include "godhand/vu0.h"



__attribute__((section(".text.func_001BBEB8")))
void *func_001BBEB8(char *a0)
{
    InitFields_1B6E90(a0);
    *(int**)(a0 + 0x214) = &D_004292F0;
    VU0_SQC2_VF0(a0, 0x610);
    *(int*)(a0 + 0x620) = 0;
    *(int*)(a0 + 0x634) = 0;
    *(short*)(a0 + 0x630) = 0;
    *(int*)(a0 + 0x644) = 0;
    return a0;
}

__attribute__((section(".text.func_001BD528")))
void *func_001BD528(void)
{
    if (D_007859B8 == 0) {
        GetOrInitGlobal785878_1B8058();
        SetField_0_4_8_31EEA8(&D_007859B8, &D_004293A0, &D_00785878);
    }
    return &D_007859B8;
}

__attribute__((section(".text.func_002A9300")))
void *func_002A9300(void)
{
    if (D_007854D8 == 0) {
        func_0014FD20();
        SetField_0_4_8_31EEA8(&D_007854D8, &D_0044AEC8, &D_007854F8);
    }
    return &D_007854D8;
}

__attribute__((section(".text.func_002AA3D8")))
void func_002AA3D8(void *a0)
{
    void *v0 = cIDBase_getIDWork(a0);
    if (v0 != 0) {
        cIDBase_initEntry(a0, *(int*)((char*)v0 + 0x1C), v0);
    }
}

__attribute__((section(".text.func_002B6328")))
int func_002B6328(int a0) {
    func_002B64C0(a0);
    return a0 + 0x50;
}

__attribute__((section(".text.func_00380AE8")))
int func_00380AE8(int a0, int a1) {
    int *s0 = (int *)a1;
    int r;
    func_00380E88();
    r = func_0031C890(0x231E4);
    s0[0x34/4] = r;
    if (r == 0) {
        func_003A6A20(D_0045C470);
        return 1;
    }
    r = func_00329438(2, r, 0x231E4);
    s0[0x30/4] = r;
    if (r == 0) {
        func_003A6A20(D_0045C4A0);
        func_0031C900(s0[0x34/4]);
        return 2;
    }
    return 0;
}

__attribute__((section(".text.func_00126770")))
void func_00126770(char *a0) {
    char *s1 = a0;
    char *s0;
    int v0, v1;
    int x;
    x = *(int *)(s1 + 0x165C);
    if (x != 0) {
        cActionButtonUnit_setExit(x);
        *(int *)(s1 + 0x165C) = 0;
    }
    s0 = D_005FEE00;
    cSnd_SeStop(s0, *(int *)(s1 + 0x161C));
    *(int *)(s1 + 0x161C) = 0;
    v0 = *(int *)(s0 + 0xB0);
    v1 = *(int *)(s0 + 0xAC);
    v0 &= 0xFFBFFFFF;
    v1 &= 0xFFBFFFFF;
    *(int *)(s0 + 0xB0) = v0;
    *(int *)(s0 + 0xAC) = v1;
    cSnd_SeStop(s0, *(int *)(s1 + 0x1620));
    *(int *)(s1 + 0x1620) = 0;
}

__attribute__((section(".text.func_00143A90")))
void func_00143A90(int a0) {
    int *p = (int *)a0;
    if (p[0x94/4] != 0) {
        p[0x90/4] = cCoreSave_getGold((int)&D_00569B70);
        *(int *)(p[0x94/4] + 0x84) = cCoreSave_getGold((int)&D_00569B70);
        cCoreSave_initAddGold((int)&D_00569B70);
    }
}

__attribute__((section(".text.func_001DD5A0")))
void func_001DD5A0(int a0, int a1) {
    SetCustomIDDispOneOrAll_1DD258(a0, 0x25, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x26, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x27, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x28, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x29, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x2A, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x2B, a1);
    SetCustomIDDispOneOrAll_1DD258(a0, 0x2C, a1);
}

__attribute__((section(".text.func_00201108")))
void func_00201108(int a0, int a1) {
    while (cDvd_Check(a0, a1) != 0) {
        func_002D5250(1);
    }
    func_002D5250(1);
}

__attribute__((section(".text.func_0028EB88")))
void func_0028EB88(int a0, int a1) {
    *(int **)((char *)a0 + 0x214) = &D_0044A660;
    func_001FE370(&D_00574380, a0);
    cCollisionSolidManage_ReleaseUnit(&D_00462FC0, a0);
    func_002A73C8(a0, a1);
}

__attribute__((section(".text.func_002B4768")))
void func_002B4768(int a0, int a1, int a2) {
    int v0;
    v0 = func_002AF218(*(int *)a2);
    *(int *)a1 = *(int *)a1 + v0;
    v0 = cMessCommon_getCodeSize(*(unsigned short *)(*(int *)a2));
    *(int *)a2 = *(int *)a2 + (v0 << 1);
}

__attribute__((section(".text.cCamManager_setPartsCamera")))
void cCamManager_setPartsCamera(void *a0, int a1)
{
    void *s0 = a0;
    int a3 = a1 & 0xFF;
    int v1 = *(int*)((char*)s0 + 0x1028);
    void *s2;
    if (v1 == 0x40)
        return;
    if (v1 == 0x10)
        return;
    s2 = (char*)s0 + 0x920;
    if (a3 != 0) {
        func_00138CA8(s0, s2, D_005CAFF0, a3);
    }
    *(int*)((char*)s0 + 0x102C) = *(int*)((char*)s0 + 0x1028);
    *(void**)((char*)s0 + 0xFF0) = D_005CAFF0;
    D_005CAFF0 = s2;
    *(int*)((char*)s0 + 0x1028) = 0x40;
}
