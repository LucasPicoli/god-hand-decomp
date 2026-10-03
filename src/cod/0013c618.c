#include "godhand/cOm60.h"
#include "godhand/cCockTutorial.h"

__attribute__((section(".text.ClearBytesAt74And79To7C_13C618")))
void ClearBytesAt74And79To7C_13C618(char *a0) {
    *(char*)(a0 + 0x74) = 0;
    *(char*)(a0 + 0x79) = 0;
    *(char*)(a0 + 0x7A) = 0;
    *(char*)(a0 + 0x7B) = 0;
    *(char*)(a0 + 0x7C) = 0;
}

__attribute__((section(".text.InitFieldsAt90_13D1D0")))
void InitFieldsAt90_13D1D0(char *a0) {
    *(char*)(a0 + 0x93) = 0;
    *(short*)(a0 + 0x90) = 6;
    *(char*)(a0 + 0x92) = 0;
}

__attribute__((section(".text.InitFieldsAt90_13D1E8")))
void InitFieldsAt90_13D1E8(char *a0) {
    *(char*)(a0 + 0x93) = 0;
    *(short*)(a0 + 0x90) = 6;
    *(char*)(a0 + 0x92) = 0;
}

__attribute__((section(".text.ClearFields94And9C_13E7D8")))
void ClearFields94And9C_13E7D8(char *a0) {
    *(int*)(a0 + 0x94) = 0;
    *(int*)(a0 + 0x9C) = 0;
}

__attribute__((section(".text.ClearFields_B0_AC_147018")))
void ClearFields_B0_AC_147018(char *a0) {
    unsigned int v = 0xFFFF;
    *(int*)(a0 + 0xB0) = 0;
    *(short*)(a0 + 0xAC) = v;
}

/* End the tutorial: forget the loaded pack, set the message number back to
 * none and clear the flag byte. */
__attribute__((section(".text.ClearActiveSlot_147188")))
void ClearActiveSlot_147188(cCockTutorial *self) {
    unsigned int none = COCKTUT_MSG_NONE;
    if (self->data) {
        self->data = 0;
        self->curMsg = none;
        self->unkB8 = 0;
    }
}

__attribute__((section(".text.SetPackedFields10And18_14FF60")))
void SetPackedFields10And18_14FF60(int a0, int *a1) {
    *(long long*)((char*)a0 + 0x18) = 0;
    *(long long*)((char*)a0 + 0x10) = ((long long)*a1 << 32) | 0x20000000;
}

__attribute__((section(".text.ClearFields_4_8_C_E_159998")))
void ClearFields_4_8_C_E_159998(int a0) {
    *(int*)((char*)a0 + 0x4) = 0;
    *(int*)((char*)a0 + 0x8) = 0;
    *(short*)((char*)a0 + 0xC) = 0;
    *(short*)((char*)a0 + 0xE) = 0;
}

__attribute__((section(".text.Set_Field_0_4_8_1646B0")))
void Set_Field_0_4_8_1646B0(int a0, int a1, int a2, int a3) {
    *(int*)((char*)a0 + 0x0) = a1;
    *(int*)((char*)a0 + 0x4) = a2;
    *(int*)((char*)a0 + 0x8) = a3;
}

__attribute__((section(".text.SetField_606_17AEA0")))
void SetField_606_17AEA0(int a0) {
    *(short*)((char*)a0 + 0x606) = 6;
}

__attribute__((section(".text.ClearBytes_764_765_17F6B0")))
void ClearBytes_764_765_17F6B0(int a0) {
    *(char*)((char*)a0 + 0x765) = 0;
    *(char*)((char*)a0 + 0x764) = 0;
}

__attribute__((section(".text.SetField_9E0_1AA500")))
void SetField_9E0_1AA500(void *a0) {
    *(int *)((char *)a0 + 0x9E0) = 8;
}

__attribute__((section(".text.cOm5a_setFaceOpen")))
void cOm5a_setFaceOpen(void *a0) {
    *(int *)((char *)a0 + 0x604) = 0;
    *(int *)((char *)a0 + 0x608) = 1;
}

