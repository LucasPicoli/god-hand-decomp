/* sn-2.95.3-136 matched TU. */
#include "godhand/CustomIDWork.h"

extern int D_0044FAD0;
extern unsigned int D_007476B0;
extern int D_00568288;
extern void LookupSlotPopulateFieldsAndDispatch_1F7858(int *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern int cModel_getMeshPtr(int a0, int a1);
extern void func_001344A0(int *a0);
extern void func_00134458(int *a0, int a1);

__attribute__((section(".text.cSnd_GetBgmData")))
int cSnd_GetBgmData(int a0, int a1) {
    int v0 = *(int*)((char*)a0 + 0x40);
    int t = a1 * 0x44;
    return v0 + t;
}

__attribute__((section(".text.cMessCommon_getCodeSize")))
int cMessCommon_getCodeSize(unsigned int a0) {
    a0 = a0 & 0xFFFF;
    if (a0 >> 15) {
        return a0 & 0xF;
    }
    return 1;
}

__attribute__((section(".text.func_002FBE28")))
void func_002FBE28(int a0) {
    *(int **)((char*)a0 + 0xF0) = &D_0044FAD0;
    func_002FBDD8(a0);
}

__attribute__((section(".text.func_00151368")))
long func_00151368(int a0, int a1) {
    int v0 = D_007476B0 & 0x1;
    a0 = a0 + 0x3DC88;
    a0 = a0 + ((v0 << 3) + (a1 << 4));
    return *(long*)((char*)a0);
}

__attribute__((section(".text.func_002DB7A8")))
void func_002DB7A8(void) {
    LookupSlotPopulateFieldsAndDispatch_1F7858(&D_00568288, 0xB, 0x14, 0x11, 0, 0, 0);
}

/* Blends the colour back and forth between `from` and `to` over `frames` frames. */
__attribute__((section(".text.CustomIDWork_SetColorAnimSin")))
void CustomIDWork_SetColorAnimSin(CustomIDWork *self, int from, int to, int frames) {
    if (self->obj != 0) {
        frames = frames & 0xFFFF;
        *(int *)self->colorFrom = from;
        self->colorFlags = CIDW_ANIM_ON | CIDW_ANIM_SINE;
        *(int *)self->colorTo = to;
        self->colorTotal = frames;
        if (frames == 0) {
            self->colorTotal = 1;
        }
        self->colorCount = 0;
    }
}

__attribute__((section(".text.func_001E8E48")))
int func_001E8E48(int a0, int a1) {
    int p = *(int*)a0;
    if (p != 0) {
        return 0;
    }
    a0 = *(int*)((char*)p + 0xF0);
    if (a1 != a0) {
        *(float*)((char*)a1 + 0x0) = *(float*)((char*)a0 + 0x0);
        *(float*)((char*)a1 + 0x4) = *(float*)((char*)a0 + 0x4);
        *(float*)((char*)a1 + 0x8) = *(float*)((char*)a0 + 0x8);
    }
    return 1;
}

__attribute__((section(".text.func_001BFB28")))
int func_001BFB28(int a0){
    int *v0;
    int *v1;
    v0 = (int *)cModel_getMeshPtr(a0, 0);
    *(int *)((char *)v0 + 0x380) = *(int *)((char *)v0 + 0x380) & 0xFFFFFFFE;
    v1 = *(int **)((char *)a0 + 0x600);
    if (v1 != 0) {
        *v1 = *v1 | 1;
    }
    return 1;
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit")))
void cCollisionSolidManage_ReleaseUnit(int *a0, int a1){
    int *node;
    int *prev;
    int *head;
    int next;

    prev = 0;
    if (a1 == 0) {
        return;
    }
    head = *(int **)a0;
    node = head;
    while (node != 0) {
        if (*node == a1) {
            break;
        }
        prev = node;
        node = *(int **)((char *)node + 0x10);
    }
    if (node == 0) {
        return;
    }
    next = *(int *)((char *)node + 0x10);
    if (node != head) {
        *(int *)((char *)prev + 0x10) = next;
    } else {
        *(int *)a0 = next;
    }
    func_001344A0(node);
    if (node != 0) {
        func_00134458(node, 3);
    }
    *(int *)((char *)a0 + 0x4) = *(int *)((char *)a0 + 0x4) - 1;
}
