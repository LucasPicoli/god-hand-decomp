/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cDamageGive.h"

extern unsigned char D_0042C4D8[];
extern unsigned char D_0042C4B8[];
extern unsigned char D_0042C498[];
extern void func_001FF0B0(void *);
extern void ClearSlotArray_1FF5B8(void *);
extern void func_0032A6D0(void *a0, void *a1, void *a2);
extern void ClearSlotRefs_376AE0(void *a0, int a1);
extern void func_00378020(void *a0);
extern void func_00378070(void *a0);

__attribute__((section(".text.ResetObjectFields_1FCDE8")))
void ResetObjectFields_1FCDE8(cDamageTake *self) {
    ActorRec_reset((cDamageUnit *)self);
    self->attacker = 0;
    self->type = 2;
    self->hitFlags = 0;
}

#include "godhand/vu0.h"



__attribute__((section(".text.InitObjectA_1FCE20")))
void *InitObjectA_1FCE20(void *a0) {
    *(unsigned char**)((char*)a0+0x50) = D_0042C4D8;
    *(int*)((char*)a0+0x0) = 0;
    VU0_SQC2_VF0(a0, 0x10);
    VU0_SQC2_VF0(a0, 0x20);
    *(int*)((char*)a0+0x3C) = 0;
    *(unsigned char**)((char*)a0+0x50) = D_0042C4B8;
    *(char*)((char*)a0+0x49) = 1;
    func_001FCDB8(a0);
    return a0;
}

#include "godhand/vu0.h"



__attribute__((section(".text.InitObjectB_1FD3B8")))
void *InitObjectB_1FD3B8(void *a0) {
    *(unsigned char**)((char*)a0+0x50) = D_0042C4D8;
    *(int*)((char*)a0+0x0) = 0;
    VU0_SQC2_VF0(a0, 0x10);
    VU0_SQC2_VF0(a0, 0x20);
    *(int*)((char*)a0+0x3C) = 0;
    *(int*)((char*)a0+0x60) = 0;
    *(unsigned char**)((char*)a0+0x50) = D_0042C498;
    *(char*)((char*)a0+0x49) = 2;
    ResetObjectFields_1FCDE8(a0);
    return a0;
}

__attribute__((section(".text.ResetSlotState_1FF2E0")))
int ResetSlotState_1FF2E0(void *a0, int a1) {
    int v0;
    if (a1) *(int*)((char*)a0+4) = 0;
    func_001FF0B0(a0);
    if (*(int*)((char*)a0+4)) {
        v0 = 3;
    } else {
        ClearSlotArray_1FF5B8(a0);
        v0 = 5;
    }
    *(int*)((char*)a0+0) = v0;
    return v0;
}

__attribute__((section(".text.ForwardCollectionItems_374820")))
void ForwardCollectionItems_374820(void *a0, void *a1, void *a2) {
    int i;
    if (*(int*)a0 == 0) return;
    if (*(int*)((char*)a0+0xC) <= 0) return;
    i = 0;
    do {
        void *p = func_00374928(a0, i);
        i++;
        func_0032A6D0(p, a1, a2);
    } while (i < *(int*)((char*)a0+0xC));
}

__attribute__((section(".text.SetSlotEntry_376260")))
void SetSlotEntry_376260(void *a0, void *a1) {
    unsigned char *p = (unsigned char *)a1 + 0x20;
    unsigned short v1 = *(unsigned short *)(p + 6);
    if ((unsigned short)(v1 + 1) < 2) {
        ClearSlotRefs_376AE0(a0, (short)v1);
        return;
    }
    *(short *)((char *)a0 + 0x1A) = *(unsigned short *)(p + 2) << 8;
    *(short *)((char *)a0 + 0x1E) = *(unsigned short *)(p + 6);
    func_00378020((char *)a0 + 0x18);
    *(unsigned short *)a0 |= 0x100;
}

__attribute__((section(".text.UpdateSlotState_3767B0")))
void UpdateSlotState_3767B0(void *a0) {
    char *s = (char *)a0;
    unsigned short flags = *(unsigned short *)s;
    if (flags & 0x100) {
        short v1 = *(short *)(s + 0x18);
        short v0 = *(short *)(s + 0x1A);
        if (v1 == v0) {
            *(short *)s = (short)(flags & 0xFEFF);
            if (v1 == 0) {
                ClearSlotRefs_376AE0(a0, 0);
            }
        } else {
            func_00378070((void *)(s + 0x18));
            *(short *)(s + 0x12) = (short)(*(unsigned short *)(s + 0x12) | 0x1);
        }
    }
}