/* 1 while the object is still held by a parent. */
__attribute__((section(".text.cOm60_ckParent")))
int cOm60_ckParent(cOm60 *self) {
    return self->parent != 0;
}

__attribute__((section(".text.SetEntryParams_1B1928")))
void SetEntryParams_1B1928(void *a0, int a1, short a2) {
    *(int *)((char *)a0 + 0x660) = a1;
    *(short *)((char *)a0 + 0x664) = a2;
    *(char *)((char *)a0 + 0x666) = 0;
}

__attribute__((section(".text.cOmBase_canCarry")))
long long cOmBase_canCarry(void *a0) {
    long long v = *(unsigned int *)((char *)a0 + 0x5B0);
    return (v >> 3) & 0x1;
}

__attribute__((section(".text.SetFlagBit_1BD698")))
int SetFlagBit_1BD698(int a0) {
    *(int*)((char*)a0 + 0x5B8) |= 0x8;
    return 1;
}

__attribute__((section(".text.cOme9_setSwell")))
void cOme9_setSwell(int a0) {
    *(char*)((char*)a0 + 0x2F4) = 1;
    *(char*)((char*)a0 + 0x2F5) = 0;
    *(char*)((char*)a0 + 0x2F6) = 0;
    *(char*)((char*)a0 + 0x2F7) = 0;
}

__attribute__((section(".text.SetField_674_1C20C8")))
void SetField_674_1C20C8(char *a0) {
    a0[0x674] = 1;
}

__attribute__((section(".text.SetField_2F6_1C2308")))
void SetField_2F6_1C2308(char *a0) {
    a0[0x2F6] = 6;
}

__attribute__((section(".text.ClearField630_SetField2F6_1C2318")))
void ClearField630_SetField2F6_1C2318(char *a0) {
    *(int*)(a0 + 0x630) = 0;
    a0[0x2F6] = 2;
}

__attribute__((section(".text.IsEntryActive_1C2490")))
int IsEntryActive_1C2490(int a0) {
    return *(unsigned char*)((char*)a0 + 0x660) != 0;
}

__attribute__((section(".text.InitNode_1D0C78")))
int InitNode_1D0C78(int a0) {
    *(int*)((char*)a0 + 0x0) = 0;
    *(int*)((char*)a0 + 0x4) = 2;
    return a0;
}

__attribute__((section(".text.ClearFields_20_24_28_30_1FC7F8")))
void ClearFields_20_24_28_30_1FC7F8(int a0) {
    *(int*)((char*)a0 + 0x28) = 0;
    *(short*)((char*)a0 + 0x30) = 0;
    *(int*)((char*)a0 + 0x20) = 0;
    *(int*)((char*)a0 + 0x24) = 0;
}

__attribute__((section(".text.NoOp_1FD528")))
void NoOp_1FD528(void) {}

__attribute__((section(".text.SetFields_4_And_8_1FE6B8")))
int SetFields_4_And_8_1FE6B8(int a0, int a1, int a2) {
    *(int*)((char*)a0 + 0x4) = a2;
    *(int*)((char*)a0 + 0x8) = a1;
    return a0;
}

__attribute__((section(".text.BuildPackedAddr_1FFD98")))
int BuildPackedAddr_1FFD98(int a0, unsigned char *a1)
{
    unsigned int v1 = a1[1];
    unsigned short v0 = *(unsigned short *)(a1 + 2);
    return ((unsigned int)v0 + (v1 << 16)) << 4;
}

__attribute__((section(".text.NoOp_1FFE00")))
void NoOp_1FFE00(void)
{
}

extern int D_00760D84;
extern int D_00760D88;
extern int D_00760D8C;

__attribute__((section(".text.Forward3428A0_342870")))
int Forward3428A0_342870(int a0, int a1, int a2) {
    return func_003428A0(a0, a1, a2, 1);
}

__attribute__((section(".text.Forward342910_342888")))
int Forward342910_342888(int a0, int a1, int a2, int a3) {
    return Forward348870_342910(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward348870_342910")))
int Forward348870_342910(int a0, int a1, int a2, int a3) {
    return func_00348870(a0 + 0x284, a1, a2, a3);
}

__attribute__((section(".text.Forward324950_342928")))
int Forward324950_342928(int a0, int a1, int a2, int a3) {
    return func_00324950(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward324AC8_342940")))
int Forward324AC8_342940(int a0, int a1, int a2, int a3) {
    return func_00324AC8(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward329EA8_342A70")))
int Forward329EA8_342A70(int a0, int a1, int a2, int a3) {
    return func_00329EA8(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward35F900_346BF8")))
int Forward35F900_346BF8(void){ return func_0035F900(); }

__attribute__((section(".text.Forward35F970_346C18")))
int Forward35F970_346C18(void){ return func_0035F970(); }

__attribute__((section(".text.Forward35FB88_346C30")))
int Forward35FB88_346C30(void){ return func_0035FB88(); }

__attribute__((section(".text.Forward347218_3471F0")))
int Forward347218_3471F0(int a0, int a1, int a2){ return func_00347218(a0, a1, a2, 0); }

__attribute__((section(".text.Forward33BEC0_3489F0")))
int Forward33BEC0_3489F0(void){ return func_0033BEC0(); }

__attribute__((section(".text.Forward33B938_348A50")))
int Forward33B938_348A50(void){ return func_0033B938(2, D_00760D84); }

__attribute__((section(".text.Forward33B938_348AA8")))
int Forward33B938_348AA8(void){ return func_0033B938(6, D_00760D88); }

__attribute__((section(".text.MWSFSVM_DeleteIdleFunc")))
int MWSFSVM_DeleteIdleFunc(int a0, int a1, int a2, int a3) { return func_0033B938(5, D_00760D8C, a2, a3); }

__attribute__((section(".text.Forward3466C0_348B78")))
int Forward3466C0_348B78(int a0, int a1, int a2, int a3) { return Forward3462D8_3466C0(a0, a1, a2, a3); }

__attribute__((section(".text.Forward3466D8_348B90")))
int Forward3466D8_348B90(int a0, int a1, int a2, int a3) { return Forward346368_3466D8(a0, a1, a2, a3); }

__attribute__((section(".text.Forward33BF18_348BC8")))
int Forward33BF18_348BC8(int a0, int a1, int a2, int a3) { return func_0033BF18(a0, a1, a2, a3); }

__attribute__((section(".text.Forward33BBD8_348C78")))
int Forward33BBD8_348C78(int a0, int a1, int a2, int a3) { return func_0033BBD8(6, a1, a2, a3); }

__attribute__((section(".text.Forward33B790_348C98")))
int Forward33B790_348C98(int a0, int a1, int a2, int a3) { return func_0033B790(a0, a1, a2, a3); }

__attribute__((section(".text.Forward349308_349238")))
int Forward349308_349238(int a0, int a1, int a2, int a3) { return func_00349308(a0, a1, a2, a3); }

__attribute__((section(".text.Forward349480_349468")))
int Forward349480_349468(int a0, int a1, int a2, int a3) {
    return func_00349480(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward349590_349578")))
int Forward349590_349578(int a0, int a1, int a2, int a3) {
    return func_00349590(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward349988_349960")))
int Forward349988_349960(int a0, int a1, int a2, int a3) {
    return func_00349988(a0, a1, a2, 0, 0, *(int*)((char*)a1 + 0xC), *(int*)((char*)a1 + 0x10));
}

__attribute__((section(".text.Forward327D00_349AA0")))
int Forward327D00_349AA0(int a0, int a1, int a2, int a3) {
    return func_00327D00(a0, 0, a2, a3);
}

__attribute__((section(".text.Forward327D90_349AB8")))
int Forward327D90_349AB8(int a0, int a1, int a2, int a3) {
    return func_00327D90(a0, a1, a2, a3);
}

__attribute__((section(".text.Forward3281C8_349B48")))
int Forward3281C8_349B48(int a0, int a1, int a2, int a3) {
    return func_003281C8(a0, a1, a2, a3);
}
